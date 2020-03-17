#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "hoc.y"
#include "hoc.h"
#define	code2(c1,c2)	code(c1); code(c2)
#define	code3(c1,c2,c3)	code(c1); code(c2); code(c3)
int bandera=0;
#line 7 "hoc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	Symbol	*sym;	/* symbol table pointer */
	Inst	*inst;	/* machine instruction */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 36 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUMBER 257
#define PRINT 258
#define VAR 259
#define BLTIN 260
#define UNDEF 261
#define WHILE 262
#define IF 263
#define ELSE 264
#define OR 265
#define AND 266
#define GT 267
#define GE 268
#define LT 269
#define LE 270
#define EQ 271
#define NE 272
#define UNARYMINUS 273
#define NOT 274
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    2,    1,    1,    1,
    1,    1,    1,    5,    6,    7,    8,    4,    4,    4,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,
};
static const short yylen[] = {                            2,
    0,    2,    3,    3,    3,    3,    3,    1,    2,    4,
    4,    7,    3,    3,    1,    1,    0,    0,    2,    2,
    5,    5,    5,    5,    1,    1,    4,    3,    3,    3,
    3,    3,    3,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    2,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,   15,   16,    0,    0,    0,
    2,   18,    0,    0,    0,    0,    0,    0,    6,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    4,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,   13,   20,    0,   28,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,   17,   27,    0,    0,    0,    0,
   14,   10,    0,   21,   22,   23,   24,    0,   17,   12,
};
static const short yydgoto[] = {                          1,
   14,   20,   58,   28,   47,   17,   18,   82,
};
static const short yysindex[] = {                         0,
  200,   -7,  138,  -55,  -26,    0,    0, -242,  146,  138,
    0,    0,  138,    9,   15,  124,  -14,  -14,    0,    0,
  756,  138,  138,  -33,  -21,  -67,  -67,  480,  506,    0,
    0,  138,  138,  138,  138,  138,  138,  138,  138,  138,
  138,  138,  138,  138,    0,  138,  -32,  -32,  756,  543,
 -229, -228, -221, -219,    0,    0,    0,  756,    0,  789,
  795,  -38,  -38,  -38,  -38,  -38,  -38,  -24,  -24,  -67,
  -67,  -67,  722,    0,    0,    0,  -66,  -65,  -64,  -63,
    0,    0, -225,    0,    0,    0,    0,  -32,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,  -10,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  782,    0,    0,    0,    0,    0,
  559,    0,    0,    0,    0,    7,   24,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  526,    0,
    0,    0,    0,    0,    0,    0,    0,  645,    0,  488,
  471,  174,  359,  376,  409,  437,  454,   96,  113,   45,
   62,   79,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  533,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -27,   43,  889,    0,   27,    0,    0,  -73,
};
#define YYTABLESIZE 1067
static const short yytable[] = {                         25,
   57,   83,   19,   42,   40,   22,   41,   13,   43,   51,
    8,   52,    9,   23,   24,   90,   34,   42,   30,   74,
   75,   53,   43,   54,   31,   46,   44,   77,   78,   25,
   25,   25,   25,   43,   25,   79,   25,   80,   88,   84,
   85,   86,   87,   15,   48,    0,   34,   34,   34,   34,
    0,   34,    0,   34,   31,   44,    0,    0,    0,    0,
   89,    0,    0,   43,   43,   43,   43,    0,   43,   44,
   43,   32,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   25,   31,   31,   31,   31,   33,   31,
   12,   31,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   32,   32,   32,   32,   29,   32,    0,   32,    0,
    0,    0,   25,    0,   25,    0,    0,    0,   33,   33,
   33,   33,   30,   33,    0,   33,    0,    0,    0,   34,
    0,   34,    0,   45,    0,   29,   29,    0,   29,    0,
   29,    0,    0,    0,    0,    0,   43,    0,   43,    0,
    0,    0,   30,   30,    0,   30,    0,   30,    0,    0,
    0,    0,    0,    0,    0,   42,   40,   31,   41,   31,
   43,    0,    0,    0,    0,    0,    0,   13,    0,    0,
    8,    0,    9,   35,   32,   13,   32,    0,    8,    0,
    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   33,    0,   33,    0,    0,    0,    0,    0,   11,
    0,    0,    0,   35,   35,    0,    0,   44,   29,    0,
   29,    0,    0,    0,    0,    3,    4,    5,    0,    6,
    7,    0,    0,    0,    0,   30,    0,   30,    0,   13,
    0,   10,    8,    0,    9,    0,    0,   25,   25,   25,
    0,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,    0,   25,   34,   34,   34,    0,   34,   34,
   34,   34,   34,   34,   34,   34,   34,   34,   34,    0,
   34,   43,   43,   43,    0,   43,   43,   43,   43,   43,
   43,   43,   43,   43,   43,   43,   35,   43,   35,    0,
    0,    0,   31,   31,   31,    0,   31,   31,   31,   31,
   31,   31,   31,   31,   31,   31,   31,    0,   31,   32,
   32,   32,   12,   32,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,    0,   32,   33,   33,   33,    0,
   33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
   33,    0,   33,   29,   29,   29,    0,   29,   29,   29,
   29,   29,   29,   29,   29,   29,   29,   29,   36,   29,
   30,   30,   30,    0,   30,   30,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   37,   30,    0,   32,   33,
   34,   35,   36,   37,   38,   39,    4,    5,   36,   36,
    0,    0,   25,    0,    4,    5,    0,    0,    0,    0,
    0,   10,    0,    0,    0,   37,   37,    0,   38,   10,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   35,   35,   35,    0,   35,   35,   35,   35,   35,
   35,   35,   35,   35,   35,   35,   39,   35,   38,   38,
    0,    0,    0,    0,    0,    2,    0,    3,    4,    5,
    0,    6,    7,   40,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   10,    0,    0,   39,   39,    0,    0,
   41,   36,    0,   36,    0,    0,    0,    0,    0,   55,
    0,    0,    0,   40,   40,    0,    0,   42,   37,    0,
   37,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   41,   41,    0,    0,    0,    0,    0,    0,    0,   13,
    0,    0,    8,    0,    9,    0,    0,   42,   42,    0,
    0,   38,    0,   38,    0,    7,    0,    0,    0,    0,
    0,    0,   11,    0,    0,    0,   59,   42,   40,    0,
   41,    0,   43,    0,    0,    0,    0,    0,    0,   39,
    0,   39,    0,    0,    0,    7,    7,    0,    9,    0,
    0,    0,   11,    0,    0,   11,   40,   11,   40,    0,
    0,    0,    0,   76,   42,   40,    0,   41,    0,   43,
    0,    0,    0,   41,    0,   41,    0,    0,    9,   44,
    0,    0,   12,    0,   56,    0,    0,    0,    0,    0,
   42,    0,   42,    0,    0,    0,   36,   36,   36,    0,
   36,   36,   36,   36,   36,   36,   36,   36,   36,   36,
   36,    0,   36,   37,   37,   37,   44,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,    7,   37,
    7,    0,    0,    0,    8,   11,    0,   11,    0,    0,
    0,    0,    0,    0,    0,    0,   38,   38,   38,    0,
   38,   38,   38,   38,   38,   38,   38,   38,   38,   38,
   38,    9,   38,    9,    8,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   39,   39,   39,    0,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,    0,
   39,   40,   40,   40,    0,   40,   40,   40,   40,   40,
   40,   40,   40,   40,   40,   40,    0,   40,   41,   41,
   41,    0,   41,   41,   41,   41,   41,    3,    4,    5,
    0,    6,    7,    0,   41,   42,   42,   42,    0,   42,
   42,   42,   42,   10,    0,    0,    0,    0,    0,    0,
    0,   42,   81,   42,   40,    0,   41,    8,   43,    8,
   32,   33,   34,   35,   36,   37,   38,   39,    0,    0,
    0,    0,    0,    7,    7,    7,    0,    7,    7,    7,
   11,   11,   11,    0,   11,   11,    0,   42,   40,    7,
   41,    0,   43,    0,    0,    0,   11,   32,   33,   34,
   35,   36,   37,   38,   39,   44,    9,    9,    9,    0,
    9,    9,    9,   26,   26,    0,   26,    0,   26,    0,
   42,   40,    9,   41,    0,   43,   42,   40,    0,   41,
    0,   43,    0,    0,    0,    0,    0,    0,    0,   44,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   26,    0,    0,    0,    0,
    0,    0,   44,    0,    0,    0,    0,    0,   44,   16,
    0,   21,    0,    0,    0,    0,    0,   26,   27,    0,
    0,   29,    8,    8,    8,    0,    8,    8,    8,    0,
   49,   50,    0,    0,    0,    0,    0,    0,    8,    0,
   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,
   70,   71,   72,    0,   73,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   32,   33,   34,   35,
   36,   37,   38,   39,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   32,   33,   34,   35,   36,   37,   38,   39,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   26,   26,   26,   26,
   26,   26,   26,   26,   33,   34,   35,   36,   37,   38,
   39,   34,   35,   36,   37,   38,   39,
};
static const short yycheck[] = {                         10,
   28,   75,   10,   42,   43,   61,   45,   40,   47,   43,
   43,   45,   45,   40,  257,   89,   10,   42,   10,   47,
   48,   43,   47,   45,   10,   40,   94,  257,  257,   40,
   41,   42,   43,   10,   45,  257,   47,  257,  264,  106,
  106,  106,  106,    1,   18,   -1,   40,   41,   42,   43,
   -1,   45,   -1,   47,   10,   94,   -1,   -1,   -1,   -1,
   88,   -1,   -1,   40,   41,   42,   43,   -1,   45,   94,
   47,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   94,   40,   41,   42,   43,   10,   45,
  123,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   10,   45,   -1,   47,   -1,
   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   40,   41,
   42,   43,   10,   45,   -1,   47,   -1,   -1,   -1,  123,
   -1,  125,   -1,   10,   -1,   40,   41,   -1,   43,   -1,
   45,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,
   -1,   -1,   40,   41,   -1,   43,   -1,   45,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   42,   43,  123,   45,  125,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,
   43,   -1,   45,   10,  123,   40,  125,   -1,   43,   -1,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   10,
   -1,   -1,   -1,   40,   41,   -1,   -1,   94,  123,   -1,
  125,   -1,   -1,   -1,   -1,  258,  259,  260,   -1,  262,
  263,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   40,
   -1,  274,   43,   -1,   45,   -1,   -1,  258,  259,  260,
   -1,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,  274,  258,  259,  260,   -1,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,   -1,
  274,  258,  259,  260,   -1,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  123,  274,  125,   -1,
   -1,   -1,  258,  259,  260,   -1,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,   -1,  274,  258,
  259,  260,  123,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,   -1,  274,  258,  259,  260,   -1,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,   -1,  274,  258,  259,  260,   -1,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,   10,  274,
  258,  259,  260,   -1,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,   10,  274,   -1,  265,  266,
  267,  268,  269,  270,  271,  272,  259,  260,   40,   41,
   -1,   -1,  257,   -1,  259,  260,   -1,   -1,   -1,   -1,
   -1,  274,   -1,   -1,   -1,   40,   41,   -1,   10,  274,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  258,  259,  260,   -1,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,   10,  274,   40,   41,
   -1,   -1,   -1,   -1,   -1,  256,   -1,  258,  259,  260,
   -1,  262,  263,   10,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,   -1,   -1,   40,   41,   -1,   -1,
   10,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   10,
   -1,   -1,   -1,   40,   41,   -1,   -1,   10,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   40,   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   43,   -1,   45,   -1,   -1,   40,   41,   -1,
   -1,  123,   -1,  125,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   10,   -1,   -1,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,  123,
   -1,  125,   -1,   -1,   -1,   40,   41,   -1,   10,   -1,
   -1,   -1,   40,   -1,   -1,   43,  123,   45,  125,   -1,
   -1,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   40,   94,
   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,  258,  259,  260,   -1,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,   -1,  274,  258,  259,  260,   94,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  123,  274,
  125,   -1,   -1,   -1,   10,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,   -1,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  123,  274,  125,   40,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  258,  259,  260,   -1,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,   -1,
  274,  258,  259,  260,   -1,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,   -1,  274,  258,  259,
  260,   -1,  262,  263,  264,  265,  266,  258,  259,  260,
   -1,  262,  263,   -1,  274,  258,  259,  260,   -1,  262,
  263,  264,  265,  274,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,   41,   42,   43,   -1,   45,  123,   47,  125,
  265,  266,  267,  268,  269,  270,  271,  272,   -1,   -1,
   -1,   -1,   -1,  258,  259,  260,   -1,  262,  263,  264,
  258,  259,  260,   -1,  262,  263,   -1,   42,   43,  274,
   45,   -1,   47,   -1,   -1,   -1,  274,  265,  266,  267,
  268,  269,  270,  271,  272,   94,  258,  259,  260,   -1,
  262,  263,  264,   42,   43,   -1,   45,   -1,   47,   -1,
   42,   43,  274,   45,   -1,   47,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,
   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,   94,    1,
   -1,    3,   -1,   -1,   -1,   -1,   -1,    9,   10,   -1,
   -1,   13,  258,  259,  260,   -1,  262,  263,  264,   -1,
   22,   23,   -1,   -1,   -1,   -1,   -1,   -1,  274,   -1,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,
   42,   43,   44,   -1,   46,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  265,  266,  267,  268,
  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  265,  266,  267,  268,  269,  270,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  265,  266,  267,  268,
  269,  270,  271,  272,  266,  267,  268,  269,  270,  271,
  272,  267,  268,  269,  270,  271,  272,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",
0,0,0,0,0,0,0,0,0,0,0,"'j'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"NUMBER","PRINT","VAR","BLTIN","UNDEF","WHILE","IF","ELSE","OR",
"AND","GT","GE","LT","LE","EQ","NE","UNARYMINUS","NOT","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list stmt '\\n'",
"list : list expr '\\n'",
"list : list error '\\n'",
"asgn : VAR '=' expr",
"stmt : expr",
"stmt : PRINT expr",
"stmt : while cond stmt end",
"stmt : if cond stmt end",
"stmt : if cond stmt end ELSE stmt end",
"stmt : '{' stmtlist '}'",
"cond : '(' expr ')'",
"while : WHILE",
"if : IF",
"end :",
"stmtlist :",
"stmtlist : stmtlist '\\n'",
"stmtlist : stmtlist stmt",
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
"expr : expr '^' expr",
"expr : '-' expr",
"expr : expr GT expr",
"expr : expr GE expr",
"expr : expr LT expr",
"expr : expr LE expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 85 "hoc.y"
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
yylex()		/* hoc5 */
{
	while ((c=getchar()) == ' ' || c == '\t')
		;
	if (c == EOF)
		return 0;
	if (c == '.' || isdigit(c)/*||c=='+'||c=='-'*/) {	/* number */
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
	switch (c) {
	case '>':	return follow('=', GE, GT);		break;
	case '<':	return follow('=', LE, LT); 	break;
	case '=':	return follow('=', EQ, '=');	break;
	case '!':	return follow('=', NE, NOT);	break;
	case '|':	return follow('|', OR, '|');	break;
	case '&':	return follow('&', AND, '&');	break;
	case '\n':	lineno++; return '\n';			break;
	default:	return c;						break;
	}
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
	init();
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
#line 562 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
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

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
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
	{ code(STOP); return 1; }
break;
case 5:
#line 26 "hoc.y"
	{ code2(print, STOP); return 1; }
break;
case 6:
#line 27 "hoc.y"
	{ yyerrok; }
break;
case 7:
#line 29 "hoc.y"
	{ yyval.inst=yystack.l_mark[0].inst; code3(varpush,(Inst)yystack.l_mark[-2].sym,assign); }
break;
case 8:
#line 31 "hoc.y"
	{ code(pop); }
break;
case 9:
#line 32 "hoc.y"
	{ code(print); yyval.inst = yystack.l_mark[0].inst; }
break;
case 10:
#line 33 "hoc.y"
	{
		(yystack.l_mark[-3].inst)[1] = (Inst)yystack.l_mark[-1].inst;	/* body of loop */
		(yystack.l_mark[-3].inst)[2] = (Inst)yystack.l_mark[0].inst; }
break;
case 11:
#line 36 "hoc.y"
	{	/* else-less if */
		(yystack.l_mark[-3].inst)[1] = (Inst)yystack.l_mark[-1].inst;	/* thenpart */
		(yystack.l_mark[-3].inst)[3] = (Inst)yystack.l_mark[0].inst; }
break;
case 12:
#line 39 "hoc.y"
	{  /* if with else */
		(yystack.l_mark[-6].inst)[1] = (Inst)yystack.l_mark[-4].inst;	/* thenpart */
		(yystack.l_mark[-6].inst)[2] = (Inst)yystack.l_mark[-1].inst;	/* elsepart */
		(yystack.l_mark[-6].inst)[3] = (Inst)yystack.l_mark[0].inst; }
break;
case 13:
#line 43 "hoc.y"
	{ yyval.inst = yystack.l_mark[-1].inst; }
break;
case 14:
#line 45 "hoc.y"
	{ code(STOP); yyval.inst = yystack.l_mark[-1].inst; }
break;
case 15:
#line 47 "hoc.y"
	{ yyval.inst = code3(whilecode, STOP, STOP); }
break;
case 16:
#line 49 "hoc.y"
	{ yyval.inst=code(ifcode); code3(STOP, STOP, STOP); }
break;
case 17:
#line 51 "hoc.y"
	{ code(STOP); yyval.inst = progp; }
break;
case 18:
#line 53 "hoc.y"
	{ yyval.inst = progp; }
break;
case 21:
#line 58 "hoc.y"
	{ yyval.inst = code3(constpush, (Inst)yystack.l_mark[-3].sym,(Inst)yystack.l_mark[-1].sym); }
break;
case 22:
#line 59 "hoc.y"
	{(yystack.l_mark[-1].sym)->u.val*=-1; yyval.inst = code3(constpush, (Inst)yystack.l_mark[-3].sym,(Inst)yystack.l_mark[-1].sym); }
break;
case 23:
#line 60 "hoc.y"
	{(yystack.l_mark[-3].sym)->u.val*=-1;  yyval.inst = code3(constpush, (Inst)yystack.l_mark[-3].sym,(Inst)yystack.l_mark[-1].sym); }
break;
case 24:
#line 61 "hoc.y"
	{(yystack.l_mark[-3].sym)->u.val*=-1; (yystack.l_mark[-1].sym)->u.val*=-1;  yyval.inst = code3(constpush, (Inst)yystack.l_mark[-3].sym,(Inst)yystack.l_mark[-1].sym); }
break;
case 25:
#line 62 "hoc.y"
	{ yyval.inst = code3(varpush, (Inst)yystack.l_mark[0].sym, eval); }
break;
case 27:
#line 66 "hoc.y"
	{ yyval.inst = yystack.l_mark[-1].inst; code2(bltin,(Inst)yystack.l_mark[-3].sym->u.ptr); }
break;
case 28:
#line 67 "hoc.y"
	{ yyval.inst = yystack.l_mark[-1].inst; }
break;
case 29:
#line 68 "hoc.y"
	{ code(add); }
break;
case 30:
#line 69 "hoc.y"
	{ code(sub); }
break;
case 31:
#line 70 "hoc.y"
	{ code(mul); }
break;
case 32:
#line 71 "hoc.y"
	{ code(div); }
break;
case 33:
#line 72 "hoc.y"
	{ code (power); }
break;
case 34:
#line 73 "hoc.y"
	{ yyval.inst = yystack.l_mark[0].inst; code(negate); }
break;
case 35:
#line 74 "hoc.y"
	{ code(gt); }
break;
case 36:
#line 75 "hoc.y"
	{ code(ge); }
break;
case 37:
#line 76 "hoc.y"
	{ code(lt); }
break;
case 38:
#line 77 "hoc.y"
	{ code(le); }
break;
case 39:
#line 78 "hoc.y"
	{ code(eq); }
break;
case 40:
#line 79 "hoc.y"
	{ code(ne); }
break;
case 41:
#line 80 "hoc.y"
	{ code(and); }
break;
case 42:
#line 81 "hoc.y"
	{ code(or); }
break;
case 43:
#line 82 "hoc.y"
	{ yyval.inst = yystack.l_mark[0].inst; code(not); }
break;
#line 927 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
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
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
