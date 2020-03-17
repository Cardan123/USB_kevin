#define NUMBER 257
#define VAR 258
#define UNARYMINUS 259
typedef union {
	void *val;
	int index;
} YYSTYPE;
extern YYSTYPE yylval;
