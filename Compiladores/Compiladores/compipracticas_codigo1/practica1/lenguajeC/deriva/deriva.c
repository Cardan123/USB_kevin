struct Nodo{
	double num;
	char oper;
	int tipo;
	struct Nodo *izq;
	struct Nodo *der;
};
typedef struct Nodo *NodoAp;
struct Deriv {
	NodoAp expr;
	NodoAp der;
};
typedef struct Deriv Deriva;

NodoAp creaHoja(double num, NodoAp izq, NodoAp der);
NodoAp creaNodo(char oper, NodoAp izq, NodoAp der);
NodoAp creaNodo_(char oper, NodoAp izq, NodoAp der);
void recorridoIn(NodoAp raiz);
void recorridoPost(NodoAp raiz);
void yyerror (char *s);
int yylex ();

#include <ctype.h>
int yylex (){
  int c;
  double num;
  while ((c = getchar ()) == ' ' || c == '\t')  
    ;
  if (c == '.' || isdigit (c)){
      ungetc (c, stdin);
      scanf ("%lf", &num);
      yylval.expr=creaHoja(num,(NodoAp)NULL,(NodoAp)NULL);
	  yylval.der=creaHoja(0,(NodoAp)NULL,(NodoAp)NULL);
      return NUM;
    }
   if (c=='x'){
		yylval.expr=creaNodo_(c, (NodoAp)NULL,(NodoAp)NULL);
		yylval.der=creaHoja(1,(NodoAp)NULL,(NodoAp)NULL);
		return VAR;
   }
  if (c == EOF)                            
    return 0;
  return c;                                
}
void yyerror (char *s) {
  printf ("%s\n", s);
}
NodoAp creaHoja(double num, NodoAp izq, NodoAp der){
	NodoAp nvo=(NodoAp)malloc(sizeof(struct Nodo));
	nvo->izq=izq; nvo->der=der;
	nvo->num=num;
	nvo->tipo=2;
	return nvo;
}
NodoAp creaNodo_(char oper, NodoAp izq, NodoAp der){
	NodoAp nvo=(NodoAp)malloc(sizeof(struct Nodo));
	nvo->izq=izq; nvo->der=der;
        nvo->oper=oper;
	nvo->tipo=3;
	return nvo;
}
NodoAp creaNodo(char oper, NodoAp izq, NodoAp der){
	NodoAp nvo=(NodoAp)malloc(sizeof(struct Nodo));
	nvo->izq=izq; nvo->der=der;
	nvo->oper=oper;
	nvo->tipo=1;
	return nvo;
}
void recorridoIn(NodoAp raiz){
	if(!raiz) return;
	recorridoIn(raiz->izq);
	if(raiz->tipo==1 || raiz->tipo==3)
		printf("%c",raiz->oper);
	else 
		printf("%g",raiz->num);
	recorridoIn(raiz->der); 
}
void main (){
  yyparse ();
}




