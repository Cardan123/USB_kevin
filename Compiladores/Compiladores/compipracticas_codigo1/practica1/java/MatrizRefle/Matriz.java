

public class Matriz {
    private final int M;             // number of rows
    private final int N;             // number of columns
    public double[][] data;   // M-by-N array
    //public Matriz(){}

    //public Matriz(double[][] numeros){
    //    this.data = numeros;
    //}
    // create M-by-N matrix of 0's
    public Matriz(int M, int N) {
        this.M = M;
        this.N = N;
        data = new double[M][N];
    }

    // create matrix based on 2d array
    public Matriz(double[][] data) {
        M = data.length;
        N = data[0].length;
        this.data = new double[M][N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                    this.data[i][j] = data[i][j];
    }

    // copy constructor
    private Matriz(Matriz A) { this(A.data); }

    // create and return a random M-by-N matrix with values between 0 and 1
    public static Matriz random(int M, int N) {
        Matriz A = new Matriz(M, N);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                A.data[i][j] = Math.random();
        return A;
    }

    // create and return the N-by-N identity matrix
    public static Matriz identity(int N) {
        Matriz I = new Matriz(N, N);
        for (int i = 0; i < N; i++)
            I.data[i][i] = 1;
        return I;
    }

    // swap rows i and j
    private void swap(int i, int j) {
        double[] temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    // create and return the transpose of the invoking matrix
    public Matriz transpose() {
        Matriz A = new Matriz(N, M);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                A.data[j][i] = this.data[i][j];
        return A;
    }

    // return C = A + B
    public Matriz sumar(Matriz B) {
        Matriz A = this;
        if (B.M != A.M || B.N != A.N) throw new RuntimeException("Illegal matrix dimensions.");
        Matriz C = new Matriz(M, N);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                C.data[i][j] = A.data[i][j] + B.data[i][j];
        return C;
    }


    // return C = A - B
    public Matriz restar(Matriz B) {
        Matriz A = this;
        if (B.M != A.M || B.N != A.N) throw new RuntimeException("Illegal matrix dimensions.");
        Matriz C = new Matriz(M, N);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                C.data[i][j] = A.data[i][j] - B.data[i][j];
        return C;
    }
    // does A = B exactly?
    public boolean eq(Matriz B) {
        Matriz A = this;
        if (B.M != A.M || B.N != A.N) throw new RuntimeException("Illegal matrix dimensions.");
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (A.data[i][j] != B.data[i][j]) return false;
        return true;
    }
    // return C = A * B
    public Matriz mult(Matriz B) {
        Matriz A = this;   
        if (A.N != B.M) throw new RuntimeException("Illegal matrix dimensions.");
        //imprime();
        //B.imprime();
        Matriz C = new Matriz(A.M, B.N);
        for (int i = 0; i < C.M; i++)
            for (int j = 0; j < C.N; j++){
                C.data[i][j] = 0;
                for (int k = 0; k < A.N; k++){
                    //System.out.println("a*b "+A.data[i][k] * B.data[k][j]);
                    //System.out.println("A a*b "+data[i][k] +" k = "+k);
                    //System.out.println("2 a*b "+B.data[k][j] +" k = "+k);
                         C.data[i][j] += (A.data[i][k] * B.data[k][j]);
                }
                //System.out.println("mat mult ij "+C.data[i][j]);
            }
        //System.out.println("mat mult CM "+C.M); 
        //C.imprime(); 
        return C;
    }
    // return x = A^-1 b, assuming A is square and has full rank
    public Matriz solve(Matriz rhs) {
        if (M != N || rhs.M != N || rhs.N != 1)
            throw new RuntimeException("Illegal matrix dimensions.");

        // create copies of the data
        Matriz A = new Matriz(this);
        Matriz b = new Matriz(rhs);

        // Gaussian elimination with partial pivoting
        for (int i = 0; i < N; i++) {

            // find pivot row and swap
            int max = i;
            for (int j = i + 1; j < N; j++)
                if (Math.abs(A.data[j][i]) > Math.abs(A.data[max][i]))
                    max = j;
            A.swap(i, max);
            b.swap(i, max);

            // singular
            if (A.data[i][i] == 0.0) throw new RuntimeException("Matriz is singular.");

            // pivot within b
            for (int j = i + 1; j < N; j++)
                b.data[j][0] -= b.data[i][0] * A.data[j][i] / A.data[i][i];

            // pivot within A
            for (int j = i + 1; j < N; j++) {
                double m = A.data[j][i] / A.data[i][i];
                for (int k = i+1; k < N; k++) {
                    A.data[j][k] -= A.data[i][k] * m;
                }
                A.data[j][i] = 0.0;
            }
        }

        // back substitution
        Matriz x = new Matriz(N, 1);
        for (int j = N - 1; j >= 0; j--) {
            double t = 0.0;
            for (int k = j + 1; k < N; k++)
                t += A.data[j][k] * x.data[k][0];
            x.data[j][0] = (b.data[j][0] - t) / A.data[j][j];
        }
        return x;
   
    }
    // print matrix to standard output
    public void imprime(){
        double[][] A = data;
        for(int i = 0; i < A.length; i++){
            for(int j = 0; j<A[0].length; j++)
                System.out.print(""+A[i][j]+" "); 
            System.out.println("");
        }
    }
}
