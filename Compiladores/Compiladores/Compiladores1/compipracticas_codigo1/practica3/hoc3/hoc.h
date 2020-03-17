typedef struct Symbol { /* entrada de la tabla de s�mbolos */
	char   *name;
	short   type;   /* VAR, BLTIN, UNDEF */
	union {
		double val;	       /* si es VAR */
		double  (*ptr)();      /* s� es BLTIN */
	} u;
	struct Symbol   *next;  /* para ligarse a otro */ 
} Symbol;

Symbol *install(char *s,int t, double d), *lookup(char *s);