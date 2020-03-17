%{
  #include "hoc.h"
  #include <math.h>
  #include <string.h>
  #define MSDOS

  /* Macros con parametros */
  #define code2(c1, c2)     code(c1); code(c2);
  #define code3(c1, c2, c3) code(c1); code(c2); code(c3);

  int yylex();
  void yyerror(char * s);
  void warning(char * s, char * t);
  void execerror(char * s, char * t);
  void fpecatch();
  extern void init();
  
%}

%union{
  double num;
  Vector * val;
  Inst * inst;      /* Instrucciones a ejecutar por la RAM*/
  Symbol * sym;
}

/* Declaración de YACC*/
%token <num> NUMBER
%token <sym> VAR INDEF VECT NUMB
%type <sym> vector numero
%type <val> expr asgn
%type <num> escalar

%right '='
%left '+' '-'
%left '*' ':' '#' '|'

/*Seccion de Reglas Gramaticales y Acciones*/
%%
  list:
    | list '\n'
    | list asgn '\n' { code2(pop, STOP); return 1; }
    | list expr '\n' { code2(print, STOP); return 1; }
    | list escalar '\n' { code2(printd, STOP) return 1; }
    | list error '\n' { yyerror; }
    ;

  asgn: VAR '=' expr { code3(varpush, (Inst)$1, assign); }
    ;

  expr: vector { code2(constpush, (Inst)$1); }
    | VAR { code3(varpush, (Inst)$1, eval); }
    | asgn
    | expr '+' expr { code(add); }
    | expr '-' expr { code(sub); }
    | escalar '*' expr { code(escalar); }
    | expr '*' escalar { code(escalar); }
    | expr '#' expr { code(producto_cruz); }
    ;

  escalar: numero   { code2(constpushd, (Inst)$1); }
    | expr ':' expr { code(producto_punto); }
    | '|' expr '|'  { code(magnitud); }
    ;

  vector: '[' NUMBER NUMBER NUMBER ']' { Vector * vector1 = creaVector(3);
                                         vector1->vec[0] = $2;
                                         vector1->vec[1] = $3;
                                         vector1->vec[2] = $4;
                                         $$ = install("", VECT , vector1);
                                       }
    ;
    
  numero: NUMBER { $$ = installd("", NUMB, $1); }

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
    for(initcode(); yyparse (); initcode())
		execute(prog);
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
        double d;
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

    if( c == '\n')  lineno++;

    return c;
}

void yyerror(char * s){     /* Llamada por yyparse ante un error */
  warning(s, (char *)0);
}

void warning(char * s, char * t) {
    fprintf(stderr, "%s: %s",progname,s);
    if (t)
        fprintf(stderr, "%s",t);
    fprintf(stderr, "Cerca de la linea %d\n",lineno);
}
