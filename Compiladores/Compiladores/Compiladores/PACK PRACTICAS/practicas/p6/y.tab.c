#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "hoc.y"
#include "hoc.h"
#define code2(c1,c2)     code(c1); code(c2)
#define code3(c1,c2,c3)  code(c1); code(c2); code(c3)
int indef;
#line 7 "hoc.y"
typedef union {
Symbol     *sym;      /*   Apuntador a la tabla de símbolos */
Inst       *inst;     /*   instrucción de máquina */
int        narg;      /*   número de argumentos */
} YYSTYPE;
#line 17 "y.tab.c"
#define NUMBER 257
#define STRING 258
#define PRINT 259
#define VAR 260
#define BLTIN 261
#define UNDEF 262
#define WHILE 263
#define IF 264
#define ELSE 265
#define FOR 266
#define FUNCTION 267
#define PROCEDURE 268
#define RETURN 269
#define FUNC 270
#define PROC 271
#define READ 272
#define ARG 273
#define OR 274
#define AND 275
#define GT 276
#define GE 277
#define LT 278
#define LE 279
#define EQ 280
#define NE 281
#define UNARYMINUS 282
#define NOT 283
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    0,    0,    0,    3,    3,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,   12,
   13,   14,   11,    6,    7,    8,    9,   10,    5,    5,
    5,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    4,    4,    4,
   18,   17,   19,   17,   15,   15,   15,   16,   16,   16,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    3,    3,    3,    3,    1,
    1,    2,    5,    2,    4,    4,    7,    3,    6,    3,
    2,    2,    1,    3,    1,    1,    0,    0,    0,    2,
    2,    5,    5,    5,    5,    1,    1,    1,    5,    4,
    4,    3,    3,    3,    3,    3,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    1,    1,    3,    3,
    0,    6,    0,    6,    1,    1,    1,    0,    1,    3,
};
short yydefred[] = {                                      1,
    0,    0,    0,    0,    0,   25,   26,   23,   27,   27,
    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,
   29,    0,    0,    0,    0,    0,    0,    0,    7,   58,
    0,   38,    0,    0,    0,    0,    0,    0,   65,   66,
   67,   61,   63,    0,    0,    0,    0,   47,   56,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    6,    5,    4,    0,    0,    0,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,   30,   18,    0,   31,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   45,   46,    0,   28,   28,    0,    0,   21,    0,    0,
   60,    0,   41,    0,    0,    0,    0,    0,   40,    0,
    0,    0,    0,   24,   15,    0,    0,    0,    0,   39,
    0,   13,    0,    0,   32,   33,   34,   35,    0,   20,
   22,   28,    0,   62,   64,   28,   19,   17,
};
short yydgoto[] = {                                       1,
   89,   23,   32,   33,   51,   68,   25,   26,   36,  125,
   27,  110,   71,  129,   42,  115,   28,   78,   79,
};
short yysindex[] = {                                      0,
  509,   12,  157,  -50,  -17,    0,    0,    0,    0,    0,
  559, -255, -255,  -12,  -32, -216,  176,  559,    0,  559,
    0,  133,   35,   36,   21,   21,   23,   38,    0,    0,
 1035,    0,   20,  559,  559,   25,   26, 1035,    0,    0,
    0,    0,    0, -193,  559,    8,    9,    0,    0,  841,
  803,  559,  559,  559,  559,  559,  559,  559,  559,  559,
  559,  559,  559,    0,    0,    0,  559,  -37,  -37, -256,
   10,    0,  539, 1035,  895,  559,  559,   28,   30,   31,
 1035, -184, -181, -180, -179,    0,    0,    0, 1035,    0,
 1098,  573,  -27,  -27,  -27,  -27,  -27,  -27,  -28,  -28,
    0,    0,  907,    0,    0,  -50,  -32,    0,  559,  559,
    0, 1035,    0, 1035,  -34,  -20,   41,   47,    0,  -16,
  -13,  -11,   -8,    0,    0, -186,  996,  951,  -37,    0,
  559,    0,  -37,  -37,    0,    0,    0,    0,  -37,    0,
    0,    0, 1035,    0,    0,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,  -10,    0,    0,    0,    0,    0,    0,
  300,    0,    0,    0,   15,    0,    0,    0,    0,    0,
    0,    0,    0, 1062,    0,    0,    0,    0,    0,    0,
  714,    0,  785,    0,    0,    0,    0,  894,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  743,    0,   -5,   -5,    0,    0,    0,
  764,    0,    0,    0,    0,    0,    0,    0,  936,    0,
  483,  462,   90,  115,  362,  387,  412,  437,   40,   65,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  830,    0,   -1,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  866,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    3,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
 1346,  -42,    1,    0,    0,   63,    0,    0,   84, -104,
    0,    0,    0,    0,   83,   24,    0,    0,    0,
};
#define YYTABLESIZE 1477
short yytable[] = {                                      36,
  126,   24,   20,  106,   39,   16,  130,   17,   90,  131,
   34,   40,   41,   62,   62,   60,  107,   61,   63,   63,
  132,   29,   35,  131,   37,  104,  105,   44,   45,   36,
   36,   36,   36,   36,   36,   68,   36,  147,   68,   69,
   46,  148,   69,   70,   65,   66,   70,   72,   36,   43,
   82,   84,   83,   85,   37,   37,   37,   37,   37,   37,
   67,   37,   70,   73,   76,   77,   80,  117,  109,  118,
  108,  119,  120,   37,   44,  121,  122,  123,  139,   43,
   43,  133,   43,   43,   43,   21,  142,  134,   69,  135,
  144,  145,  136,   37,  137,   43,  146,  138,   43,   48,
  116,    0,    0,    0,   44,   44,    0,   44,   44,   44,
    0,    0,   36,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,   44,   49,    0,    0,    0,    0,   48,
   48,    0,    0,   48,    0,    0,    0,   37,    0,   37,
    0,    0,   64,    0,    0,    0,    0,    0,   48,    0,
    0,    0,    0,    0,   49,   49,    0,    0,   49,    0,
    0,    0,   43,    0,   43,    0,    0,    0,    0,    0,
    0,    0,    0,   49,   62,   60,    0,   61,    0,   63,
    0,    0,    0,    0,    0,    0,    0,   44,    0,   44,
    0,    0,    0,    0,    0,    0,   20,    0,    0,   16,
    0,   17,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,    0,   48,   20,    0,    0,   16,    0,
   17,    3,    4,    5,    0,    6,    7,    0,    8,    9,
   10,   11,    0,    0,   14,   15,    0,   49,    0,   49,
    0,    0,    0,    0,    0,   18,    0,    0,   36,   36,
   36,    0,   36,   36,   36,   36,   36,   36,   36,    0,
    0,   36,   36,   36,   36,   36,   36,   36,   36,   36,
   36,    0,   36,   37,   37,   37,    0,   37,   37,   37,
   37,   37,   37,   37,    0,    0,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,    0,   37,   43,   43,
   43,    0,   43,   43,   43,   43,   43,   43,   43,   11,
    0,   43,   43,   43,   43,   43,   43,   43,   43,   43,
   43,    0,   43,   44,   44,   44,    0,   44,   44,   44,
   44,   44,   44,   44,    0,    0,   44,   44,   44,   44,
   44,   44,   44,   44,   44,   44,    0,   44,   48,   48,
   48,    0,   48,   48,   48,   48,   48,   48,   48,    0,
    0,   48,   48,   48,   48,   48,   48,   48,   48,   48,
   48,   50,   48,   49,   49,   49,    0,   49,   49,   49,
   49,   49,   49,   49,    0,    0,   49,   49,   49,   49,
   49,   49,   49,   49,   49,   49,   51,   49,    0,    0,
    0,   50,   50,    0,    0,   50,   52,   53,   54,   55,
   56,   57,   58,   59,   30,    0,    4,    5,    0,    0,
   50,   52,   11,    9,   11,    0,   51,   51,   14,   15,
   51,    0,   47,    0,    0,    4,    5,    0,    0,   18,
    0,    0,    9,    0,    0,   51,   53,   14,   15,    0,
    0,   52,   52,    0,    0,   52,    0,    0,   18,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   52,   54,    0,    0,    0,    0,   53,   53,    0,    0,
   53,    0,    0,    0,   50,    0,   50,    0,    0,    0,
    0,    0,   55,    0,    0,   53,    0,    0,    0,    0,
    0,   54,   54,    0,    0,   54,    0,    0,    0,   51,
    0,   51,    0,    0,    0,    0,    0,    0,   19,    0,
   54,    0,   55,   55,    0,    0,   55,    0,    0,    0,
    0,    0,    0,    0,   52,    0,   52,    0,    0,    0,
    0,   55,    0,    0,    0,    0,    0,    0,   20,    0,
    0,   16,    0,   17,    0,    0,    0,    0,   11,   53,
    0,   53,   11,   11,   11,   11,    0,   11,   11,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,    0,
    0,   16,    0,   17,   54,    0,   54,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,    0,
    0,   16,    0,   17,    0,   55,    0,   55,    0,    0,
    0,    0,    0,    0,   62,   60,    0,   61,    0,   63,
   50,   50,   50,    0,   50,   50,   50,   50,   50,   50,
   50,   21,    0,   50,   50,   50,   50,   50,   50,   50,
   50,   50,   50,    0,   50,   51,   51,   51,    0,   51,
   51,   51,   51,   51,   51,   51,    0,    0,   51,   51,
   51,   51,   51,   51,   51,   51,   51,   51,    0,   51,
   52,   52,   52,    0,   52,   52,   52,   52,   52,   52,
   52,    0,    0,   52,   52,   52,   52,   52,   52,   52,
   52,   52,   52,    0,   52,   53,   53,   53,    0,   53,
   53,   53,   53,   53,   53,   53,    0,    0,   53,   53,
   53,   53,   53,   53,   53,   53,   53,   53,    0,   53,
   54,   54,   54,   57,   54,   54,   54,   54,   54,   54,
   54,    0,    0,   54,   54,   54,   54,    0,    0,    0,
    0,   55,   55,   55,   54,   55,   55,   55,   55,   55,
   55,   55,    8,   57,   55,   55,   55,   57,    0,    0,
    0,    0,    0,    0,    2,   55,    0,    3,    4,    5,
    0,    6,    7,    9,    8,    9,   10,   11,   12,   13,
   14,   15,    8,    8,    0,    0,    8,    0,    0,    0,
    0,   18,    0,    0,   14,    0,  111,    0,    4,    5,
    0,    8,    0,    9,    9,    9,    0,    9,    0,    0,
   14,   15,   87,    0,    0,    0,    0,    0,    4,    5,
    0,   18,    9,    0,   14,    9,    0,   14,    0,   14,
   14,   15,    0,    0,    0,    0,   57,    0,   57,   59,
    0,   18,   20,    0,    0,   16,    0,   17,   54,   55,
   56,   57,   58,   59,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    8,    0,    8,    0,   59,
    0,    0,    0,   59,    0,   16,    0,    0,    0,    0,
    0,   86,   62,   60,    0,   61,    9,   63,    9,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   12,    0,   16,    0,   14,   16,   14,
   16,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   21,    0,   88,    0,    0,
    0,    0,    0,   12,    0,  113,   62,   60,    0,   61,
    0,   63,    0,    0,    0,   10,    0,  124,   62,   60,
    0,   61,   59,   63,   59,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   57,   57,   57,   10,   57,   57,   57,   57,
   57,   57,   57,    0,    0,   57,   57,    0,   16,    0,
   16,  141,   62,   60,    0,   61,   57,   63,    0,    0,
    0,    8,    8,    8,    0,    8,    8,    8,    8,    8,
    8,    8,    0,    0,    8,    8,   12,    0,   12,    0,
    0,    0,    9,    9,    9,    8,    9,    9,    9,    9,
    9,    9,    9,    0,    0,    9,    9,   62,   60,    0,
   61,    0,   63,   14,   14,   14,    9,   14,   14,   14,
   14,   14,   14,   14,  140,    0,   14,   14,   10,    0,
   10,    3,    4,    5,    0,    6,    7,   14,    8,    9,
   10,   11,    0,    0,   14,   15,   62,   60,    0,   61,
    0,   63,    0,    0,    0,   18,    0,    0,   59,   59,
   59,    0,   59,   59,   59,   59,   59,   59,   59,    0,
    0,   59,   59,   38,   38,    0,   38,    0,   38,    0,
    0,    0,   59,    0,   52,   53,   54,   55,   56,   57,
   58,   59,    0,    0,   16,   16,   16,    0,   16,   16,
    0,   16,   16,   16,   16,    0,    0,   16,   16,   62,
   60,    0,   61,    0,   63,    0,    0,    0,   16,    0,
    0,    0,   12,   12,   12,    0,   12,   12,   12,   12,
   12,   12,   12,    0,    0,   12,   12,    0,   52,   53,
   54,   55,   56,   57,   58,   59,   12,    0,    0,    0,
   52,   53,   54,   55,   56,   57,   58,   59,    0,    0,
    0,    0,    0,    0,   10,   10,   10,    0,   10,   10,
   10,   10,   10,   10,   10,    0,    0,   10,   10,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   10,    0,
    0,    0,    0,    0,   52,   53,   54,   55,   56,   57,
   58,   59,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   52,
   53,   54,   55,   56,   57,   58,   59,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   52,   53,
   54,   55,   56,   57,   58,   59,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   38,   38,   38,   38,   38,
   38,   38,   38,    0,    0,    0,   22,    0,   31,    0,
    0,    0,    0,    0,    0,    0,   38,    0,    0,    0,
    0,    0,   48,   49,    0,   50,    0,    0,    0,    0,
    0,    0,   53,   54,   55,   56,   57,   58,   59,   74,
   75,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   81,    0,    0,    0,    0,    0,    0,   91,   92,   93,
   94,   95,   96,   97,   98,   99,  100,  101,  102,    0,
    0,    0,  103,    0,    0,    0,    0,    0,  112,    0,
    0,  114,  114,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  127,  128,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  143,
};
short yycheck[] = {                                      10,
  105,    1,   40,  260,  260,   43,   41,   45,   51,   44,
   61,  267,  268,   42,   42,   43,  273,   45,   47,   47,
   41,   10,   40,   44,   10,   68,   69,   40,   61,   40,
   41,   42,   43,   44,   45,   41,   47,  142,   44,   41,
  257,  146,   44,   41,   10,   10,   44,   10,   59,   10,
   43,   43,   45,   45,   40,   41,   42,   43,   44,   45,
   40,   47,   40,   44,   40,   40,  260,   40,   59,   40,
   70,   41,  257,   59,   10,  257,  257,  257,  265,   40,
   41,   41,   43,   44,   45,  123,  129,   41,   26,  106,
  133,  134,  106,   10,  106,   13,  139,  106,   59,   10,
   77,   -1,   -1,   -1,   40,   41,   -1,   43,   44,   45,
   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   10,   -1,   -1,   -1,   -1,   40,
   41,   -1,   -1,   44,   -1,   -1,   -1,  123,   -1,  125,
   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,   59,   -1,
   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,   44,   -1,
   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   43,
   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  123,   -1,  125,   40,   -1,   -1,   43,   -1,
   45,  259,  260,  261,   -1,  263,  264,   -1,  266,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,  283,   -1,   -1,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,  269,   -1,
   -1,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,   -1,  283,  259,  260,  261,   -1,  263,  264,  265,
  266,  267,  268,  269,   -1,   -1,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,   -1,  283,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,  269,   10,
   -1,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,   -1,  283,  259,  260,  261,   -1,  263,  264,  265,
  266,  267,  268,  269,   -1,   -1,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,   -1,  283,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,  269,   -1,
   -1,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,   10,  283,  259,  260,  261,   -1,  263,  264,  265,
  266,  267,  268,  269,   -1,   -1,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,   10,  283,   -1,   -1,
   -1,   40,   41,   -1,   -1,   44,  274,  275,  276,  277,
  278,  279,  280,  281,  258,   -1,  260,  261,   -1,   -1,
   59,   10,  123,  267,  125,   -1,   40,   41,  272,  273,
   44,   -1,  257,   -1,   -1,  260,  261,   -1,   -1,  283,
   -1,   -1,  267,   -1,   -1,   59,   10,  272,  273,   -1,
   -1,   40,   41,   -1,   -1,   44,   -1,   -1,  283,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   10,   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,
   44,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   10,   -1,   -1,   59,   -1,   -1,   -1,   -1,
   -1,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,  123,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,
   59,   -1,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   -1,   43,   -1,   45,   -1,   -1,   -1,   -1,  259,  123,
   -1,  125,  263,  264,  265,  266,   -1,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   -1,   43,   -1,   45,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   -1,   43,   -1,   45,   -1,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
  259,  260,  261,   -1,  263,  264,  265,  266,  267,  268,
  269,  123,   -1,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,   -1,  283,  259,  260,  261,   -1,  263,
  264,  265,  266,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,   -1,  283,
  259,  260,  261,   -1,  263,  264,  265,  266,  267,  268,
  269,   -1,   -1,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,   -1,  283,  259,  260,  261,   -1,  263,
  264,  265,  266,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,   -1,  283,
  259,  260,  261,   10,  263,  264,  265,  266,  267,  268,
  269,   -1,   -1,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,  259,  260,  261,  283,  263,  264,  265,  266,  267,
  268,  269,   10,   40,  272,  273,  274,   44,   -1,   -1,
   -1,   -1,   -1,   -1,  256,  283,   -1,  259,  260,  261,
   -1,  263,  264,   10,  266,  267,  268,  269,  270,  271,
  272,  273,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,  283,   -1,   -1,   10,   -1,  258,   -1,  260,  261,
   -1,   59,   -1,   40,   41,  267,   -1,   44,   -1,   -1,
  272,  273,   10,   -1,   -1,   -1,   -1,   -1,  260,  261,
   -1,  283,   59,   -1,   40,  267,   -1,   43,   -1,   45,
  272,  273,   -1,   -1,   -1,   -1,  123,   -1,  125,   10,
   -1,  283,   40,   -1,   -1,   43,   -1,   45,  276,  277,
  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   40,
   -1,   -1,   -1,   44,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   41,   42,   43,   -1,   45,  123,   47,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   10,   -1,   40,   -1,  123,   43,  125,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   40,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   10,   -1,   41,   42,   43,
   -1,   45,  123,   47,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  259,  260,  261,   40,  263,  264,  265,  266,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  123,   -1,
  125,   41,   42,   43,   -1,   45,  283,   47,   -1,   -1,
   -1,  259,  260,  261,   -1,  263,  264,  265,  266,  267,
  268,  269,   -1,   -1,  272,  273,  123,   -1,  125,   -1,
   -1,   -1,  259,  260,  261,  283,  263,  264,  265,  266,
  267,  268,  269,   -1,   -1,  272,  273,   42,   43,   -1,
   45,   -1,   47,  259,  260,  261,  283,  263,  264,  265,
  266,  267,  268,  269,   59,   -1,  272,  273,  123,   -1,
  125,  259,  260,  261,   -1,  263,  264,  283,  266,  267,
  268,  269,   -1,   -1,  272,  273,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,  283,   -1,   -1,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,  269,   -1,
   -1,  272,  273,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,  283,   -1,  274,  275,  276,  277,  278,  279,
  280,  281,   -1,   -1,  259,  260,  261,   -1,  263,  264,
   -1,  266,  267,  268,  269,   -1,   -1,  272,  273,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  283,   -1,
   -1,   -1,  259,  260,  261,   -1,  263,  264,  265,  266,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  274,  275,
  276,  277,  278,  279,  280,  281,  283,   -1,   -1,   -1,
  274,  275,  276,  277,  278,  279,  280,  281,   -1,   -1,
   -1,   -1,   -1,   -1,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,  269,   -1,   -1,  272,  273,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,   -1,
   -1,   -1,   -1,   -1,  274,  275,  276,  277,  278,  279,
  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  276,  277,  278,
  279,  280,  281,   -1,   -1,   -1,    1,   -1,    3,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   11,   -1,   -1,   -1,
   -1,   -1,   17,   18,   -1,   20,   -1,   -1,   -1,   -1,
   -1,   -1,  275,  276,  277,  278,  279,  280,  281,   34,
   35,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   52,   53,   54,
   55,   56,   57,   58,   59,   60,   61,   62,   63,   -1,
   -1,   -1,   67,   -1,   -1,   -1,   -1,   -1,   73,   -1,
   -1,   76,   77,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  109,  110,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  131,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'^'",0,0,0,0,0,0,0,0,0,0,0,"'j'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUMBER","STRING","PRINT","VAR","BLTIN","UNDEF",
"WHILE","IF","ELSE","FOR","FUNCTION","PROCEDURE","RETURN","FUNC","PROC","READ",
"ARG","OR","AND","GT","GE","LT","LE","EQ","NE","UNARYMINUS","NOT",
};
char *yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list defn '\\n'",
"list : list asgn '\\n'",
"list : list stmt '\\n'",
"list : list expr '\\n'",
"list : list error '\\n'",
"asgn : VAR '=' expr",
"asgn : ARG '=' expr",
"stmt : expr",
"stmt : RETURN",
"stmt : RETURN expr",
"stmt : PROCEDURE begin '(' arglist ')'",
"stmt : PRINT prlist",
"stmt : while cond stmt end",
"stmt : if cond stmt end",
"stmt : if cond stmt end ELSE stmt end",
"stmt : '{' stmtlist '}'",
"stmt : for asgnlist forcond exprlist stmt end",
"forcond : ';' expr ';'",
"asgnlist : '(' asgn",
"exprlist : expr ')'",
"for : FOR",
"cond : '(' expr ')'",
"while : WHILE",
"if : IF",
"begin :",
"end :",
"stmtlist :",
"stmtlist : stmtlist '\\n'",
"stmtlist : stmtlist stmt",
"expr : '+' NUMBER '+' NUMBER 'j'",
"expr : '+' NUMBER '-' NUMBER 'j'",
"expr : '-' NUMBER '+' NUMBER 'j'",
"expr : '-' NUMBER '-' NUMBER 'j'",
"expr : VAR",
"expr : ARG",
"expr : asgn",
"expr : FUNCTION begin '(' arglist ')'",
"expr : READ '(' VAR ')'",
"expr : BLTIN '(' expr ')'",
"expr : '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
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
"prlist : expr",
"prlist : STRING",
"prlist : prlist ',' expr",
"prlist : prlist ',' STRING",
"$$1 :",
"defn : FUNC procname $$1 '(' ')' stmt",
"$$2 :",
"defn : PROC procname $$2 '(' ')' stmt",
"procname : VAR",
"procname : FUNCTION",
"procname : PROCEDURE",
"arglist :",
"arglist : expr",
"arglist : arglist ',' expr",
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
#line 139 "hoc.y"

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











#line 745 "y.tab.c"
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
#line 33 "hoc.y"
{ code2(pop, STOP); return 1; }
break;
case 5:
#line 34 "hoc.y"
{ code(STOP); return 1; }
break;
case 6:
#line 35 "hoc.y"
{ code2(print, STOP); return 1; }
break;
case 7:
#line 36 "hoc.y"
{ yyerrok; }
break;
case 8:
#line 38 "hoc.y"
{ code3(varpush,(Inst)yyvsp[-2].sym,assign); yyval.inst=yyvsp[0].inst; }
break;
case 9:
#line 40 "hoc.y"
{ defnonly("$"); code2(argassign,(Inst)yyvsp[-2].narg); yyval.inst=yyvsp[0].inst;}
break;
case 10:
#line 42 "hoc.y"
{ code(pop); }
break;
case 11:
#line 43 "hoc.y"
{ defnonly("return"); code(procret); }
break;
case 12:
#line 45 "hoc.y"
{ defnonly( "return" ); yyval.inst = yyvsp[0].inst; code(funcret) ; }
break;
case 13:
#line 47 "hoc.y"
{ yyval.inst = yyvsp[-3].inst; code3(call, (Inst)yyvsp[-4].sym, (Inst)yyvsp[-1].narg); }
break;
case 14:
#line 48 "hoc.y"
{ yyval.inst = yyvsp[0].inst; }
break;
case 15:
#line 49 "hoc.y"
{
           (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* cuerpo del ciclo */
           (yyvsp[-3].inst)[2] = (Inst)yyvsp[0].inst; }
break;
case 16:
#line 52 "hoc.y"
{    /* if sin else */
           (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* parte then */
           (yyvsp[-3].inst)[3] = (Inst)yyvsp[0].inst; }
break;
case 17:
#line 55 "hoc.y"
{      /* if con else */
           (yyvsp[-6].inst)[1] = (Inst)yyvsp[-4].inst;     /* parte then */
           (yyvsp[-6].inst)[2] = (Inst)yyvsp[-1].inst;     /* parte else */
           (yyvsp[-6].inst)[3] = (Inst)yyvsp[0].inst; }
break;
case 18:
#line 59 "hoc.y"
{ yyval.inst = yyvsp[-1].inst; }
break;
case 19:
#line 60 "hoc.y"
{
        (yyvsp[-5].inst)[1] = (Inst) yyvsp[-3].inst;
        (yyvsp[-5].inst)[2] = (Inst) yyvsp[-2].inst;
        (yyvsp[-5].inst)[3] = (Inst) yyvsp[-1].inst;
        (yyvsp[-5].inst)[4] = (Inst) yyvsp[0].inst;
	}
break;
case 20:
#line 67 "hoc.y"
{ code(STOP); yyval.inst = yyvsp[-1].inst; }
break;
case 21:
#line 69 "hoc.y"
{ code(STOP); }
break;
case 22:
#line 71 "hoc.y"
{ code(STOP); }
break;
case 23:
#line 74 "hoc.y"
{ yyval.inst=code(forcode); code(STOP); code3(STOP, STOP, STOP); }
break;
case 24:
#line 78 "hoc.y"
{  code(STOP);   yyval.inst =  yyvsp[-1].inst;   }
break;
case 25:
#line 80 "hoc.y"
{ yyval.inst = code3(whilecode,STOP,STOP); }
break;
case 26:
#line 82 "hoc.y"
{ yyval.inst = code(ifcode); code3(STOP,STOP,STOP); }
break;
case 27:
#line 84 "hoc.y"
{ yyval.inst = progp; }
break;
case 28:
#line 86 "hoc.y"
{ code(STOP); yyval.inst = progp; }
break;
case 29:
#line 88 "hoc.y"
{ yyval.inst = progp; }
break;
case 32:
#line 92 "hoc.y"
{ yyval.inst = code3(constpush, (Inst)yyvsp[-3].sym,(Inst)yyvsp[-1].sym); }
break;
case 33:
#line 93 "hoc.y"
{(yyvsp[-1].sym)->u.val*=-1; yyval.inst = code3(constpush, (Inst)yyvsp[-3].sym,(Inst)yyvsp[-1].sym); }
break;
case 34:
#line 94 "hoc.y"
{(yyvsp[-3].sym)->u.val*=-1;  yyval.inst = code3(constpush, (Inst)yyvsp[-3].sym,(Inst)yyvsp[-1].sym); }
break;
case 35:
#line 95 "hoc.y"
{(yyvsp[-3].sym)->u.val*=-1; (yyvsp[-1].sym)->u.val*=-1;  yyval.inst = code3(constpush, (Inst)yyvsp[-3].sym,(Inst)yyvsp[-1].sym); }
break;
case 36:
#line 97 "hoc.y"
{   yyval.inst = code3(varpush, (Inst)yyvsp[0].sym, eval); }
break;
case 37:
#line 98 "hoc.y"
{   defnonly("$"); yyval.inst = code2(arg, (Inst)yyvsp[0].narg); }
break;
case 39:
#line 101 "hoc.y"
{ yyval.inst = yyvsp[-3].inst; code3(call,(Inst)yyvsp[-4].sym,(Inst)yyvsp[-1].narg); }
break;
case 40:
#line 102 "hoc.y"
{ yyval.inst = code2(varread, (Inst)yyvsp[-1].sym); }
break;
case 41:
#line 103 "hoc.y"
{ yyval.inst=yyvsp[-1].inst; code2(bltin, (Inst)yyvsp[-3].sym->u.ptr); }
break;
case 42:
#line 104 "hoc.y"
{ yyval.inst = yyvsp[-1].inst; }
break;
case 43:
#line 105 "hoc.y"
{   code(add); }
break;
case 44:
#line 106 "hoc.y"
{   code(sub); }
break;
case 45:
#line 107 "hoc.y"
{   code(mul); }
break;
case 46:
#line 108 "hoc.y"
{   code(div); }
break;
case 47:
#line 109 "hoc.y"
{ yyval.inst=yyvsp[0].inst; code(negate); }
break;
case 48:
#line 110 "hoc.y"
{ code(gt); }
break;
case 49:
#line 111 "hoc.y"
{ code(ge); }
break;
case 50:
#line 112 "hoc.y"
{ code(lt); }
break;
case 51:
#line 113 "hoc.y"
{ code(le); }
break;
case 52:
#line 114 "hoc.y"
{ code(eq); }
break;
case 53:
#line 115 "hoc.y"
{ code(ne); }
break;
case 54:
#line 116 "hoc.y"
{ code(and);}
break;
case 55:
#line 117 "hoc.y"
{ code(or); }
break;
case 56:
#line 118 "hoc.y"
{ yyval.inst= yyvsp[0].inst; code(not); }
break;
case 57:
#line 120 "hoc.y"
{   code(prexpr); }
break;
case 58:
#line 121 "hoc.y"
{    yyval.inst = code2(prstr, (Inst)yyvsp[0].sym); }
break;
case 59:
#line 122 "hoc.y"
{   code(prexpr); }
break;
case 60:
#line 123 "hoc.y"
{   code2(prstr, (Inst)yyvsp[0].sym); }
break;
case 61:
#line 125 "hoc.y"
{ yyvsp[0].sym->type=FUNCTION; indef=1; }
break;
case 62:
#line 126 "hoc.y"
{ code(procret); define(yyvsp[-4].sym); indef=0; }
break;
case 63:
#line 127 "hoc.y"
{ yyvsp[0].sym->type=PROCEDURE; indef=1; }
break;
case 64:
#line 128 "hoc.y"
{ code(procret); define(yyvsp[-4].sym); indef=0; }
break;
case 68:
#line 134 "hoc.y"
{ yyval.narg = 0; }
break;
case 69:
#line 135 "hoc.y"
{ yyval.narg = 1; }
break;
case 70:
#line 136 "hoc.y"
{ yyval.narg = yyvsp[-2].narg + 1; }
break;
#line 1141 "y.tab.c"
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
