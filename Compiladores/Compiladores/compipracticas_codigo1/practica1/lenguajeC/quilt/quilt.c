#include "quilt.h"

int yylex(); 
void yyerror(char *s); 
Colcha *crea(int n, int m){
	char **p;
	int i;
	Colcha *c;
	c=(Colcha* )malloc(sizeof(Colcha));
        c->alto=n;
	c->ancho=m;
	c->mat=(char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++){
		c->mat[i]=(char *)malloc(m*sizeof(char));
	}
	return c;
}
Colcha *B(){
        Colcha *c=crea(2, 2);
        c->mat[0][0]='|';
	c->mat[0][1]='|';
	c->mat[1][0]='|';
	c->mat[1][1]='|';
	return c;
}
void print(Colcha *c){
	int i, j;       
	for(i=0;i< c->alto;i++){
		for(j=0;j< c->ancho;j++){
     			putchar(c->mat[i][j]);
		}
		putchar('\n');
	}
}
int yylex(){
	int c; 
   	while((c=getchar()) == ' ' || c == '\t') 
   		; 
  	if(c == EOF) 
  		return 0; 
	if(c=='r')
		return ROTA;
	if(c=='c')
		return COSE;
	return c;
}
void main() { 
   yyparse();  
}
void yyerror(char *s){
   puts(s);
}
