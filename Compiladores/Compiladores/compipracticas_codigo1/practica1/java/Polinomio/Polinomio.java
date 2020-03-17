 class Polinomio{
   private int coefis[];
   public int grado;
   public Polinomio(){}
   public Polinomio(int grado){
      if ( grado <= 0 ) grado = 0;
      coefis = new int[grado + 1];
      this.grado=grado;
   }
   public Polinomio(int n, int [] eltos) {
        this.coefis = new int[n];
        this.grado=n-1;
        for (int i = 0; i < n; i++)
            this.coefis[i] = eltos[i];
    }
   //public int grado(){ return coefis.length - 1; }
   public int grado(){ return grado; }
   public int coeficiente(int i){
      return i < coefis.length ? coefis[i] : 0;
   }
   public void imprime(){
      for ( int i = grado(); i >= 0; --i ){
         if ( coefis[i] != 0 ){
            if ( i != grado() ) System.out.print(" + ");
            if ( coefis[i] != 1 || i == 0 ) System.out.print( coefis[i] );
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
      int grade=0;
      int grado = Math.max( grado(), p.grado() );
      Polinomio resta = new Polinomio(grado);
      for ( int i = 0; i <= grado; ++i )
         resta.coefis[i] = coeficiente(i) - p.coeficiente(i);
      for(int i=0; i <= resta.grado(); i++) {
            if(resta.coefis[i]!=0){
              grade=i;
           }
      }
      resta.grado=grade;
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
void diferenciaPoli(int apt[], int lim, int coef) {
	int i;
	for (i = 0; i <= lim; i++) {
		if(i == lim) { apt[i] = coef;}
		else { apt[i] = 0;}
	}
}

Polinomio divisible(Polinomio poli, boolean flag) {
   Polinomio diferencia, modu, residuo, res=poli;
   int factor = 0, cont = 0, i; 	
   int coefactor;
   Polinomio coci = new Polinomio(grado() - poli.grado());
   residuo = this;
   while(residuo.grado() != 0 
         && residuo.grado()- poli.grado() >= 0) {
      coefactor = residuo.coefis[residuo.grado()]/poli.coefis[poli.grado()];
      diferencia = new Polinomio((residuo.grado())-(poli.grado()));
      diferenciaPoli(diferencia.coefis, 
                     (residuo.grado())-(poli.grado()), coefactor);
      coci.coefis[(residuo.grado())-(poli.grado())] = coefactor;
      res = residuo.restar(poli.multiplicar(diferencia));
      modu=residuo;
      residuo = res;
   }
   if(flag)
      return coci;
   else
      return res;
}
Polinomio modulo(Polinomio poli) {
   return divisible(poli, false);
}
Polinomio divide(Polinomio poli) {
   return divisible(poli, true);
}
Polinomio mcd(Polinomio b) {
    Polinomio a, temp;
    int expo, coefi;
    a = this;
    expo=b.grado(); coefi=b.coefis[b.grado()];
    while (!((expo == 0 ) && (coefi == 0)) ){
        temp = a.modulo( b );
        a = b;
        b = temp;
        expo = b.grado(); coefi = b.coefis[b.grado()];
    }
    return a;
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

