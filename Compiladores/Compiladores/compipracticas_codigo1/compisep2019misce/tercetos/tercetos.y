%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "y.tab.h"
typedef struct _doble_cond {
char etq_verdad[21], etq_falso[21];
} doble_cond;
typedef struct _datos_case {
char etq_final[21];
char variable_expr[21];
} datos_case;
extern int linea_actual;
%}
%union{
int numero;
char variable_aux[21];
char etiqueta_aux[21];
char etiqueta_siguiente[21];
doble_cond bloque_cond;
datos_case bloque_case;
}
%token <numero> NUMERO
%token <variable_aux> ID
%token <etiqueta_aux> IF WHILE REPEAT
%token <etiqueta_siguiente> CASO
%token ASIG THEN ELSE FIN DO UNTIL CASE OF OTHERWISE
%token MAI MEI DIF
%type <variable_aux> expr
%type <bloque_cond> cond
%type <bloque_case> inicio_case
%left OR
%left AND
%left NOT
%left '+''-'
%left '*''/'
%left MENOS_UNARIO

%%
prog : prog sent ';'
     | prog error ';' {yyerrok;}
     |
     ;
sent : ID ASIG expr {
       printf("\t%s = %s\n",$1,$3);
     }
     | IF cond
     {
       printf("label %s\n",$2.etq_verdad);
     }
     THEN sent ';'
     {
      nueva_etq($1);
      printf("\tgoto%s\n",$1);
      printf("label %s\n",$2.etq_falso);
     }
     opcional
     FIN IF
     {
      printf("label %s\n",$1);
     }
     | '{' lista_sent '}' {;}
     | WHILE
     {
       nueva_etq($1);
       printf("label %s\n",$1);
     }
     cond
     {
       printf("label %s\n",$3.etq_verdad);
     }
     DO sent ';'
     {
        printf("\tgoto %s\n",$1);
     }
     FIN WHILE
     {
        printf("label %s\n",$3.etq_falso);
     }
     | REPEAT
     {
       nueva_etq($1);
       printf("label %s\n",$1);
     }
     sent ';'
     UNTIL cond
     {
       printf("label %s\n",$6.etq_falso);
       printf("\tgoto %s\n",$1);
       printf("label %s\n",$6.etq_verdad);
     }
     | sent_case
     ;
opcional : ELSE sent';'
     |
     ; 
lista_sent : /*Epsilon*/
     | lista_sent sent ';'
     | lista_sent error ';' {yyerrok;}
     ; 
sent_case : inicio_case
     OTHERWISE sent ';'
     FIN CASE
    {
       printf("label %s\n",$1.etq_final);
    }
    | inicio_case
    FIN CASE
    {
      printf("label %s\n",$1.etq_final);
    }
    ;
    inicio_case : CASE expr OF
    {
      strcpy($$.variable_expr,$2);
      nueva_etq($$.etq_final);
    }
   | inicio_case
     CASO expr':'
     {
       nueva_etq($2);
       printf("\tif %s != %s goto %s\n", $1.variable_expr,$3,$2);
     }
     sent ';'
     {
       printf("\tgoto %s\n",$1.etq_final);
       printf("label %s\n",$2);
       strcpy($$.variable_expr,$1.variable_expr);
       strcpy($$.etq_final,$1.etq_final);
     }
     ;
expr : NUMERO {
       nueva_var($$);
       printf("\t%s = %d;\n", $$,$1);
     }
     | ID
     {
       strcpy($$,$1);
     }
     | expr'+'expr
     {
        nueva_var($$);
        printf("\t%s = %s + %s;\n",$$,$1,$3);
     }
     | expr'-'expr
     {
        nueva_var($$);
        printf("\t%s = %s - %s;\n",$$,$1,$3);
     }
     |  expr'*'expr
     {
        nueva_var($$);
        printf("\t%s = %s * %s;\n",$$,$1,$3);
     }
     | expr'/'expr
     {
       nueva_var($$);
       printf("\t%s = %s / %s;\n",$$,$1,$3);
     }
    | '-'expr %prec MENOS_UNARIO
    {
       nueva_var($$);
       printf("\t%s = - %s;\n",$$,$2);
    }
    | '('expr')'
    {
       strcpy($$,$2);
    }
    ;
cond : expr'>'expr
    {
       nueva_etq($$.etq_verdad);
       nueva_etq($$.etq_falso);
       printf("\tif %s > %s goto %s\n",$1,$3,$$.etq_verdad);
       printf("\tgoto %s\n",$$.etq_falso);
    }
    | expr'<'expr
    {
        nueva_etq($$.etq_verdad);
        printf("\tif %s < %s goto %s\n",$1,$3,$$.etq_verdad);
        nueva_etq($$.etq_falso);
        printf("\tgoto %s\n",$$.etq_falso);
    }
    | expr MAI expr{
       nueva_etq($$.etq_verdad);
       nueva_etq($$.etq_falso);
       printf("\tif %s >= %s goto %s\n",$1,$3,$$.etq_verdad);
       printf("\tgoto %s\n",$$.etq_falso);
     }
     | expr MEI expr
     {
        nueva_etq($$.etq_verdad);
        nueva_etq($$.etq_falso);
        printf("\tif %s <= %s goto %s\n",$1,$3,$$.etq_verdad);
        printf("\tgoto %s\n",$$.etq_falso);
      }
      | expr'='expr
      {
        nueva_etq($$.etq_verdad);
        nueva_etq($$.etq_falso);
        printf("\tif %s = %s goto %s\n",$1,$3,$$.etq_verdad);
        printf("\tgoto %s\n",$$.etq_falso);
      }
      | NOT cond
      {
         strcpy($$.etq_verdad,$2.etq_falso);
         strcpy($$.etq_falso,$2.etq_verdad);
      }
      |  cond AND
      {
         printf("label%s\n",$1.etq_verdad);
      }
      cond {
         printf("label %s\n",$1.etq_falso);
         printf("\tgoto %s\n",$4.etq_falso);
         strcpy($$.etq_verdad,$4.etq_verdad);
         strcpy($$.etq_falso,$4.etq_falso);
       }
      | cond OR
      {
         printf("label %s\n",$1.etq_falso);
      }
      cond {
         printf("label %s\n",$1.etq_verdad);
         printf("\tgoto %s\n",$4.etq_verdad);
         strcpy($$.etq_verdad,$4.etq_verdad);
         strcpy($$.etq_falso,$4.etq_falso);
       }
      | '(' cond ')'
      {
         strcpy($$.etq_verdad,$2.etq_verdad);
         strcpy($$.etq_falso,$2.etq_falso);
      }
      ;
%%
void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}  
void itochar(int x, char *buffer, int radix){
    int i = 0 , n,s;
    n = x;
    while (n > 0){
        s = n%radix;
        n = n/radix;
        buffer[i++] = '0' + s;
    }
    buffer[i] = '\0';
    //printf("11<%s>",buffer);
    reverse(buffer);
    //printf("22<%s>",buffer);
}
void nueva_var(char * s){
   static actual=0;
   strcpy(s, "tmp");
   itochar(++actual, &(s[3]), 10);
}
void nueva_etq(char * s){
   static actual=0;
   strcpy(s, "etq");
   itochar(++actual, &(s[3]), 10);
}
void main(){
   yyparse();
}
void yyerror(char* s){
   fprintf(stderr, "Error de sintaxis en la linea %d\n", linea_actual);
}



     

