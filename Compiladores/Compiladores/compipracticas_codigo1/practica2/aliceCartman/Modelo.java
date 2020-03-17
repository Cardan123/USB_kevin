/*
 * Modelo.java
 */
import java.util.Observable;
public class Modelo extends Observable {
    private float vel=0.2f;
    private int giro=10;
    /** Creates new Modelo */
    private int mapa[][];
    private float x,y;
    private int angulo;
    private int noPisar[];
    float seno[]=new float[360];
    float coseno[]=new float[360];
    
    public Modelo(int mapa[][], int x, int y, int angulo, int noPisar[]) {
        for (int n=0;n<360;n++){
            seno[n]=(float)(Math.sin(n*Math.PI*2/360.0));
            coseno[n]=(float)(Math.cos(n*Math.PI*2/360.0));
        }
        this.x=x;
        this.y=y;
        this.angulo=angulo;
        this.mapa=mapa;
        this.noPisar=noPisar;
    }

    public int[][] getMapa(){
        return mapa;
    }
    
    public float getX(){
        return x;
    }
    
    public float getY(){
        return y;
    }
    
    public float getAnguloRadianes(){
        return (float)(angulo*2*Math.PI / 360);
    }
    
    public float getSeno(){
        return seno[angulo];
    }

    public float getCoseno(){
        return coseno[angulo];
    }

    public float getSenoInc(int ang){
        ang=ang+angulo;
        if (ang>=360) ang=ang-360;
        if (ang<0) ang=ang+360;
        return seno[ang];
    }

    public float getCosenoInc(int ang){
        ang=ang+angulo;
        if (ang>=360) ang=ang-360;
        if (ang<0) ang=ang+360;
        return coseno[ang];
    }
    
    public boolean sePuedePisar(float x,float y){
        float dis=0.4f;
        boolean correcto=true;
/*
        for (int n=0;n<noPisar.length && correcto;n++){
            if (mapa[(int)(x+dis)][(int)(y)]==noPisar[n]) correcto=false;
            if (mapa[(int)(x-dis)][(int)(y)]==noPisar[n]) correcto=false;
            if (mapa[(int)(x)][(int)(y-dis)]==noPisar[n]) correcto=false;
            if (mapa[(int)(x)][(int)(y-dis)]==noPisar[n]) correcto=false;
            if (mapa[(int)(x+dis)][(int)(y+dis)]==noPisar[n]) correcto=false;
            if (mapa[(int)(x-dis)][(int)(y+dis)]==noPisar[n]) correcto=false;
            if (mapa[(int)(x+dis)][(int)(y-dis)]==noPisar[n]) correcto=false;
            if (mapa[(int)(x+dis)][(int)(y-dis)]==noPisar[n]) correcto=false;
        }*/
        return correcto;
    }
    
    //Mover el Muneco
    public void setXYMuneco(float xf, float yf){
        if (!sePuedePisar(xf, yf)){
            if (sePuedePisar(x, yf)){
                xf=x;
            }else if(sePuedePisar(xf,y)){
                yf=y;
            }else{
                xf=x;
                yf=y;
            }
        }
        x=xf;
        y=yf;
	System.out.println("x=("+x+")"+" y=("+y+")");
        setChanged(); 
    }
    
    public void avanzar(){
        setXYMuneco((float)(x+vel*coseno[angulo]),(float)(y+vel*seno[angulo]));
    }
    
    public void retroceder(){
        setXYMuneco((float)(x-vel*coseno[angulo]),(float)(y-vel*seno[angulo]));
    }

    public void girarDerecha(){
        angulo=angulo+giro;
        if (angulo>=360) angulo=angulo-360;
        setChanged();
    }
    
    public void girarIzquierda(){
        angulo=angulo-giro;
        if (angulo<0) angulo=angulo+360;
        setChanged();
    }
    
    public void setCambio(){
        setChanged();
    }
}
