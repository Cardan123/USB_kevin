struct nodoL {
	void *dato;
	struct nodoL *sig;
};
typedef struct nodoL NodoL;
struct pila {
   int tama;
   int tope;
   void **elementos;
};
typedef struct pila Pila;
union Symval { /* value of a symbol */
   void	*val;		/* VAR */
   void	*(*ptr)(void *);	/* BLTIN */
   //void  (*defn)();     /* FUNCIÓN, PROCEDIMIENTO */
   char **defn; 
   void  (*ci)();
};
typedef union Symval Symval;
struct simbolo { /* entrada en la tabla de símbolos */
char   *nombre;
short  tipo;
Symval  u;
};
typedef struct simbolo Simbolo;
typedef union Datum {   /* tipo de la pila del intérprete: */
void *val;
Simbolo *sym; 
} Datum;

typedef char *Inst; 

typedef struct Frame {     /* nivel da pila par» Huida a proc/func */
Simbolo  *sp;         /* entrada en la tabla da simbolos */
Inst    *retpc;   /* dónde reanudar después del retorno */
void  **argn;     /* n-esimo argumento en la pila */
int    nargs;     /* número da argumentos */
} Frame;
struct array {
 Simbolo     *sym;
 int        nindis;
};

extern  Inst *progp, *progbase, prog[]; 
extern  Inst *code(Inst f);

NodoL *creaNodoL(void *dato, NodoL *sig);
Simbolo* lookup(NodoL *env, char* s);
Simbolo *install(NodoL **env, char *s, int t, void *d);

extern void pop1(), eval(), add(), sub(), mul(), div_(), mod( ), negate(), power();
extern  void assign(), bltin(), varpush(), constpush(), print(), printVal();
extern    void gt(), lt(), eq(), ge(), le(), ne(), and(), or(), not();
extern    void ifcode(), whilecode(), call(), arg(), argassign();
extern  void funcret(), procret();

double *creaDoble(double d);
void * addDoble(void *dob1, void *dob2);
void *subDoble(void *dob1, void *dob2);
void *mulDoble(void *dob1, void *dob2);
void *div_Doble(void *dob1, void *dob2);
void *modDoble(void *dob1, void *dob2);
void *powerDoble(void *dob1, void *dob2);
void printDoble(void *dob);
void *negateDoble(void *dob);
void *gtDoble(void *dob1, void *dob2);
void *ltDoble(void *dob1, void *dob2);
void *geDoble(void *dob1, void *dob2);
void *leDoble(void *dob1, void *dob2);
void *eqDoble(void *dob1, void *dob2);
void *neDoble(void *dob1, void *dob2);
void *andDoble(void *dob1, void *dob2);
void *orDoble(void *dob1, void *dob2);
void *notDoble(void *dob);
int pilaCondDoble(void *dob);

Pila *creaPila(int tama);
int estaVacia(Pila *p);
void *top(Pila *p);
void **topDir(Pila *p);
void **topDirNArg(Pila *p, int n);
void *pop(Pila *p);
void push(Pila *p, void *dato);









