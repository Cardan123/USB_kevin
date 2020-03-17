#define NUMBER 257
#define VAR 258
#define BLTIN 259
#define UNDEF 260
#define UNARYMINUS 261
#define CHAR 262
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	Symbol *sym;
	//Inst   *inst;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
