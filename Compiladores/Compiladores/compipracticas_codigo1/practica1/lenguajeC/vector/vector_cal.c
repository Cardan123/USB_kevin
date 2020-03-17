int yylex (){
  	int c;
  	while ((c = getchar ()) == ' ' || c == '\t')  
  		;
 	if (c == EOF)                            
    		return 0;
  	if (c == '.' || isdigit (c)){
      		ungetc (c, stdin);
      		scanf ("%d", &yylval.ival);
	      	return NUMBER;
    	}
	if(islower(c)){
		yylval.index=c-'a';
		return VAR;
	}
  	return c;                                
}
void init(){
   int i;
   for(i = 0;i < 26;i++)
      mem[i]=creaVector(3);
}
void main() { 
   //init();
   yyparse(); 
}
int yyerror(const char* s) { 
  printf("%s\n", s); 
  return 0; 
}
Vector *creaVector(int n){
   Vector *vec;
   int i;
   vec=(Vector *)malloc(sizeof(Vector));
   vec->n = n;	
   vec->vec = (double *)malloc(sizeof(double)*n);
   return vec;
}
void imprimeVector(Vector *v){
   int i; 
   for(i=0; i< v->n; i++)
      printf("%f ", v->vec[i]);
   printf("\n");
}
Vector *copiaVector(Vector *v){
   int i;
   Vector *copy=creaVector(v->n);
   for(i = 0; i< v->n; i++)
      copy->vec[i]=v->vec[i];	
   return copy;	
}
Vector *sumaVector(Vector *a, Vector *b){
Vector *c;
int i;
   c=creaVector(a->n);
   for(i=0; i< a->n;i++)
      c->vec[i]=a->vec[i]+b->vec[i];
   return c;
}
Vector *restaVector(Vector *a, Vector *b){
Vector *c;
int i;
   c=creaVector(a->n);
   for(i=0; i< a->n;i++)
      c->vec[i]=a->vec[i]-b->vec[i];
   return c;
}
/*
Vector *multiVector(Vector *a, Vector *b){
Vector *c;
int i,j, k; 
double acu;
        c=creaVector(a->n);
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
}*/
