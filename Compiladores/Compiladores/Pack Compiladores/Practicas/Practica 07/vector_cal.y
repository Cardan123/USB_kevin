%{
    #include "hoc.h"
    #include <math.h>
    #include <stdio.h>
    #define MSDOS
    //Macros
    #define code2(c1, c2) code(c1); code(c2);
    #define code3(c1, c2, c3) code(c1); code(c2); code(c3);

    void yyerror(char* s);
    int yylex();
    void warning(char* s, char* t);
    void fpecatch();
    void execerror(char*s, char* t);
    extern void init();
%}  
//Definición de tipos de dato de la pila de yacc
%union{
    double comp;
    Vector* vec;
    Symbol* sym;
    Inst* inst;
    int eval;
    //Añadido en la práctica 7
    int narg;
} 

/**Creación de símbolos terminales y no terminales**/
%token<comp> NUMBER
%type<comp> escalar

%token<sym> VAR INDEF VECTOR NUMB
%type<sym> vector number

%type<inst> exp asgn

%token<sym>     PRINT WHILE IF ELSE BLTIN
%type<inst>     stmt stmtlst cond while if end    

%token<sym>     FOR
%type<inst>     for exprn

//Nuevos símbolos gramaticales para la práctica 7
%token<sym>     FUNCTION PROCEDURE RETURN FUNC PROC READ STRING
%token<narg>    ARG
%type<inst>     prlist begin
%type<sym>      procname
%type<narg>     arglist
/**Jerarquía de operadores**/

//Para práctica 3
%right '='
//Para la práctica 5
%left OR AND
%left GT GE LT LE EQ NE
//Símbolos gramaticales de la práctica 1
//Suma y resta de vectores
%left '+' '-'
//Escalar por un vector
%left '*'
//Producto cruz y producto punto
%left '#' '.' '|'
//Para la práctica 5
%left UNARYMINUS NOT

/**Gramática**/
%%

    list: 
      | list '\n'
      | list asgn '\n'    {code2(pop, STOP); return 1;}
      | list stmt '\n'    {code(STOP); return 1;}
      | list exp '\n'     {code2(print, STOP); return 1;}
      | list escalar '\n' {code2(printd, STOP); return 1;}
      | list error '\n'   {yyerror;}
      ;
    
    asgn: VAR '=' exp   {$$ = $3; code3(varpush, (Inst)$1, assign);}
    ;

    exp: vector             {$$ = code2(constpush, (Inst)$1);}
      | VAR                 {$$ = code3(varpush, (Inst)$1, eval);}
      | asgn
      | BLTIN '(' exp ')'   {$$ = $3; code2(bltin, (Inst)$1 -> u.ptr);}
      | exp '+' exp         {code(add);}
      | exp '-' exp         {code(sub);}
      | escalar '*' exp     {code(escalar);}
      | exp '*' escalar     {code(escalar);}
      | exp '#' exp         {code(producto_cruz);}
      | exp GT exp          {code(mayor);}
      | exp LT exp          {code(menor);}
      | exp GE exp          {code(mayorIgual);}
      | exp LE exp          {code(menorIgual);}
      | exp EQ exp          {code(igual);}
      | exp NE exp          {code(diferente);}
      | exp OR exp          {code(or);}
      | exp AND exp         {code(and);}
      | NOT exp             {$$ = $2; code(not);}
      //Práctica 7
      | FUNCTION begin '(' arglist ')' {$$ = $2; code3(call, (Inst)$1, (Inst)$4);}
      | READ '(' VAR ')'    {$$ = code2(varread, (Inst)$3);}
    ;

    escalar: number         {code2(constpushd, (Inst)$1);}
      | exp '.' exp         {code(producto_punto);}
      | '|' exp '|'         {code(magnitud);}
      ;

    vector: '[' NUMBER NUMBER NUMBER ']'   {  Vector* v = creaVector(3);
                                            v -> vec[0] = $2;
                                            v -> vec[1] = $3;
                                            v -> vec[2] = $4;
                                            $$ = install("", VECTOR, v);}
      ;


    number: NUMBER                      {$$ = installd("", NUMB, $1);}
    ;

    stmt: exp                                           {code(pop);}
    |   PRINT exp                                       {code(print); $$ = $2;}
    |   while cond stmt end                             {($1)[1] = (Inst)$3;
                                                         ($1)[2] = (Inst)$4;}

    | if cond stmt end                                  {($1)[1] = (Inst)$3;
                                                         ($1)[3] = (Inst)$4;}

    | if cond stmt end ELSE stmt end                    {($1)[1] = (Inst)$3;
                                                         ($1)[2] = (Inst)$6;
                                                         ($1)[3] = (Inst)$7;}

    | for '(' exprn ';' exprn ';' exprn ')' stmt end    {($1)[1] = (Inst)$5;
                                                         ($1)[2] = (Inst)$7;
                                                         ($1)[3] = (Inst)$9;
                                                         ($1)[4] = (Inst)$10;}
    | '{' stmtlst '}'                                   {$$ = $2;}
    | RETURN                                            {defonly("return"); code(procret);}
    | RETURN exp                                        {defonly("return"); $$ = $2; code(funcret);}
    ;

    cond: '(' exp ')'                   {code(STOP); $$ = $2;}
    ;

    while: WHILE                        {$$ = code3(whilecode, STOP, STOP);}
    ;

    if: IF                              {$$ = code(ifcode);
                                         code3(STOP, STOP, STOP);}
    ;

    end: /* NADA */                     {code(STOP); $$ = progp;}
    ;

    stmtlst: /* NADA */                 {$$ = progp;}
    |   stmtlst '\n'
    |   stmtlst stmt
    ;

    //PRÁCTICA 6
    for: FOR                            {$$ = code(forcode); code3(STOP, STOP, STOP); code(STOP);}
    ;

    exprn: exp                          {$$ = $1; code(STOP);}
    |   '{' stmtlst '}'                 {$$ = $2;}
    ;

    //Práctica 7
    begin: /* NADA */                   {$$ = progp;}
    ;

    prlist: exp                         {code(prexpr);}
        |   STRING                      {$$ = code2(prstr, (Inst)$1);}
        |   prlist ',' exp              {code(prexpr);}
        |   prlist ',' STRING           {code2(prstr, (Inst)$3);}
    ;

    defn: FUNC procname                 {$2->type=FUNCTION; indef = 1;}
                                        '('')' stmt {code(procret); define($2); indef=0;}
        | PROC procname                 {$2->type=PEOCEDURE; indef = 1;}
                                        '(' ')' stmt {code(procret); define($2); indef=0;}
    ;

    arglist: /* NADA */                 {$$ = 0;}
        | exp                           {$$ = $1;}
        | arglist ',' exp               {$$ = $1 + 1;}
    ;


    procname: VAR
        |   FUNCTION    
        |   PROCEDURE
    ;
%%

/****************************************************************************
*                            Código en C                                    *
****************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;
char* progname;
int lineno = 1;
//PRÁCTICA 7
int     indef;
char*   infile;
FILE*   fin;
char**  gargv;
int     gargc;
int     c;

void main(int argc, char * argv[]) {
    progname = argv[0];
    init();
    setjmp(begin);
    signal(SIGFPE, fpecatch);
    for(initcode(); yyparse (); initcode())
		execute(prog);
}

void execerror(char * s, char * t){
    warning(s, t);
    longjmp(begin, 0);
}

void fpecatch(){
    execerror("Excepcion de punto flotante", (char *)0);
}

int yylex(){
    int c;
    while ((c = getchar()) == ' ' || c == '\t')
        /**SALTA BLANCOS**/;

    if (c == EOF)
      return 0;

    if (isdigit(c) ) {
        ungetc(c, stdin);
        scanf("%lf\n", &yylval.comp);
        return NUMBER;
    }

    if (isalpha(c)) {
        Symbol* s;
        char sbuf[200];
        char* p = sbuf;
        do {
          *p++=c;
        } while((c = getchar()) != EOF && isalnum(c));

        ungetc(c, stdin);
        *p = '\0';
        if ((s = lookup(sbuf)) == (Symbol *)NULL)
          s = install(sbuf, INDEF, NULL);
        yylval.sym = s;

        if (s->type == INDEF)
          return VAR;
        else
          return s->type;
    }
    if(c == '$'){
        int n = 0;
        while(isdigit(c = getc(fin)))
            n = 10 * n + c - '0';
        unget(c, fin);
        if(n == 0)
            execerror("strange $...", (char*)0);
        yylval.narg = n;
        return ARG;
    }
    if(c == '""'){
        char sbuf[100], *p, *emalloc();
        for(p  = sbuf; (c = getc(fin)) != '""'; p++){
            if(c == '\n' || c == EOF)
                execerror("missing quote", "");
            if(p >= sbuf + sizeof(sbuf) - 1){
                *p = '\0';
                execerror("string too long", sbuf);
            }
            *p = backslash(c);
        }
        *p = 0;
        yylval.sym = (Symbol)
    }
    switch(c){
        case '>': return follow('=', GE, GT);
        case '<': return follow('=', LE, LT);
        case '=': return follow('=', EQ, '=');
        case '!': return follow('=', NE, NOT);
        case '|': return follow('|', OR, '|');
        case '&': return follow('&', AND, '&');
        case '\n': lineno++; return '\n';
        default: return c;
    }
    lineno++;
    return c;
}

int follow(int expect, int ifyes, int ifno){  /*   buscar  operadores.   */
    int c  = getchar();
    if  (c  ==  expect)
        return ifyes;
    ungetc(c,   stdin);
    return  ifno;
}

void yyerror(char * s){     /* Llamada por yyparse ante un error */
  warning(s, (char *)0);
}

void warning(char * s, char * t) {
    fprintf(stderr, "%s: %s",progname,s);
    if (t)
        fprintf(stderr, "%s",t);
    fprintf(stderr, "Cerca de la linea %d\n",lineno);
}