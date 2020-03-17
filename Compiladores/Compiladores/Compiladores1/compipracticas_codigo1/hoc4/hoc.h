typedef struct Symbol { /* entrada de la tabla de símbolos */
	char   *name;
	short   type;   /* VAR, BLTIN, UNDEF */
	union {
		double val;	       /* si es VAR */
		double  (*ptr)();      /* sí es BLTIN */
	} u;
	struct Symbol   *next;  /* para ligarse a otro */ 
} Symbol;

Symbol *install(char *s,int t, double d), *lookup(char *s);

typedef union Datum {   /* tipo de la pila del intérprete */
double  val;
Symbol  *sym; } Datum; 

extern Datum pop();
typedef int (*Inst)();  /* instrucción de máquina */ 

#define STOP    (Inst) 0
extern	Inst prog[];
extern	eval(), add(), sub(), mul(), div(), negate(), power();
extern	assign(), bltin(), varpush(), constpush(), print();
