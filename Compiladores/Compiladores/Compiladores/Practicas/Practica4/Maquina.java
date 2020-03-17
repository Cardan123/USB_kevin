import java.util.*;
import java.lang.reflect.*;

public class Maquina {
	public final static short VAR=258;

	Vector prog;
	Stack<Complejo> pila;
	OperacionesComplejos operaciones;
	Tabla tabla;
	int pc;

	Class c;
	Method metodo;

	public Maquina(){
		prog=new Vector();
		pila=new Stack<Complejo>();
		operaciones=new OperacionesComplejos();
		tabla=new Tabla();
		pc=0;
	}

	void execute(){
		pc=0;
		String inst;
		for(int i=0;i<prog.size();i++){
			try{
				inst=(String)prog.elementAt(i);
				if(inst.equals("STOP")){
					prog=new Vector();
					break;
				}
				c=this.getClass();
				metodo=c.getDeclaredMethod(inst);
				metodo.invoke(this);
				pc++;
			}catch(NoSuchMethodException e){
				pc++;
			}catch(Exception e){
				System.out.println("Error: "+e);
            }
		}
	}

	void code(String inst){
		prog.addElement(inst);
	}

	void code(Complejo numero){
		pila.push(numero);

	}

	void suma(){
		Complejo numero2=pila.pop();
		Complejo numero1=pila.pop();

		Complejo resultado=operaciones.suma(numero1,numero2);
		pila.push(resultado);
	}

	void resta(){
		Complejo numero2=pila.pop();
		Complejo numero1=pila.pop();

		Complejo resultado=operaciones.resta(numero1,numero2);
		pila.push(resultado);
	}

	void multiplicacion(){
		Complejo numero2=pila.pop();
		Complejo numero1=pila.pop();

		Complejo resultado=operaciones.multiplicacion(numero1,numero2);
		pila.push(resultado);
	}

	void division(){
		Complejo numero2=pila.pop();
		Complejo numero1=pila.pop();
		if(numero2.getReal()!= 0 && numero2.getImaginario()!=0){
			Complejo resultado=operaciones.division(numero1,numero2);
			pila.push(resultado);
		}else{
			System.out.println("Error: División entre cero");
			prog=new Vector();
		}
		
	}

	void e_complejo(){
		Complejo numero1=pila.pop();

		Complejo resultado=operaciones.e_complejo(numero1);
		pila.push(resultado);

	}

	void sin(){
		Complejo numero1=pila.pop();

		Complejo resultado=operaciones.seno(numero1);
		pila.push(resultado);
	}

	void cos(){
		Complejo numero1=pila.pop();

		Complejo resultado=operaciones.coseno(numero1);
		pila.push(resultado);
	}

	void asignar(){
		String nombreVariable=(String)prog.elementAt(pc-1);
		Complejo valorVariable=pila.pop();
		if(tabla.lookup(nombreVariable)==null){
			tabla.install(nombreVariable,VAR,valorVariable);
		}else{
			tabla.lookup(nombreVariable,valorVariable);
		}
	}

	void imprime(){
		Complejo resultado=pila.pop();
		System.out.printf(":   <%.4f,%.4fj>\n",resultado.getReal(), resultado.getImaginario());
	}

	void valorVariable(){
		String nombreVariable=(String)prog.elementAt(pc-1);
		if(tabla.lookup(nombreVariable)!=null){
			Complejo valor=(tabla.lookup(nombreVariable)).val;
			pila.push(valor);
		}else{
			System.out.println("Variable no encontrada");
			prog=new Vector();
		}
	}
}