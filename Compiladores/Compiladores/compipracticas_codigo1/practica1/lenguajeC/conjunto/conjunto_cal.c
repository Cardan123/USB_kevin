#include "conjunto_cal.h"
/*int yylex (){
  	int c;
  	while ((c = getchar ()) == ' ' || c == '\t')  
  		;
 	if (c == EOF)                            
    		return 0;
  	if (c == '.' || isdigit (c)){
      		ungetc (c, stdin);
      		scanf ("%d", &yylval.ival);
	      	return NUMBER;
    	}
	if(islower(c)){
		yylval.index=c-'a';
		return VAR;
	}
  	return c;                                
}*/
/*void init(){
   int i;
   for(i = 0;i<26;i++)
      mem[i]=creaConjunto(10);
}*/
void main() { 
   //init();
   yyparse(); 
}
int yyerror(const char* s) { 
  printf("%s\n", s); 
  return 0; 
}
Conjunto *creaConjunto(int tama){
   Conjunto *conj;
   conj=(Conjunto *)malloc(sizeof(Conjunto));
   conj->tama = tama;	
   conj->cardinal = 0;
   conj->eltos = (tTipo *)malloc(sizeof(tTipo)*tama);
   return conj;
}
void conjuPot(char **v, int n, Nodo *arri){
	Nodo mi;
	if (!n) {
		putchar('[');
		while (arri) {
			printf(" %s", arri->s);
			arri = arri->prev;
		}
		puts(" ]");
	} else {      
		mi.s = *v;               
		mi.prev = arri;
		conjuPot(v + 1, n - 1, arri);
		conjuPot(v + 1, n - 1, &mi);
	}
}
Conjunto *copiaConjunto(Conjunto *conj){
   int i;
   Conjunto *copy=creaConjunto(conj->cardinal);
   for(i = 0; i< conj->cardinal; i++)
      copy->eltos[i]=conj->eltos[i];
   copy->cardinal=conj->cardinal;	
   return copy;	
}
void imprimeConjunto(Conjunto *conj){
   int i; 
   for(i=0; i< conj->cardinal ; i++)
      printf("%d ", conj->eltos[i]);
   printf("\n");
}
int pertenece(Conjunto *A, tTipo x){
  int i;
  for (i = 0; i < A->cardinal; i++)
    if (A->eltos[i] == x) return 1;
  return 0;
}
Conjunto *insertar(Conjunto *A, tTipo x){
  if (!pertenece(A, x))
    A->eltos[A->cardinal++] = x;
  printf("card= (%d) \n", A->cardinal);
  return A;
}
Conjunto *borrar(Conjunto *A, tTipo x){
  int i;
  for (i = 0; i < A->cardinal; i++)
    if (A->eltos[i] == x) {
      A->eltos[i] = A->eltos[--A->cardinal]; return;
    }
  return A;
}
Conjunto *unirConjunto(Conjunto *A, Conjunto *B){
  Conjunto *nvo;
  int i;
  nvo=creaConjunto(A->cardinal+B->cardinal);
  for (i = 0; i < A->cardinal; i++)
     nvo->eltos[i]= A->eltos[i];
  nvo->cardinal=A->cardinal;
  for (i = 0; i < B->cardinal; i++)
    if (!pertenece(A, B->eltos[i]))
      insertar(nvo, B->eltos[i]);
  return nvo;
}
Conjunto *intersecConjunto(Conjunto *A, Conjunto *B){
  Conjunto *nvo;
  int i;
  nvo=creaConjunto(A->cardinal);
  nvo->cardinal = 0;
  for (i = 0; i < A->cardinal; i++)
    if (pertenece(B, A->eltos[i]))
      insertar(nvo, A->eltos[i]);
  return nvo;
}
Conjunto *diferenConjunto(Conjunto *A, Conjunto *B){
   Conjunto *nvo;
   int i;
   nvo=creaConjunto(A->cardinal);
   nvo->cardinal = 0;
   for (i = 0; i < A->cardinal; i++)
      if (!pertenece(B, A->eltos[i]))
         insertar(nvo, A->eltos[i]);
   return nvo;
}
Conjunto *difsimConjunto(Conjunto *A, Conjunto *B){
  Conjunto *nvo;
  int i;
  nvo=creaConjunto(A->cardinal+B->cardinal);  
  nvo->cardinal = 0;
  for (i = 0; i < A->cardinal; i++)
    if (!pertenece(B, A->eltos[i]))
      insertar(nvo, A->eltos[i]);
  for (i = 0; i < B->cardinal; i++)
    if (!pertenece(A, B->eltos[i]))
      insertar(nvo, B->eltos[i]); 
  return nvo; 
}
int subconjunto(Conjunto *A, Conjunto *B) {
   int i, esta;
   esta = 1;
   for (i = 0; i < A->cardinal; i++)
      if (!pertenece(B, A->eltos[i])) return 0;
   return 1;
}
int iguales(Conjunto *A, Conjunto *B){
  return (subconjunto(A,B) && A->cardinal == B->cardinal);
}
