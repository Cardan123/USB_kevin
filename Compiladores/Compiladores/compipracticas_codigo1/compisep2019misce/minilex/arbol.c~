#include <stdio.h>
#include <stdlib.h>
#include "regexp.h"
int esHoja(NodoArb *r){
   if(!r->izq && !r->der)
       return 1;
   return 0;
}
NodoArb *creaNodoArb(void *dato,NodoArb *izq,NodoArb *der){
   NodoArb *nvo;
   nvo=(NodoArb *)malloc(sizeof(NodoArb));
   if(!nvo){
      puts("no hay memoria para crear NodoArb");
      return (NodoArb *)NULL;
   }
   nvo->izq=izq;
   nvo->der=der;
   nvo->info=dato;
   return nvo;
}
void imprimeArb(NodoArb *raiz, void (*f)(void *)){
   if(!raiz) return;
   imprimeArb(raiz->izq,f);
   (*f)(raiz->info);
   imprimeArb(raiz->der,f);       
}
