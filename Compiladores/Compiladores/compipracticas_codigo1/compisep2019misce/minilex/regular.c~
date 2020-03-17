
#include <stdio.h>
#include <string.h>
#include "regexp.h"

extern Conjunto *sig[1000];
char *alfab[]={ "a", "b", NULL};
int tran[100][100];
NodoL *head=(NodoL *)NULL,*tail=(NodoL *)NULL;

int nullable(NodoArb *raiz){
   //cerradura de kleene siempre retorna verdadero
   //if (raiz.getId().equals(AutomataMain.EPSILON))
   //    return 1;
   //si contiene epsilon, es true
   /*else*/ 
   if (((NodoI *)raiz->info)->id[0]=='*')
      return 1;
        //cuando es or, se verifica cada una las hojas del nodo
   else if (((NodoI *)raiz->info)->id[0]=='|')
      return (nullable(raiz->izq))||(nullable(raiz->der));
        //cuando es concatenacion solo si los dos nodos son true, devuelve true
   else if (((NodoI *)raiz->info)->id[0]==':')
      return (nullable(raiz->izq))&&(nullable(raiz->der));
          //verificar si es una hoja terminal
   else if (esHoja(raiz))
      return 0;

        //valor por default a regresar
   return 0;   
}
Conjunto *firstPos(NodoArb *raiz){
   Conjunto *resultado = creaConjunto(1000);
   //regresar i en caso de que sea epsilon, regresa vacio
   //if (raiz.getId().equals(AutomataMain.EPSILON))
   //    return resultado;
   //en caso de sea una hoja regresa el nodo i en el arreglo
   //else 
   if (esHoja(raiz)){
      //resultado.add(raiz);
      insertar(resultado, 
          creaNodoI(strdup(((NodoI *)raiz->info)->id), 
                    ((NodoI *)raiz->info)->num, 0), cmpNodoNum, copiaNodoI);
            //return resultado;
   }
   //en caso del OR hace la union de firstPos de los nodos hijos
   else if (((NodoI *)raiz->info)->id[0]=='|'){
      return unirConjunto(firstPos(raiz->izq),
                          firstPos(raiz->der), cmpNodoNum, copiaNodoI);
           
   }
   /*en el caso de la concatenacion primero revisa el nullable y
   despues realiza la union */
   else if (((NodoI *)raiz->info)->id[0]==':'){
      if (nullable(raiz->izq)){
         resultado=unirConjunto(firstPos(raiz->izq),
                   firstPos(raiz->der), cmpNodoNum, copiaNodoI);
      } else{
         resultado=firstPos(raiz->izq);
      }
   }
        //en el caso de la cerradura de kleene regresa firstPos del nodo hijo izquierdo
   else if (((NodoI *)raiz->info)->id[0]=='*'){
      resultado=firstPos(raiz->izq);
   }   
   return resultado;
}
Conjunto *lastPos(NodoArb * raiz){  
   Conjunto *resultado = creaConjunto(1000);
   //regresar i en caso de que sea epsilon, regresa vacio 
   //if (raiz.getId().equals(AutomataMain.EPSILON))
   //    return resultado;      
   //else 
   if (esHoja(raiz)){
      //resultado.add(raiz);
      //return resultado;
      insertar(resultado, 
          creaNodoI(strdup(((NodoI *)raiz->info)->id), 
                    ((NodoI *)raiz->info)->num, 0), cmpNodoNum, copiaNodoI);
   }
   else if (((NodoI *)raiz->info)->id[0]=='*'){
      resultado=lastPos(raiz->izq);
   }
   else if (((NodoI *)raiz->info)->id[0]=='|'){
      resultado=unirConjunto(lastPos(raiz->izq),
                             lastPos(raiz->der), cmpNodoNum, copiaNodoI);
   }
   else if (((NodoI *)raiz->info)->id[0]==':'){
      if (nullable(raiz->der)){
         resultado=unirConjunto(lastPos(raiz->izq),
                                lastPos(raiz->der), cmpNodoNum, copiaNodoI);
      } else{
         resultado=lastPos(raiz->der);
      }
   }
   return resultado;
}
void followPos(NodoArb *raiz){
   //por definicion follow pos aplica para cerradura de kleene y concatenacion
   //System.out.println(raiz.getId());    
   //si es cerradura de kleen
   int i, j;
   if(!raiz) return;
   followPos(raiz->izq);
   if (((NodoI *)raiz->info)->id[0]=='*'){    
      //según el algoritmo primero verificamos el lastPos
      //el follow pos del lastPos incluye todo lo que este en el first pos
      //del kleen    
      //por lo tanto se necesita el firstPos del kleen
      Conjunto *lastPosition = lastPos(raiz);   //c1   
      Conjunto *firstPosition = firstPos(raiz); //c2
      for(i=0; i < lastPosition->cardinal;i++){
         for(j=0; j < firstPosition->cardinal;j++){
            insertar(sig[ ((NodoI *)lastPosition->eltos[i])->num], 
                     firstPosition->eltos[j], cmpNodoNum, copiaNodoI);
         }
      }
   }
   //si es concatenación
   if (((NodoI *)raiz->info)->id[0]==':'){
      /*según el algoritmo el follow pos del cada posicion del last pos
      del hijo izquierdo debe incluir el el first pos del hijo derecho*/   
      //obtener el lastPos del hijo izquierdo    
      //obtener el fistPos del lado derecho  
      Conjunto *lastPosition = lastPos(raiz->izq);  //c1    
      Conjunto *firstPosition = firstPos(raiz->der);//c2         
      for(i=0; i < lastPosition->cardinal;i++){
         for(j=0; j < firstPosition->cardinal;j++){
            insertar(sig[((NodoI *)lastPosition->eltos[i])->num], 
             firstPosition->eltos[j], cmpNodoNum, copiaNodoI);
         }
      }
   } 
   followPos(raiz->der); 
}

int indice = 1;
void generarNumeracionNodos(NodoArb *raiz/*, void (*f)(void *)*/){  
   generarNumeracionNodos(raiz->izq);
   if(esHoja(raiz)) {
      //arrayNodos.get(i).setNumeroNodo(index);
      indice++;
      return;
   } 
   //(*f)(raiz->info);
   generarNumeracionNodos(raiz->der);        
}
void crearEstados(NodoArb *raiz){
   //Conjunto *estadosD[100];
   Conjunto *c1, *c2, *cobj, *tempi;
   NodoI *ni;
   int indexEstadoInicio=0;
   int indexEstados=1;
   int i, j, cta, enc;
   //puts("1111 crearEstados");
   Conjunto *estadosD=creaConjunto(100);
   //printf("AFD 0 (%s)  ",  alfab[0]);
   c2=((NodoI *)raiz->info)->first;
   insertarSet(estadosD, c2, cmpNodoNum, copiaNodoI);
   c2->id = 0;
   //printf("AFD card (%d)  ", ((NodoI *)raiz->info)->first->cardinal );
   creaCola(&head, &tail);
   put_(&head,&tail,(void *)copiaConjunto(c2, copiaNodoI));
   //imprimeConjunto( (Conjunto *)head->info, imprimeNodoI);
   while(!empty(head)){
      cobj=(Conjunto *)(get(&head)->info);
      for (i=0; alfab[i] ;i++){
         tempi=creaConjunto(100);
         //printf("AFD AFD AFD (%s)  ", alfab[i]);    
         for (j=0; j < cobj->cardinal ;j++){
            ni=((NodoI *)cobj->eltos[j]);
        //printf("AFD (%d, %d) id=%s num=%d ", i, j, ni->id, ni->num);
            if(ni->id[0] == alfab[i][0]){
              tempi=unirConjunto(tempi, sig[ni->num], cmpNodoNum, copiaNodoI);
            }
         }     
         //puts("Conj transi");
         //imprimeConjunto(tempi, imprimeNodoI);
         if (!contains(estadosD, tempi, &enc, cmpNodoNum)){ 
            //puts("Conj nuevo");
            //imprimeConjunto(tempi, imprimeNodoI);
            tempi->id = indexEstados;
            put(&head,&tail,(void *)tempi);
            //insertar(estadosD, tempi, cmpNodoNum, copiaNodoI);
            insertarSet(estadosD, tempi, cmpNodoNum, copiaNodoI);
            printf("IFIF %d->%d con %s \n", 
                  indexEstadoInicio, indexEstados, alfab[i]);
            tran[indexEstadoInicio][alfab[i][0]-'a']=indexEstados;
            indexEstados++;
         } else {    
            int sig=((Conjunto *)estadosD->eltos[enc])->id;  
            printf("ELSE %d->%d con %s \n", 
                   indexEstadoInicio, sig, alfab[i]);
            tran[indexEstadoInicio][alfab[i][0]-'a']=sig;
         }
         //printf("%d->%d con %s ", indexEstados, indexEstados+1, alfab[i]);
      }
      indexEstadoInicio++;
      printf("%d \n", indexEstadoInicio);
   }
   for(i=0; i < indexEstadoInicio ;i++){
      for(j=0; alfab[j] ;j++){
         printf(" %d, ", tran[i][j]);
      }
      printf("\n");
   }
}



