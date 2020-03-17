class Racional {
	int den, num;

	public Racional(int num, int den){
		this.den=den; 
		this.num=num;
	}
	public Racional mult(Racional r){
		return new Racional(num * r.num, den * r.den);
	}
	public Racional division(Racional r){
		return new Racional(num * r.den, den * r.num);
	}
	public boolean esIgual(Racional r){
		return num * r.den == den * r.num;
	}
	public void imprime(){
		System.out.println(this.num+" / "+ this.den);
	}
}	
