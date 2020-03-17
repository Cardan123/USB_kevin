#include "hoc.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NodoL *creaNodoL(void *dato, NodoL *sig){
   NodoL *nvo;
   //puts("creaNodoL");
   nvo=(NodoL*)malloc(sizeof(NodoL));
   nvo->dato=dato;
   nvo->sig=sig;
   return nvo;
}
NodoL *find(NodoL  *inicio, void *key, int (*cmp)(void *, void *)){
   NodoL *p;
   for(p=inicio;p;p=p->sig)
      if(!(*cmp)(p->dato, key))
         return p;
   return p; //NULL
}
Simbolo *creaSymbol(char *s,int t, void *d){
   Simbolo *sp=(Simbolo *)malloc(sizeof(Simbolo));
   sp->nombre = strdup(s);
   sp->tipo = t;
   sp->u.val = d;
   return sp;
}
int cmpSymbol(void *p1, void *p2){
   Simbolo *s1=(Simbolo* )p1;
   Simbolo *s2=(Simbolo* )p2;
   //puts("s1");puts(s1->name);
   //puts("s2");puts(s2->name);
   return strcmp(s1->nombre, s2->nombre);
}
Simbolo* lookup(NodoL *env, char* s){
   NodoL *p, *enc; 
   //printf("EN lookup: %s ", s);
   for (p = env; p ; p = p->sig) {
      enc=find(p, (void *)creaSymbol(s, 0, NULL), cmpSymbol);
      if(enc) return (Simbolo*)(enc->dato);
   }//while ext
   puts("NULLNULLNULL");
   return NULL;
}
Simbolo *install(NodoL **env, char *s, int t, void *d){
   //printf("install ( %s ) (%d) d=(%.8g)", s, t, *((double *)d) );
   *env  = creaNodoL(creaSymbol(s, t, d), *env);
   return (Simbolo*)((*env)->dato); 
}
char *emalloc(unsigned n){
char *p;
p = malloc(n);
if (p == 0)
execerror("out of memory", (char *) 0);
return p;
}
