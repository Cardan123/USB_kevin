struct nodoArb {
	struct nodoArb* izq;
	struct nodoArb* der;
	void *info;
};
typedef struct nodoArb  NodoArb;
NodoArb *creaNodoArb(void *dato, NodoArb *izq, NodoArb *der);
void imprimeArb(NodoArb *raiz, void (*f)(void *));
void imprimeCade(void *s);
