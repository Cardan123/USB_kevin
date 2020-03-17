struct complejo{
	double valR;
	double valI;
};
typedef struct complejo Complejo;

typedef struct Symbol {	/* symbol table entry */
	char	*name;
	short	type;	/* VAR, BLTIN, UNDEF */
	union {
		//double	val;
		/* if VAR */
		Complejo* comp;
		double val;
		double* (*ptr)();	/* if BLTIN */
	} u;
	struct Symbol	*next;	/* to link to another */
} Symbol;
Symbol	*install(), *lookup();

typedef union Datum {	/* interpreter stack type */
	double val;
	Complejo* comp;
	Symbol	*sym;
} Datum;
extern	Datum pop();

typedef int (*Inst)();	/* machine instruction */
#define	STOP	(Inst) 0

extern	Inst prog[], *progp, *code();
extern	eval(), add(), sub(), mul(), div(), negate(), power();
extern	assign(), bltin(), varpush(), constpush(), print();
extern	prexpr();
extern	gt(), lt(), eq(), ge(), le(), ne(), and(), or(), not();
extern	ifcode(), whilecode();

Complejo *creaComplejo(double real, double img);
Complejo *Complejo_add(Complejo *, Complejo *);
Complejo *Complejo_sub(Complejo *, Complejo *);
Complejo *Complejo_mul(Complejo *, Complejo *);
Complejo *Complejo_div(Complejo *, Complejo *);
void imprimirC(Complejo *c);

