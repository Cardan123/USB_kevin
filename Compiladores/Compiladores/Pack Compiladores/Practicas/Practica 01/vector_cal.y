%{
#include <stdio.h>
#include "vector_cal.h"
#include <ctype.h>
#include <stdio.h>
#include <math.h>
//#define YYSTYPE double

int yyerror (char *s);
int yylex ();
 
%}
%union{
    double val;
    Vector *vec;
}

/*Declaración de YACC*/
%token <val> NUMBER
%type <vec> exp
%type <vec> vector
%type <val> number
%left '+' '-'
%left '*'
%left 'x' 'o'


/*Gramatica*/
%%
input: /*Cadena vacia*/
           |input list
           ;

list: '\n'
        | exp '\n'  { imprimeVector($1); }
        | number '\n' {printf("%lf\n", $1);}
        ;

exp:  vector
        | exp '+' exp {$$ = sumaVector($1,$3); }
        | exp '-' exp  {$$ = restaVector($1,$3); }
        |NUMBER '*' exp  {$$ = escalarVector($1, $3);}
        | exp '*' NUMBER {$$ = escalarVector($3,$1);  }
        | exp 'x' exp {$$ = productoCruz($1, $3); }
        ;

number: NUMBER
        | vector 'o' vector {$$ = productoPunto($1,$3);}
        | '|' vector '|' {$$ = magnitudVector($2); }
        ;

vector : '[' NUMBER NUMBER NUMBER ']' {Vector *v = creaVector(3);
                                                                                     v->vec[0] = $2;
                                                                                     v->vec[1] = $3;
                                                                                     v->vec[2] = $4;
                                                                                     $$ = v;
                                                                                    }
%%

int yylex (){
  	int c;
  	while ((c = getchar ()) == ' ' || c == '\t')
  		;
 	if (c == EOF)
    		return 0;
  	if (c == '.' || isdigit (c)){
      		ungetc (c, stdin);
      		scanf ("%lf", &yylval.val);
	      	return NUMBER;
    	}
  	return c;
}

void main() {
   yyparse();
}
int yyerror(char *s) {
  printf("%s\n", s);
  return 0;
}
