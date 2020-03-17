
#include <stdio.h>
#include <stdlib.h>
#include "regexp.h"


Conjunto *creaConjunto(int tama){
   Conjunto *conj;
   conj=(Conjunto *)malloc(sizeof(Conjunto));
   conj->tama = tama;	
   conj->cardinal = 0;
   conj->eltos = (tTipo *)malloc(sizeof(tTipo)*tama);
   return conj;
}
Conjunto *copiaConjunto(Conjunto *conj, void *(*cp)(void *)){
   int i;
   Conjunto *copy=creaConjunto(conj->cardinal);
   for(i = 0; i< conj->cardinal; i++)
      copy->eltos[i]=cp(conj->eltos[i]);
   copy->cardinal=conj->cardinal;
   copy->id=conj->id;	
   return copy;	
}
void imprimeConjunto(Conjunto *conj, void (*f)(void *)){
   int i; 
   for(i=0; i< conj->cardinal ; i++)
      f(conj->eltos[i]);
      //printf("%d ", conj->eltos[i]);
   printf("\n");
}
int pertenece(Conjunto *A, tTipo key, int (*cmp)(void *, void *)){
  int i;
  //puts("1pertenece =  ");
  //imprimeNodoI(key);
    for (i = 0; i < A->cardinal; i++){
         //puts("for =  "); imprimeNodoI(A->eltos[i]);
       if(!cmp(A->eltos[i], key)) return 1;
       //if (A->eltos[i] == x) return 1;
    }
  //puts("2pertenece =  0000");
  return 0;
}
Conjunto *insertar(Conjunto *A, tTipo x, 
                   int (*cmp)(void *, void *),  void *(*cp)(void *)){
  //puts("insertar =  "); imprimeNodoI(x);
  if (!pertenece(A, x, cmp))
    A->eltos[A->cardinal++] = cp(x);
  //printf("card= (%d, %d) \n", A->cardinal, x);
  return A;
}
int contains(Conjunto *conte, Conjunto *ele, int *enc, int (*cmp)(void *, void *)){
   int i;
   for(i=0; i < conte->cardinal;i++){
       if(iguales((Conjunto *)conte->eltos[i], ele, cmp) ){ 
          //printf("CCCCcontains id1=%d id2=%d ", 
          //       ((Conjunto *)conte->eltos[i])->id, ele->id);
          *enc=i;
          return 1; 
       }
   }
   return 0;
}
Conjunto *insertarSet(Conjunto *A, Conjunto * x, 
                   int (*cmp)(void *, void *), void *(*cp)(void *)){
  int enc;
  //puts("insertar =  "); imprimeNodoI(x);
  
  if (!contains(A, x, &enc, cmp))
    //A->eltos[A->cardinal++] = copiaConjunto(x, cp) ;
    A->eltos[A->cardinal++] = x ;
  //printf("card= (%d, %d) \n", A->cardinal, x);
  return A;
}
Conjunto *borrar(Conjunto *A, tTipo key, int (*cmp)(void *, void *)){
  int i;
  for (i = 0; i < A->cardinal; i++)
    if (!cmp(A->eltos[i], key)) {
      A->eltos[i] = A->eltos[--A->cardinal];
      return A;
    }
  return A;
}
Conjunto *unirConjunto(Conjunto *A, Conjunto *B, 
          int (*cmp)(void *, void *), void *(*cp)(void *)){
  Conjunto *nvo;
  int i;
  //puts("ENTRA UUUunirConjunto = ");
  nvo=creaConjunto(A->cardinal+B->cardinal);
  for (i = 0; i < A->cardinal; i++)
     nvo->eltos[i]= cp(A->eltos[i]);
  nvo->cardinal=A->cardinal;
  for (i = 0; i < B->cardinal; i++)
    if (!pertenece(A, B->eltos[i], cmp))
      insertar(nvo, B->eltos[i], cmp, cp);
  //puts("SAL UUUunirConjunto = ");
  return nvo;
}
Conjunto *intersecConjunto(Conjunto *A, Conjunto *B, 
          int (*cmp)(void *, void *), void *(*cp)(void *)){
  Conjunto *nvo;
  int i;
  nvo=creaConjunto(A->cardinal);
  nvo->cardinal = 0;
  for (i = 0; i < A->cardinal; i++)
    if (pertenece(B, A->eltos[i], cmp))
      insertar(nvo, A->eltos[i], cmp, cp);
  return nvo;
}
Conjunto *diferenConjunto(Conjunto *A, Conjunto *B, 
          int (*cmp)(void *, void *), void *(*cp)(void *)){
   Conjunto *nvo;
   int i;
   nvo=creaConjunto(A->cardinal);
   nvo->cardinal = 0;
   for (i = 0; i < A->cardinal; i++)
      if (!pertenece(B, A->eltos[i], cmp))
         insertar(nvo, A->eltos[i], cmp, cp);
   return nvo;
}
Conjunto *difsimConjunto(Conjunto *A, Conjunto *B, 
          int (*cmp)(void *, void *), void *(*cp)(void *)){
  Conjunto *nvo;
  int i;
  nvo=creaConjunto(A->cardinal+B->cardinal);  
  nvo->cardinal = 0;
  for (i = 0; i < A->cardinal; i++)
    if (!pertenece(B, A->eltos[i], cmp))
      insertar(nvo, A->eltos[i], cmp, cp);
  for (i = 0; i < B->cardinal; i++)
    if (!pertenece(A, B->eltos[i], cmp))
      insertar(nvo, B->eltos[i], cmp, cp); 
  return nvo; 
}
int subconjunto(Conjunto *A, Conjunto *B, int (*cmp)(void *, void *)) {
   int i, esta;
   esta = 1;
   for (i = 0; i < A->cardinal; i++)
      if (!pertenece(B, A->eltos[i], cmp)) return 0;
   return 1;
}
int iguales(Conjunto *A, Conjunto *B, int (*cmp)(void *, void *)){
  return (subconjunto(A, B, cmp) && A->cardinal == B->cardinal);
}
 
