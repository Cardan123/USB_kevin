import java.lang.reflect.*;
public class UtilReflect {
    
    public static void ejecutaMetodo(Object obj, String inst){
        Method metodo;
        try {
            System.out.println(" instr "+inst);
            metodo=obj.getClass().getDeclaredMethod(inst, null);
            metodo.invoke(obj, null);
        } catch(NoSuchMethodException e){
            System.out.println(" No metodo "+e);
        } catch(InvocationTargetException e){
            System.out.println(" inst = "+inst+"  "+e);
        } catch(IllegalAccessException e){
            System.out.println(e);
        }
    }
    public static Double ejecutaMetodoUno(Object obj, String inst, Double d){
        Method metodo;
        Class c;
    
        Class paramC[]={java.lang.Double.TYPE};
        Object param[]=new Object[1];
        param[0]=d;
        c=java.lang.Math.class;
        try {
            metodo=c.getDeclaredMethod(inst, paramC);
            return (Double)metodo.invoke(obj, param);
        } catch(NoSuchMethodException e){
            System.out.println("No metodo "+e+ "instru "+inst);
            return null;
        } catch(InvocationTargetException e){
            System.out.println(e);
            return null;
        } catch(IllegalAccessException e){
            System.out.println(e);
            return null;
        }
    }
}
