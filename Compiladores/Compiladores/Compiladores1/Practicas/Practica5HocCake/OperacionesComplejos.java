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

	public Complejo pow(Complejo numero,double expo){
		Complejo resultado=new Complejo(numero.getReal(),numero.getImaginario());
		int num=(int)expo;
		if (num==0) {
			resultado=new Complejo(1,0);
		}else{
			for (int i=1;i<num;i++ ) {
				resultado=multiplicacion(resultado,numero);
			}
		}
		
		return resultado;
	}

	public boolean igualdad(Complejo numero1,Complejo numero2){
		if (numero1.getReal()==numero2.getReal() && numero1.getImaginario()==numero2.getImaginario()) {
			return true;
		}
		return false;
	}

	public boolean desigualdad(Complejo numero1, Complejo numero2){
		if (numero1.getReal()!=numero2.getReal() || numero1.getImaginario()!=numero2.getImaginario()) {
			return true;
		}
		return false;
	}

	public boolean menorQue(Complejo numero1,Complejo numero2){
		double num1=this.modulo(numero1);
		double num2=this.modulo(numero2);
		boolean resultado=(num1<num2)?true:false;
		return resultado;
	}

	public boolean menorIgualQue(Complejo numero1,Complejo numero2){
		double num1=this.modulo(numero1);
		double num2=this.modulo(numero2);
		boolean resultado=(num1<=num2)?true:false;
		return resultado;
	}

	public boolean mayorQue(Complejo numero1,Complejo numero2){
		double num1=this.modulo(numero1);
		double num2=this.modulo(numero2);
		boolean resultado=(num1>num2)?true:false;
		return resultado;
	}

	public boolean mayorIgualQue(Complejo numero1,Complejo numero2){
		double num1=this.modulo(numero1);
		double num2=this.modulo(numero2);
		boolean resultado=(num1>=num2)?true:false;
		return resultado;
	}

	public double modulo(Complejo numero){
		return Math.sqrt(Math.pow(numero.getReal(),2)+Math.pow(numero.getImaginario(),2));
	}
}