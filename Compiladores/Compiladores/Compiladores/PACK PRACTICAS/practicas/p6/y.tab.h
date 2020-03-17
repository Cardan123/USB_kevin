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
typedef union {
Symbol     *sym;      /*   Apuntador a la tabla de símbolos */
Inst       *inst;     /*   instrucción de máquina */
int        narg;      /*   número de argumentos */
} YYSTYPE;
extern YYSTYPE yylval;
