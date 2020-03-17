#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ATRI 	1
#define VAL  	2 
#define GE	3
#define GT	4
#define LE	5
#define LT 	6
#define EQ	7

char operadores[]={
' ', /*0*/
' ',/*1*/
' ',/*2*/
'>',/*3*/
'g',/*4*/
'<',/*5*/
'l',/*6*/
'='/*7*/
};


struct nodoL {
   void *info;
   struct nodoL *sig;
};

typedef struct nodoL NodoL;

struct nodoArb {
	struct nodoArb* izq;
	struct nodoArb* der;
	void *info;
};
typedef struct nodoArb  NodoArb;
struct opera {
        void *(*igual)(void *);
        char operador;    
        char tipo;  
};

typedef struct opera Opera;

struct perro{
	char nombre[1000];
	char raza[1000];
	int edad;
	char genero;
};
typedef struct perro Perro;

typedef enum { FALSE=0,TRUE} Bool;

typedef  void *(*apfuncompa)(void *);

int preanalisis;

NodoArb *izq, *der;

char atributo[200];
char valor[200];

void expr();
void masterminos();
void termino();
void masfactores();
void factor();
int cmpPerroNombre(void *p1, void *p2);
int cmpPerroRaza(void *p1, void *p2);
int cmpPerroEdad(void *p1, void *p2);
int cmpPerroGen(void *p1, void *p2);

NodoL *find(NodoL  *inicio, void *key, int (*igual)(void *, void *));
NodoL *findGen(NodoArb *raiz,NodoL  *inicio, void *key, void (*f)(void *));
Bool evalua(NodoArb *raiz, NodoL *p, void *dato);

void imprime(NodoL *inicio, void (*f)(void *));
void imprimeArb(NodoArb *raiz);
void clonar(NodoL *inicio1, NodoL **inicio2,void *(*copyInfo)(void *));
NodoL *creaPila(NodoL **stack);
int estaVacia(NodoL *stack);
NodoL *push(NodoL **stack, void *dato);
void *top(NodoL *stack);
NodoL *pop(NodoL **stack);
NodoArb *creaNodoArb(void *dato, NodoArb *izq, NodoArb *der);
Opera *creaOpera(char operador,char tipo,void *(*igual)(void *));

void *PerroNombre(void *p);
void *PerroEdad(void *p);
void *PerroRaza(void *p);
void *PerroGenero(void *p);
apfuncompa arreapunf[]={
PerroNombre,
PerroRaza,
PerroEdad,
PerroGenero
};
char tipos[]={
's',
's',
'i',
'c'
};
apfuncompa propiedad;
char *atributos[]={
	"nombre",
        "raza",
        "edad",   
        "genero",
        NULL
};
char *valores[100];
int posi=-1;
int yylval;

NodoL *pila=NULL;
int busca(char **atributos, char *cad){
	int i;
	for(i=0;atributos[i];i++){
                printf("atr=(%s) cad=(%s) ",atributos[i], cad);
		if(!strcmp(atributos[i],cad))
			return i;
        }
	return -1;
}
void parea(char t){
	if(t==preanalisis)
		preanalisis=analex();
	else {
		puts("error de sintaxis");
		exit(1);
	}
}
void termino(){
	factor();masterminos();
}
void masterminos(){
	if(preanalisis=='|'){
		parea('|');factor();
        	der=(NodoArb *)(pop(&pila)->info);
                izq=(NodoArb *)(pop(&pila)->info);
                push(&pila, creaNodoArb(creaOpera('|',' ',NULL), izq, der) );
		//push(&pila, creaNodoArb(strdup("+"),izq,der) );
        	masterminos();
	}
	else if(preanalisis=='&'){
		parea('&');factor();
        	der=(NodoArb *)(pop(&pila)->info);
                izq=(NodoArb *)(pop(&pila)->info);
		push(&pila, creaNodoArb(creaOpera('&',' ',NULL), izq, der) );
                //push(&pila, creaNodoArb(strdup("&"),izq,der) );
        	masterminos();
	}
	else ;
}

follow(int expect,   int ifyes,   int ifno, int *oper)  /*   buscar  >=, etc.   */ 
{
int c  = getchar();
if  (c  ==  expect){
*oper=operadores[ifyes];
return ifyes; 
}
ungetc(c,   stdin); 
*oper=operadores[ifno];
return  ifno;
}
void factor(){
    char cados[2];
    char cad[300];
    int indice=-1;
    int oper;
    
    if(preanalisis=='('){
         parea('(');termino();parea(')');
    } 
    else if(preanalisis==ATRI){
	parea(ATRI); indice=posi;
        strcpy(cad,atributo);
        atributo[0]=0;
        printf("preana=(%c) ",preanalisis);
        switch (preanalisis) {
				 
	case '>':                preanalisis=follow('=', GE, GT,&oper);
				 parea( preanalisis);
				 break;
	case '<':                
				 puts("2o");
                                 preanalisis=follow('=', LE, LT,&oper);
				 parea( preanalisis);
				 break;
				 
	case '=':                preanalisis=follow('=', EQ, EQ ,&oper);
				 parea( preanalisis);
				 break;
        default:                 puts("se esperaba comp"); 
				 break;
        }
        printf("oper=(%c) ",oper);
        parea(VAL);
        valores[indice]=strdup(valor);
        printf("ind=<%d> posi=<%d> tipo=(%c) val=(%s)",
                indice, posi, tipos[indice], valores[indice]);
        //posi=-1;
        strcat(cad,valor);
        izq=creaNodoArb(creaOpera(oper,tipos[indice],propiedad),(NodoArb *)NULL,(NodoArb *)NULL);
        //izq=creaNodoArb(strdup(cad),NULL,NULL);
        valor[0]=0;
        push(&pila, izq); 
    }  
    else {
	puts("error de sintaxis");
	exit(1);
    }
}
int analex(){
	int c;

  	while ((c = getchar ()) == ' ' || c == '\t')  
  		;
 	if (c == EOF)                            
    		return 0;
  	if (c == '.' || isdigit (c))                
    	{	
      		ungetc (c, stdin);
      		scanf ("%d", &yylval);
                sprintf(valor, "%d",yylval);
	      	return VAL;
    	}
	if(isalpha(c)){
		char sbuf[200], *p=sbuf;
		do {
			*p++=c;
		} while ((c=getchar())!=EOF && isalnum(c));
		ungetc(c, stdin);
		*p='\0';
                printf("ant if posi=(%d) sbuf=(%s) ",posi, sbuf);
                posi=busca(atributos,sbuf);
                if(posi!=-1){
                        strcpy(atributo,sbuf);
                        printf("posici=(%d) atrib=(%s) sbuf=(%s) ",
                        posi, atributo, sbuf);
                        propiedad=arreapunf[posi];
			return ATRI;
                }
		else {
                        strcpy(valor,sbuf);
			return VAL;
		}
	}
	return c; 
}

NodoL *creaNodoL(void *info, NodoL *sig ){
   NodoL *nvo;
   nvo=(NodoL *)malloc(sizeof(NodoL));
   if(!nvo){
	puts("no hay memoria para crear NodoL");
        return (NodoL *)NULL;
   }
   nvo->info=info;
   nvo->sig=sig;
   return nvo;
}

NodoArb *creaNodoArb(void *dato,NodoArb *izq,NodoArb *der){
	NodoArb *nvo;
	nvo=(NodoArb *)malloc(sizeof(NodoArb));
        if(!nvo){
	    puts("no hay memoria para crear NodoL");
            return (NodoArb *)NULL;
        }
        nvo->izq=izq;
        nvo->der=der;
        nvo->info=dato;
        return nvo;
}
Opera *creaOpera(char operador,char tipo,void *(*igual)(void *)){
	 Opera *nvo;
	
	nvo=(Opera *)malloc(sizeof(Opera));
        if(!nvo){
	    puts("no hay memoria para crear NodoL");
            return (Opera *)NULL;
        }
        nvo->operador=operador;
        nvo->igual=igual;
        nvo->tipo=tipo;
        return nvo;
}
NodoL *remueve(NodoL **cab){
   NodoL *p;
   if(!*cab){
      puts("remueve: lista vacia");
      return (NodoL *)NULL;
   }
   p=*cab;
   *cab=p->sig;
   p->sig=(NodoL *)NULL;
   return p;
}
NodoL *remueve_(NodoL **cab,  NodoL *p){
   NodoL *q,*r;
   if(!*cab){
      puts("remueve: lista vacia");
      return (NodoL *)NULL;
   }
   if(p==*cab){
	*cab=p->sig;
	p->sig=(NodoL *)NULL;  
        return *cab;  
   }
   for(q=(*cab) , r=q->sig; r ;q=q->sig,r=r->sig){
	if(p==r){
             q->sig=r->sig;
             r->sig=(NodoL *)NULL;
             return *cab;
	}
   }
   return *cab;  
}
Perro *creaPerro(char nombre[], char raza[], int edad, char genero){
	Perro *nvo;
	nvo = (Perro*)malloc(sizeof(Perro));
	strcpy(nvo -> nombre, nombre);
	strcpy(nvo -> raza, raza);
	nvo -> edad = edad;
	nvo -> genero = genero;
	return nvo;
}
void imprimePerro(void *p){
	Perro *pe = (Perro *)p;
	printf("\n");
	puts(pe -> nombre);
	puts(pe -> raza);
	printf("%d \n", pe->edad);
	printf("%c \n", pe->genero);
}
void *copiaPerro(void *p){
	Perro *pe = (Perro *)p;
	return creaPerro(pe->nombre, pe->raza, pe->edad, pe->genero);
}
int cmpPerroNombre(void *p1, void *p2){
	Perro *pe1 = (Perro *)p1;
	Perro *pe2 = (Perro *)p2;
	return strcmp(pe1->nombre, pe2->nombre);
}
int cmpPerroRaza(void *p1, void *p2){
	Perro *pe1 = (Perro *)p1;
	Perro *pe2 = (Perro *)p2;	
	return strcmp(pe1->raza, pe2->raza);
}
int cmpPerroEdad(void *p1, void *p2){
	Perro *pe1 = (Perro *)p1;
	Perro *pe2 = (Perro *)p2;
	return(pe1->edad - pe2->edad);
}
int cmpPerroGen(void *p1, void *p2){
	Perro *pe1 = (Perro *)p1;
	Perro *pe2 = (Perro *)p2;
	return (pe1->genero != pe2->genero);
}
void *PerroNombre(void *p){
        return (void *)((Perro*)p)->nombre;
}
void *PerroEdad(void *p){
	 return (void *)&( ((Perro*)p)->edad);
}
void *PerroRaza(void *p){
        return (void *) &( ((Perro*)p)->raza);
}
void *PerroGenero(void *p){
        return (void *)& (((Perro*)p)->genero);
}
void imprime(NodoL *inicio, void (*f)(void *)){
   NodoL *p;  
    if(!inicio){
      puts("imprime:lista vacia");
      return ;
   }
   for(p=inicio;p;p=p->sig)
      (*f)(p->info);
}
void clonar(NodoL *inicio1, NodoL **inicio2,void *(*copyInfo)(void *)){
   NodoL *p;
   
    if(!inicio1){
      puts("imprime:lista vacia");
      return ;
   }
   *inicio2=(NodoL *)NULL;
   for(p=inicio1;p;p=p->sig){
      *inicio2=creaNodoL((*copyInfo)(p->info), *inicio2);
   }
}
NodoL *find(NodoL  *inicio, void *key, int (*igual)(void *, void *)){
	NodoL *p;
	for(p=inicio;p;p=p->sig)
             if(!(*igual)(p->info, key))
		return p;
	return p;
}

NodoL *findGen(NodoArb *raiz,NodoL  *inicio, void *key, void (*f)(void *)){
	NodoL *p;
        puts("findgen");
	for(p=inicio;p;p=p->sig){
             (*f)(p->info);
             puts("================================");
             (*f)(key);
             //Bool evalua(NodoArb *raiz, NodoL *p, void *dato)
             if(evalua(raiz,p, key))
		return p;   
        }
	return p;
}
NodoL *creaPila(NodoL **stack){
	*stack=(NodoL *)NULL;
	return *stack;
}
int estaVacia(NodoL *stack){
	return !stack;
}
NodoL *push(NodoL **stack, void *dato){
	*stack=creaNodoL(dato, *stack );
       return *stack; 
}
void *top(NodoL *stack){
	return stack->info;
}
NodoL *pop(NodoL **stack){
	return remueve(stack);
	
}
/*
NodoArb *creaNodo(char operador,int (*igual)(void *, void *),NodoArb *operand1,NodoArb *operand2)
{
	NodoArb *nvo;
	
	nvo=(NodoArb *)malloc(sizeof(NodoArb));
        if(!nvo){
	    puts("no hay memoria para crear NodoL");
            return (NodoArb *)NULL;
        }
        nvo->_operand1=operand1;
        nvo->_operand2=operand1;
        nvo->operador=operador;
        nvo->igual=igual;
        return nvo;
}
*/
   /*
                logi=  *(int *)( (((Opera *)raiz->info)->igual)(p->info) ) == 
                           *(int *)( (((Opera *)raiz->info)->igual)(dato)  );
                printf("evaint (%d, %d) logi=<%d>\n", *(int *)( (((Opera *)raiz->info)->igual)(p->info) ) , 
                           *(int *)( (((Opera *)raiz->info)->igual)(dato)  ) , logi);*/
Bool evalua(NodoArb *raiz, NodoL *p, void *dato){
        int logi;
        void *op1, *op2;     
        //puts("evalua");
        putchar(((Opera *)raiz->info)->operador);
	if( ((Opera *)raiz->info)->igual){
            op1=(((Opera *)raiz->info)->igual)(p->info);
            op2=(((Opera *)raiz->info)->igual)(dato) ;
           //return !(((Opera *)raiz->info)->igual)(p->info,dato);
           if( ((Opera *)raiz->info)->operador=='='){
                if( ((Opera *)raiz->info)->tipo=='c'){      
                	return   *(char *)op1 == *(char *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='i'){      
                	return   *(int *)op1 == *(int *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='f'){
                	return  *(float *)op1 == *(float *)op2;
           	}
                if( ((Opera *)raiz->info)->tipo=='d'){
                	return  *(double *)op1 == *(double *)op2;
           	}
           	return !strcmp(  (char *) op1, (char *) op2);
           }
           if( ((Opera *)raiz->info)->operador=='!'){
                if( ((Opera *)raiz->info)->tipo=='c'){      
                	return   *(char *)op1 != *(char *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='i'){      
                	return   *(int *)op1 != *(int *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='f'){
                	return  *(float *)op1 != *(float *)op2;
           	}
                if( ((Opera *)raiz->info)->tipo=='d'){
                	return  *(double *)op1 != *(double *)op2;
           	}
           	return strcmp(  (char *) op1, (char *) op2);
           }
           if( ((Opera *)raiz->info)->operador=='l'){
                 if( ((Opera *)raiz->info)->tipo=='c'){      
                	return   *(char *)op1 < *(char *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='i'){      
                	return   *(int *)op1 < *(int *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='f'){
                	return  *(float *)op1 < *(float *)op2;
           	}
		if( ((Opera *)raiz->info)->tipo=='d'){
                	return  *(double *)op1 < *(double *)op2;
           	}
                return strcmp(  (char *) op1, (char *) op2) < 0;
           }
           if( ((Opera *)raiz->info)->operador=='<'){
                 if( ((Opera *)raiz->info)->tipo=='c'){      
                	return   *(char *)op1 <= *(char *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='i'){      
                	return   *(int *)op1 <= *(int *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='f'){
                	return  *(float *)op1 <= *(float *)op2;
           	}
		if( ((Opera *)raiz->info)->tipo=='d'){
                	return  *(double *)op1 <= *(double *)op2;
           	}
                return strcmp(  (char *) op1, (char *) op2) <= 0;
           }
            if( ((Opera *)raiz->info)->operador=='g'){
                if( ((Opera *)raiz->info)->tipo=='c'){      
                	return   *(char *)op1 > *(char *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='i'){      
                	return   *(int *)op1 > *(int *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='f'){
                	return  *(float *)op1 > *(float *)op2;
           	}
                if( ((Opera *)raiz->info)->tipo=='d'){
                	return  *(double *)op1 > *(double *)op2;
           	}
                return strcmp(  (char *) op1, (char *) op2) > 0;
           }
	   if( ((Opera *)raiz->info)->operador=='>'){
                if( ((Opera *)raiz->info)->tipo=='c'){      
                	return   *(char *)op1 >= *(char *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='i'){      
                	return   *(int *)op1 >= *(int *)op2;
           	}
           	if( ((Opera *)raiz->info)->tipo=='f'){
                	return  *(float *)op1 >= *(float *)op2;
           	}
                if( ((Opera *)raiz->info)->tipo=='d'){
                	return  *(double *)op1 >= *(double *)op2;
           	}
                return strcmp(  (char *) op1, (char *) op2) >= 0;
           }
        }
        if( ((Opera *)raiz->info)->operador=='&')
           return  evalua(raiz->izq,p,dato) &&  evalua(raiz->der,p,dato);
	 if( ((Opera *)raiz->info)->operador=='|')
           return  evalua(raiz->izq,p,dato) ||  evalua(raiz->der,p,dato);
	
} 
Perro perros[]={
{"fido","criollo",0,'M'},
{"solovino","dalmata",2,'M'},
{"daysi","boxer",2,'H'},
{"pulgas","dalmata",2,'M'},
{"kaiser","dalmata",2,'M'},
{"manchas","labrador",3,'M'}
};
NodoL *cab=NULL;
NodoL *cab1=NULL;
NodoL *satis=NULL;
NodoL *satis1=NULL;
NodoL *satis2=NULL;
NodoL *satis3=NULL;
NodoL *satis4=NULL;
void encuentra(NodoL *inicio, NodoL **cumplen,  void *info, int (*igual)(void *, void *),void *(*copyInfo)(void *)){    
     NodoL *enc;     
     if(!inicio){
      puts("Encuentra:lista vacia");
      return ;
     }
     enc=find(inicio,info,igual);
     for(;enc;){
         remueve_(&inicio, enc);
         *cumplen=creaNodoL((*copyInfo)(enc->info), *cumplen);
         enc=find(inicio, info,igual);
     }    
}
void encuentraGen(NodoArb *raiz,NodoL *inicio, NodoL **cumplen,  void *info,void *(*copyInfo)(void *), void (*f)(void *)){    
     NodoL *enc;   
     if(!inicio){
      puts("Encuentra:lista vacia");
      return ;
     }
     puts("encGen");
     enc=findGen(raiz,inicio,info,f);
     for(;enc;){
         remueve_(&inicio, enc);
         *cumplen=creaNodoL((*copyInfo)(enc->info), *cumplen);
         enc=findGen(raiz,inicio, info,f);
     }  
}
int main(){
    NodoArb *a1,*raiz;
    Perro *e;
    int i, edad;

    for(i=0; i< sizeof(perros)/ sizeof(Perro);i++){
    	e=creaPerro( perros[i].nombre, perros[i].raza,perros[i].edad, perros[i].genero);
        cab=creaNodoL((void *)e, cab);
    }
    imprime(cab, imprimePerro);
    clonar(cab,&cab1,copiaPerro);
     
    creaPila(&pila);
    preanalisis=analex();
    termino();
    raiz=(NodoArb *)(pop(&pila)->info);
    //imprimeArb((NodoArb *)(pop(&pila)->info));
    edad=atoi(valores[1]);
    //escribir raza=dalmata
    e=creaPerro( " "/*valores[0]*/, valores[1], 0 /*edad*/, ' ');
    //puts(valores[0]);
    encuentraGen(raiz, cab1, &satis4, e, copiaPerro, imprimePerro);

    puts("Cumplen5---------------------------------------------------");
    imprime(satis4,imprimePerro);
    putchar('\n');
} 








