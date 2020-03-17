struct colcha {
	int alto;
	int ancho;
	char **mat;
};
typedef struct colcha Colcha;
typedef struct colcha *ColchaAP;

Colcha *crea(int n, int m);
Colcha *A();
Colcha *B();
void map(int n, int i, int j,int *i_, int *j_);
Colcha *rota(Colcha *orig);
Colcha *cose(Colcha *c1, Colcha *c2);
void print(Colcha *c1);
