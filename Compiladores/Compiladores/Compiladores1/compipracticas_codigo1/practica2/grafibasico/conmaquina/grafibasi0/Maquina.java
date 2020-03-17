import java.awt.*;
import java.util.*;
import java.lang.reflect.*;

class  Maquina {

Stack pila;
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
   Maquina(){  }
   Maquina(Graphics g){ this.g=g; }
   public void setGraphics(Graphics g){ this.g=g; }
   public Vector getProg(){ return prog; }
   void initcode(){
      pila=new Stack();
      prog=new Vector();
   }
   Object pop(){ return pila.pop(); }
   int code(Object f){
		System.out.println("Gen ("+f+") size="+prog.size());
   		prog.addElement(f);
		return prog.size()-1;
   }
   void execute(int p){
		String inst;
                System.out.println("progsize="+prog.size());
                for(pc=0;pc < prog.size(); pc=pc+1){
			System.out.println("pc="+pc+" inst "+prog.elementAt(pc));
		}
		for(pc=p; !(inst=(String)prog.elementAt(pc)).equals("STOP") && !returning;){
		//for(pc=p;pc < prog.size();){
			try {
			//System.out.println("111 pc= "+pc);
			inst=(String)prog.elementAt(pc);
			pc=pc+1;
			System.out.println("222 pc= "+pc+" instr "+inst);
                        c=this.getClass();
			//System.out.println("clase "+c.getName());
          		metodo=c.getDeclaredMethod(inst, null);
			metodo.invoke(this, null);
			}
			catch(NoSuchMethodException e){
				System.out.println("No metodo "+e);
                        }

			catch(InvocationTargetException e){
				System.out.println(e);
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
      pila.push(new Double(s.val));
   }
   void color(){
      Color colors[]={Color.red,Color.green,Color.blue};
      double d1;
      d1=((Double)pila.pop()).doubleValue();
      if(g!=null){
         g.setColor(colors[(int)d1]);
      }
        
   }
   void line(){
      double d1;
      d1=((Double)pila.pop()).doubleValue();
      if(g!=null){
         (new Linea(x+150,150-y,
	 (int)(x+d1*Math.cos(angulo))+150, 
	 150-(int)(y+d1*Math.sin(angulo))) ).dibujar(g);
      }
      x=(int)(x+d1*Math.cos(angulo));
      y=(int)(y+d1*Math.sin(angulo));
      System.out.println("x="+x+" y="+y+" d1="+d1);
   }
   void circulo(){
      double d1;
      d1=((Double)pila.pop()).doubleValue();
      if(g!=null){
         (new Circulo(x+150, 150-y, (int)d1)).dibujar(g);
      }
   }
   void print(){
	Double d;
	//d=(Double)pila.pop();
	//System.out.println(""+d.doubleValue());
   }
   void prexpr(){
	Double d;
	//d=(Double)pila.pop();
	//System.out.print("["+d.doubleValue()+"]");
   }
}
