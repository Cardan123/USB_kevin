%{
#include "hoc.h"
#define code2(c1,c2)     code(c1); code(c2)
#define code3(c1,c2,c3)  code(c1); code(c2); code(c3)
int indef;
%}
%union {
Symbol     *sym;      /*   Apuntador a la tabla de símbolos */
Inst       *inst;     /*   instrucción de máquina */
int        narg;      /*   número de argumentos */
}

%token     <sym>   NUMBER STRING PRINT VAR BLTIN UNDEF WHILE IF ELSE FOR
%token     <sym>   FUNCTION PROCEDURE RETURN FUNC PROC READ
%token     <narg>  ARG
%type      <inst>  expr stmt asgn prlist stmtlist
%type      <inst>  cond while if begin end for forcond asgnlist exprlist
%type      <sym>   procname
%type      <narg>  arglist
%right     '='
%left       OR
%left       AND
%left       GT GE LT LE EQ NE
%left       '+' '-'
%left       '*' '/'
%left       UNARYMINUS NOT
%right      '^'

%%
list:            /* nada */
   | list '\n'
   | list defn '\n'
   | list asgn '\n'  { code2(pop, STOP); return 1; }
   | list stmt '\n'  { code(STOP); return 1; }
   | list expr '\n'  { code2(print, STOP); return 1; }
   | list error '\n' { yyerrok; }
   ;
asgn: VAR '=' expr { code3(varpush,(Inst)$1,assign); $$=$3; }
   |  ARG '=' expr
{ defnonly("$"); code2(argassign,(Inst)$1); $$=$3;}
   ;
stmt:     expr  { code(pop); }
   | RETURN { defnonly("return"); code(procret); } 
   | RETURN expr
          { defnonly( "return" ); $$ = $2; code(funcret) ; } 
   | PROCEDURE begin '(' arglist ')'
          { $$ = $2; code3(call, (Inst)$1, (Inst)$4); } 
   | PRINT prlist  { $$ = $2; }
   | while cond stmt end {
           ($1)[1] = (Inst)$3;     /* cuerpo del ciclo */
           ($1)[2] = (Inst)$4; } /* fin, si la condición no se cumple */ 
   | if cond stmt end {    /* if sin else */
           ($1)[1] = (Inst)$3;     /* parte then */
           ($1)[3] = (Inst)$4; } /* fin, si la condición no se cumple */ 
   | if cond stmt end ELSE stmt end {      /* if con else */
           ($1)[1] = (Inst)$3;     /* parte then */
           ($1)[2] = (Inst)$6;     /* parte else */
           ($1)[3] = (Inst)$7; } /* fin, si la condición no se cumple */ 
   | '{' stmtlist '}'     { $$ = $2; }
   | for asgnlist forcond exprlist stmt end {
        ($1)[1] = (Inst) $3;
        ($1)[2] = (Inst) $4;
        ($1)[3] = (Inst) $5;
        ($1)[4] = (Inst) $6;
	}
   ;
forcond:  ';' expr ';'  { code(STOP); $$ = $2; }
    ;
asgnlist:  '(' asgn    { code(STOP); }
    ;
exprlist:    expr ')'  { code(STOP); }
    ;   
   
for:  FOR   { $$=code(forcode); code(STOP); code3(STOP, STOP, STOP); }
	;
   
   
cond: '(' expr ')'     {  code(STOP);   $$ =  $2;   }
   ;
while:  WHILE { $$ = code3(whilecode,STOP,STOP); }
   ;
if:     IF   { $$ = code(ifcode); code3(STOP,STOP,STOP); }
   ;
begin:  /* nada */          { $$ = progp; }
   ;
end:    /* nada */          { code(STOP); $$ = progp; }
   ;
stmtlist: /* nada */        { $$ = progp; }
   | stmtlist '\n' 
   | stmtlist stmt
   ;  
expr:	'+'NUMBER '+' NUMBER'j'	{ $$ = code3(constpush, (Inst)$2,(Inst)$4); }
	|	'+'NUMBER '-' NUMBER'j'	{($4)->u.val*=-1; $$ = code3(constpush, (Inst)$2,(Inst)$4); }
	|	'-' NUMBER '+' NUMBER'j'{($2)->u.val*=-1;  $$ = code3(constpush, (Inst)$2,(Inst)$4); }
	|	'-' NUMBER '-' NUMBER'j'{($2)->u.val*=-1; ($4)->u.val*=-1;  $$ = code3(constpush, (Inst)$2,(Inst)$4); }
		//NUMBER {   $$ = code2(constpush, (Inst)$1); }
   |   VAR    {   $$ = code3(varpush, (Inst)$1, eval); }
   |   ARG    {   defnonly("$"); $$ = code2(arg, (Inst)$1); }
   |   asgn
   | FUNCTION begin '(' arglist ')'
           { $$ = $2; code3(call,(Inst)$1,(Inst)$4); }  
   | READ '(' VAR ')' { $$ = code2(varread, (Inst)$3); }  
   | BLTIN '(' expr ')' { $$=$3; code2(bltin, (Inst)$1->u.ptr); }  
   | '(' expr ')'  { $$ = $2; }
   | expr   '+'   expr {   code(add); }
   | expr   '-'   expr {   code(sub); }
   | expr   '*'   expr {   code(mul); }
   | expr   '/'   expr {   code(div); }
   | '-' expr  %prec UNARYMINUS   { $$=$2; code(negate); }
   | expr   GT	  expr	{ code(gt); }
   | expr   GE	  expr	{ code(ge); }
   | expr   LT	  expr	{ code(lt); }
   | expr   LE	  expr	{ code(le); }
   | expr   EQ	  expr	{ code(eq); } 
   | expr   NE	  expr	{ code(ne); }
   | expr  AND    expr  { code(and);}
   | expr   OR    expr  { code(or); }
   | NOT expr     { $$= $2; code(not); }
   ;
prlist:expr                {   code(prexpr); }
   |   STRING              {    $$ = code2(prstr, (Inst)$1); }
   |   prlist ','  expr    {   code(prexpr); }
   |   prlist ','  STRING  {   code2(prstr, (Inst)$3); }
   ;
defn:    FUNC procname { $2->type=FUNCTION; indef=1; }
'(' ')' stmt { code(procret); define($2); indef=0; } 
   | PROC procname { $2->type=PROCEDURE; indef=1; }
'(' ')' stmt { code(procret); define($2); indef=0; }
   ;
procname: VAR
   | FUNCTION 
   | PROCEDURE
   ;
arglist:  /* nada */   { $$ = 0; }
   | expr                 { $$ = 1; }
   | arglist ',' expr     { $$ = $1 + 1; }
   ;
%%

/* fin de la gramática */ 
#include <stdio.h> 
#include <ctype.h> 

char    *progname; 
int    lineno = 1 ; 

#include <signal.h> 
#include <setjmp.h> 
jmp_buf begin; 
//int    indef;
char   *infile;       /* nombre de archivo de entrada */ 
FILE    *fin;         /* apuntador a archivo de entrada */
char   **gargv;       /* lista global de argumentos */ 
int    gargc; 
int c;  /* global, para uso de warning() */

yylex()
{
while  ((c=getc(fin)) ==  ' ' ||  c ==   '\t')
          ;
if (c == EOF)
	return 0; 
if (c == '.' || isdigit(c)) {   /* número */
	double d;
	ungetc(c, fin); 
	fscanf(fin, "%lf", &d);
	yylval.sym = install("", NUMBER, d);
	return NUMBER; 
}
if (isalpha(c)) { 
	if(c=='j'){
		return c;}
	Symbol *s;
	char sbuf[100], *p = sbuf; 
	do {
		if (p >= sbuf + sizeof(sbuf) - 1) { 
			*p = '\0'; 
			execerror("name too long", sbuf);
		}
	*p++ = c;
	} while ((c=getc(fin)) != EOF && isalnum(c)); 
	ungetc(c, fin); 
	*p = '\0'; 
	if ((s=lookup(sbuf)) == 0)
       		s=install(sbuf, UNDEF, 0.0); 
	yylval.sym = s;
	return s->type == UNDEF ? VAR : s->type;
}
if (c == '$') { /* ¿argumento? */ 
	int n = 0; 
	while (isdigit(c=getc(fin)))
		n = 10 * n + c - '0'; 
	ungetc(c, fin); 
	if (n == 0)
		execerror("strange $...", (char *)0); 
	yylval.narg = n; 
	return ARG;
}
if (c == '"') { /* cadena entre comillas */ 
	char sbuf[100], *p, *emalloc(); 
	for (p = sbuf; (c=getc(fin)) != '"'; p++) { 
		if (c == '\n' || c == EOF)
			execerror("missing quote", ""); 
		if (p >= sbuf + sizeof(sbuf) - 1) { 
			*p = '\0';
			execerror("string too long", sbuf); 
		}
		*p = backslash(c); 
	}
	*p = 0;
	yylval.sym = (Symbol *)emalloc(strlen(sbuf)+1); 
	strcpy(yylval.sym, sbuf); 
	return STRING;
}
	switch (c) {
	case '>':                return follow('=', GE, GT);
	case '<':                return follow('=', LE, LT);
	case '=':                return follow('=', EQ, '=');
	case '!':                return follow('=', NE, NOT);
	case '|':                return follow('|', OR, '|');
	case '&':                return follow('&', AND, '&');
	case '\n':              lineno++; return '\n';
	default:                  return c; 
        }
}


backslash( c )       /*   tomar siguiente carácter con las \ interpretadas   */
int   c; 
{
char *strchr( ) ;  /* strchr() en algunos sistemas */
static char transtab[] = "b\bf\fn\nr\rt\t";
if (c != '\\')
	return c;
c = getc(fin);
if (islower(c) && strchr(transtab, c)) 
	return strchr(transtab, c)[1];
return c; 
}

follow(expect, ifyes, ifno)     /* búsqueda hacia adelante para > -, etc. */ 
{
int c = getc(fin);
if (c == expect)
	return ifyes;
ungetc(c, fin);
return ifno; 
} 

defnonly( char *s )     /* advertena la si hay definición i legal */
{
if (!indef)
	execerror(s, "used outside definition"); 
} 

yyerror(char *s)      /* comunicar errores de tiempo de compilación */
{
warning(s, (char *)0); 
} 

execerror(char *s, char *t) /* recuperación de errores de tiempo de ejecución */
{
warning(s, t);
fseek( fin, 0L, 2);       /* sacar el resto del archivo */
longjmp(begin, 0); 
}

void fpecatch()      /* detectar errores por punto flotante */ 
{
execerror("floating point exception", (char *) 0); 
}		

main(int argc, char **argv)       /* hoc6 */ 
{
int i;
void fpecatch();
progname = argv[0];
if (argc == 1) {        /* simular una lista de argumentos */ 
	static char *stdinonly[] = { "-" };
	gargv = stdinonly;
	gargc = 1; } 
else {
	gargv = argv+1;
	gargc = argc-1; 
}
init(); 
while (moreinput())
	run(); 
return 0;
}
                                                                                    
moreinput( ) {
if (gargc-- <= 0)
	return 0; 
if (fin && fin != stdin)
fclose(fin); 
infile = *gargv++; 
printf("arch ent=(%s)\n",infile);
lineno = 1; 
if (strcmp(infile, "-") == 0) {
	fin = stdin;
	infile = 0; 
} else if ((fin=fopen(infile, "r")) == NULL) {
	fprintf(stderr, "%s: can't open %s\n" , progname, infile);
	return moreinput();
}
return 1;
}

run()   /* ejecutar hasta el fin de archivo (EOF) */
{
setjmp(begin);
signal(SIGFPE,   fpecatch);
for   (initcode();   yyparse();   initcode())
	execute(progbase); 
}

warning(char *s, char *t)        /*   imprimir mensaje de advertencia   */
{
fprintf(stderr, "%s: %s", progname, s); 
if (t)
	fprintf(stderr, " %s", t); 
if (infile)
	fprintf(stderr, " in %s", infile); 
fprintf(stderr, " near line %d\n", lineno); 
while (c != '\n' && c != EOF)
c = getc(fin);  /* sacar el resto del renglón de entrada */
if (c == '\n')
	lineno++;
}











