import java.awt.*;
import java.util.*;
import java.lang.reflect.*;

class  Maquina {
//ver como automatizar esto
public final static short NUMBER=257;
public final static short PRINT=258;
public final static short VAR=259;
public final static short BLTIN=260;
public final static short INDEF=261;
public final static short WHILE=262;
public final static short IF=263;
public final static short ELSE=264;
public final static short OR=265;
public final static short AND=266;
public final static short GT=267;
public final static short LT=268;
public final static short UNARYMINUS=269;
public final static short NOT=270;
public final static short YYERRCODE=256;
//hasta aqui
Stack pila;
Stack marcos;
Vector prog;

static int pc=0;
int progbase=0;
boolean returning=false;

int numArchi=0;
Method metodo;
Method metodos[];
Class c;
Graphics g;
double angulo;
int x=0, y=0;
Class parames[];
OperacionesComplejos operaciones=new OperacionesComplejos();
//Algebra alge;
  Maquina(){
    
  }
  public Vector getProg(){
    return prog;
  }
  void initcode(){
          pila=new Stack();
    prog=new Vector();
  }
  Object pop(){
    return pila.pop();
  }
  int code(Object f){
    //System.out.println("Gen ("+f+") size="+prog.size());
      prog.addElement(f);
    return prog.size()-1;
  }
   void execute(int p){
      String inst;
      //System.out.println("progsize="+prog.size()+" p = "+p);
      for(pc=0;pc < prog.size(); pc=pc+1){
    //System.out.println("pc="+pc+" inst "+prog.elementAt(pc));
      }
      for(pc = p; !(inst=(String)prog.elementAt(pc)).equals("STOP"); ){
    //for(pc=p;pc < prog.size();){
      try {
      //System.out.println("111 pc= "+pc);
      inst=(String)prog.elementAt(pc);
      pc=pc+1;
      //==System.out.println("222 pc= "+pc+" instr "+inst);
                        c=this.getClass();
      //System.out.println("clase "+c.getName());
              metodo=c.getDeclaredMethod(inst);
      metodo.invoke(this);
      }
      catch(NoSuchMethodException e){
        System.out.println("No metodo "+e);
                        }

      catch(InvocationTargetException e){
   System.out.println(" inst = "+inst+"  "+e+"this "+this);
                        }
      catch(IllegalAccessException e){
        System.out.println(e);
                        }
    }
  }
  void constpush(){
  Simbolo s;
  Double d;

  s=(Simbolo)prog.elementAt(pc);
  pc=pc+1;
  pila.push(new Double(s.dval));
  }
  void varpush(){
  Simbolo s;
  double d;
  //d.simb=(Simbolo *)(*pc++);
  s=(Simbolo)prog.elementAt(pc);
  pc=pc+1;
  pila.push(s);
  }
   void whilecode(){
      boolean d;
      int savepc = pc;
      execute(savepc+2);  /* condition */
      d=((Boolean)pila.pop()).booleanValue();
      while (d) {
   execute(
            ((Integer)prog.elementAt(savepc)).intValue());
   execute(savepc+2);
   d=((Boolean)pila.pop()).booleanValue();  
      }
      pc=((Integer)prog.elementAt(savepc+1)).intValue();
   }
   void ifcode(){
      boolean d;
      //double d;
      int savepc=pc;
      execute(savepc+3);
      //d=((Double)pila.pop()).doubleValue();
      d=((Boolean)pila.pop()).booleanValue();
      if(d){
         execute(((Integer)prog.elementAt(savepc)).intValue());
      }
      else if(!prog.elementAt(savepc+1).toString().equals("STOP"))
         execute(((Integer)prog.elementAt(savepc+1)).intValue());
      pc=((Integer)prog.elementAt(savepc+2)).intValue();
   }
   void define(Simbolo s){
    s.defn=progbase;
    progbase=prog.size();
   }
   void add(){
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        Complejo resultado=operaciones.suma(numero1,numero2);

        pila.push(new Double(resultado.getReal()));
        pila.push(new Double(resultado.getImaginario()));
   }
   void sub(){
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        Complejo resultado=operaciones.resta(numero1,numero2);

        pila.push(new Double(resultado.getReal()));
        pila.push(new Double(resultado.getImaginario()));
      }
   void mul(){
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        Complejo resultado=operaciones.multiplicacion(numero1,numero2);

        pila.push(new Double(resultado.getReal()));
        pila.push(new Double(resultado.getImaginario()));
   }
   void div(){
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        if(numero2.getReal()!=0 && numero2.getImaginario()!=0){
          Complejo resultado=operaciones.division(numero1,numero2);

          pila.push(new Double(resultado.getReal()));
          pila.push(new Double(resultado.getImaginario()));
        }
   }

   void negate(){
        double d;
        d=((Double)pila.pop()).doubleValue();
        d=-d;
        pila.push(new Double(d));
   }
   void eq(){
      boolean res;          
         
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        res=operaciones.igualdad(numero1,numero2);

      pila.push(new Boolean(res));
   }
   void ne(){
      boolean res;          
         
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        res=operaciones.desigualdad(numero1,numero2);

      pila.push(new Boolean(res));
   }
   void lt(){
      boolean res;          
         
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        res=operaciones.menorQue(numero1,numero2);

      pila.push(new Boolean(res));
   }
   void le(){
      boolean res;          
         
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        res=operaciones.menorIgualQue(numero1,numero2);

      pila.push(new Boolean(res));
   }
   void gt(){
      boolean res;          
         
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        res=operaciones.mayorQue(numero1,numero2);

      pila.push(new Boolean(res));
   }
   void ge(){
      boolean res;          
         
        double real, imaginario;
        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero2=new Complejo(real,imaginario);

        imaginario=((Double)pila.pop()).doubleValue();
        real=((Double)pila.pop()).doubleValue();
        Complejo numero1=new Complejo(real,imaginario);

        res=operaciones.mayorIgualQue(numero1,numero2);

      pila.push(new Boolean(res));
   }
   void or(){
      boolean d1, d2;
      d2=((Boolean)pila.pop()).booleanValue();
      d1=((Boolean)pila.pop()).booleanValue();
      d1=(d1 || d2);
      pila.push(new Boolean(d1));
   }
   void and(){
      boolean d1, d2;
      d2=((Boolean)pila.pop()).booleanValue();
      d1=((Boolean)pila.pop()).booleanValue();
      d1=(d1 && d2);
      pila.push(new Boolean(d1));
   }
   void not(){
      boolean d;
      d=((Boolean)pila.pop()).booleanValue();
      d=!d;
      pila.push(new Boolean(d));
   }
   void eval(){
      Simbolo s;
      s=(Simbolo)pila.pop();
      if(s.tipo == INDEF)
         System.out.println("variable no definida "+ s.nombre);
    //execerror("variable no definida", d.simb->nombre);
      pila.push(new Double(s.val.getReal()));
      pila.push(new Double(s.val.getImaginario()));
   }
/*
  void eval()
  {
        Simbolo s;
    s=(Simbolo)pila.pop();
    pila.push(new Double(s.val));
  }
*/
  void assign()
  {
  Simbolo s;
  Double imaginario,real;
  s=(Simbolo)pila.pop();
  imaginario=(Double)pila.pop();
  real=(Double)pila.pop();
    //execerror("asignacion  a una no variable", 
      //d1.simb->nombre);
  if(s.tipo != VAR && s.tipo != INDEF)
    System.out.println("asignacion  a una no variable "+s.nombre);
  s.val = new Complejo(real.doubleValue(),imaginario.doubleValue());
  s.tipo= VAR;
  pila.push(new Double(s.val.getReal()));
  pila.push(new Double(s.val.getImaginario()));
  }
  void print(){
  Double real,imaginario;
  imaginario=(Double)pila.pop();
  real=(Double)pila.pop();
  System.out.printf("[%.2f %+.2f j]\n",real.doubleValue(),imaginario.doubleValue());
  }
  void prexpr(){
  Double real,imaginario;
  imaginario=(Double)pila.pop();
  real=(Double)pila.pop();
  System.out.printf("[%.2f %+.2f j]\n",real.doubleValue(),imaginario.doubleValue());
  }

  void sin(){
    Double real,imaginario;
    imaginario=(Double)pila.pop();
    real=(Double)pila.pop();
    Complejo numero = new Complejo(real,imaginario);

    Complejo resultado = operaciones.seno(numero);

    pila.push(new Double(resultado.getReal()));
    pila.push(new Double(resultado.getImaginario()));
  }

  void cos(){
    Double real,imaginario;
    imaginario=(Double)pila.pop();
    real=(Double)pila.pop();
    Complejo numero = new Complejo(real,imaginario);

    Complejo resultado = operaciones.coseno(numero);

    pila.push(new Double(resultado.getReal()));
    pila.push(new Double(resultado.getImaginario()));
  }

  /*void exp(){
    Double exponente;
    Complejo resultado = operaciones.exponencial(exponente);
    pila.push(new Double(resultado.getReal()));
    pila.push(new Double(resultado.getImaginario()));
  }*/

  void bltin()
  {
  Maquina maquina=new Maquina();
  Class clase=maquina.getClass();
  String inst;
  inst=((Simbolo)prog.elementAt(pc)).nombre;
  try{
    Method metodoExistente=clase.getDeclaredMethod(inst);
    metodoExistente.invoke(this);
  } catch(NoSuchMethodException e) {
         System.out.println(e.toString());
  } catch (IllegalArgumentException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
  }catch (IllegalAccessException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
  }catch (InvocationTargetException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
  }
  pc=pc+1;
  }

}