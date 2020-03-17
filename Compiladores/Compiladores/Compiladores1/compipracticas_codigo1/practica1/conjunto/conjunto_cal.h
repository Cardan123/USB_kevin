#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 1000
typedef int tTipo;
struct conjunto {
  tTipo *eltos;
  int cardinal;
  int tama;
};
typedef struct conjunto Conjunto;
Conjunto *creaConjunto(int tama);
Conjunto *copiaConjunto(Conjunto *conj);
int pertenece(Conjunto *A, tTipo x);
Conjunto *insertar(Conjunto *A, tTipo x);
Conjunto *borrar(Conjunto *A, tTipo x);
Conjunto *unirConjunto(Conjunto *A, Conjunto *B);
Conjunto *intersecConjunto(Conjunto *A, Conjunto *B);
Conjunto *diferenConjunto(Conjunto *A, Conjunto *B);
Conjunto *difsimConjunto(Conjunto *A, Conjunto *B);
int subconjunto(Conjunto *A, Conjunto *B);
int iguales(Conjunto *A, Conjunto *B);
 
