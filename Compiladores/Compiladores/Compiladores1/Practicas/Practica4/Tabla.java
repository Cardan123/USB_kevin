public class Tabla {
   Simbolo listaSimbolo;
   Tabla(){
      listaSimbolo=null;
   }
   Simbolo install(String s, short t, Complejo d){
      Simbolo simb=new Simbolo(s,t,d);
      simb.ponSig(listaSimbolo);
      listaSimbolo=simb;
      return simb;
   }
   Simbolo lookup(String s){
      for(Simbolo sp=listaSimbolo; sp!=null; sp=sp.obtenSig()){
         if((sp.obtenNombre()).equals(s)){
            return sp;
         }
      }
      return null;
   }

   Simbolo lookup(String s, Complejo valor){
      for(Simbolo sp=listaSimbolo; sp!=null; sp=sp.obtenSig()){
         if((sp.obtenNombre()).equals(s)){
            listaSimbolo.val=valor;
            return sp;
         }
      }
      return null;
   }
}