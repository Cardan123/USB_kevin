%{
#include <stdio.h>
//#include <stdlib.h>
#include "big_calc.h"
int tempo[1000];
int yylex(void);
int yyerror(const char*);
//#define YYSTYPE BigAP
%}
%union {  
BigAP val;    
int ival;
}
%token  <ival> NUMBER
%type <val> expr vector
%type <ival> list
%right '='
%left '+' '-'
%left '*' '/'
%nonassoc '(' ')'
%%
input: /* vacio */ 
   | input line
   ;
line: '\n'
   | expr '\n' { imprimeBig($1); }
   ;
expr: vector
   | expr '+' expr { $$ = sumaBig($1, $3);}
   | expr '*' expr { $$ = multiBig($1, $3);}
   | '(' expr ')' {$$ = $2;}   
   ;
vector: '[' list ']' { int i;
      $$=creaBig($2);
      //printf("[%d >", $2);
      for(i=0; i < $2 ; i++)
         $$->cifras[i] = tempo[$2-i-1];
      //imprimeBig($$);
   }
   ;
list: NUMBER { $$ = 1; tempo[0]=$1; }
   | list NUMBER { $$ = $1+1; tempo[$1]=$2; }
   ;    
%%
int yylex (){
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
   return c;                                
}
void main() { 
   yyparse(); 
}
int yyerror(const char* s) { 
  printf("%s\n", s); 
  return 0; 
}
