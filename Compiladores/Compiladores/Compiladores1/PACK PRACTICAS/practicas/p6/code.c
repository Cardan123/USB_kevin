#include "hoc.h"
#include "y.tab.h"
#include <stdio.h>
#define NSTACK  256
static Datum stack[NSTACK];    /* la pila */
static Datum *stackp;          /* siguiente sitio libre en la pila */
#define NPROG  2000
Inst   prog[NPROG];   /* la Máquina */
Inst   *progp;        /* siguiente sitio libre para la generación de código */
Inst   *pc;              /* contador de programa durante la ejecución */
Inst   *progbase = prog; /* Inicie del subprograaa actual */
int    returning;      /* 1 si se ve la proposiolón de retorno */

typedef struct Frame {     /* nivel da pila par» Huida a proc/func */
Symbol  *sp;         /* entrada en la tabla da simbolos */
Inst    *retpc;   /* dónde reanudar después del retorno */
Datum  *argn;     /* n-esimo argumento en la pila */
int    nargs;     /* número da argumentos */
} Frame;

#define NFRAME  100 
Frame  frame[NFRAME] ;
Frame   *fp;  /* apuntador a nivel */

initcode() 
{
progp = progbase;
stackp = stack;
fp = frame;
returning = 0; 
}


push(d)
Datum d;
{
if (stackp >= &stack[NSTACK])
execerror("stack too deep", (char *)0); 
*stackp++ = d;
}

Datum pop( )
{
if (stackp == stack)
execerror("stack underflow" , (char *)0);
return *--stackp;
}


constpush()
{
	Datum d;
	double real=((Symbol *)*pc++)->u.val;
	double imaginario=((Symbol *)*pc++)->u.val;
	d.comp =creaComplejo(real,imaginario);
	push(d);
}

varpush()
{
	Datum d;
	d.sym =  (Symbol *)(*pc++);
	push(d);
}

whilecode()
{
	Datum d;
	Inst *savepc = pc;
	execute(savepc+2);      /* condición */ 
	d = pop( ); 
	while (d.val) {
		execute(*((Inst **)(savepc)));  /* cuerpo */
		if (returning) break;
			execute(savepc+2);      /* condición */ 
			d = pop();
	} 
	if (!returning)
		pc = *((Inst **)(savepc+1)); /* siguiente proposición */ 
}

ifcode() {
	Datum d;
	Inst *savepc = pc;      /* parte then */
	execute(savepc+3);     /* condición */ 
	d = pop (); 
	if (d.val)
		execute(*((Inst **)(savepc))); 
	else if (*((Inst **)(savepc+1))) /* ¿parte else? */
		execute(*((Inst **)(savepc+1))); 
	if (!returning)
		pc = *((Inst **)(savepc+2)); /* siguiente proposición */ 
} 
forcode()
{
	Datum d;
	Inst *savepc = pc;
	execute(savepc+4);		/* precharge */
	pop();
	execute(*((Inst **)(savepc)));	/* condition */
	d = pop();

	while (d.val) {
		execute(*((Inst **)(savepc+2)));	/* body */
		execute(*((Inst **)(savepc+1)));	/* post loop */
		pop();
		execute(*((Inst **)(savepc)));	/* condition */
		d = pop();
	}
}

define(sp)      /* poner func/proc en tabla de símbolos */
Symbol *sp; 
{
	sp->u.defn = (Inst)progbase;    /* lnlolo de código */ 
	progbase = progp;      /* el siguiente código comienza aquí */
}

call()               /*   llamar función  */
{
Symbol  *sp  =   (Symbol *)pc[0];   /*   entrada en tabla da simbolos  */ 
                                    /*   para la función   */
if   (fp++   >=  &frame[NFRAME-1])
	execerror(sp->name,   "call  nested too deeply");
	fp->sp = sp;
	fp->nargs =   (int)pc[1];
	fp->retpc = pc  + 2;
	fp->argn  =  stackp  -   1;     /*   último argumento   */
	execute(sp->u.defn);
	returning = 0; 
} 

ret( )                          /* retorno común de func o proc */
{
	int i;

	for (i = 0; i < fp->nargs; i++)
		pop();  /* sacar argunentos de la pila */
	pc = (Inst *)fp->retpc;
	--fp;
	returning = 1; 
}

int funcret()      /* retorno de una función */ 
{
Datum d;
if (fp->sp->type == PROCEDURE)
execerror(fp->sp->name, "(proc) returns value");
d = pop();      /* conservar el valor de retorno de la funolón */
ret();
push(d); 
}

int procret( )             /*   retorno de un prooedimiento   */
{
if   (fp->sp->type  ==  FUNCTION)
execerror(fp->sp->name,
"(func) returns no value"); 
ret(); 
}

double *getarg( )       /* apuntador de retorno para argumento */ 
{
	int nargs = (int) *pc++;
	if (nargs > fp->nargs)
		execerror(fp-> sp->name, "not enough arguments");
	return &fp->argn[nargs - fp->nargs].val; 
}

arg( )   /* meter argumento en la pila */ 
{
	Datum d;
	d.val = *getarg();
	push(d); 
}

argassign()          /*  guardar tope de pila en argumento  */
{
	Datum d;
	d =pop();
	push(d);       /* dejar valor en la pila */
	*getarg() = d.val; 
}

bltin() 
{
	Datum d;
	d = pop();
	//d.val =  (*(double  (*)())*pc++)(d.val);
	d.comp = (*(Complejo* (*)())(*pc++))(d.comp);
	push(d);
}

eval()
{
	Datum d;
	d = pop();
	if (d.sym->type != VAR && d.sym->type != UNDEF)
		execerror("attempt to evaluate non-variable", d.sym->name); 
	if (d.sym->type == UNDEF)
		execerror("undefined variable", d.sym->name); 
	//d.val = d.sym->u.val; 
	d.comp = d.sym->u.comp;
	push(d);
}
//------------------------
add()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.comp = Complejo_add(d1.comp,d2.comp);
	push(d1);
}

sub()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.comp = Complejo_sub(d1.comp,d2.comp);
	push(d1);
}

mul()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.comp = Complejo_mul(d1.comp,d2.comp);
	push(d1);
}

div()
{
	Datum d1, d2;
	d2 = pop();
	//if (d2.val->valR == 0.0)
	//	execerror("division by zero", (char *)0);
	d1 = pop();
	d1.comp=Complejo_div(d1.comp,d2.comp);
	push(d1);
}

negate()
{
	Datum d;
	d = pop();
	d.comp =  Complejo_negate(d.comp);
	push(d);
}

gt()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	/*double md1=sqrt(pow(d1.comp->valR,2)+pow(d1.comp->valI,2));
	double md2=sqrt(pow(d2.comp->valR,2)+pow(d2.comp->valI,2));
	d1.val = (double)(md1 > md2)&&(d1.comp->valR > d2.comp->valR);*/
	d1.val=(double)((d1.comp->valR > d2.comp->valR)&&(d1.comp->valI > d2.comp->valI));
	push(d1);
}

lt()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	/*double md1=sqrt(pow(d1.comp->valR,2)+pow(d1.comp->valI,2));
	double md2=sqrt(pow(d2.comp->valR,2)+pow(d2.comp->valI,2));
	d1.val = (double)(md1 < md2)&&(d1.comp->valR < d2.comp->valR);*/
	d1.val=(double)((d1.comp->valR < d2.comp->valR)&&(d1.comp->valI < d2.comp->valI));
	push(d1);
}

ge()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	//d1.val->valR = (double)(d1.val->valR >= d2.val->valR);
	/*d1.comp->valR = (double)(d1.comp->valR >= d2.comp->valR);
	d1.comp->valI = (double)(d1.comp->valI >= d2.comp->valI);*/
	//d1.val = (double)(Complejo_modulo(d1) >= Complejo_modulo(d2));
	d1.val=(double)((d1.comp->valR >= d2.comp->valR)&&(d1.comp->valI >= d2.comp->valI));
	push(d1);
}

le()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	//d1.val->valR = (double)(d1.val->valR <= d2.val->valR);
	//d1.comp->valR = (double)(d1.comp->valR <= d2.comp->valR);
	//d1.comp->valI = (double)(d1.comp->valI <= d2.comp->valI);
	//d1.val = (double)(Complejo_modulo(d1) <= Complejo_modulo(d2));
	d1.val=(double)((d1.comp->valR <= d2.comp->valR)&&(d1.comp->valI <= d2.comp->valI));
	push(d1);
}

eq()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	//d1.val->valR = (double)(d1.val->valR == d2.val->valR);
	//d1.comp->valR = (double)(d1.comp->valR == d2.comp->valR);
	//d1.comp->valI = (double)(d1.comp->valI == d2.comp->valI);
	//d1.val = (double)(Complejo_modulo(d1) == Complejo_modulo(d2));
	d1.val=(double)((d1.comp->valR == d2.comp->valR)&&(d1.comp->valI == d2.comp->valI));
	push(d1);
}

ne()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	//d1.val->valR = (double)(d1.val->valR  !=  d2.val->valR);
	//d1.comp->valR = (double)(d1.comp->valR != d2.comp->valR);
	//d1.comp->valI = (double)(d1.comp->valI != d2.comp->valI);
	//d1.val = (double)(Complejo_modulo(d1) != Complejo_modulo(d2));
	d1.val=(double)((d1.comp->valR != d2.comp->valR)&&(d1.comp->valI != d2.comp->valI));
	push(d1);
}

and()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	//d1.val->valR = (double)(d1.val->valR != 0.0 && d2.val->valR != 0.0);
	//d1.comp->valR = (double)(d1.comp->valR != 0.0 && d2.comp->valR!= 0.0);
	//d1.comp->valI = (double)(d1.comp->valI != 0.0 && d2.comp->valI!= 0.0);
	d1.val=(double)((d1.comp->valR != 0.0 && d2.comp->valR !=0.0)&&(d1.comp->valI != 0.0 && d2.comp->valI != 0.0));

	push(d1);
}

or()	
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	//d1.val->valR = (double)(d1.val->valR != 0.0 || d2.val->valR != 0.0);
	//d1.comp->valR = (double)(d1.comp->valR != 0.0 || d2.comp->valR != 0.0);
	//d1.comp->valI = (double)(d1.comp->valI != 0.0 || d2.comp->valI != 0.0);
	d1.val=(double)((d1.comp->valR != 0.0 || d2.comp->valR !=0.0)&&(d1.comp->valI != 0.0 || d2.comp->valI != 0.0));
	push(d1);
}

not()
{
	Datum d;
	d = pop();
	//d.val->valR = (double)(d.val->valR == 0.0);
	//d.comp->valR = (double)(d.comp->valR == 0.0);
	//d.comp->valI = (double)(d.comp->valI == 0.0);
	d.val=(double)(d.val == 0.0);
	push(d);
}


//------------------------

assign()
{
	Datum d1, d2;
	d1 = pop();
	d2 = pop();
	if (d1.sym->type != VAR && d1.sym->type != UNDEF)
		execerror("assignment to non-variable",d1.sym->name);
	d1.sym->u.comp = d2.comp;
	d1.sym->type = VAR;
	push(d2);
}

print()
{
	Datum d;
	d = pop();
	if(d.comp==NULL)
		printf("\t%.8g\n", d.val);	
	else
		imprimirC(d.comp);
	//printf("\t%.8g\n", d.val->valR);
}

prexpr()	/* print numeric value */
{
	Datum d;
	d = pop();
	imprimirC(d.comp);
	//printf("%.8g\n",d.val);
}

prstr() {
/* Imprimir valor de la cadena */ printf("%s", (char *) *pc++);
}

varread()              /*   leer en una variable   */
{
Datum d;
extern FILE *fin; 
Symbol *var = (Symbol *) *pc++; 
Again:
switch (fscanf(fin, "%lf", &var->u.val)) { 
case EOF:
if (moreinput())
goto Again;
d.val = var->u.val = 0.0;
break; 
case 0:
execerror("non-number read into", var->name);
break; 
default:
d.val = 1.0;
break; 
}
var->type = VAR; 
push(d);
}

Inst *code(f)   /* lnstalar una lnstrucción u operando */
Inst f; 
{
Inst *oprogp = progp;
if (progp >= &prog[NPROG])
execerror("program too big", (char *)0);
*progp++ = f;
return oprogp;
}

execute(p)
Inst *p;
{
for (pc = p; *pc != STOP && !returning; ) 
	(*(*pc++))();
}

