struct complejo{
	double valR;
	double valI;
};
typedef struct complejo Complejo;

typedef struct Symbol { /* entrada en la tabla de símbolos */
char   *name;
short  type;
union {
	Complejo* comp;
	double  val;           /* VAR */
	double  (*ptr)();      /* BLTIN */
	int     (*defn)();     /* FUNCIÓN, PROCEDIMIENTO */
	char    *str;         /* CADENA */
} u;
struct Symbol   *next;  /* para ligar a otro */
} Symbol;
Symbol  *install(), *lookup();

typedef union Datum {   /* tipo de la pila del intérprete: */
	Complejo* comp;
	double val;
	Symbol *sym; 
} Datum;

extern Datum pop( );
extern eval(), add(), sub(), mul(), div(), negate();// power();

typedef int (*Inst)();
#define STOP   (Inst) 0
extern    Inst *progp, *progbase, prog[], *code();
extern    assign(), bltin(), varpush(), constpush(), print(), varread();
extern    prexpr(), prstr();
extern    gt(), lt(), eq(), ge(), le(), ne(), and(), or(), not();
extern    ifcode(), whilecode(), call(), arg(), argassign(),forcode();
extern    int funcret(), procret();

Complejo *creaComplejo(double real, double img);
Complejo *Complejo_add(Complejo *, Complejo *);
Complejo *Complejo_sub(Complejo *, Complejo *);
Complejo *Complejo_mul(Complejo *, Complejo *);
Complejo *Complejo_div(Complejo *, Complejo *);
void imprimirC(Complejo *c);


