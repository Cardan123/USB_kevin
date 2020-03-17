#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 1 "hoc5.y"

#include<stdlib.h>
#include <string.h>
#include "hoc.h"
#define code2(c1,c2)     code(c1); code(c2)
#define code3(c1,c2,c3) code(c1); code(c2); code(c3)

NodoL *symlist = (NodoL *)NULL;
NodoL **globals = (NodoL **)NULL;

void warning(char *s, char *t);
void yyerror(char *s);
void execerror(char *s, char *t);
void run();

#line 17 "hoc5.y"
typedef union {
   Simbolo *sym;
   Inst *inst;
   int narg;      /*   número de argumentos */  
} YYSTYPE;
#line 28 "y.tab.c"
#define NUMBER 257
#define STRING 258
#define PRINT 259
#define VAR 260
#define BLTIN 261
#define INDEF 262
#define WHILE 263
#define IF 264
#define ELSE 265
#define FUNCTION 266
#define PROCEDURE 267
#define RETURN 268
#define FUNC 269
#define PROC 270
#define READ 271
#define ARG 272
#define OR 273
#define AND 274
#define GT 275
#define GE 276
#define LT 277
#define LE 278
#define EQ 279
#define NE 280
#define UNARYMINUS 281
#define NOT 282
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    0,    0,    0,    3,    3,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    6,    7,
    8,    9,   10,    5,    5,    5,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    4,    4,    4,    4,   14,   13,   15,   13,   11,   11,
   11,   12,   12,   12,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    3,    3,    3,    3,    1,
    1,    2,    5,    2,    4,    4,    7,    3,    3,    1,
    1,    0,    0,    0,    2,    2,    1,    1,    1,    1,
    5,    4,    4,    3,    3,    3,    3,    3,    3,    3,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    1,    1,    3,    3,    0,    6,    0,    6,    1,    1,
    1,    0,    1,    3,
};
short yydefred[] = {                                      1,
    0,    0,   27,    0,    0,    0,   20,   21,   22,   22,
    0,    0,    0,    0,    0,    0,    2,    0,   24,    0,
    0,    0,    0,    0,    0,    0,    7,   52,    0,   30,
    0,    0,    0,    0,    0,    0,   59,   60,   61,   55,
   57,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    6,
    0,    0,    5,    4,    0,    0,    0,    3,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,   25,   18,
    0,   26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,   23,   54,
    0,   33,    0,    0,    0,    0,    0,   32,   19,   15,
    0,   31,    0,   13,    0,    0,    0,    0,   56,   58,
   23,   17,
};
short yydgoto[] = {                                       1,
   81,   22,   30,   31,   46,   66,   24,   25,   34,  110,
   40,  104,   26,   74,   75,
};
short yysindex[] = {                                      0,
  822,   -8,    0,  896,  -57,  -28,    0,    0,    0,    0,
  935, -238, -238,  -23,  -42,  935,    0,  935,    0,  935,
  137,   11,   28,    3,    3,   30,    0,    0,  506,    0,
    1,  935,  935,   13,   24,  506,    0,    0,    0,    0,
    0, -192,  935,  -31,  -34, 1206,  -31,  935,  935,  935,
  935,  935,  935,  935,  935,  935,  935,  935,  935,    0,
  935,  935,    0,    0,  935, 1275, 1275,    0,  915,  506,
  158,  935,  935,   31,   33,   29,  506,    0,    0,    0,
  506,    0,  561,  821,  -27,  -27,  -27,  -27,  -27,  -27,
   -1,  -31,  -31,  -31,  506,  506,  182,    0,    0,    0,
  506,    0,  506,   -2,    6,   36,   42,    0,    0,    0,
 -179,    0,  935,    0, 1275, 1275, 1275,  506,    0,    0,
    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,  -10,    0,    0,    0,    0,    0,
  670,    0,    0,    0,   14,    0,    0,    0,    0,    0,
    0,    0,  530,    0,    0,    0,    0,    0, 1145,    0,
 1169,    0,    0,    0,    0, 1017,    0,    0,    0,    0,
    0,    0,    0,   38,    0,    0,   62,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  846,
    0,    8,    8,    0,    0,    0, 1085,    0,    0,    0,
 1235,    0,  802,  782,  410,  434,  458,  482,  734,  758,
  386,   86,  110,  362, 1105, 1125,    0,    0,    0,    0,
 1189,    0,   21,    0,    0,    0,    0,    0,    0,    0,
 1255,    0,    0,    0,    0,    0,    0,   25,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
 1544,  -41,   87,    0,    0,   64,    0,    0,   77,  -98,
   78,   17,    0,    0,    0,
};
#define YYTABLESIZE 1657
short yytable[] = {                                      28,
  111,   27,   62,   32,   82,   62,   78,   57,   56,   62,
   61,   33,   58,   61,   57,   56,   42,   61,   43,   58,
   63,   37,  122,   29,   98,   99,   28,   38,   39,   28,
   28,   28,   28,   28,   28,   62,   28,   64,  112,   68,
   57,  113,   65,   61,   69,   58,  114,   50,   62,  113,
   29,   62,   72,   29,   29,   29,   29,   29,   29,   59,
   29,   63,   59,   73,   63,   64,   59,   76,   64,  108,
  106,   41,  107,  119,  120,  121,  115,   50,   50,   50,
   50,   50,  116,   28,   50,  117,   35,   23,   67,  105,
   41,    0,   59,    0,    0,   37,    0,    0,    0,    0,
    0,   41,   41,   41,   41,   41,    0,   29,   41,    0,
    0,    0,   28,    0,   28,    0,    0,    0,    0,   38,
    0,    0,    0,    0,    0,   37,   37,   37,   37,   37,
    0,    0,   37,    0,    0,    0,   29,    0,   29,    0,
    0,    0,    0,    0,    0,    0,   60,    0,    0,   38,
   38,   38,   38,   38,    0,    0,   38,    0,    0,    0,
   50,    0,   50,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   62,    0,    0,    0,    0,   57,   56,
    0,   61,    0,   58,   41,    0,   41,    0,    0,    0,
    0,    0,    0,    0,   62,    0,    0,    0,  102,   57,
   56,    0,   61,    0,   58,    0,    0,    0,   37,    0,
   37,    0,    0,    0,    0,    0,    0,    0,   62,    0,
    0,    0,  109,   57,   56,    0,   61,    0,   58,    0,
   59,    0,   38,    0,   38,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   28,    0,   28,   28,
   28,   59,   28,   28,   28,   28,   28,   28,    0,    0,
   28,   28,   28,   28,   28,   28,   28,   28,   28,   28,
   29,   28,   29,   29,   29,   59,   29,   29,   29,   29,
   29,   29,    0,    0,   29,   29,   29,   29,   29,   29,
   29,   29,   29,   29,   50,   29,   50,   50,   50,    0,
   50,   50,   50,   50,   50,   50,    0,    0,   50,   50,
   50,   50,   50,   50,   50,   50,   50,   50,   41,   50,
   41,   41,   41,    0,   41,   41,   41,   41,   41,   41,
    0,    0,   41,   41,   41,   41,   41,   41,   41,   41,
   41,   41,   37,   41,   37,   37,   37,    0,   37,   37,
   37,   37,   37,   37,    0,    0,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   38,   37,   38,   38,
   38,   40,   38,   38,   38,   38,   38,   38,    0,    0,
   38,   38,   38,   38,   38,   38,   38,   38,   38,   38,
    0,   38,    0,    0,    0,   35,    0,    0,    0,    0,
    0,   40,   40,   40,   40,   40,    0,    0,   40,   48,
   49,   50,   51,   52,   53,   54,   55,    0,    0,   42,
    0,    0,    0,    0,    0,   35,   35,    0,   35,   35,
   48,   49,   50,   51,   52,   53,   54,   55,    0,    0,
    0,    0,    0,   43,    0,    0,    0,    0,    0,   42,
   42,    0,    0,   42,   48,   49,   50,   51,   52,   53,
   54,   55,    0,    0,    0,    0,    0,   44,    0,    0,
    0,    0,    0,   43,   43,    0,    0,   43,    0,    0,
    0,    0,    0,    0,   40,    0,   40,    0,    0,    0,
    0,   45,    0,    0,    0,    0,    0,   44,   44,    0,
    0,   44,    0,    0,    0,    0,    0,    0,   35,    0,
   35,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   45,   45,    0,    0,   45,    0,    0,    0,    0,
    0,    0,   42,    0,   42,    0,    0,    0,    0,    0,
    0,    0,   62,    0,    0,    0,    0,   57,   56,    0,
   61,    0,   58,    0,    0,    0,   43,    0,   43,    0,
    0,    0,    0,    0,    0,    0,   30,    0,    0,    0,
    0,   30,   30,    0,   30,    0,   30,    0,    0,    0,
   44,    0,   44,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   62,    0,   59,
    0,    0,   57,   56,   45,   61,   45,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   40,    0,
   40,   40,   40,   30,   40,   40,   40,   40,   40,   40,
    0,    0,   40,   40,   40,   40,   40,   40,   40,   40,
   40,   40,   35,   40,   35,   35,   35,    0,   35,   35,
   35,   35,   35,   35,   59,    0,   35,   35,   35,   35,
   35,   35,   35,   35,   35,   35,   42,   35,   42,   42,
   42,    0,   42,   42,   42,   42,   42,   42,    0,   11,
   42,   42,   42,   42,   42,   42,   42,   42,   42,   42,
   43,   42,   43,   43,   43,    0,   43,   43,   43,   43,
   43,   43,    0,    0,   43,   43,   43,   43,   43,   43,
   43,   43,   43,   43,   44,   43,   44,   44,   44,    0,
   44,   44,   44,   44,   44,   44,    0,    0,   44,   44,
   44,   44,   44,   44,   44,   44,   44,   44,   45,   44,
   45,   45,   45,   46,   45,   45,   45,   45,   45,   45,
    0,    0,   45,   45,   45,   45,   45,   45,   45,   45,
   45,   45,    0,   45,    0,    0,    0,   47,    0,    0,
    0,    0,    0,   46,   46,    0,    0,   46,   48,   49,
   50,   51,   52,   53,   54,   55,    0,    0,    0,    0,
    0,   48,   11,    0,   11,    0,    0,   47,   47,    0,
    0,   47,   30,   30,   30,   30,   30,   30,   30,   30,
    0,   49,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   48,   48,    0,    0,   48,    0,    0,    0,    0,
    0,   17,    0,    0,   49,   50,   51,   52,   53,   54,
   55,   49,   49,    0,    0,   49,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    8,   46,   62,   46,    0,
    0,   18,   57,   56,    0,   61,   20,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   47,    0,   47,    0,    0,    8,    8,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   48,    0,   48,    0,    0,    0,
    0,    0,    0,    0,   59,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,    0,   49,    0,   11,    0,
    0,    0,   11,   11,   11,   18,   11,   11,    0,    0,
   20,    0,    0,    0,   19,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   18,    0,    0,    0,    0,   20,
    0,    0,    0,    0,    0,    0,    0,    0,    8,    0,
    8,    0,    0,    0,   18,    0,    0,    0,    0,   20,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   46,    0,   46,   46,   46,    0,   46,   46,   46,   46,
   46,   46,    0,    0,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   47,   46,   47,   47,   47,    0,
   47,   47,   47,   47,   47,   47,   12,    0,   47,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   48,   47,
   48,   48,   48,    0,   48,   48,   48,   48,   48,   48,
    0,    0,   48,   48,   48,   48,   12,    0,   49,    0,
   49,   49,   49,   48,   49,   49,   49,   49,   49,   49,
    0,    0,   49,   49,   49,    0,    0,    2,    3,    0,
    4,    5,    6,   49,    7,    8,    0,    9,   10,   11,
   12,   13,   14,   15,    9,   50,   51,   52,   53,   54,
   55,    0,    8,   16,    8,    8,    8,    0,    8,    8,
    8,    8,    8,    8,   36,    0,    8,    8,    0,    0,
    0,    0,    0,    0,    9,    9,    0,    8,    9,    0,
    0,    0,    0,    0,   39,    0,    0,    0,    0,   12,
    0,   12,    0,    0,   36,   36,    0,    0,   36,    0,
    0,    0,    3,   28,   51,    5,    6,    0,    0,    0,
    0,    9,    0,    0,   39,   39,   14,   15,   39,    0,
    0,    3,  100,    0,    5,    6,    0,   16,   14,    0,
    9,    0,    0,    0,   51,   14,   15,    0,   51,    0,
    0,    3,    0,    0,    5,    6,   16,    0,   53,    0,
    9,    0,    0,    0,    0,   14,   15,    9,   14,    9,
    0,    0,    0,   14,    0,   79,   16,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,   53,   36,
    0,    0,   53,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   10,   18,    0,   39,    0,   39,
   20,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   16,    0,    0,   51,    0,   51,
    0,    0,    0,   12,   10,   12,   12,   12,    0,   12,
   12,   12,   12,   12,   12,    0,    0,   12,   12,    0,
    0,   14,    0,   14,   16,    0,    0,    0,   12,   16,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   53,    0,   53,   18,    0,    0,    0,    0,   20,
    0,    0,    0,    0,    0,    0,    0,    0,   19,    0,
   80,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    9,    0,    9,    9,    9,    0,    9,    9,    9,
    9,    9,    9,    0,    0,    9,    9,   10,    0,   10,
    0,   36,    0,   36,   36,   36,    9,   36,   36,   36,
   36,   36,   36,    0,    0,   36,   36,   16,    0,   16,
    0,   39,    0,   39,   39,   39,   36,   39,   39,   39,
   39,   39,   39,    0,    0,   39,   39,   19,    0,    0,
    0,   51,    0,   51,   51,   51,   39,   51,   51,   51,
   51,   51,   51,    0,    0,   51,   51,    0,    0,    0,
    0,    0,    0,    0,    0,   14,   51,   14,   14,   14,
    0,   14,   14,   14,   14,   14,   14,    0,    0,   14,
   14,    0,    0,    0,    0,   53,    0,   53,   53,   53,
   14,   53,   53,   53,   53,   53,   53,    0,    0,   53,
   53,    0,    3,    0,    4,    5,    6,    0,    7,    8,
   53,    9,   10,   11,    0,    0,   14,   15,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   16,    0,    0,
    0,   10,    0,   10,   10,   10,    0,   10,   10,   10,
   10,   10,   10,    0,    0,   10,   10,    0,    0,    0,
    0,   16,    0,   16,   16,   16,   10,   16,   16,    0,
   16,   16,   16,    0,    0,   16,   16,    0,    0,    0,
    0,    3,    0,    4,    5,    6,   16,    7,    8,    0,
    9,   10,   11,    0,   21,   14,   15,   29,    0,    0,
    0,    0,    0,    0,   36,    0,   16,    0,    0,   44,
    0,   45,    0,   47,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   70,   71,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   77,    0,    0,    0,
    0,   83,   84,   85,   86,   87,   88,   89,   90,   91,
   92,   93,   94,    0,   95,   96,    0,    0,   97,    0,
    0,    0,  101,    0,    0,  103,  103,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  118,
};
short yycheck[] = {                                      10,
   99,   10,   37,   61,   46,   37,   41,   42,   43,   37,
   45,   40,   47,   45,   42,   43,   40,   45,   61,   47,
   10,  260,  121,   10,   66,   67,   37,  266,  267,   40,
   41,   42,   43,   44,   45,   37,   47,   10,   41,   10,
   42,   44,   40,   45,   44,   47,   41,   10,   41,   44,
   37,   44,   40,   40,   41,   42,   43,   44,   45,   94,
   47,   41,   94,   40,   44,   41,   94,  260,   44,   41,
   40,   10,   40,  115,  116,  117,   41,   40,   41,   42,
   43,   44,   41,   94,   47,  265,   10,    1,   25,   73,
   13,   -1,   94,   -1,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   44,   -1,   94,   47,   -1,
   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   10,
   -1,   -1,   -1,   -1,   -1,   40,   41,   42,   43,   44,
   -1,   -1,   47,   -1,   -1,   -1,  123,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,   40,
   41,   42,   43,   44,   -1,   -1,   47,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   37,   -1,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   37,   -1,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   37,   -1,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   94,   -1,  123,   -1,  125,   -1,   -1,   -1,  273,  274,
  275,  276,  277,  278,  279,  280,  257,   -1,  259,  260,
  261,   94,  263,  264,  265,  266,  267,  268,   -1,   -1,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  257,  282,  259,  260,  261,   94,  263,  264,  265,  266,
  267,  268,   -1,   -1,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  257,  282,  259,  260,  261,   -1,
  263,  264,  265,  266,  267,  268,   -1,   -1,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  257,  282,
  259,  260,  261,   -1,  263,  264,  265,  266,  267,  268,
   -1,   -1,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  257,  282,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,   -1,   -1,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  257,  282,  259,  260,
  261,   10,  263,  264,  265,  266,  267,  268,   -1,   -1,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
   -1,  282,   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   44,   -1,   -1,   47,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   10,
   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   43,   44,
  273,  274,  275,  276,  277,  278,  279,  280,   -1,   -1,
   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,   40,
   41,   -1,   -1,   44,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,
   -1,   -1,   -1,   40,   41,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,   10,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   37,   -1,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,  123,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   37,   -1,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   37,   -1,   94,
   -1,   -1,   42,   43,  123,   45,  125,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,
  259,  260,  261,   94,  263,  264,  265,  266,  267,  268,
   -1,   -1,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  257,  282,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,   94,   -1,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  257,  282,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,   -1,   10,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  257,  282,  259,  260,  261,   -1,  263,  264,  265,  266,
  267,  268,   -1,   -1,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  257,  282,  259,  260,  261,   -1,
  263,  264,  265,  266,  267,  268,   -1,   -1,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  257,  282,
  259,  260,  261,   10,  263,  264,  265,  266,  267,  268,
   -1,   -1,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,  282,   -1,   -1,   -1,   10,   -1,   -1,
   -1,   -1,   -1,   40,   41,   -1,   -1,   44,  273,  274,
  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,   -1,
   -1,   10,  123,   -1,  125,   -1,   -1,   40,   41,   -1,
   -1,   44,  273,  274,  275,  276,  277,  278,  279,  280,
   -1,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   10,   -1,   -1,  274,  275,  276,  277,  278,  279,
  280,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   10,  123,   37,  125,   -1,
   -1,   40,   42,   43,   -1,   45,   45,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   40,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,  259,   -1,
   -1,   -1,  263,  264,  265,   40,  267,  268,   -1,   -1,
   45,   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,   -1,  259,  260,  261,   -1,  263,  264,  265,  266,
  267,  268,   -1,   -1,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  257,  282,  259,  260,  261,   -1,
  263,  264,  265,  266,  267,  268,   10,   -1,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  257,  282,
  259,  260,  261,   -1,  263,  264,  265,  266,  267,  268,
   -1,   -1,  271,  272,  273,  274,   40,   -1,  257,   -1,
  259,  260,  261,  282,  263,  264,  265,  266,  267,  268,
   -1,   -1,  271,  272,  273,   -1,   -1,  256,  257,   -1,
  259,  260,  261,  282,  263,  264,   -1,  266,  267,  268,
  269,  270,  271,  272,   10,  275,  276,  277,  278,  279,
  280,   -1,  257,  282,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,   10,   -1,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   40,   41,   -1,  282,   44,   -1,
   -1,   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,  123,
   -1,  125,   -1,   -1,   40,   41,   -1,   -1,   44,   -1,
   -1,   -1,  257,  258,   10,  260,  261,   -1,   -1,   -1,
   -1,  266,   -1,   -1,   40,   41,  271,  272,   44,   -1,
   -1,  257,  258,   -1,  260,  261,   -1,  282,   10,   -1,
  266,   -1,   -1,   -1,   40,  271,  272,   -1,   44,   -1,
   -1,  257,   -1,   -1,  260,  261,  282,   -1,   10,   -1,
  266,   -1,   -1,   -1,   -1,  271,  272,  123,   40,  125,
   -1,   -1,   -1,   45,   -1,   10,  282,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   40,  125,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   10,   40,   -1,  123,   -1,  125,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   10,   -1,   -1,  123,   -1,  125,
   -1,   -1,   -1,  257,   40,  259,  260,  261,   -1,  263,
  264,  265,  266,  267,  268,   -1,   -1,  271,  272,   -1,
   -1,  123,   -1,  125,   40,   -1,   -1,   -1,  282,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   40,   -1,   -1,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  257,   -1,  259,  260,  261,   -1,  263,  264,  265,
  266,  267,  268,   -1,   -1,  271,  272,  123,   -1,  125,
   -1,  257,   -1,  259,  260,  261,  282,  263,  264,  265,
  266,  267,  268,   -1,   -1,  271,  272,  123,   -1,  125,
   -1,  257,   -1,  259,  260,  261,  282,  263,  264,  265,
  266,  267,  268,   -1,   -1,  271,  272,  123,   -1,   -1,
   -1,  257,   -1,  259,  260,  261,  282,  263,  264,  265,
  266,  267,  268,   -1,   -1,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  282,  259,  260,  261,
   -1,  263,  264,  265,  266,  267,  268,   -1,   -1,  271,
  272,   -1,   -1,   -1,   -1,  257,   -1,  259,  260,  261,
  282,  263,  264,  265,  266,  267,  268,   -1,   -1,  271,
  272,   -1,  257,   -1,  259,  260,  261,   -1,  263,  264,
  282,  266,  267,  268,   -1,   -1,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  282,   -1,   -1,
   -1,  257,   -1,  259,  260,  261,   -1,  263,  264,  265,
  266,  267,  268,   -1,   -1,  271,  272,   -1,   -1,   -1,
   -1,  257,   -1,  259,  260,  261,  282,  263,  264,   -1,
  266,  267,  268,   -1,   -1,  271,  272,   -1,   -1,   -1,
   -1,  257,   -1,  259,  260,  261,  282,  263,  264,   -1,
  266,  267,  268,   -1,    1,  271,  272,    4,   -1,   -1,
   -1,   -1,   -1,   -1,   11,   -1,  282,   -1,   -1,   16,
   -1,   18,   -1,   20,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   32,   33,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   43,   -1,   -1,   -1,
   -1,   48,   49,   50,   51,   52,   53,   54,   55,   56,
   57,   58,   59,   -1,   61,   62,   -1,   -1,   65,   -1,
   -1,   -1,   69,   -1,   -1,   72,   73,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  113,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'^'","'_'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUMBER","STRING","PRINT","VAR","BLTIN","INDEF",
"WHILE","IF","ELSE","FUNCTION","PROCEDURE","RETURN","FUNC","PROC","READ","ARG",
"OR","AND","GT","GE","LT","LE","EQ","NE","UNARYMINUS","NOT",
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
"cond : '(' expr ')'",
"while : WHILE",
"if : IF",
"begin :",
"end :",
"stmtlist :",
"stmtlist : stmtlist '\\n'",
"stmtlist : stmtlist stmt",
"expr : NUMBER",
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
"expr : expr '%' expr",
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
#line 145 "hoc5.y"

/* fin de la gramática */  

#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;
int    indef;
char   *infile;       /* nombre de archivo de entrada */ 
FILE    *fin;         /* apuntador a archivo de entrada */
char   **gargv;       /* lista global de argumentos */ 
int    gargc; 
int c;  

char *progname;
int lineno = 1;

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
void defnonly( char *s )     /* advertena la si hay definición i legal */
{
if (!indef)
	execerror(s, "used outside definition"); 
} 
void yyerror(char *s) {
   warning(s, (char *)0); 
} 
void execerror(char *s, char *t){/* recuperación de errores de tiempo de ejecución */
warning(s, t);
fseek( fin, 0L, 2);       /* sacar el resto del archivo */
longjmp(begin, 0); 
}
void fpecatch(){
   execerror("floating point exception", (char *) 0); 
}
int main(int argc, char **argv){       /* hoc6 */ 
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
int moreinput( ) {
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
void run() {
   Inst *pc1;
   setjmp(begin);
   signal(SIGFPE,   fpecatch);
   for   (initcode();   yyparse();   initcode()){
        /*for  (pc1 = prog; pc1 < progp ; ) {
              printf(" maincta = (%d, %s)\n", pc1-prog , *pc1);
              pc1 = pc1 + 1; 
        }*/ 
	execute(progbase); 
        puts("despues execute(progbase)");
   }
}
void warning(char *s, char *t) {
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











#line 712 "y.tab.c"
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
#line 41 "hoc5.y"
{ puts("list asgn");code2( strdup("pop1"), strdup("STOP") ); 
                       return 1; }
break;
case 5:
#line 43 "hoc5.y"
{ code(strdup("STOP")); return 1; }
break;
case 6:
#line 44 "hoc5.y"
{ code2(strdup("printVal"), strdup("STOP")); 
                       return 1; }
break;
case 7:
#line 46 "hoc5.y"
{ yyerrok; }
break;
case 8:
#line 48 "hoc5.y"
{ 
      code3(strdup("varpush"), (Inst)yyvsp[-2].sym, strdup("assign")); 
      yyval.inst=yyvsp[0].inst;
   }
break;
case 9:
#line 53 "hoc5.y"
{ defnonly("$"); code2(strdup("argassign"),(Inst)yyvsp[-2].narg); 
      yyval.inst=yyvsp[0].inst;
   }
break;
case 10:
#line 57 "hoc5.y"
{ code(strdup("pop1")); }
break;
case 11:
#line 59 "hoc5.y"
{ defnonly("return"); code(strdup("procret")); }
break;
case 12:
#line 61 "hoc5.y"
{ defnonly( "return" ); yyval.inst = yyvsp[0].inst; code(strdup("funcret")) ; }
break;
case 13:
#line 63 "hoc5.y"
{ yyval.inst = yyvsp[-3].inst; code3(strdup("call"), (Inst)yyvsp[-4].sym, (Inst)yyvsp[-1].narg); }
break;
case 14:
#line 64 "hoc5.y"
{ yyval.inst = yyvsp[0].inst; }
break;
case 15:
#line 65 "hoc5.y"
{
           (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* cuerpo del ciclo */
           (yyvsp[-3].inst)[2] = (Inst)yyvsp[0].inst; }
break;
case 16:
#line 68 "hoc5.y"
{    /* if sin else */
           (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* parte then */
           (yyvsp[-3].inst)[3] = (Inst)yyvsp[0].inst; 
     }
break;
case 17:
#line 72 "hoc5.y"
{      /* if con else */
           (yyvsp[-6].inst)[1] = (Inst)yyvsp[-4].inst;     /* parte then */
           (yyvsp[-6].inst)[2] = (Inst)yyvsp[-1].inst;     /* parte else */
           (yyvsp[-6].inst)[3] = (Inst)yyvsp[0].inst;   
     }
break;
case 18:
#line 77 "hoc5.y"
{ yyval.inst = yyvsp[-1].inst; }
break;
case 19:
#line 79 "hoc5.y"
{   code(strdup("STOP"));  yyval.inst=  yyvsp[-1].inst;   }
break;
case 20:
#line 81 "hoc5.y"
{   
        yyval.inst = code3(strdup("whilecode"), strdup("STOP"), strdup("STOP")); 
        }
break;
case 21:
#line 85 "hoc5.y"
{ yyval.inst=code(strdup("ifcode")); 
          code3( strdup("STOP"), strdup("STOP"), strdup("STOP")); }
break;
case 22:
#line 88 "hoc5.y"
{ yyval.inst = progp; }
break;
case 23:
#line 90 "hoc5.y"
{ code( strdup("STOP") ); yyval.inst = progp; }
break;
case 24:
#line 92 "hoc5.y"
{ yyval.inst = progp; }
break;
case 27:
#line 96 "hoc5.y"
{  /*puts("NUMBER"); */
                 yyval.inst = code2(strdup("constpush"), (Inst)yyvsp[0].sym); 
              }
break;
case 28:
#line 99 "hoc5.y"
{  
                 yyval.inst = code3(strdup("varpush"), (Inst)yyvsp[0].sym, strdup("eval"));
              }
break;
case 29:
#line 102 "hoc5.y"
{   /*puts("yacc ARG");*/
                     defnonly("$"); yyval.inst = code2(strdup("arg"), (Inst)yyvsp[0].narg); }
break;
case 31:
#line 106 "hoc5.y"
{ yyval.inst = yyvsp[-3].inst; code3(strdup("call"),(Inst)yyvsp[-4].sym,(Inst)yyvsp[-1].narg); }
break;
case 32:
#line 107 "hoc5.y"
{ yyval.inst = code2(strdup("varread"), (Inst)yyvsp[-1].sym); }
break;
case 33:
#line 108 "hoc5.y"
{ yyval.inst = yyvsp[-1].inst; code2(strdup("bltin"), (Inst)yyvsp[-3].sym->u.ptr);}
break;
case 34:
#line 109 "hoc5.y"
{ yyval.inst = yyvsp[-1].inst; }
break;
case 35:
#line 110 "hoc5.y"
{ code(strdup("add")); }
break;
case 36:
#line 111 "hoc5.y"
{ code(strdup("sub")); }
break;
case 37:
#line 112 "hoc5.y"
{ code(strdup("mul")); }
break;
case 38:
#line 113 "hoc5.y"
{ code(strdup("div")); }
break;
case 39:
#line 114 "hoc5.y"
{ code(strdup("mod")); }
break;
case 40:
#line 115 "hoc5.y"
{ code(strdup("power")); }
break;
case 41:
#line 116 "hoc5.y"
{ code(strdup("negate")); }
break;
case 42:
#line 117 "hoc5.y"
{ code(strdup("gt")); }
break;
case 43:
#line 118 "hoc5.y"
{ code(strdup("ge")); }
break;
case 44:
#line 119 "hoc5.y"
{ code(strdup("lt")); }
break;
case 45:
#line 120 "hoc5.y"
{ code(strdup("le")); }
break;
case 46:
#line 121 "hoc5.y"
{ code(strdup("eq")); }
break;
case 47:
#line 122 "hoc5.y"
{ code(strdup("ne")); }
break;
case 48:
#line 123 "hoc5.y"
{ code(strdup("and")); }
break;
case 49:
#line 124 "hoc5.y"
{ code(strdup("or")); }
break;
case 50:
#line 125 "hoc5.y"
{ yyval.inst = yyvsp[0].inst; code(strdup("not")); }
break;
case 51:
#line 127 "hoc5.y"
{   code(strdup("printVal")); }
break;
case 52:
#line 128 "hoc5.y"
{    yyval.inst = code2(strdup("prstr"), (Inst)yyvsp[0].sym); }
break;
case 53:
#line 129 "hoc5.y"
{   code(strdup("printVal")); }
break;
case 54:
#line 130 "hoc5.y"
{   code2(strdup("prstr"), (Inst)yyvsp[0].sym); }
break;
case 55:
#line 132 "hoc5.y"
{ yyvsp[0].sym->tipo=FUNCTION; indef=1; }
break;
case 56:
#line 133 "hoc5.y"
{ code(strdup("procret")); define(yyvsp[-4].sym); indef=0; }
break;
case 57:
#line 134 "hoc5.y"
{ yyvsp[0].sym->tipo=PROCEDURE; indef=1; }
break;
case 58:
#line 135 "hoc5.y"
{ code(strdup("procret")); define(yyvsp[-4].sym); indef=0; }
break;
case 62:
#line 141 "hoc5.y"
{ yyval.narg = 0; }
break;
case 63:
#line 142 "hoc5.y"
{ yyval.narg = 1; }
break;
case 64:
#line 143 "hoc5.y"
{ yyval.narg = yyvsp[-2].narg + 1; }
break;
#line 1096 "y.tab.c"
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
