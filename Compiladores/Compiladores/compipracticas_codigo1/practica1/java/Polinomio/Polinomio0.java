 class Polinomio{
   private long coefis[];
   
   public Polinomio(){}
   public Polinomio(int grado){
      if ( grado <= 0 ) grado = 0;
      coefis = new long[grado + 1];
   }
   public Polinomio(int n, long [] eltos) {
        this.coefis = new long[n];
        for (int i = 0; i < n; i++)
            this.coefis[i] = eltos[i];
    }
   public int grado(){ return coefis.length - 1; }
   public long coeficiente(int i){
      return i < coefis.length ? coefis[i] : 0;
   }
   public void imprime(){
      for ( int i = grado(); i >= 0; --i ){
         if ( coefis[i] != 0 ){
            if ( i != grado() ) System.out.print(" + ");
            if ( coefis[i] != 1 || i == 0 ) System.out.print(coefis[i]);
            if ( i > 0 ) System.out.print("x");
            if ( i > 1 ) System.out.print("^" + i);
         }
      }
   }
   Polinomio sumar(Polinomio p){
      int grado = Math.max( grado(), p.grado() );
      Polinomio suma = new Polinomio(grado);
      for ( int i = 0; i <= grado; ++i )
         suma.coefis[i] = coeficiente(i) + p.coeficiente(i);
      return suma;
   }
   Polinomio restar(Polinomio p){
      int grado = Math.max( grado(), p.grado() );
      Polinomio resta = new Polinomio(grado);
      for ( int i = 0; i <= grado; ++i )
         resta.coefis[i] = coeficiente(i) - p.coeficiente(i);
      return resta;
   }
   Polinomio multiplicar(Polinomio p){
      int grado = grado() + p.grado();
      Polinomio producto = new Polinomio(grado);
      for ( int i = 0; i <= grado(); ++i )
         for ( int j = 0; j <= p.grado(); ++j )
            producto.coefis[i + j] += coeficiente(i) * p.coeficiente(j);
      return producto;
   }
 
   public static void imprimirOperacion(Polinomio a, Polinomio b, String op, Polinomio resultado){
      System.out.print("\n(");
      a.imprime();
      System.out.print(") " + op + " (");
      b.imprime();
      System.out.print(") = ");
      resultado.imprime();
      System.out.println();
   }
}

