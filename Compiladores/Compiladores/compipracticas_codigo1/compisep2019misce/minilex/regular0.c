#include "regexp.h"

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
      //insertar(resultado, 
      //    creaNodoI(strdup(cade), cta, 0), cmpNodoNum, copiaNodoI);
            //return resultado;
      ;
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
      ;
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
        if (((NodoI *)raiz->info)->id[0]=='*'){    
            //según el algoritmo primero verificamos el lastPos
            //el follow pos del lastPos incluye todo lo que este en el first pos
            //del kleen    
            //por lo tanto se necesita el firstPos del kleen
            Conjunto *lastPosition = lastPos(raiz);      
            Conjunto *firstPosition = firstPos(raiz);
            for(int j=0;j < lastPosition->cardinal;j++){
                int numero = lastPosition.get(j).getNumeroNodo();

                if(resultadoFollowPos.containsKey(numero)){
                    //si ya la tiene, es agregar
                    firstPosition.addAll((Collection)resultadoFollowPos.get(numero));
                    //this.Sort_Set((LinkedList<Integer>)SiguientePos.get(numero));
                }
               
                    //si no la tiene, es poner
                    resultadoFollowPos.put(numero,firstPosition);
                   
            }
        }
        //si es concatenación
        else if (((NodoI *)raiz->info)->id[0]==':'){
            /*según el algoritmo el follow pos del cada posicion del last pos
            del hijo izquierdo debe incluir el el first pos del hijo derecho*/
            
            //obtener el lastPos del hijo izquierdo    
            //obtener el fistPos del lado derecho  
            Conjunto *lastPosition = lastPos(raiz->izq);      
            Conjunto *firstPosition = firstPos(raiz->der);
            //usamos el last pos del hijo izquierdo 
            for (int i = 0;i < lastPosition->cardinal;i++){
                firstPosition->eltos[j]
                int numero = (int) lastPosition.get(i).getNumeroNodo();
                //le agregamos el first pos del hijo derecho [merge si ya existe]
                if (resultadoFollowPos.containsKey(numero)){
                    //System.out.println(resultadoFollowPos);
                    //System.out.println(numero);
                    //System.out.println(firstPosition);
                    firstPosition.addAll((Collection) resultadoFollowPos.get(numero));//merge
                    
                }
                    insertar(sig[ ((NodoI *)c1->eltos[i])->num], 
                     c2->eltos[j], cmpNodoNum, copiaNodoI);
                
                resultadoFollowPos.put(numero, firstPosition);
                firstPosition = firstPos(raiz.getDerecha());
            }
            
        }  
}

