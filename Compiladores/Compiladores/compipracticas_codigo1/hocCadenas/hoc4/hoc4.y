%{
#include<stdlib.h>
#include "hoc.h"
#define code2(c1,c2)     code(c1); code(c2)
#define code3(c1,c2,c3) code(c1); code(c2); code(c3)

NodoL *symlist = (NodoL *)NULL;
NodoL **globals = (NodoL **)NULL;

void warning(char *s, char *t);
void yyerror(char *s);
void execerror(char *s, char *t);

%}
%union {
	Simbolo *sym;
	Inst *inst;
}
%token <sym> NUMBER VAR BLTIN INDEF
%right '='
%left '+' '-'
%left '*' '/'
%left UNARYMINUS
%right '^'
%%
list:            /* nada */
   | list '\n'
   | list asgn '\n'  { code2( strdup("pop1"), strdup("STOP") ); 
                       return 1; }
   | list expr '\n'  { code2(strdup("print"), strdup("STOP")); 
                       return 1; }
   | list error '\n' { yyerrok; }
   ; 
asgn: VAR '=' expr { 
      code3(strdup("varpush"), (Inst)$1, strdup("assign")); 
   }
   ;
expr:  NUMBER {  //puts("NUMBER"); 
                 code2(strdup("constpush"), (Inst)$1); 
              }
   |   VAR    {  
                 code3(strdup("varpush"), (Inst)$1, strdup("eval"));
              } 
   | asgn
   | BLTIN '(' expr ')' { 
              code2(strdup("bltin"), (Inst)$1->u.ptr);
           }  
   | '(' expr ')'  
   | expr '+' expr     { code(strdup("add")); }
   | expr '-' expr     { code(strdup("sub")); }
   | expr '*' expr     { code(strdup("mul")); }
   | expr '/' expr     { code(strdup("div")); }
   | expr '%' expr     { code(strdup("mod")); }
   | expr '^' expr     { code(strdup("power")); }
   | '-' expr %prec UNARYMINUS { code(strdup("negate")); }
   ;
%%
/* fin de la gram�tica */ 
#include <stdio.h> 
#include <ctype.h> 
#include <string.h>

char    *progname; 
int    lineno = 1 ; 

#include <signal.h> 
#include <setjmp.h> 
jmp_buf begin; 

void yyerror(char *s) {
   warning(s, (char *)0); 
} 
void execerror(char *s, char *t){
	warning(s, t);
	longjmp(begin, 0);
}
void fpecatch(){
   execerror("floating point exception", (char *) 0); 
}
void main (int argc, char *argv[]){
   progname=argv[0];
   init();
   setjmp(begin);
   signal(SIGFPE, fpecatch);
   for(initcode(); yyparse (); initcode())
      execute(prog);
}		
void warning(char *s, char *t){
	fprintf (stderr, "%s: %s", progname, s);
	if(t)
		fprintf (stderr, " %s", t);
	fprintf (stderr, "cerca de la linea %d\n", lineno);
}                                                                            










