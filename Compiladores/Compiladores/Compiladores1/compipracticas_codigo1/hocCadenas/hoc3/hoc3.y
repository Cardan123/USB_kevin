%{
#include <stdio.h>
#include <math.h>
#include "hoc.h"

NodoL *symlist = (NodoL *)NULL;
NodoL **globals = (NodoL **)NULL;

void yyerror (char *s);
int yylex ();
void warning(char *s, char *t);
void execerror(char *s, char *t);
void fpecatch();

void *(*add_)(void *dob1, void *dob2)=addDoble;
void *(*sub_)(void *dob1, void *dob2)=subDoble;
void *(*mul_)(void *dob1, void *dob2)=mulDoble;
void *(*div__)(void *dob1, void *dob2)=div_Doble;
void *(*power_)(void *dob1, void *dob2)=powerDoble;
void (*print_)(void *dob)=printDoble;
%}
%union {
   void *val;
   Simbolo *sym;
}
%token <val> NUMBER
%token <sym> VAR BLTIN INDEF
%type <val> exp asgn

%right '='
%left '+' '-'
%left '*' '/'
%left UNARYMINUS
%right '^'
%% 
list:   
   | list'\n'
   | list asgn '\n'
   | list exp '\n'  { print_($2); }
   | list error '\n' { yyerrok; } 
   ;
asgn: VAR '=' exp { $$=$1->u.val=$3; $1->tipo=VAR;}
   ;
exp: NUMBER          { $$ = $1; }
   | VAR { if($1->tipo == INDEF)
		execerror("variable no definida",$1->nombre);
		$$=$1->u.val;
	 }
   | asgn
   | BLTIN  '(' exp ')' { $$=($1->u.ptr)($3); }
   | exp '+' exp     { $$ = add_($1, $3); }
   | exp '-' exp     { $$ = sub_($1, $3); }
   | exp '*' exp     { $$ = mul_($1, $3); }
   | exp '/' exp     { $$ = div__($1,$3); }
   | exp '^' exp   { $$=power_($1, $3);}
   | '(' exp ')'     { $$ = $2;}
   | '-' exp %prec UNARYMINUS { $$= negateDoble($2) ; }
   ;
%%
#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;
char *progname;
int lineno = 0;

void main (int argc, char *argv[]){
   progname=argv[0];
   init();
   setjmp(begin);
   signal(SIGFPE, fpecatch);
   yyparse ();
}
void execerror(char *s, char *t){
	warning(s, t);
	longjmp(begin, 0);
}
void fpecatch(){
	execerror("excepcion de punto flotante", (char *)0);
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




