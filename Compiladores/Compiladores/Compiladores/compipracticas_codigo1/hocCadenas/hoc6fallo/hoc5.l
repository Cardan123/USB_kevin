%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include "hoc.h"
#include "y.tab.h"
void RmWs(char* str);
extern int lineno;
NodoL **globals;
extern YYSTYPE yylval;
%}
ws [ \t]+ 
digits [0-9]
entero (0|[1-9]+{digits}*)
flotante {entero}?\.?{entero}?
letra [a-z]
%%
\< { return LT; }
"<=" { return LE; }
\> { return GT; }
">=" { return GE; }
"==" { return EQ; }
"!=" { return NE; }
"&&" { return AND; }
"||" { return OR; }
"!" { return NOT; }
{flotante} {
   double number;
   //puts("yylex NUMBER");
   //printf("yytext=(%s)\n", yytext);
   RmWs(yytext); 
   sscanf (yytext, "%lf", &number);
   //printf("number = (%.8g)\n", number);
   yylval.sym = install(globals, "numero", NUMBER, creaDoble(number));
   //yylval.val=creaDoble(number);
   return NUMBER;
}
\"[^\"]*\" { 
        //puts("cadena");
        //puts(yytext);
        yylval.sym = (Simbolo *)strdup(yytext);
	return STRING;
}
\${entero} {
   int n=0;
   printf("ARG yytext=(%s) sizeapchar=(%d)\n", yytext+1,sizeof(char *));
   sscanf(yytext+1,"%d", &n);
   printf("n=(%d)\n", n);
   if (n == 0)
      execerror("strange $...", (char *)0);     
   //yylval.sym = install(globals, "numero", NUMBER, creaDoble(n));
   yylval.narg = n;
   //puts("yylex ARG");
   return ARG;
}
[a-zA-Z][a-zA-Z0-9]* { 
   Simbolo *s;
   if((s=lookup(*globals, yytext))==(Simbolo *)NULL)
      s=install(globals, yytext, INDEF, NULL);
   yylval.sym=s;   
   //printf("func=(%s) tipo=(%d) \n", s->nombre, s->tipo);
   if(s->tipo == INDEF){
      return VAR;
   } else {
      //printf("func=(%s) tipo=(%d) \n", s->nombre, s->tipo);
      return s->tipo;
   }
}
\r |
\n { 
     //puts("enter");
     lineno++;
     return *yytext; }
{ws}  { }
. {
   //printf("regresando =(%c, %d)\n", yytext[0], yytext[0]);
   return *yytext;
}
%%
void RmWs(char* str) {
  int i = 0, j = 0;
  char *temp=strdup(str);
  while (temp[i] != '\0') {
    while (temp[i] == ' ')
      i++;
    str[j] = temp[i];
    i++;
    j++;
  }
 str[j] = '\0';
 free(temp);
}
