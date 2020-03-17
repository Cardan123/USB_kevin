struct nodoL {
	void *dato;
	struct nodoL *sig;
};
typedef struct nodoL NodoL;
struct symbol { 
	char   *name;
	short   type;   
	union {
                double val;	  	      
		double (*ptr)(double);     
	} u;
};
typedef struct symbol Symbol;
NodoL *lookup(char *s);
NodoL *install(char *s,int t, double d);
void init( );
