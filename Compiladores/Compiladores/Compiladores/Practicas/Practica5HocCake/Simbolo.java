class Simbolo {
	String nombre;
	public short tipo;
	Complejo val=new Complejo(0,0);
	double dval;
	public String metodo;
	int defn;
	Simbolo sig;

	Simbolo(String s, short t, Complejo d)
	{
		nombre=s;
		tipo=t;
		val=d;
	}
	Simbolo(String s, short t, double d)
	{
		nombre=s;
		tipo=t;
		dval=d;
	}
        public Simbolo obtenSig()
        {
		return sig;
	}
        public void ponSig(Simbolo s)
	{
		sig=s;
	}
        public String obtenNombre()
	{
		return nombre;
	}
}