import java.util.ArrayList;
import java.util.Random;
import java.util.Arrays;

public class Conjuntos{
    private static ArrayList<String> union(ArrayList<String> primero, ArrayList<String> segundo){
        ArrayList<String> retVal = new ArrayList<String>(primero); 
        for(String worte: segundo){
            if(!primero.contains(worte))
                retVal.add(worte);
        }        
        return retVal;
    }

    private static ArrayList<String> interseccion(ArrayList<String> a, ArrayList<String> b){
        ArrayList<String> c = new ArrayList<String>();
        ArrayList<String> iter = a.size() > b.size() ? a : b;
        for(String elem: iter){
           if(a.contains(elem) && b.contains(elem)){
            c.add(elem);
           }
        }
        return c;
    }
    private static ArrayList<String> diferencia(ArrayList<String> a, ArrayList<String> b){
	ArrayList<String> c = new ArrayList<String>();
	for(String elem: a)
		if(!b.contains(elem)){c.add(elem);}
	return c;
    }
}
