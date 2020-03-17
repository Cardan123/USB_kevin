import java.lang.*;

public class OperacionesComplejos{

	public Complejo suma(Complejo numero1, Complejo numero2){
		Complejo resultado=new Complejo(0,0);
		resultado.setReal(numero1.getReal()+numero2.getReal());
		resultado.setImaginario(numero1.getImaginario()+numero2.getImaginario());
		return resultado;
	}

	public Complejo resta(Complejo numero1, Complejo numero2){
		Complejo resultado=new Complejo(0,0);
		resultado.setReal(numero1.getReal()-numero2.getReal());
		resultado.setImaginario(numero1.getImaginario()-numero2.getImaginario());
		return resultado;
	}

	public Complejo multiplicacion(Complejo numero1, Complejo numero2){
		Complejo resultado=new Complejo(0,0);
		double realReal=numero1.getReal()*numero2.getReal();//real
		double realImaginario=numero1.getReal()*numero2.getImaginario();//imaginario
		double imaginarioReal=numero1.getImaginario()*numero2.getReal();//imaginario
		double imaginarioImaginario=(-1)*numero1.getImaginario()*numero2.getImaginario();//-real

		resultado.setReal(realReal+imaginarioImaginario);
		resultado.setImaginario(realImaginario+imaginarioReal);
		return resultado;
	}

	public Complejo division(Complejo numero1, Complejo numero2){
		Complejo resultado=new Complejo(0,0);
		Complejo conjugado=new Complejo(numero2.getReal(),(-1)*numero2.getImaginario());

		Complejo auxiliar=this.multiplicacion(numero1,conjugado);
		double dividendo=this.multiplicacion(numero2,conjugado).getReal();

		resultado.setReal(auxiliar.getReal()/dividendo);
		resultado.setImaginario(auxiliar.getImaginario()/dividendo);
		return resultado;
	}

	public Complejo seno(Complejo numero){
		Complejo resultado=new Complejo(0,0);
		double real=Math.sin(numero.getReal())*Math.cosh(numero.getImaginario());
		double imaginario=Math.cos(numero.getReal())*Math.sinh(numero.getImaginario());
		resultado.setReal(real);
		resultado.setImaginario(imaginario);
		return resultado;

	}

	public Complejo coseno(Complejo numero){
		Complejo resultado=new Complejo(0,0);
		double real=Math.cos(numero.getReal())*Math.cosh(numero.getImaginario());
		double imaginario=(-1)*Math.sin(numero.getReal())*Math.sinh(numero.getImaginario());
		resultado.setReal(real);
		resultado.setImaginario(imaginario);
		return resultado;
	}

	public Complejo e_complejo(Complejo numero){
	 	double real=Math.exp(numero.getReal())*(Math.cos(numero.getImaginario()));
		double imaginario=Math.exp(numero.getReal())*(Math.sin(numero.getImaginario()));
	 	Complejo resultado=new Complejo(real,imaginario);
		return resultado;
	}
}