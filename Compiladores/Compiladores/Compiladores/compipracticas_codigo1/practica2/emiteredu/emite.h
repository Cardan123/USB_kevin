
typedef struct Symbol {	/* symbol table entry */
	char	*name;
	short	type;	/* VAR, BLTIN, UNDEF */
	double val;		/* if VAR */
	struct Symbol	*next;	/* to link to another */
} Symbol;
void genDataSec();
char *genNumero(char *numero);
char *genSuma(void *op1, void *op2);
void emite(char *s);
char *createmporal();


