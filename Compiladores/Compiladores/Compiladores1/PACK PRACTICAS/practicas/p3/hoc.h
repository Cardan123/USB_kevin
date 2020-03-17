struct Symbol
{
	char *name;
	short type;
	union
	{
		char val;
		char (*ptr)();
	} u;
	struct Symbol *next;
};

typedef struct Symbol Symbol;

Symbol *install(char *s, int t, char d);
Symbol *lookup(char *s);

void *emalloc(unsigned int n);
void yyerror(char *s, ...);
void warning(char *s, char *t);
void execerror(char *s, char *t);
void fpecatch();
int yylex();
