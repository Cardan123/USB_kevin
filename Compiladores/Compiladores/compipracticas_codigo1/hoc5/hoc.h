typedef struct Symbol { /* entrada en la tabla de símbolos */
char    *name;
short   type;   /* VAR, BLTIN, UNDEF */
union {
double val;	/* si es VAR */
double  (*ptr)();       /* si es BLTIN */
} u;
struct Symbol   *next;  /* para ligarse a otro */ } Symbol;
Symbol  *install(), *lookup();

typedef union Datum {   /* tipo de la pila del intérprete */
double  val;
Symbol  *sym; } Datum; 

extern Datum pop();

typedef int (*Inst)();  /* instrucción de maquina */ 

#define STOP    (Inst) 0

extern	Inst prog[ ] , *progp, *code();

extern	eval(), add(), sub(), mul(), div(), negate(), power();
extern	assign(), bltin(), varpush(), constpush(), print();

extern	prexpr();
extern	gt(), lt(), eq(), ge(), le(), ne(), and() , or(), not();
extern	ifcode(), whilecode();
