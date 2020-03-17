#include<string.h>
#include<stdlib.h>
struct pila {
	int tope;
	void **elementos;
};
typedef struct pila Pila;
struct perro {
	char nombre[100];
	char raza[100];
};
typedef struct perro Perro;
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

Perro *creaPerro(char nombre[], char raza[]){
	Perro *nvo;
	nvo=(Perro *)malloc(sizeof(Perro));
	strcpy(nvo->nombre, nombre);
	strcpy(nvo->raza, raza);
	return nvo;
}
void imprimePerro(void *dato){
	Perro *p=(Perro *)dato;
	puts(p->nombre);
	puts(p->raza);
}
int main(){
	Perro *pe;
	Pila *p;
	p=creaPila(10);
	pe=creaPerro("Fido","pastor");
	push(p,(void *)pe);
	pe=creaPerro("Firulais","boxer");
	push(p,(void *)pe);
	pe=creaPerro("Manchas","maltes");
	push(p,(void *)pe);
	imprimePerro(pop(p));
	imprimePerro(pop(p));
	imprimePerro(pop(p));
}
