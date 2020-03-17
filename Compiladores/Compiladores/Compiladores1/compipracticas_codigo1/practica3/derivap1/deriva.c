#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>
#include "deriva.h"

void yyerror(char *s); 
void warning(char *s, char *t); 
int yylex(void);

char *progname; 
int lineno = 1; 
void imprimeCadena(void *p){
   //puts((char*)p);
   printf("%s ", (char*)p);
}
int yylex() { 
   int c; 
   double num;
   while((c=getchar()) == ' ' || c == '\t') 
      ; 
   if(c == EOF) 
     return 0; 
   if (c == '.' || isdigit (c)){
      char sbuf[100];
      ungetc(c, stdin); 
      scanf ("%lf", &num);
      sprintf(sbuf,"%lf", num);
      yylval.expr=creaNodoArb(
      strdup(sbuf),NUMBER,(NodoArb *)NULL,(NodoArb*)NULL);
      yylval.der=creaNodoArb(
      strdup("0"), NUMBER,(NodoArb *)NULL,(NodoArb *)NULL);
      return NUMBER;
    }
   if (c=='x'){
      return VAR;
   }
   if(c == '\n') 
      lineno++; 
   return c; 
  } 
void yyerror(char *s) { 
   warning(s, (char *)0); 
} 
void warning(char *s, char *t) { 
   fprintf(stderr, "%s: %s", progname, s); 
    if(t) 
       fprintf(stderr, " %s",t); 
    fprintf(stderr, " near line %d\n", lineno); 
} 
void main(int argc, char *argv[]) { 
    progname = argv[0]; 
    yyparse(); 
}
NodoArb *creaNodoArb(void *dato, short tipo, 
                     NodoArb *izq,NodoArb *der){
	NodoArb *nvo;
	nvo=(NodoArb *)malloc(sizeof(NodoArb));
        if(!nvo){
	    puts("no hay memoria para crear NodoL");
            return (NodoArb *)NULL;
        }
        nvo->izq=izq;
        nvo->der=der;
        nvo->info=dato;
        nvo->tipo=tipo;
        return nvo;
}
NodoArb *clonaNodoArb(NodoArb *r){
   return creaNodoArb(r->info, r->tipo, r->izq, r->der);
}
void imprimeArb(NodoArb *raiz, void (*f)(void *)){
   if(!raiz)
      return;
   imprimeArb(raiz->izq,f);
   (*f)(raiz->info);
   imprimeArb(raiz->der,f);       
}
NodoArb *Evalua(NodoArb *r, int dir){
NodoArb *evai, *evad;

   if (r->tipo == NUMBER) return r;
   if (r->tipo == VAR) return r;
   if (r->tipo == OPER){
      switch ((*(char*)(r->info))){
      case '+':   
         evai=Evalua (r->izq, 0);
         evad=Evalua (r->der, 1);
         if((*(char*)(evai->info))=='x' &&
            (*(char*)(evad->info))=='x'){
	     NodoArb *op1, *op2, *oper;
             op1=creaNodoArb(
              strdup("2"), OPER, (NodoArb *)NULL,(NodoArb*)NULL);    
             op2=creaNodoArb(
   strdup("x"), OPER, (NodoArb *)NULL,(NodoArb*)NULL);              
             oper=creaNodoArb(
                    strdup("*"), OPER, op1, op2);
             if(dir==0){
                if(r->padre)
                   r->padre->izq=oper;          
             }
	     else {
                if(r->padre)
                   r->padre->der=oper;
             }
             return oper;
         }
         if((*(char*)(evai->info))=='0'){
             if(dir==0){
                if(r->padre)
                   r->padre->izq=evad;          
             }
	     else {
                if(r->padre)
                   r->padre->der=evad;
             }
             return evad;
         }
         if((*(char*)(evad->info))=='0'){
             //puts("en if");
             if(dir==0){
		if(r->padre)
                   r->padre->izq=evai;
             }
	     else {
                if(r->padre)
                   r->padre->der=evai;
             }
             return evai;
         } 
         //puts("ultimo ret +");
         return r;  
      case '-':
         return r ;
      case '*':
         evai=Evalua (r->izq, 0);
         evad=Evalua (r->der, 1);
          if((*(char*)(evai->info))=='x' &&
            (*(char*)(evad->info))=='x'){
	     NodoArb *op1, *op2, *oper;
             op1=creaNodoArb(
              strdup("x"), OPER, (NodoArb *)NULL,(NodoArb*)NULL);    
             op2=creaNodoArb(
   strdup("2"), OPER, (NodoArb *)NULL,(NodoArb*)NULL);              
             oper=creaNodoArb(
                    strdup("^"), OPER, op1, op2);
             if(dir==0){
                if(r->padre)
                   r->padre->izq=oper;          
             }
	     else {
                if(r->padre)
                   r->padre->der=oper;
             }
             return oper;
         } 
         if((*(char*)(evai->info))=='1'){
             if(dir==0){
                if(r->padre)
                   r->padre->izq=evad;          
             }
	     else {
                if(r->padre)
                   r->padre->der=evad;
             }
             return evad;
         }
         if((*(char*)(evad->info))=='1'){
             //puts("en if");
             if(dir==0){
		if(r->padre)
                   r->padre->izq=evai;
             }
	     else {
                if(r->padre)
                   r->padre->der=evai;
             }
             return evai;
         } 
         if((*(char*)(evai->info))=='0'){
             if(dir==0){
                if(r->padre)
                   r->padre->izq=evai;          
             }
	     else {
                if(r->padre)
                   r->padre->der=evai;
             }
             return evai;
         }
         if((*(char*)(evad->info))=='0'){
             puts("en if");
             if(dir==0){
		if(r->padre)
                   r->padre->izq=evad;
             }
	     else {
                if(r->padre)
                   r->padre->der=evad;
             }
             return evad;
         } 
         //puts("ultimo ret *");
         return r;  
/*
   case '/':
    return (Evalua (r->izq) / Evalua (r->der,1)) ;*/
  }
 }
 
}
