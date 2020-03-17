


public class Quilt {
   int alto;
   int ancho;
   char[][] mat;

   public Quilt(int n, int m) {
      alto = n;
      ancho = m;
      mat = new char[n][m];
   }
   public static Quilt A() {
      Quilt c = new Quilt(2,2);	
      c.mat[0][0]='/';
      c.mat[0][1]='/';
      c.mat[1][0]='/';
      c.mat[1][1]='+';
      return c;
   }
   public static Quilt B() {
      Quilt c = new Quilt(2,2);	
      c.mat[0][0]='|';
      c.mat[0][1]='|';
      c.mat[1][0]='|';
      c.mat[1][1]='|';
      return c;
   }
   public Quilt cose(Quilt c) {
      if(alto != c.alto){
         System.out.println(
           "Cosiendo colchas incompatibles! "+alto +" "+c.alto);
         return null;
      }
      Quilt colcha = new Quilt(alto, ancho + c.ancho);
      for (int i = 0; i < colcha.alto; i++) {
         for (int j = 0; j < colcha.ancho; j++) {
	    if (j < ancho) {
		colcha.mat[i][j] = mat[i][j];
	    } else {
                //System.out.println("nume "+(j-ancho)+" i "+i+" j "+j);
		colcha.mat[i][j] = c.mat[i][j-ancho];
	    }
         }
      }
      return colcha;
   }
   public Quilt rota() {
      Quilt c = new Quilt(alto, ancho);
      int i_, j_;
      for(int i=0;i < alto;i++){
         for(int j=0;j < ancho;j++){
	    //map(orig.alto-1, i, j, &i_, &j_);
            i_=j;
            j_= alto-1-i;
            //System.out.println("alto: "+alto+" i_= "+i_+" j_ "+j_);
	    if(mat[i][j]=='+')
               c.mat[i_][j_]='+';
            if(mat[i][j]=='/')
	       c.mat[i_][j_]='\\';
	    if(mat[i][j]=='\\')
	       c.mat[i_][j_]='/';
	    if(mat[i][j]=='|')
               c.mat[i_][j_]='-';
            if(mat[i][j]=='-')
	       c.mat[i_][j_]='|';
         }
      }
      return c;
   }
   public void print() {
      //System.out.println("print "+alto);
      for (int i = 0; i < alto; i++) {
	 for (int j = 0; j < ancho; j++) {
	    System.out.print(mat[i][j]);
	 }
	 System.out.println();
      }
   }
}
