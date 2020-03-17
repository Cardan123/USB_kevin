class Simbolo {
   String nombre;
   short tipo;
   Complejo val;
   Simbolo sig;
   Simbolo(String s, short t, Complejo d){
      nombre=s;
      tipo=t;
      val=d;
   }
   public Simbolo obtenSig(){ return sig; }
   public void ponSig(Simbolo s){ sig=s; }
   public String obtenNombre(){ return nombre; }
}