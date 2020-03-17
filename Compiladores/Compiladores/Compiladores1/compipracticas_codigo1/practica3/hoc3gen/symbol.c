#include <stdlib.h>
#include <string.h>
#include  "hoc.h" 
#include  "y.tab.h"

static NodoL  *symlist=(NodoL *)0;

NodoL *creaNodoL(void *dato, NodoL *sig){
	NodoL *nvo;
	nvo=(NodoL*)malloc(sizeof(NodoL));
	nvo->dato=dato;
	nvo->sig=sig;
	return nvo;
}
NodoL *find(NodoL  *inicio, void *key, int (*igual)(void *, void *)){
	NodoL *p;
	for(p=inicio;p;p=p->sig)
             if(!(*igual)(p->dato, key))
		return p;
	return p; //NULL
}
Symbol *creaSymbol(char *s,int t, double d){
   Symbol *sp=(Symbol *)malloc(sizeof(Symbol));
   sp->name = strdup(s);
   sp->type = t;
   sp->u.val = d;
   return sp;
}
int cmpSymbol(void *p1, void *p2){
   Symbol *s1=(Symbol* )p1;
   Symbol *s2=(Symbol* )p2;
   return strcmp(s1->name, s2->name);
}
NodoL *lookup(char *s){
   return find(symlist, (void *)creaSymbol(s, 0, 0.0), cmpSymbol);
}
NodoL *install(char *s,int t, double d) {
   symlist   = creaNodoL(creaSymbol(s, t, d), symlist);
   return symlist; 
}
