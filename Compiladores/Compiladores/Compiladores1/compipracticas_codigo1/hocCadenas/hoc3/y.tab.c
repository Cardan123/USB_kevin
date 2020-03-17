#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 1 "hoc2.y"

#include <stdio.h>
#include <math.h>
#include "hoc.h"

NodoL *symlist = (NodoL *)NULL;
NodoL **globals = (NodoL **)NULL;

void yyerror (char *s);
int yylex ();
void warning(char *s, char *t);
void execerror(char *s, char *t);
void fpecatch();

void *(*add_)(void *dob1, void *dob2)=addDoble;
void *(*sub_)(void *dob1, void *dob2)=subDoble;
void *(*mul_)(void *dob1, void *dob2)=mulDoble;
void *(*div__)(void *dob1, void *dob2)=div_Doble;
void *(*power_)(void *dob1, void *dob2)=powerDoble;
void (*print_)(void *dob)=printDoble;
#line 22 "hoc2.y"
typedef union {
   void *val;
   Simbolo *sym;
} YYSTYPE;
#line 32 "y.tab.c"
#define NUMBER 257
#define VAR 258
#define BLTIN 259
#define INDEF 260
#define UNARYMINUS 261
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    0,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    3,    1,    1,    1,    4,
    3,    3,    3,    3,    3,    3,    2,
};
short yydefred[] = {                                      1,
    0,    0,    7,    0,    0,    0,    2,    0,    0,    0,
    5,    0,    0,    0,    9,    0,    0,    0,    0,    0,
    0,    4,    3,    0,    0,   16,    0,    0,    0,    0,
    0,   10,
};
short yydgoto[] = {                                       1,
    9,   15,
};
short yysindex[] = {                                      0,
  -10,   -6,    0,  -48,  -16,  -39,    0,  -39,    1,   10,
    0,  -39,  -39,  -68,    0,  -33,  -39,  -39,  -39,  -39,
  -39,    0,    0,  -20,  -26,    0,  -40,  -40,  -68,  -68,
  -68,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,   -5,    0,    0,    0,    0,    0,  -14,
    0,    0,    0,    8,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -7,    0,    0,   42,   61,   22,   49,
   56,    0,
};
short yygindex[] = {                                      0,
   99,   38,
};
#define YYTABLESIZE 249
short yytable[] = {                                       7,
    8,   19,    6,   11,    8,    6,   20,   26,   19,   17,
   22,   18,   12,   20,   32,   19,   17,   17,   18,   23,
   20,   19,   17,   13,   18,   21,   20,    9,    9,    8,
    9,   13,    9,    6,    6,    8,    8,    8,   10,    8,
    0,    8,   19,   17,    0,   18,    0,   20,   17,   17,
   17,   11,   17,   21,   17,    0,    0,    0,   14,    0,
   21,    0,   13,   13,   13,   15,   13,   21,   13,    0,
   12,    0,    0,   21,    0,    0,    0,    0,    0,    9,
    0,    0,   11,    0,   11,    0,   11,    0,    8,   14,
   14,   14,    0,   14,   21,   14,   15,   15,   15,    0,
   15,   12,   15,   12,   14,   12,   16,    0,    0,    0,
   24,   25,    0,    0,    0,   27,   28,   29,   30,   31,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
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
   40,   42,   10,   10,   10,   45,   47,   41,   42,   43,
   10,   45,   61,   47,   41,   42,   43,   10,   45,   10,
   47,   42,   43,   40,   45,   94,   47,   42,   43,   40,
   45,   10,   47,   41,   45,   41,   42,   43,    1,   45,
   -1,   47,   42,   43,   -1,   45,   -1,   47,   41,   42,
   43,   10,   45,   94,   47,   -1,   -1,   -1,   10,   -1,
   94,   -1,   41,   42,   43,   10,   45,   94,   47,   -1,
   10,   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,   94,
   -1,   -1,   41,   -1,   43,   -1,   45,   -1,   94,   41,
   42,   43,   -1,   45,   94,   47,   41,   42,   43,   -1,
   45,   41,   47,   43,    6,   45,    8,   -1,   -1,   -1,
   12,   13,   -1,   -1,   -1,   17,   18,   19,   20,   21,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"NUMBER","VAR","BLTIN","INDEF","UNARYMINUS",
};
char *yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list exp '\\n'",
"list : list error '\\n'",
"asgn : VAR '=' exp",
"exp : NUMBER",
"exp : VAR",
"exp : asgn",
"exp : BLTIN '(' exp ')'",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '^' exp",
"exp : '(' exp ')'",
"exp : '-' exp",
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
#line 59 "hoc2.y"

#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;
char *progname;
int lineno = 0;

void main (int argc, char *argv[]){
   progname=argv[0];
   init();
   setjmp(begin);
   signal(SIGFPE, fpecatch);
   yyparse ();
}
void execerror(char *s, char *t){
	warning(s, t);
	longjmp(begin, 0);
}
void fpecatch(){
	execerror("excepcion de punto flotante", (char *)0);
}
void yyerror (char *s) {
   warning(s, (char *) 0);
}
void warning(char *s, char *t){
   fprintf (stderr, "%s: %s", progname, s);
   if(t)
      fprintf (stderr, " %s", t);
   fprintf (stderr, "cerca de la linea %d\n", lineno);
}




#line 225 "y.tab.c"
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
case 4:
#line 39 "hoc2.y"
{ print_(yyvsp[-1].val); }
break;
case 5:
#line 40 "hoc2.y"
{ yyerrok; }
break;
case 6:
#line 42 "hoc2.y"
{ yyval.val=yyvsp[-2].sym->u.val=yyvsp[0].val; yyvsp[-2].sym->tipo=VAR;}
break;
case 7:
#line 44 "hoc2.y"
{ yyval.val = yyvsp[0].val; }
break;
case 8:
#line 45 "hoc2.y"
{ if(yyvsp[0].sym->tipo == INDEF)
		execerror("variable no definida",yyvsp[0].sym->nombre);
		yyval.val=yyvsp[0].sym->u.val;
	 }
break;
case 10:
#line 50 "hoc2.y"
{ yyval.val=(yyvsp[-3].sym->u.ptr)(yyvsp[-1].val); }
break;
case 11:
#line 51 "hoc2.y"
{ yyval.val = add_(yyvsp[-2].val, yyvsp[0].val); }
break;
case 12:
#line 52 "hoc2.y"
{ yyval.val = sub_(yyvsp[-2].val, yyvsp[0].val); }
break;
case 13:
#line 53 "hoc2.y"
{ yyval.val = mul_(yyvsp[-2].val, yyvsp[0].val); }
break;
case 14:
#line 54 "hoc2.y"
{ yyval.val = div__(yyvsp[-2].val,yyvsp[0].val); }
break;
case 15:
#line 55 "hoc2.y"
{ yyval.val=power_(yyvsp[-2].val, yyvsp[0].val);}
break;
case 16:
#line 56 "hoc2.y"
{ yyval.val = yyvsp[-1].val;}
break;
case 17:
#line 57 "hoc2.y"
{ yyval.val= negateDoble(yyvsp[0].val) ; }
break;
#line 420 "y.tab.c"
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
