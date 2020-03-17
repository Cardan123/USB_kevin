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
typedef union {
Symbol     *sym;      /*   Apuntador a la tabla de símbolos */
Inst       *inst;     /*   instrucción de máquina */
int        narg;      /*   número de argumentos */
} YYSTYPE;
extern YYSTYPE yylval;
