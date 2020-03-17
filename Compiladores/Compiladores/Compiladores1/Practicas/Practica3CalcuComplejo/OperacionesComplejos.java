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

	public Complejo exponencial(Complejo numero,double expo){
		Complejo resultado=new Complejo(numero.getReal(),numero.getImaginario());
		int num=(int)expo;
		if (num==0) {
			resultado=new Complejo(1,0);
		}else{
			for (int i=0;i<num-1;i++ ) {
				resultado=multiplicacion(resultado,numero);
			}
		}
		
		return resultado;
	}

	public Complejo ln(Complejo numero){
		double real = numero.getReal();
		double imag = numero.getImaginario();
		double r_real = Math.log((double)Math.sqrt(Math.pow(real,2) + Math.pow(imag,2)));
		double r_imag = Math.atan(imag/real);
		Complejo resultado = new Complejo(r_real, r_imag);
		return resultado;
	}
}
