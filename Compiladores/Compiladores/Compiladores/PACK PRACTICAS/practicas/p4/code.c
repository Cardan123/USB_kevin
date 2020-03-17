#include "hoc.h"
#include "y.tab.h"
#include <stdio.h>
#define	NSTACK	256

static Datum stack[NSTACK];
static Datum *stackp;

#define	NPROG	2000
Inst prog[NPROG];
static Inst *pc;
Inst *progp;

initcode()
{
	progp = prog;
	stackp = stack;
}

push(d)
	Datum d;
{
	if (stackp >= &stack[NSTACK])
		execerror("stack too deep", (char *)0);
	*stackp++ = d;
}

Datum
pop()
{
	if (stackp == stack)
		execerror("stack underflow", (char *)0);
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
	d.sym = (Symbol *)(*pc++);
	push(d);
}

bltin()
{
	Datum d;
	d = pop();
	//d.comp = ((Complejo (*)())(*pc++))(d.comp);
	d.comp = (*(Complejo* (*)())(*pc++))(d.comp);
	push(d);
}

eval() /* Evaluate variable on stack */
{
	Datum d;
	d = pop();
	if (d.sym->type != VAR && d.sym->type != UNDEF)
		execerror("attempt to evaluate non-variable", d.sym->name);
	if (d.sym->type == UNDEF)
		execerror("undefined variable", d.sym->name);
	d.comp = d.sym->u.comp;
	push(d);
}

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

Inst *code(f)	/* install one instruction or operand */
	Inst f;
{
	Inst *oprogp = progp;
	if (progp >= &prog[NPROG])
		execerror("expression too complicated", (char *)0);
	*progp++ = f;
	return oprogp;
}

execute(p)
	Inst *p;
{
	for (pc = p; *pc != STOP; )
		(*(*pc++))();
}

