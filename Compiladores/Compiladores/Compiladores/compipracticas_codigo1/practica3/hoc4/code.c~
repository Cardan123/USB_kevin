#include "hoc.h" 
#include "y.tab.h"
#define NSTACK  256
static  Datum  stack[NSTACK];  /* la pila */
static  Datum   *stackp;       /* siguiente lugar libre en la pila */
#define NPROG   2000
Inst    prog[NPROG];    /* la máquina */
Inst    *progp;         /* siguiente lugar libre para la generación de código */
Inst    *pc;	/* contador de programa durante la ejecución */


initcode()      /* inicialización para la generación de código */ {
stackp = stack;
progp = prog;
}

push(d)	/*  meter d en la pila  */
Datum d; 
{
if (stackp >= &stack[NSTACK])
execerror("stack overflow", (char *) 0);
*stackp++ = d;
}

Datum pop( )     /* sacar y retornar de la pila el elemento del tope */
{
if (stackp <= stack)
execerror("stack underflow", (char *) 0);
return  *--stackp;
}


constpush( )	/* meter una constante a la pila  */
{
Datum d;
d.val  =  ((Symbol  *)*pc++)->u.val;
push(d);
}

varpush()	/* meter una variable a la pila   */
{
Datum d;
d.sym  =  (Symbol   *)(*pc++);
push(d);
}

eval( )	/*  evaluar una variable en la pila   */
{
Datum  d;
d   =  pop();
if   (d.sym->type   ==   INDEF)
execerror("undefined variable",   
d.sym->name); 
d.val   =  d.sym->u.val; push(d);
}

add( )	/*   sumar los dos elementos superiores de la pila   */
{
Datum d1,   d2; 
d2  =  pop(); 
d1   =  pop(); 
d1.val  +=  d2.val; push(d1); 
}

sub()
{
Datum d1,  d2; 
d2  = pop(); 
d1  = pop(); 
d1.val  -= d2.val; 
push(d1);
}

mul()
{
Datum d1, d2;
d2 = pop(); 
d1 = pop(); 
d1.val *= d2.val; 
push(d1);
}


div( )
{
Datum d1, d2;
d2 = pop();
if (d2.val == 0.0)
execerror("division by zero", (char *)0);
d1 = pop(); 
d1.val /= d2.val; 
push(d1);
}

negate()
{
Datum d; 
d = pop(); 
d.val  =  -d.val; 
push(d);
}

power()
{
Datum d1, d2;
extern double Pow();
d2 = pop();
d1 = pop();
d1.val = Pow(d1.val, d2.val);
push(d1);
}


assign( )        /* asignar el valor superior al siguientevalor */ 
{
Datum d1, d2;
d1 = pop();
d2 = pop();
if (d1.sym->type != VAR && d1.sym->type != INDEF) 
execerror("assignment to non-variable", d1.sym->name);
d1.sym->u.val = d2.val;
d1.sym->type = VAR;
push(d2); 
} 

print( )  /* sacar el valor superior de la pila e imprimirlo */ 
{
Datum d;
d = pop();
printf("\t%.8g\n",   d.val);
}

bltin( )/*  evaluar un predefinido en el tope de la pila  */
{
Datum d;
d  =  pop();
d.val  =   (*(double   (*)())(*pc++))(d.val);
push(d);
}
 

Inst   *code(Inst f) /*   instalar una instrucción u operando   */
{
Inst *oprogp = progp;
	if (progp >= &prog [ NPROG ])
		execerror("program too big", (char *) 0);
	*progp++ = f;
	return oprogp;
}

execute(Inst p)	/*   ejecución con la máquina   */
{
for  (pc  =  p;   *pc != STOP; ) 
	(*(*pc++))();
}

