%{
#include <math.h>
#define MSDOS

double mem[26];

void yyerror (char *s);
int yylex ();
void warning(char *s, char *t);
void execerror(char *s, char *t);
void fpecatch();
%}

%union {
	double val;
	int index;
}

%token <val> NUMBER
%token <index> VAR
%type <val> expr

%right '='
%left '+' '-'
%left '*' '/'
%left UNARYMINUS

%% /* A continuación las reglas gramaticales y las acciones */
list:   
	| list'\n'
        | list expr '\n'  { printf("\t%.8g\n", $2); }
	| list error '\n' { yyerrok; } 
	;

expr:      NUMBER           { $$ = $1;  }
	| VAR               {$$=mem[$1];}
	| VAR '=' expr      {$$=mem[$1]=$3;}
        | expr '+' expr     { $$ = $1+$3;  }
        | expr '-' expr     { $$ = $1-$3;  }
        | expr '*' expr     { $$ = $1*$3;  }
        | expr '/' expr     { 
		if($3==0.0)
			execerror("division por cero", "");
		$$ = $1/$3; }
        | '(' expr ')'     { $$ = $2;}
	| '-' expr %prec UNARYMINUS { $$= -$2; }
	;
%%

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;

char *progname;
int lineno = 1;

void main (int argc, char *argv[])
{
	progname=argv[0];
	setjmp(begin);
	signal(SIGFPE, fpecatch);
  	yyparse ();
}

void execerror(char *s, char *t)
{
	warning(s, t);
	longjmp(begin, 0);
}

void fpecatch()
{
	execerror("excepcion de punto flotante", (char *)0);
}

int yylex ()
{
  	int c;

  	while ((c = getchar ()) == ' ' || c == '\t')  
  		;
 	if (c == EOF)                            
    		return 0;
  	if (c == '.' || isdigit (c))                
    	{
      		ungetc (c, stdin);
      		scanf ("%lf", &yylval.val);
	      	return NUMBER;
    	}
	if(islower(c)){
		yylval.index=c-'a';
		return VAR;
	}
  	if(c == '\n')
		lineno++;
  	return c;                                
}

void yyerror (char *s)  /* Llamada por yyparse ante un error */
{
	warning(s, (char *) 0);
}

void warning(char *s, char *t)
{
	fprintf (stderr, "%s: %s", progname, s);
	if(t)
		fprintf (stderr, " %s", t);
	fprintf (stderr, "cerca de la linea %d\n", lineno);
}