
struct matriz {
	char name;
	int n;
	double **mat;
};
typedef struct matriz Matriz;
Matriz *creaMatriz(int n);
void imprimeMatriz(Matriz *a);
Matriz *copiaMatriz(Matriz *a);
Matriz *sumaMatriz(Matriz *a, Matriz *b);
Matriz *restaMatriz(Matriz *a, Matriz *b);
Matriz *multiMatriz(Matriz *a, Matriz *b);
void invierteMatriz(Matriz *orig, Matriz *inv) ;
