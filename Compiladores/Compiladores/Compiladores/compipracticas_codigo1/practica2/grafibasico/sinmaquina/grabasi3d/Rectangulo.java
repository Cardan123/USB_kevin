import java.awt.*;
import javax.vecmath.*;
import javax.media.j3d.*;

public class Rectangulo implements Dibujable {
	private double x=0;
	private double  y=0;
	private double  ancho=0;
	private double  alto=0;

	public Rectangulo(double  x, double  y, double  ancho, double  alto){
		this.x=x;
                this.y=y;
		this.ancho=ancho;
		this.alto=alto;
	}
        public void transladar(double dx,double dy) {
        	this.x+=dx; this.y+=dy;
    	}
        public void escalar(double dx, double dy){}
	//public void dibuja(Graphics g){
        public void dibujar(
           BranchGroup bg, Appearance branchApp){
		//g.drawRect(x1,y1,x2,y2);
               bg.addChild( CylinderCreator.create(
           new Point3d(x, y, 0), 
           new Point3d(x+ancho, y, 0), /*cylRadius*/0.01f, branchApp));
         bg.addChild( CylinderCreator.create(
           new Point3d(x, y, 0), 
           new Point3d(x, y+alto, 0), /*cylRadius*/0.01f, branchApp));
         bg.addChild( CylinderCreator.create(
           new Point3d(x+ancho, y, 0), 
           new Point3d(x+ancho, y+alto, 0), /*cylRadius*/0.01f, branchApp));
         bg.addChild( CylinderCreator.create(
           new Point3d(x, y+alto, 0), 
           new Point3d(x+ancho, y+alto, 0), /*cylRadius*/0.01f, branchApp));
	}
}
