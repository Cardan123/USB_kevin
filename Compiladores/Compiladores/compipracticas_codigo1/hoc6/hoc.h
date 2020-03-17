typedef struct Symbol { /* entrada en la tabla de símbolos */
char   *name;
short  type;
union {
double  val;           /* VAR */
double  (*ptr)();      /* BLTIN */
void     (*defn)();     /* FUNCIÓN, PROCEDIMIENTO */
char    *str;         /* CADENA */
} u;
struct Symbol   *next;  /* para ligar a otro */
} Symbol;
Symbol  *install(), *lookup();

typedef union Datum {   /* tipo de la pila del intérprete: */
double val;
Symbol *sym; 
} Datum;

extern void pop1( );
extern Datum pop( );
extern void eval(), add(), sub(), mul(), div(), negate(), power();

typedef void (*Inst)(void);
#define STOP   (Inst) 0
extern    Inst *progp, *progbase, prog[], *code();
extern    void assign(), bltin(), varpush(), constpush(), print(), varread();
extern    void prexpr(), prstr();
extern    void gt(), lt(), eq(), ge(), le(), ne(), and(), or(), not();
extern    void ifcode(), whilecode(), call(), arg(), argassign();
extern    void funcret(), procret();


