%{
#include <stdio.h>
#include <stdlib.h>
#include "sql.h"
int yylex(void);
int yyerror(const char*);

struct elemento {
   NodoArb  *nodo;   
   int    index; 
   char *string;
   void *apv;
   Campo campo;
};
typedef struct elemento Elemento;
#define YYSTYPE struct elemento
#define NUM_TABLAS 1024
Tabla tablita[NUM_TABLAS];
%}

%%
#include<ctype.h>
Perro perros[]={
{"fido","criollo",0,'M'},
{"solovino","dalmata",2,'M'},
{"daisy","boxer",2,'H'},
{"pulgas","dalmata",2,'M'},
{"kaiser","dalmata",2,'M'},
{"manchas","labrador",3,'M'}
};
void main() { 
   Perro *e;
   int i;
   FILE *fdatos;
   inicia();
   AbreArchivoW("perros", &fdatos);
   for(i=0; i< sizeof(perros)/ sizeof(Perro);i++){
    	e=creaPerro( perros[i].nombre, perros[i].raza, 
                     perros[i].edad, perros[i].genero);
        guardaPerro(fdatos, (void *)e);
   }
   CierraArchivo(fdatos);
   listar("perros");
   yyparse(); 
}
int yyerror(const char* s) { 
  printf("%s\n", s); 
  return 0; 
}  
char atributo[200];
int posi=-1;
Bool buscaTabla(char *llave, int *posicion){
   Bool bandera=FALSE;
   *posicion=0;
   printf("Tabla Busca llave =<%s>\n",llave);
   while(!bandera && (*posicion < 2 /* NUM_TABLAS*/)){
       printf("Tabla Busca item=<%s>\n", tablita[*posicion].nombre);
       bandera=!strcmp(tablita[*posicion].nombre, llave);
       (*posicion)++;
   }
   (*posicion)--;
   return bandera;
}
Bool buscaField(char *llave, Tabla tabla, int *posicion){
   Bool bandera=FALSE;
   *posicion=0;
   printf("Field Busca llave =<%s>\n",llave);
   while(!bandera && (*posicion < tabla.num_campos)){
       printf("Field Busca item=<%s>\n", tabla.campos[*posicion].nombre);
       bandera=!strcmp(tabla.campos[*posicion].nombre,llave);
       (*posicion)++;
   }
   (*posicion)--;
   return bandera;
}
#include"lex.yy.c"    
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
Opera *creaOpera(char operador, char tipo, char *nombre,void *dato){
	Opera *nvo;
	
	nvo=(Opera *)malloc(sizeof(Opera));
        if(!nvo){
	    puts("no hay memoria para crear NodoL");
            return (Opera *)NULL;
        }
        nvo->operador=operador;
        nvo->nombre=nombre;
        nvo->tipo=tipo;
        nvo->dato=dato;
        return nvo;
}
void imprimeOpera(void *op){
   Opera *opera=(Opera *)op;
 printf("impOpe op = (%c) tipo = (%c) nombre = (%s) dato = (%p) ", 
      opera->operador, opera->tipo, opera->nombre, opera->dato);
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
void guardaPerro(FILE *fp, void *regis){
   fwrite(regis, sizeof(Perro), 1, fp);
}
void *copiaPerro(void *p){
	Perro *pe = (Perro *)p;
	return creaPerro(pe->nombre, pe->raza, pe->edad, pe->genero);
}
void imprimeArb(NodoArb *raiz, void (*f)(void *)){
	if(!raiz)
		return;
	imprimeArb(raiz->izq,f);
	(*f)(raiz->info);
	imprimeArb(raiz->der,f);       
}
void inicia(){
	/*strcpy(tablita[0].nombre, "empleado.txt");
        tablita[0].num_campos=3;
        tablita[0].tam_registro=73;
	strcpy(tablita[0].campos[0].nombre, "nombre");
        tablita[0].campos[0].tamano=50;
	strcpy(tablita[0].campos[1].nombre, "edad");
        tablita[0].campos[1].tamano=3;
	strcpy(tablita[0].campos[2].nombre, "telefono");
        tablita[0].campos[2].tamano=20;*/
        strcpy(tablita[0].nombre, "perros");
        tablita[0].num_campos=4;
        tablita[0].tam_registro=sizeof(Perro);
	strcpy(tablita[0].campos[0].nombre, "nombre");
        tablita[0].campos[0].tipo='s';
        tablita[0].campos[0].tamano=sizeof(char)*100;
        strcpy(tablita[0].campos[1].nombre, "raza");
        tablita[0].campos[1].tipo='s';
        tablita[0].campos[1].tamano=sizeof(char)*100;
	strcpy(tablita[0].campos[2].nombre, "edad");
        tablita[0].campos[2].tipo='i';
        tablita[0].campos[2].tamano=sizeof(int);
	strcpy(tablita[0].campos[3].nombre, "genero");
        tablita[0].campos[3].tipo='c';
        tablita[0].campos[3].tamano=sizeof(char);
}
int buscaCampo(char *nomcampo, Tabla tabla, int *tamcampo){
   int i;
   int poscampo = 0;
   for(i=0; i<tabla.num_campos; i+=1){
      if(!strcmp(tabla.campos[i].nombre, nomcampo)){
         *tamcampo=tabla.campos[i].tamano;
         return poscampo;  
      }
      poscampo = poscampo + tabla.campos[i].tamano;
   }
   return -1;
}
void *traeCampo(Tabla tabla, char *nomcampo,void *regis){
   int poscampo, tamcampo;
   void *campo;
   poscampo=buscaCampo(nomcampo, tabla, &tamcampo);
   //printf("traeCampo poscampo: <%d> <%d>\n", poscampo, tamcampo);
   campo=(void *)malloc(tamcampo);
   memset(campo, 0, tamcampo);
   memmove(campo, (char *)regis+poscampo, tamcampo);
   //printf("traeCampo edad: <%d>\n", *(int *)campo);
   return campo;
}
Bool evalua(Tabla tabla, NodoArb *raiz, void *regis){
        int logi;
        void *op1, *op2;     
        //puts("evalua");
        //imprimeOpera(((Opera *)raiz->info));
	if( ((Opera *)raiz->info) ){
            op1=traeCampo(tabla, 
                    ((Opera *)raiz->info)->nombre, regis);
            //**op2=(((Opera *)raiz->info)->igual)(dato) ;
           op2=((Opera *)raiz->info)->dato;
           //printf("EVA op2: <%d>\n", *(int *)op2);
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
           return  evalua(tabla, raiz->izq, regis) &&  
                   evalua(tabla, raiz->der, regis);
	 if( ((Opera *)raiz->info)->operador=='|')
           return  evalua(tabla, raiz->izq, regis) ||  
                   evalua(tabla, raiz->der, regis);	
} 
void mostrar_regis(Tabla tab,void *reg){
   char cad[256];
   void *tmp;
   int i=0;

   tmp=reg;
   for(i=0; i<tab.num_campos; i++){
      if( tab.campos[i].tipo =='c'){ 
         printf("<%s>: <%c>\n",
                      tab.campos[i].nombre, *(char *)tmp);   
      }
      if( tab.campos[i].tipo =='i'){      
         printf("<%s>: <%d>\n",
                      tab.campos[i].nombre, *(int *)tmp);
      }
      if( tab.campos[i].tipo =='f'){
         printf("<%s>: <%f>\n",
                      tab.campos[i].nombre, *(float *)tmp);
      }
      if( tab.campos[i].tipo == 'd'){
         printf("<%s>: <%f>\n",
                      tab.campos[i].nombre, *(double *)tmp);
      } 
      if( tab.campos[i].tipo == 's') {
	    memmove(cad,tmp,tab.campos[i].tamano);
	    printf("<%s>: <%s>\n",tab.campos[i].nombre, cad);
      }      
      tmp=(char*)tmp+tab.campos[i].tamano;
   }
}
Bool AbreArchivo(char* nombre, FILE **fp){
  if ((*fp = fopen(nombre,"rb+")) == NULL){
	   printf("no se puede abrir el archivo %s\n",nombre);
	   return FALSE;
  }
  return TRUE;
}
Bool AbreArchivoW(char *nombre, FILE **fp){
   if ((*fp  = fopen(nombre,"wb+")) == NULL){
      printf("AbreArchW no se puede abrir el archivo %s\n",nombre);
      return FALSE;
   }
   return TRUE;
}
void CierraArchivo(FILE *fp){
    if(fclose(fp) == EOF)
       puts("No se puede cerrar el archivo de datos");
}
void consulta(NodoArb *raiz, char *tabla){
 Tabla tab;
 int tam_reg=0;
 char cad[256];
 void *reg;
 void *tmp;
 FILE *fdatos;
 int i, leidos=1;

 AbreArchivo(tabla,&fdatos);
 tab=tablita[0];
 tam_reg=tab.tam_registro;
 reg=(void *)malloc(tam_reg);
 //memset(reg,0,tam_reg);
 //leidos=fread(reg, tam_reg, 1, fdatos);
 while(leidos==1){
	printf("\n");
	tmp=reg;
	memset(tmp,0,tam_reg);
	leidos=fread(reg,tam_reg,1,fdatos);
        //mostrar_regis(tab, reg); 
        if(evalua(tab, raiz, reg))
	  mostrar_regis(tab, reg);   
  }
  CierraArchivo(fdatos);
}
void listar(char *tabla){
 Tabla tab;
 int tam_reg=0;
 char cad[256];
 void *reg;
 void *tmp;
 FILE *fdatos;
 int i, leidos=1;

 AbreArchivo(tabla,&fdatos);
 tab=tablita[0];
 tam_reg=tab.tam_registro;
 reg=(void *)malloc(tam_reg);
 while(leidos==1){
	printf("\n");
	tmp=reg;
	memset(tmp,0,tam_reg);
	leidos=fread(reg,tam_reg,1,fdatos);
	mostrar_regis(tab, reg);   
  }
  CierraArchivo(fdatos);
}



