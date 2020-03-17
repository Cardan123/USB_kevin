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
%token <sym>   NUMBER PRINT VAR BLTIN INDEF WHILE IF ELSE 
%type  <inst>  stmt asgn expr stmtlist cond while if end
%right	'='
%left	OR
%left	AND
%left	GT GE LT LE EQ NE
%left	'+' '_'
%left	'*' '/'
%left	UNARYMINUS NOT
%right '^'
%%
list:            /* nada */
   | list '\n'
   | list asgn '\n'  { code2( strdup("pop1"), strdup("STOP") ); 
                       return 1; }
   | list stmt '\n'  { code(strdup("STOP")); return 1; }
   | list expr '\n'  { code2(strdup("print"), strdup("STOP")); 
                       return 1; }
   | list error '\n' { yyerrok; }
   ; 
asgn: VAR '=' expr { 
      code3(strdup("varpush"), (Inst)$1, strdup("assign")); 
   }
   ;
stmt: expr   { code(strdup("pop1")); }
   | PRINT expr    { code(strdup("printVal")); $$ = $2;} 
   | while cond stmt end {
           ($1)[1] = (Inst)$3;     /* cuerpo del ciclo */
           ($1)[2] = (Inst)$4; } 
   | if cond stmt end {    /* if sin else */
           ($1)[1] = (Inst)$3;     /* parte then */
           ($1)[3] = (Inst)$4; 
     } /* fin, si la condición no se cumple */ 
   | if cond stmt end ELSE stmt end {      /* if con else */
           ($1)[1] = (Inst)$3;     /* parte then */
           ($1)[2] = (Inst)$6;     /* parte else */
           ($1)[3] = (Inst)$7;   
     } /* fin, si la condición no se cumple */ 
   |  '{' stmtlist '}'     { $$ = $2; }
   ; 
cond:	'('   expr   ')' {   code(strdup("STOP"));  $$=  $2;   }
        ;
while:	WHILE   {   
        $$ = code3(strdup("whilecode"), strdup("STOP"), strdup("STOP")); 
        }
	;
if:IF   { $$=code(strdup("ifcode")); 
          code3( strdup("STOP"), strdup("STOP"), strdup("STOP")); }
	;
end:      /* nada */ { code( strdup("STOP") ); $$ = progp; }
	;
stmtlist: /* nada */        { $$ = progp; }
   | stmtlist '\n' 
   | stmtlist stmt
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
   | '(' expr ')'      { $$ = $2; }
   | expr '+' expr     { code(strdup("add")); }
   | expr '-' expr     { code(strdup("sub")); }
   | expr '*' expr     { code(strdup("mul")); }
   | expr '/' expr     { code(strdup("div")); }
   | expr '%' expr     { code(strdup("mod")); }
   | expr '^' expr     { code(strdup("power")); }
   | '-' expr %prec UNARYMINUS { code(strdup("negate")); }
   | expr GT expr  { code(strdup("gt")); }
   | expr GE expr  { code(strdup("ge")); }
   | expr LT expr  { code(strdup("lt")); }
   | expr LE expr  { code(strdup("le")); }
   | expr EQ expr  { code(strdup("eq")); }
   | expr NE expr  { code(strdup("ne")); }
   | expr AND expr { code(strdup("and")); }
   | expr OR expr  { code(strdup("or")); }
   | NOT expr      { $$ = $2; code(strdup("not")); }
   ;
%%
/* fin de la gramática */ 
#include <stdio.h> 
#include <ctype.h> 
#include <string.h>

char    *progname; 
int    lineno = 1 ; 

#include <signal.h> 
#include <setjmp.h> 
jmp_buf begin; 

/*int yylex(){
   int c;
   while  ((c=getc(stdin)) ==  ' ' ||  c ==   '\t')
          ;
   if (c == EOF)
	return 0; 
   if (isdigit(c)) {   
      double d;
      ungetc(c, stdin); 
      scanf("%lf", &d);
      yylval.sym = install(globals, "numero", NUMBER, creaDoble(d));
      return NUMBER; 
   }
   if (isalpha(c)) { 
      Simbolo *s;
      char sbuf[100], *p = sbuf; 
      do {
         if (p >= sbuf + sizeof(sbuf) - 1) { 
			*p = '\0'; 
			execerror("name too long", sbuf);
         }
      *p++ = c;
      } while ((c=getchar()) != EOF && isalnum(c)); 
      ungetc(c, stdin); 
      *p = '\0'; 
      if ((s=lookup(*globals,sbuf)) == 0)
         s=install(globals, sbuf, INDEF, NULL); 
      yylval.sym = s;
      return s->tipo == INDEF ? VAR : s->tipo;
   }
   return c; 
}*/
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











