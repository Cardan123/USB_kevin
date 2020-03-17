#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 1 "hoc.y"

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
#line 18 "y.tab.c"
#define NUMBER 257
#define STRING 258
#define PRINT 259
#define VAR 260
#define BLTIN 261
#define UNDEF 262
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
    1,    1,    1,    1,    1,    1,    1,    1,    1,    4,
    4,    4,    4,   14,   13,   15,   13,   11,   11,   11,
   12,   12,   12,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    3,    3,    3,    3,    1,
    1,    2,    5,    2,    4,    4,    7,    3,    3,    1,
    1,    0,    0,    0,    2,    2,    1,    1,    1,    1,
    5,    4,    4,    3,    3,    3,    3,    3,    3,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    1,
    1,    3,    3,    0,    6,    0,    6,    1,    1,    1,
    0,    1,    3,
};
short yydefred[] = {                                      1,
    0,    0,   27,    0,    0,    0,   20,   21,   22,   22,
    0,    0,    0,    0,    0,    0,    0,    2,    0,   24,
    0,    0,    0,    0,    0,    0,    7,   51,    0,   30,
    0,    0,    0,    0,    0,    0,   58,   59,   60,   54,
   56,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    5,    4,    0,    0,    0,    3,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   34,   25,   18,    0,
   26,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   23,   23,   53,    0,   33,
    0,    0,    0,    0,    0,   32,   19,   15,    0,   31,
    0,   13,    0,    0,    0,    0,   55,   57,   23,   17,
};
short yydgoto[] = {                                       1,
   80,   22,   30,   31,   47,   65,   24,   25,   34,  108,
   40,  102,   26,   73,   74,
};
short yysindex[] = {                                      0,
  846,    4,    0,  -34,  -56,  -19,    0,    0,    0,    0,
  177, -258, -258,  -18,  -51,  177,  177,    0,  177,    0,
  137,    6,   17,  -12,  -12,   32,    0,    0, 1277,    0,
    1,  177,  177,    7,    9, 1277,    0,    0,    0,    0,
    0, -216,  177,  -48,  -48,  506, 1186,  177,  177,  177,
  177,  177,  177,  177,  177,  177,  177,  177,  177,  177,
    0,    0,    0,  177, 1276, 1276,    0,  175, 1277,  530,
  177,  177,   10,   11,   12, 1277,    0,    0,    0, 1277,
    0,  856,  866,  -30,  -30,  -30,  -30,  -30,  -30,  -24,
  -24,  -48,  -48,  -48,  554,    0,    0,    0, 1277,    0,
 1277,  -37,  -15,   19,   21,    0,    0,    0, -213,    0,
  177,    0, 1276, 1276, 1276, 1277,    0,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,  -10,    0,    0,    0,    0,    0,
  694,    0,    0,    0,   14,    0,    0,    0,    0,    0,
    0,    0, 1291,    0,    0,    0,    0,    0, 1129,    0,
 1149,    0,    0,    0,    0, 1206,    0,    0,    0,    0,
    0,    0,    0,   38,   62,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1085,    0,
   -5,   -5,    0,    0,    0, 1109,    0,    0,    0, 1235,
    0,  826,  806,  434,  458,  482,  734,  758,  782,  386,
  410,   86,  110,  362,    0,    0,    0,    0, 1169,    0,
   -3,    0,    0,    0,    0,    0,    0,    0, 1259,    0,
    0,    0,    0,    0,    0,   -1,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
 1571,  -46,   64,    0,    0,   41,    0,    0,   53,  -94,
   58,    2,    0,    0,    0,
};
#define YYTABLESIZE 1682
short yytable[] = {                                      28,
   81,   37,  109,  110,   32,   19,  111,   38,   39,   43,
   16,   58,   56,   27,   57,   62,   59,   58,   96,   97,
   33,   42,   59,   29,  120,  112,   63,   64,  111,   28,
   28,   28,   28,   28,   28,   61,   28,   62,   61,   63,
   62,   67,   63,   75,   68,   60,   71,   40,   72,  104,
  105,  115,  106,   29,   29,   29,   29,   29,   29,  113,
   29,  114,   35,   60,   23,   66,  117,  118,  119,   60,
   41,   49,    0,  103,    0,    0,    0,   40,   40,   40,
   40,   40,   40,   28,   40,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   37,    0,    0,    0,    0,
    0,   49,   49,   49,   49,   49,   49,   29,   49,    0,
    0,    0,   28,    0,   28,    0,    0,    0,    0,   38,
    0,    0,    0,    0,    0,   37,   37,   37,   37,   37,
   37,    0,   37,    0,    0,    0,   29,    0,   29,    0,
    0,    0,    0,    0,    0,    0,   61,    0,    0,   38,
   38,   38,   38,   38,   38,    0,   38,    0,    0,    0,
   40,    0,   40,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   58,   56,
    0,   57,    0,   59,   49,    0,   49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   37,    0,
   37,    0,    0,    0,   19,    0,   19,    0,    0,   16,
    0,   16,    3,   28,    0,    5,    6,    0,    0,    0,
   60,    9,   38,    0,   38,    0,   14,   15,    0,    0,
    0,    0,    0,    0,    0,    0,   28,   17,   28,   28,
   28,    0,   28,   28,   28,   28,   28,   28,    0,    0,
   28,   28,   28,   28,   28,   28,   28,   28,   28,   28,
   29,   28,   29,   29,   29,    0,   29,   29,   29,   29,
   29,   29,    0,    0,   29,   29,   29,   29,   29,   29,
   29,   29,   29,   29,   40,   29,   40,   40,   40,    0,
   40,   40,   40,   40,   40,   40,    0,    0,   40,   40,
   40,   40,   40,   40,   40,   40,   40,   40,   49,   40,
   49,   49,   49,    0,   49,   49,   49,   49,   49,   49,
    0,    0,   49,   49,   49,   49,   49,   49,   49,   49,
   49,   49,   37,   49,   37,   37,   37,    0,   37,   37,
   37,   37,   37,   37,    0,    0,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   38,   37,   38,   38,
   38,   39,   38,   38,   38,   38,   38,   38,    0,    0,
   38,   38,   38,   38,   38,   38,   38,   38,   38,   38,
    0,   38,    0,    0,    0,   35,    0,    0,    0,    0,
    0,   39,   39,   39,   39,   39,   39,    0,   39,   48,
   49,   50,   51,   52,   53,   54,   55,    0,    0,   36,
    0,    0,    0,    0,    0,   35,   35,    0,   35,   35,
   35,    3,   98,    3,    5,    6,    5,    6,    0,    0,
    9,    0,    9,   41,    0,   14,   15,   14,   15,   36,
   36,    0,   36,   36,   36,    0,   17,    0,   17,    0,
    0,    0,    0,    0,    0,    0,    0,   42,    0,    0,
    0,    0,    0,   41,   41,    0,    0,   41,    0,    0,
    0,    0,    0,    0,   39,    0,   39,    0,    0,    0,
    0,   43,    0,    0,    0,    0,    0,   42,   42,    0,
    0,   42,    0,    0,    0,    0,    0,    0,   35,    0,
   35,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   43,   43,    0,    0,   43,    0,    0,    0,    0,
    0,    0,   36,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   77,   58,   56,    0,
   57,    0,   59,    0,    0,    0,   41,    0,   41,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  100,   58,   56,    0,   57,    0,   59,    0,    0,    0,
   42,    0,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  107,   58,   56,    0,   57,   60,
   59,    0,    0,    0,   43,    0,   43,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   39,    0,
   39,   39,   39,   60,   39,   39,   39,   39,   39,   39,
    0,    0,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   35,   39,   35,   35,   35,   60,   35,   35,
   35,   35,   35,   35,    0,    0,   35,   35,   35,   35,
   35,   35,   35,   35,   35,   35,   36,   35,   36,   36,
   36,    0,   36,   36,   36,   36,   36,   36,    0,    0,
   36,   36,   36,   36,   36,   36,   36,   36,   36,   36,
   41,   36,   41,   41,   41,    0,   41,   41,   41,   41,
   41,   41,    0,   11,   41,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   42,   41,   42,   42,   42,    0,
   42,   42,   42,   42,   42,   42,    0,    0,   42,   42,
   42,   42,   42,   42,   42,   42,   42,   42,   43,   42,
   43,   43,   43,   44,   43,   43,   43,   43,   43,   43,
    0,    0,   43,   43,   43,   43,   43,   43,   43,   43,
   43,   43,    0,   43,    0,    0,    0,   45,    0,    0,
    0,    0,    0,   44,   44,    0,    0,   44,   48,   49,
   50,   51,   52,   53,   54,   55,    0,    0,    0,    0,
    0,   46,    0,    0,    0,    0,    0,   45,   45,    0,
    0,   45,   48,   49,   50,   51,   52,   53,   54,   55,
    0,    0,    0,    0,    0,   47,   11,    0,   11,    0,
    0,   46,   46,    0,    0,   46,   48,   49,   50,   51,
   52,   53,   54,   55,    0,   48,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   47,   47,    0,    0,   47,
    0,    0,    0,    0,    0,   18,   44,    0,   44,    0,
    0,    0,    0,    0,    0,   48,   48,    0,    0,   48,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   45,    0,   45,    0,    0,   19,    0,    0,    0,    0,
   16,    0,    0,    0,    0,    0,    0,   58,   56,    0,
   57,    0,   59,    0,   46,    0,   46,   58,   56,    0,
   57,    0,   59,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   47,    0,
   47,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   48,   60,
   48,    0,   11,    0,    0,    0,   11,   11,   11,   60,
   11,   11,    0,    0,    0,    0,    0,    0,   20,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   44,    0,   44,   44,   44,    0,   44,   44,   44,   44,
   44,   44,    0,    0,   44,   44,   44,   44,   44,   44,
   44,   44,   44,   44,   45,   44,   45,   45,   45,    0,
   45,   45,   45,   45,   45,   45,    0,    0,   45,   45,
   45,   45,   45,   45,   45,   45,   45,   45,   46,   45,
   46,   46,   46,    0,   46,   46,   46,   46,   46,   46,
    0,    0,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   47,   46,   47,   47,   47,    0,   47,   47,
   47,   47,   47,   47,    0,    0,   47,   47,   47,   47,
    0,    0,   48,    0,   48,   48,   48,   47,   48,   48,
   48,   48,   48,   48,    8,    0,   48,   48,   48,    0,
    0,    2,    3,    0,    4,    5,    6,   48,    7,    8,
    0,    9,   10,   11,   12,   13,   14,   15,    9,    0,
    0,    0,    0,    0,    8,    8,    0,   17,    8,   49,
   50,   51,   52,   53,   54,   55,    0,    0,   50,    0,
   50,   51,   52,   53,   54,   55,    0,    0,    9,    9,
    0,    0,    9,    0,    0,    0,    0,    0,   14,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   50,    0,
    0,    0,   50,    0,    0,    0,    0,    0,   52,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   14,    0,
    0,    0,    0,   14,    0,   78,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    8,   52,    8,
    0,    0,   52,    0,    0,   12,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   19,    0,    0,    0,    0,
   16,    9,    0,    9,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   10,   12,    0,    0,    0,    0,
    0,   50,    0,   50,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   16,    0,
    0,   14,    0,   14,   10,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   52,    0,   52,    0,    0,    0,    0,   16,    0,
    0,    0,    0,   16,    0,    0,    0,    0,   20,    0,
   79,    0,    0,    0,    0,   19,    0,    0,   58,   56,
   16,   57,    0,   59,    0,    0,    0,    0,   12,    0,
   12,    0,   30,   30,    0,   30,    0,   30,    0,    0,
    0,    8,    0,    8,    8,    8,    0,    8,    8,    8,
    8,    8,    8,    0,    0,    8,    8,   10,    0,   10,
    0,    0,    0,    0,    0,    9,    8,    9,    9,    9,
   60,    9,    9,    9,    9,    9,    9,    0,    0,    9,
    9,   16,    0,   16,   30,   50,    0,   50,   50,   50,
    9,   50,   50,   50,   50,   50,   50,    0,   20,   50,
   50,    0,    0,    0,    0,   14,    0,   14,   14,   14,
   50,   14,   14,   14,   14,   14,   14,    0,    0,   14,
   14,    0,    0,    0,    0,   52,    0,   52,   52,   52,
   14,   52,   52,   52,   52,   52,   52,    0,    0,   52,
   52,    0,    3,    0,    4,    5,    6,    0,    7,    8,
   52,    9,   10,   11,    0,    0,   14,   15,    0,    0,
    0,    0,   12,    0,   12,   12,   12,   17,   12,   12,
   12,   12,   12,   12,    0,    0,   12,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   12,    0,    0,
    0,   10,    0,   10,   10,   10,    0,   10,   10,   10,
   10,   10,   10,    0,    0,   10,   10,    0,    0,    0,
    0,    0,    0,    0,    0,   16,   10,   16,   16,   16,
    0,   16,   16,    0,   16,   16,   16,    0,    0,   16,
   16,    0,    3,    0,    4,    5,    6,    0,    7,    8,
   16,    9,   10,   11,    0,    0,   14,   15,    0,   48,
   49,   50,   51,   52,   53,   54,   55,   17,    0,    0,
    0,    0,    0,   30,   30,   30,   30,   30,   30,   30,
   30,   21,    0,    0,   29,    0,    0,    0,    0,    0,
    0,   36,    0,    0,    0,    0,   44,   45,    0,   46,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   69,   70,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   76,    0,    0,    0,    0,   82,   83,
   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,
   94,    0,    0,    0,   95,    0,    0,    0,   99,    0,
    0,  101,  101,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  116,
};
short yycheck[] = {                                      10,
   47,  260,   97,   41,   61,   40,   44,  266,  267,   61,
   45,   42,   43,   10,   45,   10,   47,   42,   65,   66,
   40,   40,   47,   10,  119,   41,   10,   40,   44,   40,
   41,   42,   43,   44,   45,   41,   47,   41,   44,   41,
   44,   10,   44,  260,   44,   94,   40,   10,   40,   40,
   40,  265,   41,   40,   41,   42,   43,   44,   45,   41,
   47,   41,   10,   94,    1,   25,  113,  114,  115,   94,
   13,   10,   -1,   72,   -1,   -1,   -1,   40,   41,   42,
   43,   44,   45,   94,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   44,   45,   94,   47,   -1,
   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   10,
   -1,   -1,   -1,   -1,   -1,   40,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,  123,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,   40,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   40,   -1,   40,   -1,   -1,   45,
   -1,   45,  257,  258,   -1,  260,  261,   -1,   -1,   -1,
   94,  266,  123,   -1,  125,   -1,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  282,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,   -1,   -1,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  257,  282,  259,  260,  261,   -1,  263,  264,  265,  266,
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
   -1,   40,   41,   42,   43,   44,   45,   -1,   47,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   10,
   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   43,   44,
   45,  257,  258,  257,  260,  261,  260,  261,   -1,   -1,
  266,   -1,  266,   10,   -1,  271,  272,  271,  272,   40,
   41,   -1,   43,   44,   45,   -1,  282,   -1,  282,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,
   -1,   -1,   -1,   40,   41,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,   10,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,  123,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   41,   42,   43,   -1,   45,   94,
   47,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,
  259,  260,  261,   94,  263,  264,  265,  266,  267,  268,
   -1,   -1,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  257,  282,  259,  260,  261,   94,  263,  264,
  265,  266,  267,  268,   -1,   -1,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  257,  282,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,   -1,   -1,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  257,  282,  259,  260,  261,   -1,  263,  264,  265,  266,
  267,  268,   -1,   10,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  257,  282,  259,  260,  261,   -1,
  263,  264,  265,  266,  267,  268,   -1,   -1,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  257,  282,
  259,  260,  261,   10,  263,  264,  265,  266,  267,  268,
   -1,   -1,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,  282,   -1,   -1,   -1,   10,   -1,   -1,
   -1,   -1,   -1,   40,   41,   -1,   -1,   44,  273,  274,
  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,   -1,
   -1,   10,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,
   -1,   44,  273,  274,  275,  276,  277,  278,  279,  280,
   -1,   -1,   -1,   -1,   -1,   10,  123,   -1,  125,   -1,
   -1,   40,   41,   -1,   -1,   44,  273,  274,  275,  276,
  277,  278,  279,  280,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   10,  123,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   40,   -1,   -1,   -1,   -1,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,  123,   -1,  125,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   94,
  125,   -1,  259,   -1,   -1,   -1,  263,  264,  265,   94,
  267,  268,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,   -1,  259,  260,  261,   -1,  263,  264,  265,  266,
  267,  268,   -1,   -1,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  257,  282,  259,  260,  261,   -1,
  263,  264,  265,  266,  267,  268,   -1,   -1,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  257,  282,
  259,  260,  261,   -1,  263,  264,  265,  266,  267,  268,
   -1,   -1,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  257,  282,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,   -1,   -1,  271,  272,  273,  274,
   -1,   -1,  257,   -1,  259,  260,  261,  282,  263,  264,
  265,  266,  267,  268,   10,   -1,  271,  272,  273,   -1,
   -1,  256,  257,   -1,  259,  260,  261,  282,  263,  264,
   -1,  266,  267,  268,  269,  270,  271,  272,   10,   -1,
   -1,   -1,   -1,   -1,   40,   41,   -1,  282,   44,  274,
  275,  276,  277,  278,  279,  280,   -1,   -1,   10,   -1,
  275,  276,  277,  278,  279,  280,   -1,   -1,   40,   41,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   10,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   10,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   -1,   -1,   -1,   45,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   40,  125,
   -1,   -1,   44,   -1,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,
   45,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   10,   40,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,
   -1,  123,   -1,  125,   40,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   40,   -1,
   -1,   -1,   -1,   45,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   40,   -1,   -1,   42,   43,
   45,   45,   -1,   47,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,  257,   -1,  259,  260,  261,   -1,  263,  264,  265,
  266,  267,  268,   -1,   -1,  271,  272,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,  257,  282,  259,  260,  261,
   94,  263,  264,  265,  266,  267,  268,   -1,   -1,  271,
  272,  123,   -1,  125,   94,  257,   -1,  259,  260,  261,
  282,  263,  264,  265,  266,  267,  268,   -1,  123,  271,
  272,   -1,   -1,   -1,   -1,  257,   -1,  259,  260,  261,
  282,  263,  264,  265,  266,  267,  268,   -1,   -1,  271,
  272,   -1,   -1,   -1,   -1,  257,   -1,  259,  260,  261,
  282,  263,  264,  265,  266,  267,  268,   -1,   -1,  271,
  272,   -1,  257,   -1,  259,  260,  261,   -1,  263,  264,
  282,  266,  267,  268,   -1,   -1,  271,  272,   -1,   -1,
   -1,   -1,  257,   -1,  259,  260,  261,  282,  263,  264,
  265,  266,  267,  268,   -1,   -1,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  282,   -1,   -1,
   -1,  257,   -1,  259,  260,  261,   -1,  263,  264,  265,
  266,  267,  268,   -1,   -1,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  282,  259,  260,  261,
   -1,  263,  264,   -1,  266,  267,  268,   -1,   -1,  271,
  272,   -1,  257,   -1,  259,  260,  261,   -1,  263,  264,
  282,  266,  267,  268,   -1,   -1,  271,  272,   -1,  273,
  274,  275,  276,  277,  278,  279,  280,  282,   -1,   -1,
   -1,   -1,   -1,  273,  274,  275,  276,  277,  278,  279,
  280,    1,   -1,   -1,    4,   -1,   -1,   -1,   -1,   -1,
   -1,   11,   -1,   -1,   -1,   -1,   16,   17,   -1,   19,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   32,   33,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   43,   -1,   -1,   -1,   -1,   48,   49,
   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
   60,   -1,   -1,   -1,   64,   -1,   -1,   -1,   68,   -1,
   -1,   71,   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  111,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"NUMBER","STRING","PRINT","VAR","BLTIN","UNDEF","WHILE","IF",
"ELSE","FUNCTION","PROCEDURE","RETURN","FUNC","PROC","READ","ARG","OR","AND",
"GT","GE","LT","LE","EQ","NE","UNARYMINUS","NOT",
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
#line 119 "hoc.y"


/* fin de la gramática */ 
#include <stdio.h> 
#include <ctype.h> 

char    *progname; 
int    lineno = 1 ; 

#include <signal.h> 
#include <setjmp.h> 
jmp_buf begin; 
int    indef;
char   *infile;       /* nombre de archivo de entrada */ 
FILE    *fin;         /* apuntador a archivo de entrada */
char   **gargv;       /* lista global de argumentos */ 
int    gargc; 
int c;  /* global, para uso de warning() */

yylex(){
while  ((c=getc(fin)) ==  ' ' ||  c ==   '\t')
          ;
if (c == EOF)
	return 0; 
if (c == '.' || isdigit(c)) {   /* número */
	double d;
	ungetc(c, fin); 
	fscanf(fin, "%lf", &d);
        //printf("val = < %g >", d);
	yylval.sym = install("", NUMBER, d);
	return NUMBER; 
}
if (isalpha(c)) { 
	Symbol *s;
	char sbuf[100], *p = sbuf; 
	do {
		if (p >= sbuf + sizeof(sbuf) - 1) { 
			*p = '\0'; 
			execerror("name too long", sbuf);
		}
	*p++ = c;
        //putchar(c);
	} while ((c=getc(fin)) != EOF && isalnum(c)); 
	ungetc(c, fin); 
	*p = '\0'; 
        
	if ((s=lookup(sbuf)) == 0)
       		s=install(sbuf, UNDEF, 0.0); 
        //printf("sbuf = < %s > tipo=(%d)", sbuf, s->type);
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
	case '=':               putchar(c);putchar(c); putchar(c);
                                 return follow('=', EQ, '=');
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
for   (initcode();   yyparse();   initcode()){
        //puts("ant execute");
	execute(progbase); 
 }
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











#line 776 "y.tab.c"
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
#line 32 "hoc.y"
{ puts("list asgn");
                       code2(pop1, STOP); return 1; }
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
{ /*puts("VAR = expr ###");*/
              code3(varpush,(Inst)yyvsp[-2].sym, assign); yyval.inst=yyvsp[0].inst; }
break;
case 9:
#line 41 "hoc.y"
{ defnonly("$"); code2(argassign,(Inst)yyvsp[-2].narg); yyval.inst=yyvsp[0].inst;}
break;
case 10:
#line 43 "hoc.y"
{ code(pop1); }
break;
case 11:
#line 44 "hoc.y"
{ defnonly("return"); code(procret); }
break;
case 12:
#line 46 "hoc.y"
{ defnonly( "return" ); yyval.inst = yyvsp[0].inst; code(funcret) ; }
break;
case 13:
#line 48 "hoc.y"
{ yyval.inst = yyvsp[-3].inst; code3(call, (Inst)yyvsp[-4].sym, (Inst)yyvsp[-1].narg); }
break;
case 14:
#line 49 "hoc.y"
{ yyval.inst = yyvsp[0].inst; }
break;
case 15:
#line 50 "hoc.y"
{
           (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* cuerpo del ciclo */
           (yyvsp[-3].inst)[2] = (Inst)yyvsp[0].inst; }
break;
case 16:
#line 53 "hoc.y"
{    /* if sin else */
           (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* parte then */
           (yyvsp[-3].inst)[3] = (Inst)yyvsp[0].inst; }
break;
case 17:
#line 56 "hoc.y"
{      /* if con else */
           (yyvsp[-6].inst)[1] = (Inst)yyvsp[-4].inst;     /* parte then */
           (yyvsp[-6].inst)[2] = (Inst)yyvsp[-1].inst;     /* parte else */
           (yyvsp[-6].inst)[3] = (Inst)yyvsp[0].inst; }
break;
case 18:
#line 60 "hoc.y"
{ yyval.inst = yyvsp[-1].inst; }
break;
case 19:
#line 62 "hoc.y"
{  code(STOP);   yyval.inst =  yyvsp[-1].inst;   }
break;
case 20:
#line 64 "hoc.y"
{ yyval.inst = code3(whilecode,STOP,STOP); }
break;
case 21:
#line 66 "hoc.y"
{ yyval.inst = code(ifcode); code3(STOP,STOP,STOP); }
break;
case 22:
#line 68 "hoc.y"
{ yyval.inst = progp; }
break;
case 23:
#line 70 "hoc.y"
{ code(STOP); yyval.inst = progp; }
break;
case 24:
#line 72 "hoc.y"
{ yyval.inst = progp; }
break;
case 27:
#line 76 "hoc.y"
{   yyval.inst = code2(constpush, (Inst)yyvsp[0].sym); }
break;
case 28:
#line 77 "hoc.y"
{   yyval.inst = code3(varpush, (Inst)yyvsp[0].sym, eval); }
break;
case 29:
#line 78 "hoc.y"
{   defnonly("$"); yyval.inst = code2(arg, (Inst)yyvsp[0].narg); }
break;
case 31:
#line 81 "hoc.y"
{ yyval.inst = yyvsp[-3].inst; code3(call,(Inst)yyvsp[-4].sym,(Inst)yyvsp[-1].narg); }
break;
case 32:
#line 82 "hoc.y"
{ yyval.inst = code2(varread, (Inst)yyvsp[-1].sym); }
break;
case 33:
#line 83 "hoc.y"
{ yyval.inst=yyvsp[-1].inst; code2(bltin, (Inst)yyvsp[-3].sym->u.ptr); }
break;
case 34:
#line 84 "hoc.y"
{ yyval.inst = yyvsp[-1].inst; }
break;
case 35:
#line 85 "hoc.y"
{   code(add); }
break;
case 36:
#line 86 "hoc.y"
{   code(sub); }
break;
case 37:
#line 87 "hoc.y"
{   code(mul); }
break;
case 38:
#line 88 "hoc.y"
{   code(div); }
break;
case 39:
#line 89 "hoc.y"
{   code(power); }
break;
case 40:
#line 90 "hoc.y"
{ yyval.inst=yyvsp[0].inst; code(negate); }
break;
case 41:
#line 91 "hoc.y"
{ code(gt); }
break;
case 42:
#line 92 "hoc.y"
{ code(ge); }
break;
case 43:
#line 93 "hoc.y"
{ code(lt); }
break;
case 44:
#line 94 "hoc.y"
{ code(le); }
break;
case 45:
#line 95 "hoc.y"
{ code(eq); }
break;
case 46:
#line 96 "hoc.y"
{ code(ne); }
break;
case 47:
#line 97 "hoc.y"
{ code(and);}
break;
case 48:
#line 98 "hoc.y"
{ code(or); }
break;
case 49:
#line 99 "hoc.y"
{ yyval.inst= yyvsp[0].inst; code(not); }
break;
case 50:
#line 101 "hoc.y"
{   code(prexpr); }
break;
case 51:
#line 102 "hoc.y"
{    yyval.inst = code2(prstr, (Inst)yyvsp[0].sym); }
break;
case 52:
#line 103 "hoc.y"
{   code(prexpr); }
break;
case 53:
#line 104 "hoc.y"
{   code2(prstr, (Inst)yyvsp[0].sym); }
break;
case 54:
#line 106 "hoc.y"
{ yyvsp[0].sym->type=FUNCTION; indef=1; }
break;
case 55:
#line 107 "hoc.y"
{ code(procret); define(yyvsp[-4].sym); indef=0; }
break;
case 56:
#line 108 "hoc.y"
{ yyvsp[0].sym->type=PROCEDURE; indef=1; }
break;
case 57:
#line 109 "hoc.y"
{ code(procret); define(yyvsp[-4].sym); indef=0; }
break;
case 61:
#line 115 "hoc.y"
{ yyval.narg = 0; }
break;
case 62:
#line 116 "hoc.y"
{ yyval.narg = 1; }
break;
case 63:
#line 117 "hoc.y"
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
