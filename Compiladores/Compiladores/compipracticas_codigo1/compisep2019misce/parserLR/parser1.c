#include<stdio.h>
#include<stdlib.h>
#define EDO 7
#define SIM 6
#define SGR 7
#define RED 3
#define SHIFT 7
#define ACCEPT 8


/* a ( ) ; n o S  */
struct pila {
	int tope;
	void **elementos;
};
typedef struct pila Pila;
/*
1) E->T-E
2) E->T
3) T->F*T
4) T->F
5) F->(E)
6) F->i
*/

int accion[EDO][SIM]={
/*a (  )  ;  $  o      */
  7, 7, 0, 0, 0, 0,  //0
  0, 0, 0, 7, 0, 0,  //1
  0, 0, 0, 0, 8, 0,  //2
  7, 7, 0, 0, 0, 0,  //3
  0, 0, 7, 0, 0, 0,  //4
  0, 0, 1, 1, 0, 0,  //5
  0, 0, 2, 2, 0, 0,  //6
};
int sig_edo[EDO][SGR]={
 /*0 1  2  3  4  5  6  7  8  9   */
 /*a (  )  ;  $  S o */
   6, 3, 0, 0, 0, 1, 0,  //0
   0, 0, 0, 2, 2, 0, 0,  //1
   0, 0, 0, 0, 8, 0, 0,  //2
   6, 3, 0, 0, 0, 4, 0, //3
   0, 0, 5, 0, 0, 0, 0,  //4
   0, 0, 0, 0, 0, 0, 0,  //5
   0, 0, 0, 0, 0, 0, 0, //6
};
/*                S  S */
int lhs[RED]={ 4, 5, 5};
char *lizq[]={ 0, 0, 0, 0, 0, "S",};
char *reglas[]={"S1","S->(S)","S->a"};
/*                    E  E  T  T  F  F */
int no_elem[RED]={ 2, 3, 1};
int simbolo;
Pila *p;
Pila *creaPila(int tama){
	Pila *nvo;
	nvo=(Pila *)malloc(sizeof(Pila));
	nvo->tope=0;
	nvo->elementos=(void **)malloc(sizeof(void *)*tama);
	return nvo;
}
int estaVacia(Pila *p){
	return p->tope==0;
}
void *top(Pila *p){
	if(!estaVacia(p))
		return p->elementos[p->tope-1];
	return (void *)NULL;
}
void *pop(Pila *p){
	if(!estaVacia(p)){
		p->tope=p->tope-1;
		return p->elementos[p->tope];
	}
	return (void *)NULL;
}
void push(Pila *p, void *dato){
	p->elementos[p->tope]=dato;
	p->tope=p->tope+1;	
}
int *creaInt(int d){
   int *nvo=(int *)malloc(sizeof(int));
   *nvo=d;
   return nvo;
}

int sigtoken(){
   int ch;
   while ((ch=getchar()) == ' ' || ch == '\t')
		;
   if (ch == '\n'){
      return 4;
   } else if (ch == 'a'){
      return 0;
   } else if (ch == '('){
      return 1;
   } else if (ch == ')'){
      return 2;
   } else if (ch == ';'){
      return 3;
   } else {
      return 5;
   }
}
void parser(){
    int t;
    int edo = 0;
    int red, i;
    while(1){
        edo = *((int *)top(p)) ;
        printf("while shift edo: (%d,%d)\n", edo, accion[edo][simbolo]);
        if(accion[edo][simbolo] == SHIFT){ /* shift*/
            t = sig_edo[edo][simbolo];
            printf("shift edo: (%d)\n", t);
            push(p, creaInt(t));
            simbolo = sigtoken();
            printf("shift token: (%d)\n", simbolo);
        }
        else if(accion[edo][simbolo] == 0){ /*error*/
            puts("error de sintax");
            exit(1);
        }
        else if((red = accion[edo][simbolo]) < 7 ){ /*reduc */
            printf("reduc : %s #sglder %d \n", reglas[red], no_elem[red]);
            for(i=1; i<= no_elem[red];i++)
            printf("pop edo: %d \n", *((int *)pop(p)));
            printf(
                   "edo cima: %d lhs= %s sig=(%d)\n", *((int *)top(p)),
                   lizq[lhs[red]], sig_edo[*((int *)top(p))][lhs[red]]);
            t = sig_edo[*((int *)top(p))][lhs[red]];
            if( t == 0){
                puts("error de sintax");
                exit(1);
            }
            push(p, creaInt(t));
            printf("push edo: %d\n", t);
        }
        else if(accion[edo][simbolo] == ACCEPT){ /* acept */
            puts("acept");
            exit(0);     
        }
    }
}
void main(){
   int valor1 = 0;
   
   p=creaPila(20);
   push(p, creaInt(valor1));
   simbolo = sigtoken();
   parser();
}
