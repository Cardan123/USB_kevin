public class Vector { 
    private final int n;         
    private double[] eltos;       

    public Vector(int n) {
        this.n = n;
        this.eltos = new double[n];
    }
    public Vector(double[] eltos) {
        n = eltos.length;
        this.eltos = new double[n];
        for (int i = 0; i < n; i++)
            this.eltos[i] = eltos[i];
    }
    public Vector(Vector v) {
        n = v.eltos.length;
        eltos = new double[n];
        for (int i = 0; i < n; i++)
            eltos[i] = v.eltos[i];
    }
    public int longitud() {
        return n;
    }
    public double punto(Vector v) {
        double acu = 0.0;
        for (int i = 0; i < n; i++)
            acu = acu + (eltos[i] * v.eltos[i]);
        return acu;
    }
    public double magnitud() {
        return Math.sqrt(punto(this));
    }
    public double distanciaA(Vector v) {
        return resta(v).magnitud();
    }
    public Vector suma(Vector v) {
        Vector c = new Vector(n);
        for (int i = 0; i < n; i++)
            c.eltos[i] = eltos[i] + v.eltos[i];
        return c;
    }
    public Vector resta(Vector v) {
        Vector c = new Vector(n);
        for (int i = 0; i < n; i++)
            c.eltos[i] = eltos[i] - v.eltos[i];
        return c;
    }
    public double cartesiano(int i) {
        return eltos[i];
    }
    public Vector veces(double factor) {
        Vector c = new Vector(n);
        for (int i = 0; i < n; i++)
           c.eltos[i] = factor * eltos[i];
        return c;
    }
    public Vector escala(double factor) {
        Vector c = new Vector(n);
        for (int i = 0; i < n; i++)
           c.eltos[i] = factor * eltos[i];
        return c;
    }
    public Vector direccion() {
        return escala(1.0 / magnitud());
    }
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append('(');
        for (int i = 0; i < n; i++) {
            s.append(eltos[i]);
            if (i < n-1) s.append(", ");
        }
        s.append(')');
        return s.toString();
    }
   public void imprime() {
        System.out.println(this);
    }
}
