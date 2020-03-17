#include <string.h>

struct nodoL {
	void *dato;
	struct nodoL *sig;
};
typedef struct nodoL NodoL;

struct termino {
        double coefi;
        unsigned expo;
   unsigned band;
} ;
typedef struct termino Termino;
struct polinomio {
   int grado;
   NodoL *cab;
}; 
typedef struct polinomio Polinomio;
typedef struct polinomio* PolinomioAP;
/*  prototypes of the provided functions */ 

NodoL *creaNodoL(void *dato, NodoL *sig);
NodoL *insertaOrdA(void *dato, NodoL **cab, int (*cmp)(void *, void *));
//void imprimeL(NodoL *inicio, void (*f)(void *));
void imprimeL(NodoL *inicio, void ( *f)(void *, int));
int igualNodoL(NodoL  *cab1, NodoL  *cab2, 
	int (*cmp)(void *, void *));
//Termino *creaTermino(int coefi,int expo);
Termino *creaTermino(double coefi, int);
//void imprimeTermino(void * dato);
void imprimeTermino(void *dato, int fin);
int cmpTermino(void *t1, void *t2);
//Polinomio *creaPolinomio(int grado, NodoL *cab);
Polinomio *creaPolinomio(int grado, NodoL *cab, int sgn);
//void asignarPolinomio(Polinomio *r, int num, int den);

Polinomio* sumaPolinomio(Polinomio *r, Polinomio *s);
Polinomio* restaPolinomio(Polinomio *r, Polinomio *s);
Polinomio* multiplicaPolinomio(Polinomio *r, Polinomio *s);
Polinomio* dividePolinomio(Polinomio *r, Polinomio *s);
int esIgualPolinomio(Polinomio *r, Polinomio *s);
void imprimePolinomio(Polinomio *p);
Polinomio *copiaPolinomio(Polinomio *r);
/*  prototypes of the provided functions */ 
/* define the return type of FLEX */
//#define YYSTYPE PolinomioAP
