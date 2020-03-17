



import java.util.ArrayList;
import java.util.Vector;

public class Symbol {

    ArrayList<SymbolData> simbolos;
    
    public Symbol(){
        simbolos = new ArrayList<SymbolData>();
    }
    
    public Object lookup(String nombre){
        for(int i = 0; i < simbolos.size(); i++)
            if(nombre.equals(simbolos.get(i).getNombre()))
                return simbolos.get(i).getObjeto();
        return null;
    }
    
    public boolean insert(String nombre, Object objeto){
        SymbolData par = new SymbolData(nombre, objeto);
        for(int i = 0; i < simbolos.size(); i++)
            if(nombre.equals(simbolos.get(i).getNombre())){
                simbolos.get(i).setObjeto(objeto);
                return true;
            }
        simbolos.add(par);
        return false;
    }
    
    public void print(){
        for(int i = 0; i < simbolos.size(); i++){
            System.out.println(simbolos.get(i).getNombre() + simbolos.get(i).getObjeto().toString());
        }
    }

}
