
typedef struct Formal	Formal;
typedef struct Saveval	Saveval;
typedef struct Fndefn	Fndefn;
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
struct campo {
    char nombre[100];
    int tamano;
    char tipo;
};
typedef struct campo Campo;
struct tabla {
    char nombre[100];
    int num_campos;
    int tam_registro;
    Campo campos[100];
};
typedef struct tabla Tabla;
union Symval { /* value of a symbol */
	void	*val;		/* VAR */
	double	(*ptr)(double);	/* BLTIN */
        void  (*ci)(); 
	Fndefn	*defn;		/* FUNCTION, PROCEDURE */
	char	*str;		/* STRING */
};
typedef union Symval Symval;
typedef struct Simbolo { /* entrada en la tabla de símbolos */
char   *nombre;
short  tipo;
NodoL  *vars;
Symval  u;
double **mat2;
double **estruct;
Tabla tabla;
struct Simbolo  *molde;
struct Simbolo  *sestruct;
int sizes[100];
struct Simbolo   *next;  /* para ligar a otro */
} Simbolo;

typedef union Datum {   /* tipo de la pila del intérprete: */
void *val;
Simbolo *sym; 
} Datum;

//typedef void (*Inst)();
typedef char *Inst; 

typedef struct Frame {     /* nivel da pila par» Huida a proc/func */
Simbolo  *sp;         /* entrada en la tabla da simbolos */
Inst    *retpc;   /* dónde reanudar después del retorno */
void  **argn;     /* n-esimo argumento en la pila */
int    nargs;     /* número da argumentos */
NodoL  *vars;
} Frame;
struct array {
 Simbolo     *sym;
 int        nindis;
};
typedef struct array Array;
struct Saveval {	/* saved value of variable */
	Symval	val;
	long	tipo;
	Saveval	*next;
};
struct Formal {	/* formal parameter */
	Simbolo	*sym;
	Saveval	*save;
	//Formal	*next;
};
struct Fndefn {	/* formal parameter */
	Inst	*code;
        //void  (*ci)(); 
	//Formal	*formals;
        NodoL *cab;
	int	nargs;
};

NodoL *creaNodoL(void *dato, NodoL *sig);
Simbolo* lookup(NodoL *env, char* s);
Simbolo *install(NodoL **env, char *s, int t, void *d);
double *creaDoble(double d);
Formal *creaFormal(Simbolo *formal);
Fndefn *creaFndefn(Inst *code, NodoL *cab, int nargs);
//extern	Formal *formallist(Simbolo*, Formal*);
extern NodoL *formallist(NodoL *env,Simbolo *formal);
extern	void restore(Simbolo*);
extern void pop1(), eval(), add(), sub(), mul(), div_(), negate(), power();

#define STOP   (Inst) 0
extern    Inst *progp, *progbase, prog[], *code();
extern double *espaestru;
extern  void assign(), bltin(), varpush(), constpush(), print(), varread(), memalloc();
void membialloc();
void memmultialloc();
extern    void prexpr(), prstr();
extern void print_( );
void printIndis();
extern    void gt(), lt(), eq(), ge(), le(), ne(), and(), or(), not();
extern    void ifcode(), whilecode(), forcode(),call(), arg(), argassign();
extern    void funcret(), procret();
extern void preinc(void);
extern void predec(void);
extern void postinc(void);
extern void postdec(void);
extern void addeq(void);
extern void subeq(void);
extern void muleq(void);
extern void elepush(), eleassign(), eleeval();
void elebiassign();
void elemultiassign();
void memberassign();
void memberpush();
void elebieval();
void acumula();
void acumula111();
void eltomulti();
int buscaCampo(char *nomcampo, Tabla tabla, int *tamcampo);
//void *traeCampo(Tabla tabla, char *nomcampo,void *regis);
void **traeCampo(Tabla tabla, char *nomcampo,void **regis);
//void modiCampo(Tabla tabla, char *nomcampo, double *regis, double val);
void modiCampo(Tabla tabla, char *nomcampo, void **regis, void *val);
void imprimeEsquema(Tabla tabla);

void * addDoble(void *dob1, void *dob2);
void *subDoble(void *dob1, void *dob2);
void *mulDoble(void *dob1, void *dob2);
void *div_Doble(void *dob1, void *dob2);
void *modDoble(void *dob1, void *dob2);
void *powerDoble(void *dob1, void *dob2);
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
void *sumaUnoDoble(void *dob);
void *restaUnoDoble(void *dob);
int pilaCondDoble(void *dob);
int convPilaDoble(void *dob);

Pila *creaPila(int tama);
int estaVacia(Pila *p);
void *top(Pila *p);
void **topDir(Pila *p);
void **topDirNArg(Pila *p, int n);
void *pop(Pila *p);
void push(Pila *p, void *dato);

void define(Simbolo* sp, NodoL *nl);





