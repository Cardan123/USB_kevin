#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "hoc.y"
#include "hoc.h"
#define	code2(c1,c2)	code(c1); code(c2)
#define	code3(c1,c2,c3)	code(c1); code(c2); code(c3)
int bandera=0;
#line 7 "hoc.y"
typedef union {
	Symbol	*sym;	/* symbol table pointer */
	Inst	*inst;	/* machine instruction */
} YYSTYPE;
#line 16 "y.tab.c"
#define NUMBER 257
#define PRINT 258
#define VAR 259
#define BLTIN 260
#define UNDEF 261
#define OR 262
#define AND 263
#define GT 264
#define GE 265
#define LT 266
#define LE 267
#define EQ 268
#define NE 269
#define UNARYMINUS 270
#define NOT 271
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    0,    1,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    3,    5,    5,    5,    5,
    1,    1,    4,    3,    3,    3,    3,    3,
};
short yydefred[] = {                                      1,
    0,    0,    0,    0,    0,    0,    2,    0,    0,    0,
    5,    0,    0,    0,    0,   12,    0,    3,    0,    0,
    0,    0,    4,    0,    0,    0,    0,    0,    0,   14,
    0,    0,   17,   18,   13,    0,    0,    0,    0,    7,
    8,    9,   10,
};
short yydgoto[] = {                                       1,
   16,   10,
};
short yysindex[] = {                                      0,
  -10,   -8,  -52,  -24, -235, -229,    0,  -39,   22,    1,
    0,  -39,  -39,  -22,  -14,    0,   14,    0,  -39,  -39,
  -39,  -39,    0,  -35,   21, -218, -216, -206, -204,    0,
  -27,  -27,    0,    0,    0,  -48,  -46,  -41,  -33,    0,
    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,   -5,    0,    0,    0,    0,    0,   27,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -7,    0,    0,    0,    0,    0,    0,
    4,    9,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
short yygindex[] = {                                      0,
   66,    5,
};
#define YYTABLESIZE 250
short yytable[] = {                                       7,
    8,   11,    6,    5,   11,    6,   21,   19,   12,   20,
   23,   22,   17,   15,   21,   13,   24,   25,   16,   22,
   26,   14,   27,   31,   32,   33,   34,   15,   28,    8,
   29,   18,    5,    6,    6,   11,   11,   11,   36,   11,
   37,   11,   21,   19,   15,   20,   15,   22,   15,   16,
   38,   16,   39,   16,   30,   21,   19,   40,   20,   41,
   22,   35,   21,   19,   42,   20,    9,   22,   12,   12,
    0,   12,   43,   12,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    0,    0,    3,    4,
};
short yycheck[] = {                                      10,
   40,   10,   10,   43,   10,   45,   42,   43,   61,   45,
   10,   47,    8,   10,   42,   40,   12,   13,   10,   47,
   43,  257,   45,   19,   20,   21,   22,  257,   43,   40,
   45,   10,   43,   41,   45,   41,   42,   43,  257,   45,
  257,   47,   42,   43,   41,   45,   43,   47,   45,   41,
  257,   43,  257,   45,   41,   42,   43,  106,   45,  106,
   47,   41,   42,   43,  106,   45,    1,   47,   42,   43,
   -1,   45,  106,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,   -1,   -1,  259,  260,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",
0,0,0,0,0,0,0,0,0,0,0,"'j'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"NUMBER","PRINT","VAR","BLTIN","UNDEF","OR","AND","GT","GE","LT","LE",
"EQ","NE","UNARYMINUS","NOT",
};
char *yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list expr '\\n'",
"list : list error '\\n'",
"asgn : VAR '=' expr",
"expr : '+' NUMBER '+' NUMBER 'j'",
"expr : '+' NUMBER '-' NUMBER 'j'",
"expr : '-' NUMBER '+' NUMBER 'j'",
"expr : '-' NUMBER '-' NUMBER 'j'",
"expr : VAR",
"expr : asgn",
"expr : BLTIN '(' expr ')'",
"expr : '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
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
#line 47 "hoc.y"
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
#line 280 "y.tab.c"
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
case 2:
#line 23 "hoc.y"
{bandera=0;}
break;
case 3:
#line 24 "hoc.y"
{ code2(pop, STOP); return 1; }
break;
case 4:
#line 25 "hoc.y"
{ code2(print, STOP); return 1; }
break;
case 5:
#line 26 "hoc.y"
{ yyerrok; }
break;
case 6:
#line 28 "hoc.y"
{ yyval.inst=yyvsp[0].inst; code3(varpush,(Inst)yyvsp[-2].sym,assign); }
break;
case 7:
#line 31 "hoc.y"
{ yyval.inst = code3(constpush, (Inst)yyvsp[-3].sym,(Inst)yyvsp[-1].sym); }
break;
case 8:
#line 32 "hoc.y"
{(yyvsp[-1].sym)->u.val*=-1; yyval.inst = code3(constpush, (Inst)yyvsp[-3].sym,(Inst)yyvsp[-1].sym); }
break;
case 9:
#line 33 "hoc.y"
{(yyvsp[-3].sym)->u.val*=-1;  yyval.inst = code3(constpush, (Inst)yyvsp[-3].sym,(Inst)yyvsp[-1].sym); }
break;
case 10:
#line 34 "hoc.y"
{(yyvsp[-3].sym)->u.val*=-1; (yyvsp[-1].sym)->u.val*=-1;  yyval.inst = code3(constpush, (Inst)yyvsp[-3].sym,(Inst)yyvsp[-1].sym); }
break;
case 11:
#line 35 "hoc.y"
{ yyval.inst = code3(varpush, (Inst)yyvsp[0].sym, eval); }
break;
case 13:
#line 39 "hoc.y"
{ yyval.inst = yyvsp[-1].inst; code2(bltin,(Inst)yyvsp[-3].sym->u.ptr); }
break;
case 14:
#line 40 "hoc.y"
{ yyval.inst = yyvsp[-1].inst; }
break;
case 15:
#line 41 "hoc.y"
{ code(add); }
break;
case 16:
#line 42 "hoc.y"
{ code(sub); }
break;
case 17:
#line 43 "hoc.y"
{ code(mul); }
break;
case 18:
#line 44 "hoc.y"
{ code(div); }
break;
#line 484 "y.tab.c"
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
