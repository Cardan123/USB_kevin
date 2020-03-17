struct nodoL {
	void *dato;
	struct nodoL *sig;
};
typedef struct nodoL NodoL;
union Symval { /* value of a symbol */
	void	*val;		/* VAR */
	void	*(*ptr)(void *);	/* BLTIN */
};
typedef union Symval Symval;
struct simbolo { /* entrada en la tabla de símbolos */
char   *nombre;
short  tipo;
Symval  u;
};
typedef struct simbolo Simbolo;

NodoL *creaNodoL(void *dato, NodoL *sig);
Simbolo* lookup(NodoL *env, char* s);
Simbolo *install(NodoL **env, char *s, int t, void *d);

double *creaDoble(double d);
void * addDoble(void *dob1, void *dob2);
void *subDoble(void *dob1, void *dob2);
void *mulDoble(void *dob1, void *dob2);
void *div_Doble(void *dob1, void *dob2);
void *powerDoble(void *dob1, void *dob2);
void printDoble(void *dob);
void *negateDoble(void *dob);






