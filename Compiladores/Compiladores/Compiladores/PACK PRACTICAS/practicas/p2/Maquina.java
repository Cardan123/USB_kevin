import java.awt.*;
import java.util.*;
import java.lang.reflect.*;

public class Maquina{

		/*Creando la pila para la maquina virtual*/	
		Stack pila;
		Vector prog;
		static int pc=0; /*Contador de programa*/
		int progbase=0;		
		boolean returning=false;
		int numArchi=0;
		Method metodo;
		Method metodos[];
		Class c;
		Graphics g;
		Canvas canvas;
		double angulo;
		static int x=0, y=0; /*Coordenadas*/
		int dx = 1;     	//desplazamientos
    	int dy = 1;
		Class parames[];
		
		Maquina(Graphics g ,Canvas can){ 
			this.g=g; 
			this.canvas = can;
		}
		
		public Vector getProg(){ 
			return prog; 
		}
		/*Inicializando la pila*/
		void initcode(){
        	pila=new Stack();
			prog=new Vector();
		}
		/*Sacar de la pila*/
		Object pop(){ 
			return pila.pop(); 
		}
		/*Agregando una instruccion*/
		int code(Object f){
			System.out.println("Gen ("+f+") size="+prog.size());
   			prog.addElement(f);
			return prog.size()-1;
		}
		/*Ejecucion de la maquina*/
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
					}catch(NoSuchMethodException e){
						System.out.println("No metodo "+e);
		            }catch(InvocationTargetException e){
						System.out.println(e);
		            }catch(IllegalAccessException e){
						System.out.println(e);
		            }
				}
		}

	//Nota el tamaño del canvas es de 450,300
	void constpush(){
		Simbolo s;
		Double d;
		s=(Simbolo)prog.elementAt(pc);
		pc=pc+1;
		pila.push(new Double(s.val));
	}
    void color(){
        Color colors[]={Color.white,Color.red,Color.green,Color.blue,Color.orange,Color.yellow,Color.pink};
		double d1;
		d1=((Double)pila.pop()).doubleValue();
        if(g!=null) g.setColor(colors[(int)d1]);
		
    }
    /*
	void line(){
		double d1;
		d1=((Double)pila.pop()).doubleValue();
                if(g!=null){
                        (new Linea(x+150,150-y,
			(int)(x+d1*Math.cos(angulo))+150, 
			150-(int)(y+d1*Math.sin(angulo))) ).dibuja(g);
                }
                x=(int)(x+d1*Math.cos(angulo));
                y=(int)(y+d1*Math.sin(angulo));
                System.out.println("x="+x+" y="+y+" d1="+d1);
	}*/
	//implementar rectangulo 
    void rectangulo(){    	
    	int ancho = canvas.getWidth();
    	int alto = canvas.getHeight();
    	double d1,d2;
		d1=((Double)pila.pop()).doubleValue();
		d2=((Double)pila.pop()).doubleValue();
                if(g!=null){
                	new Rectangulo(x,y,(int)d1,(int)d2).dibuja(g);
                }            
                System.out.println("x="+x+" y="+y+" d1="+d1);
                System.out.println("ancho = "+ancho+ "alto = "+alto);
    }
    //implementar mover
    void mover(){         
    	 double d1 = ((Double)pila.pop()).doubleValue();
    	 double d2 = ((Double)pila.pop()).doubleValue();
    	 x = (int) d2;
    	 y = (int) d1;
    	 System.out.println("x="+x+" y="+y+" d1="+d1);       	 
    }

    void circulo(){
		int ancho = canvas.getWidth();
    	int alto = canvas.getHeight();    	
		double d1;
		d1=((Double)pila.pop()).doubleValue();
                if(g!=null){
			 		new Circulo(x,y,(int)d1).dibuja(g);
                }		 		
                System.out.println("x="+x+" y="+y+" d1="+d1);                
                System.out.println("ancho = "+ancho+ "alto = "+alto);
    }
   
	void print(){
			Double d;
			d=(Double)pila.pop();
			System.out.println(""+d.doubleValue());
	}

	void prexpr(){
		Double d;
		d=(Double)pila.pop();
		System.out.print("["+d.doubleValue()+"]");
	}
}