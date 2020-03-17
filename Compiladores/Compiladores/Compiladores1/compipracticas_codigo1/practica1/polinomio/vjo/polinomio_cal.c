#include <stdio.h>
#include <stdlib.h>
#include "polinomio_cal.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
NodoL *creaNodoL(void *dato, NodoL *sig){
	NodoL *nvo;
	nvo=(NodoL*)malloc(sizeof(NodoL));
	nvo->dato=dato;
	nvo->sig=sig;
	return nvo;
}
Termino *creaTermino(int coefi,int expo){
   Termino *nvo;
   nvo=(Termino*)malloc(sizeof(Termino));
   nvo->coefi = coefi;	
   nvo->expo = expo;
   return nvo;
}
void imprimeTermino(void * dato){
   Termino *t=(Termino *)dato;
   printf("%d x^%d + ",t->coefi, t->expo);
}
int cmpTermino(void *t1, void *t2){
   Termino *tp1 = (Termino* )t1;
   Termino *tp2 = (Termino* )t2;
   return tp1->expo - tp2->expo;
}
Polinomio *creaPolinomio(int grado, NodoL *cab){
   Polinomio *nvo=(Polinomio *)malloc(sizeof(Polinomio));
   if(!nvo){
      puts("no hay memoria para crear Polinomio ");
      return (Polinomio *)NULL;
   }  
   nvo->cab = cab;	
   nvo->grado = grado;
   return nvo;
}
NodoL *insertaOrdA(void *dato, NodoL **cab, int (*cmp)(void *, void *)){
	NodoL *p, *q;
        if(!*cab){
                //puts("1er nodo");
		*cab=creaNodoL(dato,(NodoL *)NULL);
		return *cab;
	}
        if(cmp((*cab)->dato, dato) >= 0){
		*cab=creaNodoL(dato,*cab);
		return *cab;
	}
        //puts("antes for");
        for(p=*cab,q=p->sig; q && cmp(q->dato, dato) < 0 ;p=q, q=q->sig)
        	;
	q=creaNodoL(dato,q);
        p->sig=q;
		
}
void imprimeL(NodoL *inicio, void (*f)(void *)){
   NodoL *p;
   if(!inicio){
      puts("imprime:lista vacia");
      return ;
   }
   for(p=inicio;p;p=p->sig)
      (*f)(p->dato);
}
int igualNodoL(NodoL  *cab1, NodoL  *cab2, 
	int (*cmp)(void *, void *)){
	for (; cab1 && cab2; cab1=cab1->sig,cab2=cab2->sig){
     	        if (cmp(cab1->dato, cab2->dato)){	
			return 0;
     		}
	}
	if (!cab1 && !cab2)
		return 1;
     	return 0;
}
/*void asignaPolinomio(Polinomio *r, int num, int den){
}*/
Polinomio* sumaPolinomio(Polinomio *p, Polinomio *q){
   NodoL *suma=NULL; 
   NodoL *aux;  
   NodoL *aux2; 
   Termino *tp1;
   Termino *tp2;
   for(aux=p->cab; aux; aux=aux->sig) { 
      tp1=(Termino *)aux->dato;
      for(aux2=q->cab;aux2;aux2=aux2->sig) { 
         tp2=(Termino *)aux2->dato;
         if((tp1->expo == tp2->expo) ) {   
            insertaOrdA(
            (void*)creaTermino(tp1->coefi+tp2->coefi,tp1->expo), 
                  &suma, cmpTermino);  
            tp1->band=1; 
            tp2->band=1; 
         }    
      } 
      if(tp1->band==0) 
         insertaOrdA((void*)creaTermino(tp1->coefi,tp1->expo), 
                      &suma, cmpTermino);   
    }      
    for(aux2=q->cab;aux2;aux2=aux2->sig){
        tp2=(Termino *)aux2->dato; 
        if(tp2->band==0) 
           insertaOrdA((void*)creaTermino(tp2->coefi,tp2->expo), 
                      &suma, cmpTermino);
    } 
    return creaPolinomio(max(p->grado,q->grado), suma);
}
Polinomio* restaPolinomio(Polinomio *p, Polinomio *q){
   NodoL *resta=NULL; 
   NodoL *aux;  
   NodoL *aux2; 
   Termino *tp1;
   Termino *tp2;
   for(aux=p->cab; aux; aux=aux->sig) { 
      tp1=(Termino *)aux->dato;
      for(aux2=q->cab;aux2;aux2=aux2->sig) { 
         tp2=(Termino *)aux2->dato;
         if((tp1->expo == tp2->expo) ) {   
            insertaOrdA(
            (void*)creaTermino(tp1->coefi-tp2->coefi,tp1->expo), 
                  &resta, cmpTermino);  
            tp1->band=1; 
            tp2->band=1; 
         }    
      } 
      if(tp1->band==0) 
         insertaOrdA((void*)creaTermino(tp1->coefi,tp1->expo), 
                      &resta, cmpTermino);   
   }      
   for(aux2=q->cab;aux2;aux2=aux2->sig){
        tp2=(Termino *)aux2->dato; 
        if(tp2->band==0) 
           insertaOrdA((void*)creaTermino(tp2->coefi,tp2->expo), 
                      &resta, cmpTermino);
   } 
   return creaPolinomio(max(p->grado,q->grado), resta); 
}

Polinomio* multiplicaPolinomio(Polinomio *p, Polinomio *q){
   NodoL *producto=NULL; 
   NodoL *aux;  
   NodoL *aux2; 
   Termino *tp1;
   Termino *tp2;
   for(aux=p->cab; aux; aux=aux->sig) { 
      tp1=(Termino *)aux->dato;
      for(aux2=q->cab;aux2;aux2=aux2->sig) { 
         tp2=(Termino *)aux2->dato;
         insertaOrdA((void*)creaTermino(tp1->coefi*tp2->coefi,
               tp1->expo+tp2->expo), &producto, cmpTermino);    
      }
   }
   return creaPolinomio(p->grado+q->grado, producto);
}
/*
Polinomio* dividePolinomio(Polinomio *r, Polinomio *s){
	return ;
}*/
int esIgualPolinomio(Polinomio *p, Polinomio *q){
   return igualNodoL(p->cab, p->cab, cmpTermino);
}
void imprimePolinomio(Polinomio *p){
   imprimeL(p->cab, imprimeTermino);
}
Polinomio *copiaPolinomio(Polinomio *p){
   NodoL *copia=NULL; 
   NodoL *aux;  
   Termino *tp;
   for(aux = p->cab; aux ; aux=aux->sig) { 
      tp=(Termino *)aux->dato;
      insertaOrdA((void*)creaTermino(tp->coefi,tp->expo), 
                  &copia, cmpTermino); 
   }
   return creaPolinomio(p->grado, copia);
}
