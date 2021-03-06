%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include "polinomio_cal.h"
#include "y.tab.h"
void RmWs(char* str);
extern YYSTYPE yylval;
//NodoL *cab=NULL;
%}
op [-+*/()]
ws [ \t]+ 
digits [0-9]
number (0|[1-9]+{digits}*)
termino  {ws}*[+|-]*{ws}*{number}{ws}*x[+|-]*{ws}*{number}{ws}* 
%%
{termino} {
   int coefi, expo;
   RmWs(yytext); 
   sscanf(yytext,"%dx%d", &coefi, &expo); 
   yylval.term=creaTermino(coefi,expo);
   return TERMINO;
}
{op} | 
\r |
\n {
	return *yytext;
}
{ws} { } 
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

