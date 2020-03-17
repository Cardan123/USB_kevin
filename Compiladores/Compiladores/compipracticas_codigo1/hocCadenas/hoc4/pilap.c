/*apuntador a funcion, apuntador doble ejemplo arreglo cadenas*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "hoc.h"
Pila *creaPila(int tama){
	Pila *nvo;
	nvo=(Pila *)malloc(sizeof(Pila));
	nvo->tope=0;
        nvo->tama=tama;
	nvo->elementos=(void **)malloc(sizeof(void *)*tama);
	return nvo;
}
// 0,1,2,3,4
int estaVacia(Pila *p){
	return p->tope == 0;
}
int estaLlena(Pila *p){
        //fp++   >=  &frame[NFRAME-1]
	return p->tope >= p->tama;
}
void *top(Pila *p){
	if(!estaVacia(p))
		return p->elementos[p->tope-1];
	return (void *)NULL;
}
void **topDir(Pila *p){
   if(!estaVacia(p)){
      //printf("topDir  (%.8g)\n", 
      //*((double *)((Datum *)p->elementos[p->tope-1])->val));
      return (p->elementos+(p->tope-1));
   }
   return (void **)NULL;
}
void **topDirNArg(Pila *p, int n){
   if(!estaVacia(p)){
      //printf("topDirNArg  (%.8g)\n", 
      //*((double *)((Datum *)p->elementos[p->tope-n])->val));
      
      return (p->elementos+(p->tope-n));
      //return &(p->elementos[p->tope-n]);
   }
   return (void **)NULL;
}
void *pop(Pila *p){
	if(!estaVacia(p)){
		p->tope=p->tope-1;
		return p->elementos[p->tope];
	}
	return (void *)NULL;
}
void push(Pila *p, void *dato){
	p->elementos[p->tope]=dato; 
	p->tope=p->tope+1;
        //printf("push  (%.8g, %.8g)\n", *((double *)dato), 
        //printf("push  (%.8g)\n",
        //*((double *)((Datum *)p->elementos[p->tope-1])->val));
	
}

