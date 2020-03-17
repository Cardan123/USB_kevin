struct nodoL {
   void *info;
   struct nodoL *sig;
};
typedef struct nodoL NodoL;
struct nodoArb {
	struct nodoArb* izq;
	struct nodoArb* der;
	void *info;
        //int num;
        //int anu;
};
typedef struct nodoArb  NodoArb;
#define MAXELEM 1000
typedef void *tTipo;
struct conjunto {
    tTipo *eltos;
    int cardinal;
    int tama;
    int id;
};
typedef struct conjunto Conjunto;
struct nodoI {
        char *id;
        int num;
        int anu;
    Conjunto *first;
    Conjunto *last;
    Conjunto *sig[100];
};
typedef struct nodoI  NodoI;
NodoI *creaNodoI(char *dato, int num, int anu);
void *copiaNodoI(void *p);
int esHoja(NodoArb *r);
NodoArb *creaNodoArb(void *dato, NodoArb *izq, NodoArb *der);
void imprimeNodoI(void *v);
void imprimeNodoII(void *v);
void imprimeArb(NodoArb *raiz, void (*f)(void *));
void imprimeCade(void *s);
int cmpNodoNum(void *p1, void *p2);
int cmpNodoID(void *p1, void *p2);
Conjunto *creaConjunto(int tama);
Conjunto *copiaConjunto(Conjunto *conj, void *(*cp)(void *));
void imprimeConjunto(Conjunto *conj, void (*f)(void *));
int pertenece(Conjunto *A, tTipo key, int (*cmp)(void *, void *));
Conjunto *insertar(Conjunto *A, tTipo x, 
                   int (*cmp)(void *, void *),  void *(*cp)(void *));
Conjunto *borrar(Conjunto *A, tTipo key, int (*cmp)(void *, void *));
Conjunto *unirConjunto(Conjunto *A, Conjunto *B, 
          int (*cmp)(void *, void *), void *(*cp)(void *));
Conjunto *intersecConjunto(Conjunto *A, Conjunto *B, 
          int (*cmp)(void *, void *), void *(*cp)(void *));
Conjunto *diferenConjunto(Conjunto *A, Conjunto *B, 
          int (*cmp)(void *, void *), void *(*cp)(void *));
Conjunto *difsimConjunto(Conjunto *A, Conjunto *B, 
          int (*cmp)(void *, void *), void *(*cp)(void *));
int subconjunto(Conjunto *A, Conjunto *B, int (*cmp)(void *, void *));
int iguales(Conjunto *A, Conjunto *B, int (*cmp)(void *, void *));
int contains(Conjunto *conte, Conjunto *ele, int *enc, int (*cmp)(void *, void *));
Conjunto *insertarSet(Conjunto *A, Conjunto * x, 
                   int (*cmp)(void *, void *), void *(*cp)(void *));
NodoL *get(NodoL **head);
Conjunto *firstPos(NodoArb *raiz);

