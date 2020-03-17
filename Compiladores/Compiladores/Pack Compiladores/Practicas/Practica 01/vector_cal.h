#include <stdio.h>
#include <math.h>

struct vector {
	char name;
	int n;
	double *vec;
};
typedef struct vector Vector;
Vector *creaVector(int n);
void imprimeVector(Vector *a);
Vector *copiaVector(Vector *a);
Vector *sumaVector(Vector *a, Vector *b);
Vector *restaVector(Vector *a, Vector *b);
Vector *escalarVector(double escalar, Vector *a);
double productoPunto(Vector *a, Vector *b);
Vector *productoCruz(Vector *a, Vector *b);
double magnitudVector(Vector *a);
//Vector *multiVector(Vector *a, Vector *b);
