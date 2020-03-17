%{ 
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>
#include "arboles.h"

#define YYSTYPE NodoArb *

#include "y.tab.h"
void yyerror(char *s); 
void warning(char *s, char *t); 
int yylex(void);
%} 
%token NUMBER 
%left '+' '-' 
%left '*' '/' 
%% 
list: 
  | list '\n' 
  | list expr '\n' { imprimeArb($2, imprimeCadena);} 
; 
expr: NUMBER { $$=$1; } 
  | expr '+' expr { $$=creaNodoArb(strdup("+"), $1, $3); } 
  | expr '-' expr { $$=creaNodoArb(strdup("-"), $1, $3); }  
  | expr '*' expr { $$=creaNodoArb(strdup("*"), $1, $3); } 
  | expr '/' expr { $$=creaNodoArb(strdup("/"), $1, $3); } 
  | '(' expr ')' { $$ = $2; } 
; 
%% 
char *progname; 
int lineno = 1; 
void imprimeCadena(void *p){
   puts((char*)p);
}
int yylex() { 
   int c; 
   int val;
   while((c=getchar()) == ' ' || c == '\t') 
      ; 
   if(c == EOF) 
     return 0; 
   if(isdigit(c)) { 
      char sbuf[100];
      ungetc(c, stdin); 
      scanf("%d",&val); 
      sprintf(sbuf,"%d", val);
      yylval=creaNodoArb(strdup(sbuf), NULL, NULL);
      return NUMBER; 
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
NodoArb *creaNodoArb(void *dato,NodoArb *izq,NodoArb *der){
	NodoArb *nvo;
	nvo=(NodoArb *)malloc(sizeof(NodoArb));
        if(!nvo){
	    puts("no hay memoria para crear NodoL");
            return (NodoArb *)NULL;
        }
        nvo->izq=izq;
        nvo->der=der;
        nvo->info=dato;
        return nvo;
}
void imprimeArb(NodoArb *raiz, void (*f)(void *)){
   if(!raiz)
      return;
   imprimeArb(raiz->izq,f);
   (*f)(raiz->info);
   imprimeArb(raiz->der,f);       
}
