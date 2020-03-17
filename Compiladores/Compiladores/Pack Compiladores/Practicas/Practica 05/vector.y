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
  int eval;
}

/* Declaración de YACC*/
%token <num> NUMBER
%token <sym> VAR INDEF VECT NUMB PRINT WHILE IF ELSE BLTIN
%type <inst> stmt asgn expr stmtlist cond while if end
%type <sym> vector numero
%type <num> escalar

%right '='
%left OR AND
%left GT GE LT LE EQ NE
%left '+' '-'
%left '*' ':' '#' '|'
%left UNARYMINUS NOT 

/*Seccion de Reglas Gramaticales y Acciones*/
%%
  list:
    | list '\n'
    | list asgn '\n' { code2(pop, STOP); return 1; }
    | list stmt '\n' { code(STOP); return 1; }
    | list expr '\n' { code2(print, STOP); return 1; }
    | list escalar '\n' { code2(printd, STOP) return 1; }
    | list error '\n' { yyerror; }
    ;

  asgn: VAR '=' expr { $$ = $3; code3(varpush, (Inst)$1, assign); }
    ;
  
  stmt: expr { code(pop); }
    | PRINT expr    { code(print); $$ = $2; }
    | while cond stmt end {
            ($1)[1] = (Inst)$3; /* Cuerpo de la iteracion */ 
            ($1)[2] = (Inst)$4; /*Termina si la condicion no se cumple */
            }
    | if cond stmt end {    /* Proposicion if*/
            ($1)[1] = (Inst)$3;    /* Parte then */
            ($1)[2] = (Inst)$4;    /* Termina si la condicion no se cumple */
            }
    | if cond stmt end ELSE stmt end {  /* Proposicion if-else */
            ($1)[1] = (Inst)$3; /* Parte then */
            ($1)[2] = (Inst)$6  /* Parte else */
            ($1)[3] = (Inst)$7; /* Termina si las condiciones no se cumplen*/            
            }
    | '{' stmtlist '}'  { $$ = $2; }
    ;

  cond: '(' expr ')' { code(STOP); $$ = $2; }
    ;

  while: WHILE    { $$ = code3(whilecode, STOP, STOP); }
    ;

  if: IF  { $$ = code(ifcode); 
              code3(STOP, STOP, STOP);
            }
    ;

  end: /* Nada */ { code(STOP); $$ = progp; }
    ;

  stmtlist: /* Nada */	{ $$ = progp; }
    | stmtlist '\n'
	| stmtlist stmt
	;

  expr: vector { code2(constpush, (Inst)$1); }
    | VAR { code3(varpush, (Inst)$1, eval); }
    | asgn
    | BLTIN '(' expr ')' { $$ = $3; code2(bltin, (Inst)$1->u.ptr); }
    | expr '+' expr { code(add); }
    | expr '-' expr { code(sub); }
    | escalar '*' expr { code(escalar); }
    | expr '*' escalar { code(escalar); }
    | expr '#' expr { code(producto_cruz); }
    | expr GT expr { code(gt); }
    | expr LT expr { code(lt); }
    | expr GE expr { code(ge); }
    | expr LE expr { code(le); }
    | expr EQ expr { code(eq); }
    | expr NE expr { code(ne); }
    | expr OR expr { code(or); }
    | expr AND expr { code(and); }
    | NOT expr { $$ = $2; code(not); }
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
    init();
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

    switch(c){
        case '>':   return follow('=', GE, GT);
	    case '<':   return follow('=', LE, LT);
        case '=':   return follow('=', EQ, '=');
	    case '!':   return follow('=', NE, NOT);
	    case '|':   return follow('|', OR, '|');
	    case '&':   return follow('&', AND, '&');
	    case '\n':  lineno++; return '\n';
	    default:    return c;
    }

    if( c == '\n')  lineno++;

    return c;
}

follow(expect,   ifyes,   ifno){  /*   buscar  operadores.   */
    int c  = getchar();
    if  (c  ==  expect)
        return ifyes;
    ungetc(c,   stdin);
    
    return  ifno;
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
