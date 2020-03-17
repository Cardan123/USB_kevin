%{
#include "hoc.h"
#define	code2(c1,c2)	code(c1); code(c2)
#define	code3(c1,c2,c3)	code(c1); code(c2); code(c3)
int bandera=0;
%}
%union {
	Symbol	*sym;	/* symbol table pointer */
	Inst	*inst;	/* machine instruction */
}
%token	<sym>	NUMBER PRINT VAR BLTIN UNDEF
%type	<inst>  asgn expr 
%right	'='
%left	OR
%left	AND
%left	GT GE LT LE EQ NE
%left	'+' '-'
%left	'*' '/'
%left	UNARYMINUS NOT 
%right	'^'
%%
list:	  /* nothing */
	| list '\n'		  {bandera=0;}
	| list asgn '\n'  { code2(pop, STOP); return 1; }
	| list expr '\n'  { code2(print, STOP); return 1; }
	| list error '\n' { yyerrok; }
	;
asgn:	  VAR '=' expr	{ $$=$3; code3(varpush,(Inst)$1,assign); }
	;

expr:	'+'NUMBER '+' NUMBER'j'	{ $$ = code3(constpush, (Inst)$2,(Inst)$4); }
	|	'+'NUMBER '-' NUMBER'j'	{($4)->u.val*=-1; $$ = code3(constpush, (Inst)$2,(Inst)$4); }
	|	'-' NUMBER '+' NUMBER'j'{($2)->u.val*=-1;  $$ = code3(constpush, (Inst)$2,(Inst)$4); }
	|	'-' NUMBER '-' NUMBER'j'{($2)->u.val*=-1; ($4)->u.val*=-1;  $$ = code3(constpush, (Inst)$2,(Inst)$4); }
	| VAR						{ $$ = code3(varpush, (Inst)$1, eval); }
	
	| asgn
	| BLTIN '(' expr ')'
		{ $$ = $3; code2(bltin,(Inst)$1->u.ptr); }
	| '(' expr ')'	{ $$ = $2; }
	| expr '+' expr	{ code(add); }
	| expr '-' expr	{ code(sub); }
	| expr '*' expr	{ code(mul); }
	| expr '/' expr	{ code(div); }
	;
%%
	/* end of grammar */
#include <stdio.h>
#include <ctype.h>
char	*progname;
int	lineno = 1;
#include <signal.h>
#include <setjmp.h>
jmp_buf	begin;
int	defining;

int c;	/* global for use by warning() */
yylex()	
{
	while ((c=getchar()) == ' ' || c == '\t')
		;
	if (c == EOF)
		return 0;
	if (c == '.' || isdigit(c)) {	/* number */
		double d;
		ungetc(c, stdin);
		scanf("%lf", &d);
		yylval.sym = install("", NUMBER, d);
		return NUMBER;
	}
	if (isalpha(c)) {
		if(c=='j'){
			return c;}
		Symbol *s;
		char sbuf[100], *p = sbuf;
		do
			*p++ = c;
		while ((c=getchar()) != EOF && isalnum(c));
		ungetc(c, stdin);
		*p = '\0';
		if ((s=lookup(sbuf)) == 0)
			s = install(sbuf, UNDEF, 0.0);
		yylval.sym = s;
		return s->type == UNDEF ? VAR : s->type;
	}
	
	return c;
}
follow(expect, ifyes, ifno)  /* look ahead for >=, etc. */
{
	int c = getchar();

	if (c == expect)
		return ifyes;
	ungetc(c, stdin);
	return ifno;
}
yyerror(s)
	char *s;
{
	warning(s, (char *)0);
}

execerror(s, t)	/* recover from run-time error */
	char *s, *t;
{
	warning(s, t);
	longjmp(begin, 0);
}

fpecatch()	/* catch floating point exceptions */
{
	execerror("floating point exception", (char *) 0);
}
main(argc, argv)
	char *argv[];
{
	int fpecatch();

	progname = argv[0];
	setjmp(begin);
	signal(SIGFPE, fpecatch);
	for (initcode(); yyparse(); initcode())
		execute(prog);
	return 0;
}
warning(s, t)
	char *s, *t;
{
	fprintf(stderr, "%s: %s", progname, s);
	if (t && *t)
		fprintf(stderr, " %s", t);
	fprintf(stderr, " near line %d\n", lineno);
	while (c != '\n' && c != EOF)
		c = getchar();	/* flush rest of input line */
	fseek(stdin, 0L, 2);		/* flush rest of file */
	longjmp(begin, 0);
}
