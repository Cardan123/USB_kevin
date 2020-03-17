/*Declaraciones*/
%{
  #include <stdio.h>
  #include <ctype.h>
  #define YYSTYPE int /*Pila de YACC*/
  char *progname;
  int lineno = 1;
  void warning(char *s,char *y);
  void yyerror(char *s);
  int yylex();  
  void evalua(int a,int b,int op);
%}

/*Componente lexico o Terminal*/
%token RES
/*Precedencia de operadores*/
%left 'v'
%left '^'
%left '-'

/*Reglas*/
%%  
  
  list : /*NADA*/
     | list '\n'
     | list expr '\n'     
     ;

  expr : RES         {$$ = $1;}     
     | expr 'v' expr {(($1 || $3) == 0 )? printf("F\n"):printf("T\n");}
     | expr '^' expr { evalua($1,$3,2);}
     | '-' expr      { evalua(0,$2,3); }  
     | '(' expr ')'  {$$ = $2;} 
     ;
/*Codigo*/
%%
  /*Funcion principal*/
  void main (int argc, char *argv[]){
    progname= argv[0];
      yyparse ();
  }
  /*Funcion que hace el analisis lexico*/
  int yylex (){
      int c;
      while ((c = getchar ()) == ' ' || c == '\t' )  
        ;
    if (c == EOF)  return 0;
    
    if (isupper(c)){            
          if(c == 'F'){
              ungetc(c-22,stdin);                       
            }else if(c == 'T'){
            ungetc(c-35,stdin);                       
          }
            scanf ("%d", &yylval);
            return RES;             
      }
      if(c == '\n')
      lineno++;
    return c;                                
  }
  /* Llamada por yyparse ante un error */
  void yyerror (char *s){
    warning(s, (char *) 0);
  }

  void warning(char *s, char *t){
    fprintf (stderr, "%s: %s", progname, s);
    if(t) fprintf (stderr, " %s", t);
    fprintf (stderr, "cerca de la linea %d\n", lineno);
  }
  
  /*Funcion que evalua las expresiones booleanas*/
  void evalua(int a,int b,int op){  
    switch(op){
      case 1: ((a || b) == 0 )? printf("F\n"):printf("T\n");                   
          break;
      case 2: ((a && b) == 0 )? printf("F\n"):printf("T\n");
          break;
      case 3: ((!b) == 0 )? printf("F\n"):printf("T\n");
          break;
    }
  }
