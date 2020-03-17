#include <string.h>

struct racional {
	int num, den;
}; 
typedef struct racional Racional;
typedef struct racional* RacionalAP;
/*  prototypes of the provided functions */ 
Racional *creaRacional(int num, int den);
void asignar(Racional *r, int num, int den);
int numerador(Racional *r);
int denominador(Racional *r);
Racional* racionalSuma(Racional *r, Racional *s);
Racional* racionalResta(Racional *r, Racional *s);
Racional* racionalMultiplicar(Racional *r, Racional *s);
Racional* racionalDividir(Racional *r, Racional *s);
int esIgual(Racional *r, Racional *s);
void imprimirR(void *r);
Racional *copiar(Racional *r);
/*  prototypes of the provided functions */ 
/* define the return type of FLEX */
#define YYSTYPE RacionalAP
