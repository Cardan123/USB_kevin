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
public final static short FORWARD=262;
public final static short RIGHT=263;
public final static short OR=264;
public final static short AND=265;
public final static short GT=266;
public final static short LT=267;
public final static short GE=268;
public final static short LE=269;
public final static short EQ=270;
public final static short NOT=271;
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
Cartman body;

	Maquina(Graphics g){
		this.g=g;
	}
	public Vector getProg(){
		return prog;
	}
	public void setBody(Cartman body){
		this.body=body;
	}
	void initcode(){
        	pila=new Stack();
		marcos=new Stack();
		prog=new Vector();
	}
	Object pop(){
		return pila.pop();
	}
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
        void forward(){
		double d1;
		d1=((Double)pila.pop()).doubleValue() * 0.01f;
/*
                if(g!=null)
			g.drawLine(x+150,150-y,
			(int)(x+d1*Math.cos(angulo))+150, 
			150-(int)(y+d1*Math.sin(angulo)));
                x=(int)(x+d1*Math.cos(angulo));
                y=(int)(y+d1*Math.sin(angulo));
                System.out.println("x="+x+" y="+y+" d1="+d1);*/
                System.out.println("x= "+Math.cos(angulo)*d1+
                " y= "+Math.sin(angulo)*d1);
                //body.moveBy(Math.cos(angulo),Math.sin(angulo));
                body.moveBy(d1 * Math.sin(angulo), d1* Math.cos(angulo));
                try { Thread.sleep(1000);
		} catch (Exception e){}
	}
        void right(){
		double d1;
		d1=((Double)pila.pop()).doubleValue();   
                angulo=angulo+d1*(Math.PI/180);
		if(angulo>2*Math.PI)
                   angulo=angulo-2*Math.PI;
	}
	void print()
	{
	Double d;
	d=(Double)pila.pop();
	System.out.println(""+d.doubleValue());
	}
}
