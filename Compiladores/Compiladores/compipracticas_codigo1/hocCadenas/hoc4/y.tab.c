#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 1 "hoc4.y"

#include<stdlib.h>
#include "hoc.h"
#define code2(c1,c2)     code(c1); code(c2)
#define code3(c1,c2,c3) code(c1); code(c2); code(c3)

NodoL *symlist = (NodoL *)NULL;
NodoL **globals = (NodoL **)NULL;

void warning(char *s, char *t);
void yyerror(char *s);
void execerror(char *s, char *t);

#line 15 "hoc4.y"
typedef union {
	Simbolo *sym;
	Inst *inst;
} YYSTYPE;
#line 25 "y.tab.c"
#define NUMBER 257
#define VAR 258
#define BLTIN 259
#define INDEF 260
#define UNARYMINUS 261
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    0,    1,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    3,    1,    1,    1,    4,
    3,    3,    3,    3,    3,    3,    3,    2,
};
short yydefred[] = {                                      1,
    0,    0,    7,    0,    0,    0,    2,    0,    0,    0,
    5,    0,    0,    9,    0,    0,    3,    0,    0,    0,
    0,    0,    4,    0,    0,    0,   11,    0,    0,    0,
    0,    0,    0,   10,
};
short yydgoto[] = {                                       1,
   14,   10,
};
short yysindex[] = {                                      0,
  -10,   -6,    0,  -40,  -12,  -39,    0,  -39,   23,    2,
    0,  -39,  -39,    0,  -35,  -34,    0,  -39,  -39,  -39,
  -39,  -39,    0,  -39,  -20,  -27,    0,  -18,  -18,  -35,
  -35,  -35,  -20,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,   -5,    0,    0,    0,    0,    9,    0,
    0,    0,    0,    0,   21,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   16,    0,    0,   67,   68,   38,
   45,   59,   24,    0,
};
short yygindex[] = {                                      0,
   40,  108,
};
#define YYTABLESIZE 249
short yytable[] = {                                       7,
    8,   24,   24,   11,    8,    6,   27,   20,   18,   24,
   19,   23,   21,   34,   20,   18,   24,   19,   24,   21,
   12,   20,   18,   20,   19,    6,   21,   13,   21,    8,
   18,    8,   17,   16,    6,    8,    8,    8,   24,    8,
    9,    8,    0,   20,   18,    9,   19,   14,   21,    0,
    9,    9,    0,    9,   15,    9,    6,    0,   22,   22,
    0,   18,   18,   18,   16,   18,   22,   18,   17,    0,
    0,    0,    0,   22,    0,   22,   12,   13,   14,   14,
   14,    0,   14,    0,   14,   15,   15,   15,    8,   15,
    0,   15,    0,    0,    0,   22,    0,    0,    0,   17,
   17,   17,    9,   17,    0,   17,    0,   12,   13,   12,
   13,   12,   13,   15,    0,   16,    0,    0,    0,   25,
   26,    0,    0,    0,    0,   28,   29,   30,   31,   32,
    0,   33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,    4,    5,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    3,    4,    5,
};
short yycheck[] = {                                      10,
   40,   37,   37,   10,   10,   45,   41,   42,   43,   37,
   45,   10,   47,   41,   42,   43,   37,   45,   37,   47,
   61,   42,   43,   42,   45,   10,   47,   40,   47,   40,
   10,   37,   10,   10,   45,   41,   42,   43,   37,   45,
    1,   47,   -1,   42,   43,   37,   45,   10,   47,   -1,
   42,   43,   -1,   45,   10,   47,   41,   -1,   94,   94,
   -1,   41,   42,   43,   41,   45,   94,   47,   10,   -1,
   -1,   -1,   -1,   94,   -1,   94,   10,   10,   41,   42,
   43,   -1,   45,   -1,   47,   41,   42,   43,   94,   45,
   -1,   47,   -1,   -1,   -1,   94,   -1,   -1,   -1,   41,
   42,   43,   94,   45,   -1,   47,   -1,   41,   41,   43,
   43,   45,   45,    6,   -1,    8,   -1,   -1,   -1,   12,
   13,   -1,   -1,   -1,   -1,   18,   19,   20,   21,   22,
   -1,   24,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 261
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'%'",0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"NUMBER","VAR","BLTIN","INDEF","UNARYMINUS",
};
char *yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list expr '\\n'",
"list : list error '\\n'",
"asgn : VAR '=' expr",
"expr : NUMBER",
"expr : VAR",
"expr : asgn",
"expr : BLTIN '(' expr ')'",
"expr : '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '^' expr",
"expr : '-' expr",
};
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 57 "hoc4.y"

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











#line 263 "y.tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d (%s)\n",
                    yystate, yytable[yyn],yyrule[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 3:
#line 28 "hoc4.y"
{ code2( strdup("pop1"), strdup("STOP") ); 
                       return 1; }
break;
case 4:
#line 30 "hoc4.y"
{ code2(strdup("print"), strdup("STOP")); 
                       return 1; }
break;
case 5:
#line 32 "hoc4.y"
{ yyerrok; }
break;
case 6:
#line 34 "hoc4.y"
{ 
      code3(strdup("varpush"), (Inst)yyvsp[-2].sym, strdup("assign")); 
   }
break;
case 7:
#line 38 "hoc4.y"
{  /*puts("NUMBER"); */
                 code2(strdup("constpush"), (Inst)yyvsp[0].sym); 
              }
break;
case 8:
#line 41 "hoc4.y"
{  
                 code3(strdup("varpush"), (Inst)yyvsp[0].sym, strdup("eval"));
              }
break;
case 10:
#line 45 "hoc4.y"
{ 
              code2(strdup("bltin"), (Inst)yyvsp[-3].sym->u.ptr);
           }
break;
case 12:
#line 49 "hoc4.y"
{ code(strdup("add")); }
break;
case 13:
#line 50 "hoc4.y"
{ code(strdup("sub")); }
break;
case 14:
#line 51 "hoc4.y"
{ code(strdup("mul")); }
break;
case 15:
#line 52 "hoc4.y"
{ code(strdup("div")); }
break;
case 16:
#line 53 "hoc4.y"
{ code(strdup("mod")); }
break;
case 17:
#line 54 "hoc4.y"
{ code(strdup("power")); }
break;
case 18:
#line 55 "hoc4.y"
{ code(strdup("negate")); }
break;
#line 469 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
