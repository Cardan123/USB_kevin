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

Polinomio divide(Polinomio poli) {
   Polinomio diferencia, modu, residuo, res;
   int factor = 0, cont = 0, i; 	
   int coefactor;
   int cta=0;
   Polinomio coci = new Polinomio(grado() - poli.grado());
   residuo = this;
   //for(i = 0; i <= coci.grado(); i++) 
   //   coci->Cfts[i] = crearRacional(0, 1);
   System.out.println("11divide ");
   imprime();
   System.out.println("2o");
   poli.imprime();
   //System.exit(0);
   while(residuo.grado() != 0 
         && residuo.grado()- poli.grado() >= 0 /*&& cta <= 4*/) {
      coefactor = residuo.coefis[residuo.grado()]/poli.coefis[poli.grado()];
      System.out.println("divi while resi "+residuo.grado()+" poli "+
       poli.grado()+" resta "+(residuo.grado()- poli.grado())+
       " coefactor "+ coefactor);	
      System.out.println("resi arre "+residuo.coefis[residuo.grado()]);
      System.out.println("poli arre "+poli.coefis[poli.grado()]);
   //==coefactor = residuo->Cfts[residuo->grado]/poli2->Cfts[poli2->grado];
      ///printf("divi coefi=(%d) ", coefactor->num);
      diferencia = new Polinomio((residuo.grado())-(poli.grado()));
      diferenciaPoli(diferencia.coefis, 
                     (residuo.grado())-(poli.grado()), coefactor);
      coci.coefis[(residuo.grado())-(poli.grado())] = coefactor;
      //printPolinomio(multiPolinomio(poli2, diferencia));
      System.out.println("multi"+diferencia.grado());
      poli.multiplicar(diferencia).imprime();
      res = residuo.restar(poli.multiplicar(diferencia));
      System.out.println("resta"+res.grado());
      res.imprime();
      
      //puts("divi11 resta");
      //printPolinomio(res);
      modu=residuo;
      residuo = res;
      //puts("divi11 coci");
      //printPolinomio(coci);
      //printf("res expo=%d expo2=%d coefi=%d bool=%d ", 
    //res->grado, residuo->grado-poli2->grado, 
    //residuo->Cfts[residuo->grado], (residuo->grado-poli2->grado >=-1) );
      //cta= cta+1;
   }
   //====puts("divi222222____");
   //res->grado=0;
   //printPolinomio(coci);
   return coci;
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

