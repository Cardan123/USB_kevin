#include<stdio.h>
#include<stdlib.h>
#define EDO 13
#define SIM 8
#define SGR 11
#define RED 7

struct pila {
	int tope;
	void **elementos;
};
typedef struct pila Pila;

int accion[EDO][SIM]={
  7, 0, 0, 7, 0, 0, 0, 0, //0
  0, 7, 0, 0, 0, 7, 0, 0, //1
  0, 2, 0, 0, 2, 2, 0, 0, //2
  0, 4, 7, 0, 4, 4, 0, 0, //3
  0, 6, 6, 0, 6, 6, 0, 0, //4
  7, 0, 0, 7, 0, 0, 0, 0, //5
  0, 0, 0, 0, 0, 0, 8, 0,
  7, 0, 0, 7, 0, 0, 0, 0,
  0, 1, 0, 0, 1, 1, 0, 0,
  0, 7, 0, 0, 7, 0, 0, 0,
  0, 5, 5, 0, 5, 5, 0, 0,
  7, 0, 0, 7, 0, 0, 0, 0,
  0, 3, 0, 0, 3, 3, 0, 0
};
int sig_edo[EDO][SGR]={
   4, 0, 0, 5, 0, 0, 0, 1, 2, 3, 0, 
   0, 7, 0, 0, 0, 6, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   4, 0, 0, 5, 0, 0, 0, 9, 2, 3, 0,
 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   4, 0, 0, 5, 0, 0, 0, 0, 8, 3, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 7, 0, 0, 10, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   4, 0, 0, 5, 0, 0, 0, 0, 12, 3, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
int lhs[RED]={ 6, 7, 7, 8, 8, 9, 9 };
int no_elem[RED]={ 2, 3, 1, 3, 1, 3, 1 };

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
      return 6;
   } else if (ch == 'i'){
      return 0;
   } else if (ch == '-'){
      return 1;
   } else if (ch == '*'){
      return 2;
   } else if (ch == '('){
      return 3;
   } else if (ch == ')'){
      return 4;
   } else if (ch == ';'){
      return 5;
   } else {
      return 7;
   }
}
void main(){
   int valor1 = 0;
   int token, t;
   int edo = 0;
   int red, simbolo, i;
   Pila *p;
   p=creaPila(20);
   push(p, creaInt(valor1));
   simbolo = sigtoken();
   while(1){
      edo = *((int *)top(p)) ;
      //printf("while (1) edo (%d) \n", edo);
      printf("while (1) edo (%d) simbo : (%d) red=(%d)\n", 
                 edo, simbolo, accion[edo][simbolo]);
      if(accion[edo][simbolo] == 7){ /* shift*/
         t = sig_edo[edo][simbolo];
         printf("shift edo: (%d)\n", t);
         push(p, creaInt(t));
         simbolo = sigtoken();
         //printf("edo (%d) simbo : (%d) red=(%d)\n", 
         //        edo, simbolo, accion[edo][simbolo]);
         //printf("edo (%d) simbo : (%d) red=(%d)\n", 
         //       *((int *)top(p)), simbolo, accion[*((int *)top(p))][simbolo]);
         continue;
      }
      else if(accion[edo][simbolo] == 0){ /*error*/
         
         puts("error");
         exit(1);
      }
      else if((red = accion[edo][simbolo]) < 7 ){ /*reduc */
         printf("reduc : %d\n", red);
         for(i=1; i<= no_elem[red];i++)
            printf(".. edo: %d\n", *((int *)pop(p)));
         t = sig_edo[*((int *)top(p))][lhs[red]];
         if( t == 0){
            exit(1);
         }
         push(p, creaInt(t));
         printf("push edo: %d\n", t);
      }
      else if(accion[edo][simbolo] == 8){ /* acept */
          puts("acept");
          exit(0);     
      }
   }
}
