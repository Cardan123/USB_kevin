%{
  #include "hoc.h"
  #include <math.h>
  #include <string.h>
  #define MSDOS

  int yylex();
  void yyerror(char * s);
  void warning(char * s, char * t);
  void execerror(char * s, char * t);
  void fpecatch();
%}

%union{
  double num;
  Vector * val;
  Symbol * sym;
}

/* Declaración de YACC*/
%token <num> NUMBER
%token <sym> VAR INDEF
%type <val> vector
%type <val> expr asgn
%type <num> number

%right '='
%left '+' '-'
%left '*'
%left UNARYMINUS
%left ':' '#'
%right '^'

/*Seccion de Reglas Gramaticales y Acciones*/
%%
  list:
    | list '\n'
    | list asgn '\n'
    | list expr '\n' { imprimeVector($2); }
    | list number '\n' { printf("\t%.8g\n", $2); }
    | list error '\n' { yyerror; }
    ;

  asgn: VAR '=' expr { $$ = $1->u.val = $3;
                       $1->type = VAR; }
    ;

  expr: vector { $$ = $1; }
    | VAR { if( $1->type == INDEF )
              execerror("Variable no definida", $1->name);
            $$ = $1->u.val;
          }
    | asgn
    | expr '+' expr { $$ = sumaVector ( $1, $3 ); }
    | expr '-' expr { $$ = restaVector( $1, $3 ); }
    | NUMBER '*' expr { $$ = escalarVector( $1, $3 ); }
    | expr '*' NUMBER { $$ = escalarVector( $3, $1 ); }
    | expr '#' expr { $$ = productoCruz( $1, $3 ); }
    ;

  number: NUMBER
    | expr ':' expr { $$ = productoPunto( $1, $3 ); }
    | '|' expr '|' { $$ = magnitudVector( $2 ); }
    ;

  vector: '[' NUMBER NUMBER NUMBER ']' { $$ = creaVector(3);
                                         $$->vec[0] = $2;
                                         $$->vec[1] = $3;
                                         $$->vec[2] = $4;
                                       }
    ;
%%

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;
char * progname;
int lineno = 1;

void main(int argc, char * argv[]) {
    progname = argv[0];
    setjmp(begin);
    signal(SIGFPE, fpecatch);
    yyparse();
}

void execerror(char * s, char * t){
    warning(s, t);
    longjmp(begin, 0);
}

void fpecatch(){
    execerror("Excepcion de punto flotante", (char *)0);
}

int yylex(){
    int c;
    while ((c = getchar()) == ' ' || c == '\t')
        ;
    if (c == EOF)
      return 0;

    if (c == '.' || isdigit(c) ) {
        ungetc(c, stdin);
        scanf("%lf\n", &yylval.num);
        return NUMBER;
    }

    if (isalpha(c)) {
        Symbol * s;
        char sbuf[200];
        char * p = sbuf;
        do {
            *p++=c;
        } while((c = getchar()) != EOF && isalnum(c));

        ungetc(c, stdin);
        *p = '\0';
        if ((s = lookup(sbuf)) == (Symbol *)NULL)
            s = install(sbuf, INDEF, NULL);
        yylval.sym = s;

        if (s->type == INDEF)
            return VAR;
        else{
            //printf("func=(%s) tipo=(%d) \n", s->name, s->type);
            return s->type;
        }
    }
    return c;
}

void yyerror(char * s){
  warning(s, (char *)0);
}

void warning(char * s, char * t) {
    fprintf(stderr, "%s: %s",progname,s);
    if (t)
        fprintf(stderr, "%s",t);
    fprintf(stderr, "Cerca de la linea %d\n",lineno);
}
