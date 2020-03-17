struct nodoArb {
	struct nodoArb* izq;
	struct nodoArb* der;
	void *info;
};
typedef struct nodoArb  NodoArb;
void imprimeArb(NodoArb *raiz, void (*f)(void *));
NodoArb *creaNodoArb(void *dato, NodoArb *izq, NodoArb *der);
void imprimeCadena(void *p);


