%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regexp.h"

int yylex(void);
int yyerror(const char*);
struct elemento {
   NodoArb  *nodo;   
   char car;
};
typedef struct elemento Elemento;
#define YYSTYPE struct elemento
char meta[]={'|','*','(',')','[',']','$','.','-','^',':', 0};
%}
%token CHAR
//%token ANYNONMETACHAR METACHAR
%left '*'
%left ':'
%left '|'
%%
input: /* vacio */ 
   | input line
   ;
line: '\n'
   | re '\n' { imprimeArb($1.nodo, imprimeCade); puts(" ");}
   ;
re: re ':' re { 
          $$.nodo = creaNodoArb(strdup(":"), $1.nodo, $3.nodo); 
   }
   | re '|' re {
          $$.nodo = creaNodoArb(strdup("|"), $1.nodo, $3.nodo); 
   }
   | re '*' {
          $$.nodo = creaNodoArb(strdup("*"), $1.nodo, NULL); 
   }
   | '(' re ')' { $$ = $2; }
   | CHAR {
    char cade[2]={0,0};
    cade[0]=$1.car;
    $$.nodo = creaNodoArb(strdup(cade), (NodoArb *)NULL,(NodoArb *)NULL); 
   }
   ;
%%
void main() {  yyparse();  }
int yyerror(const char* s) { 
   printf("%s\n", s); 
   return 0; 
}
int busca(char c){
   int i;
   for (i = 0; meta[i] ; i++)
      if (meta[i] == c) return 1;
   return 0;
}
int yylex (){
   int c;
   while ((c = getchar ()) == ' ' || c == '\t')  
  		;
   if (c == EOF) return 0;
   if(c != '\n' &&  busca(c)==0 ){
      yylval.car=c;
      return CHAR;
   }
   return c;                                
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
void imprimeCade(void *s){
   printf(" %s ",(char *)s);
}



