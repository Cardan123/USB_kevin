int yylex (){
  	int c;

  	while ((c = getchar ()) == ' ' || c == '\t')  
  		;
 	if (c == EOF)                            
    		return 0;
  	if (c == '.' || isdigit (c)){
      		ungetc (c, stdin);
      		scanf ("%lf", &yylval.dval);
	      	return NUMBER;
    	}
	if(islower(c)){
		yylval.index=c-'a';
		return VAR;
	}
  	return c;                                
}
int main() { return yyparse(); }
int yyerror(const char* s) { 
  printf("%s\n", s); 
  return 0; 
}
Matriz *creaMatriz(int n){
Matriz *mat;
int i;
	mat=(Matriz *)malloc(sizeof(Matriz));
	mat->n=n;
	mat->mat=(double **)malloc(sizeof(double *) * n);
	for(i=0; i< n;i++)
        	mat->mat[i]=(double *)malloc(sizeof(double)*n);
        return mat;
}
void imprimeMatriz(Matriz *a){
int i,j; 
        printf("\n");
	for(i=0; i< a->n;i++){
		for(j=0; j < a->n;j++)
			printf("%f ", a->mat[i][j]);
		printf("\n");
	}
        printf("\n");
}
Matriz *copiaMatriz(Matriz *a){
int i,j;
Matriz *copy=creaMatriz(a->n);
	for(i=0; i< a->n;i++){
		for(j=0; j < a->n;j++)
			copy->mat[i][j]=a->mat[i][j];
	}
return copy;	
}
Matriz *sumaMatriz(Matriz *a, Matriz *b){
Matriz *c;
int i,j;
        c=creaMatriz(a->n);
	for(i=0; i< a->n;i++)
		for(j=0; j < a->n;j++)
			c->mat[i][j]=a->mat[i][j]+b->mat[i][j];
	return c;
}
Matriz *restaMatriz(Matriz *a, Matriz *b){
Matriz *c;
int i,j;
        c=creaMatriz(a->n);
	for(i=0; i< a->n;i++)
		for(j=0; j < a->n;j++)
			c->mat[i][j]=a->mat[i][j]-b->mat[i][j];
	return c;
}
Matriz *multiMatriz(Matriz *a, Matriz *b){
Matriz *c;
int i,j, k; 
double acu;
        c=creaMatriz(a->n);
	for(i=0; i< a->n;i++)
		for(j=0; j < a->n;j++){
			acu=0;
			for(k=0; k < a->n;k++){
                         
				acu=acu+a->mat[i][k]*b->mat[k][j];
				//printf("<%f,%f,%f> ",a->mat[i][k],b->mat[k][j],acu);
                        }             
                        //printf("\n");
			c->mat[i][j]=acu;
		}
	return c;
}
MatrizAP potencia(MatrizAP m, int expo){
    int i, j, k, w;
    double sum;
    MatrizAP y;
    MatrizAP temp;
    y=creaMatriz(m->n);
    temp=creaMatriz(m->n);
    for( i = 0 ; i < m->n ; ++ i ){
        for( j = 0 ; j < m->n ; ++ j ) {
            y->mat[i][j] = i== j;
        }
    }
    for(w=0;w< expo;w++)  {
        for(i=0;i<m->n;i++){
            for(j=0;j<m->n;j++){
                sum=0;
                for(k=0;k<m->n;k++)
                    sum=sum+y->mat[i][k]*m->mat[k][j];
                temp->mat[i][j] = sum;
            }
        }
        for(i=0;i<m->n;i++){
            for(j=0;j<m->n;j++)
            {
                y->mat[i][j]=temp->mat[i][j];
            }
        }
    }
    //free(temp);
    return y;
}
void invierteMatriz(Matriz *orig, Matriz *inv/*, double determ*/) {
// Algoritmo para la eliminación simple de Gauss
	int i, j, k;
	double factor;
	double **L, *D, *X;
        double determ;
        double **a=copiaMatriz(orig)->mat;
        double **ainv=inv->mat;   
        int n=orig->n;
	X=(double*)malloc(sizeof(double)*n); D=(double*)malloc(sizeof(double)*n);
	L =(double**)malloc(sizeof(double *)*n);	
	for (j = 0; j < n; j++) 
		L[j] =(double*)malloc(sizeof(double)*n);
	for (k = 0; k < n - 1; k++) {		
		for (i = k+1; i < n;  i++) {
			factor = a[i][k]/a[k][k];          
                        //printf("fact=<%f> ", factor);
			for (j = k+1; j < n + 1; j++) {
				a[i][j] = a[i][j] - factor * a[k][j];
			}
		}
	}
// Cálculo del determinante
        determ = 1.;
	for (i = 0; i < n; i++) {
		determ = determ * a[i][i];
	}
if (determ != 0) {
// Rutina para determinar las matrices L (inferior) y U (superior) de la 
// descomposición LU
        for (i = 0; i < n; i++) {
               for (j = 0; j < n; j++) {
                  if (i > j) { 
                      L[i][j] = a[i][j]/a[j][j];
                      a[i][j] = 0;
                   }
               }
        }
       for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                  L[j][j] = 1;
            }
        }
// Implementación de la rutina para el cálculo de la inversa
 for (k = 0; k < n; k++) {
// Esta rutina inicializa los L[i][n] para ser utilizados con la matriz L
          for (i = 0; i < n; i++) {
               if (i == k) L[i][n] = 1;
               else  L[i][n] = 0;
           }
// Esta función implementa la sustitución hacia adelante con la matriz L y los L[i][n]
// que produce la rutina anterior
  double sum;
  D[0] = L[0][n];

  for (i = 1; i < n; i++) {
       sum = 0;
       for (j = 0; j < i; j++) {
            sum = sum + L[i][j]*D[j];
       }

        D[i] = L[i][n] - sum;
   }
// Esta rutina asigna los D[i] que produce forward para ser utilizados con la matriz U
  for (i = 0; i < n; i++) {
          a[i][n] = D[i];
  }
// Rutina que aplica la sustitución hacia atras
 X[n-1] = a[n-1][n]/a[n-1][n-1];
 // Determinación de las raíces restantes
  for (i = n - 2; i > -1; i--) {
        sum = 0;
        for (j = i+1; j < n; j++) {
              sum = sum + a[i][j]*X[j];
         }
         X[i] = (a[i][n] - sum)/a[i][i];
   }
// Esta rutina asigna los X[i] que produce Sustituir como los elementos de la matriz inversa
  for (i = 0; i < n; i++) {
         ainv[i][k] = X[i];
  }
 }   // llave de cierre del for para k
}   // cierre del if
	free(L); free(D); free(X);
}
