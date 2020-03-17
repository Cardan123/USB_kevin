%{
#include <stdio.h>
#include <math.h>
#include "hoc.h"
#define YYSTYPE double *

void yyerror (char *s);
int yylex ();
void warning(char *s, char *t);

void *(*add_)(void *dob1, void *dob2)=addDoble;
void *(*sub_)(void *dob1, void *dob2)=subDoble;
void *(*mul_)(void *dob1, void *dob2)=mulDoble;
void *(*div__)(void *dob1, void *dob2)=div_Doble;
void (*print_)(void *dob)=printDoble;
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%% 
list:   
   | list'\n'
   | list exp '\n'  { print_($2); }
   ;
exp: NUMBER          { $$ = $1;  }
   | exp '+' exp     { $$ = add_($1, $3);  }
   | exp '-' exp     { $$ = sub_($1, $3);  }
   | exp '*' exp     { $$ = mul_($1, $3);  }
   | exp '/' exp     { $$ = div__($1,$3);  }
   | '(' exp ')'     { $$ = $2;}
   ;
%%

#include <stdio.h>
#include <ctype.h>
char *progname;
int lineno = 0;

void main (int argc, char *argv[]){
   progname=argv[0];
   yyparse ();
}
void yyerror (char *s) {
   warning(s, (char *) 0);
}
void warning(char *s, char *t){
   fprintf (stderr, "%s: %s", progname, s);
   if(t)
      fprintf (stderr, " %s", t);
   fprintf (stderr, "cerca de la linea %d\n", lineno);
}




