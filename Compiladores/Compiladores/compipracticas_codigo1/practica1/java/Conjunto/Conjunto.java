import java.util.*;

public class Conjunto {
    private Object[] eltos;     // Almacenamiento para el conjunto
    private int cardinal;         // Cantidad de eltos almacenados
    int tama;
    public Conjunto() {
	this(20);
    }
    public Conjunto(int tam) {   
	eltos = new Object[tam];
	for (int i = 0; i < eltos.length; i++)
	    eltos[i] = null;
	cardinal = 0;
    }
    public Conjunto(Object[] eltos) {
	this.eltos = eltos;
	for (int i = 0; i < eltos.length; i++)
	    this.eltos[i] = eltos[i];
	cardinal = eltos.length;
        tama = eltos.length;
    }
    public Conjunto(Conjunto c) {
	eltos = new Object[c.tama];
	for (int i = 0; i < c.cardinal; i++)
	    eltos[i] = c.eltos[i];
	cardinal = c.cardinal;
    }
    public boolean estaVacio(){ 
	return cardinal == 0;
    }
    public int tamanio(){ 
	return cardinal;
    }
    public void vaciar(){ 
	cardinal = 0;
    }
   public boolean pertenece(Object elem){
      int i; 
      if (!estaVacio())
         for ( i = 0; i < cardinal; i++)
	    if (elem.equals(eltos[i]))
               return true;
      return false;
   }
    /*public void eliminar(Object elem) { 
	if (!estaVacio())
	    for (int i = 0; i < nElems; i++) 
		if (elem.equals(eltos[i])){
			//eltos[j] = eltos[nElems--];
                    eltos[i] = eltos[nElems--];
		    return;
		}
    }*/
    public void insertar(Object elem){
	/*if (nElems >= eltos.length)
	    crecerArreglo();*/
	if (!pertenece(elem)) {
	    eltos[cardinal++] = elem;
	}
    }
    private void crecerArreglo() {
	int tamanoNuevo =eltos.length + 10;
	Object[] arregloNuevo = new Object[tamanoNuevo];
	
	for (int i = 0; i < cardinal; i++)
	    arregloNuevo[i] = eltos[i];
	eltos = arregloNuevo;
    }
    public Conjunto union(Conjunto c) {
        int i;
	Conjunto nvo = new Conjunto(cardinal+c.cardinal);
        //nvo.cardinal=cardinal;
        for (i = 0; i < cardinal; i++)
            nvo.eltos[i]= eltos[i];
        nvo.cardinal=cardinal;
        for (i = 0; i < c.cardinal; i++)
           if (!pertenece(c.eltos[i]))
              nvo.insertar(c.eltos[i]);
	return nvo;
    }
   public Conjunto interseccion(Conjunto c) {
      int i;
      Conjunto nvo = new Conjunto(c.cardinal);
      nvo.cardinal = 0;
      for (i = 0; i < c.cardinal; i++)
         if (pertenece(c.eltos[i]))
            nvo.insertar(c.eltos[i]);
      return nvo;
   }
   public Conjunto diferencia(Conjunto c) {
      int i;
      Conjunto nvo = new Conjunto(c.cardinal);
      nvo.cardinal = 0;
      for (i = 0; i < c.cardinal; i++)
         if (!pertenece(c.eltos[i]))
            nvo.insertar(c.eltos[i]);
      return nvo;
   }
   Conjunto difsimConjunto(Conjunto c){
      int i;
      Conjunto nvo= new Conjunto(cardinal+c.cardinal);
      nvo.cardinal = 0;
      for (i = 0; i < cardinal; i++)
         if (!c.pertenece(eltos[i]))
            nvo.insertar(eltos[i]);
      for (i = 0; i < c.cardinal; i++)
         if (!pertenece(c.eltos[i]))
            nvo.insertar(c.eltos[i]); 
      return nvo; 
   }
   public boolean subconjunto(Conjunto c) {
      int i;
      for (i = 0; i <cardinal; i++)
         if (!c.pertenece(eltos[i]))
	    return false;
      return true;
   }
   void imprime(){
      int i; 
      for(i=0; i< cardinal ; i++)
         System.out.println(""+eltos[i]);
         //printf("%f ", conj->eltos[i]);
      //printf("\n");
   }
}

