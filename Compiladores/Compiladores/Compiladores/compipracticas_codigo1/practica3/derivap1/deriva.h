#define OPER 500
struct nodoArb {
   struct nodoArb* padre;
   struct nodoArb* izq;
   struct nodoArb* der;
   short tipo;
   void *info;
};
typedef struct nodoArb  NodoArb;
struct deriva {
	NodoArb* expr;
	NodoArb* der;
};
typedef struct deriva Deriva;
void imprimeArb(NodoArb *raiz, void (*f)(void *));
NodoArb *creaNodoArb(void *dato, short tipo,  
                     NodoArb *izq, NodoArb *der);
NodoArb *clonaNodoArb(NodoArb *r);
void imprimeCadena(void *p);
NodoArb *Evalua(NodoArb *r, int dir);


