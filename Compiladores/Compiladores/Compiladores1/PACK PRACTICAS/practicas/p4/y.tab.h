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
typedef union {
	Symbol	*sym;	/* symbol table pointer */
	Inst	*inst;	/* machine instruction */
} YYSTYPE;
extern YYSTYPE yylval;
