#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nodoL {
   void *info;
   struct nodoL *sig;
};
typedef struct nodoL NodoL;
struct empleado {
   char nombre[100];
   int edad;
   float salario;
};
typedef struct empleado Empleado;
//NodoL *head=(NodoL *)NULL,*tail=(NodoL *)NULL;
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
int empty(NodoL *head){ 
   return !head; 
}
NodoL *remueve(NodoL **cab){
   NodoL *p;
   if(!*cab){
      puts("remueve: lista vacia");
      return (NodoL *)NULL;
   }
   p=*cab;
   //printf("remueve head=%p ", *cab);
   *cab=p->sig;
   p->sig=(NodoL *)NULL;
   return p;
}
NodoL *put_(NodoL **head, NodoL **tail, void *dato){
   NodoL *nvo;
   nvo=(NodoL *)malloc(sizeof(NodoL));
   if(!nvo){
	puts("no hay memoria para crear NodoL");
        return (NodoL *)NULL;
   }
   nvo->info=dato;
   nvo->sig=(NodoL *)NULL;
   if(!*head)
      *head=nvo;
   else
      (*tail)->sig=nvo;
   *tail=nvo;
   return nvo;    
}
NodoL *get_(NodoL **head){
   NodoL *p;  
   if(!*head){
      puts("cola vacia");
      return (NodoL *)NULL;
   }
   p=*head;
   *head=(*head)->sig;
   return p;    
}
NodoL *put(NodoL **head, NodoL **tail, void *dato){
   NodoL *nvo;
   nvo=creaNodoL(dato, (NodoL *)NULL);
   if(!nvo){
	puts("no hay memoria para crear NodoL");
        return (NodoL *)NULL;
   }
   if(!*head)
      *head=nvo;
   else
      (*tail)->sig=nvo;
   *tail=nvo;
   return nvo;    
}
NodoL *get(NodoL **head){
	return remueve(head);
}
void *creaCola(NodoL **inicio, NodoL **fin){
	*inicio=(NodoL *)NULL;
	*fin=(NodoL *)NULL;
}
void imprime(NodoL *head,  NodoL *tail,void (*f)(void *)){
   NodoL *p; 
    if(!head){
      puts("imprime:lista vacia");
      return ;
   }
   for(p=head;p!=tail;p=p->sig)
      (*f)(p->info);
   (*f)(p->info);
}
Empleado *creaEmpleado( char nombre[100],
   int edad,
   float salario)
{
   Empleado *nvo;
   nvo=(Empleado *)malloc(sizeof(Empleado));
   if(!nvo){
	puts("no hay memoria para un Empleado");
        return (Empleado *)NULL;
   }
   strcpy(nvo->nombre,nombre);
   nvo->edad=edad;
   nvo->salario=salario;
   return nvo;
}
void imprimeEmp(void *info){
   Empleado *e=(Empleado *)info;
   puts(e->nombre);
   printf("edad=%d\n",e->edad);
   printf("salario=%f\n",e->salario);
}
Empleado emps[]={
{"Pedro",10,0.0},
{"Juan",20,10.0},
{"Simon",30,20.0},
{"Doug",40,10.0}
};
/*
int main(){
    Empleado *e;
    int i;
    creaCola(&head,&tail);
    for(i=0; i < 4;i++){
	    e=creaEmpleado( emps[i].nombre, emps[i].edad,emps[i].salario);
	    put(&head,&tail,(void *)e);
    }
    imprime(head, tail, imprimeEmp);
    imprimeEmp(get(&head)->info);
    imprimeEmp(get(&head)->info);
    imprimeEmp(get(&head)->info);
    imprimeEmp(get(&head)->info);
    get(&head);
}*/
     

