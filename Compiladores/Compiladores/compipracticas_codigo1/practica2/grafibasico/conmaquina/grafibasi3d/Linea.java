import java.awt.*;
import javax.vecmath.*;
import javax.media.j3d.*;

public class Linea implements Dibujable {
	private double x1=0;
	private double y1=0;
	private double x2=0;
	private double y2=0;

	public Linea(double x1, double y1, double x2, double y2){
		this.x1=x1;
		this.y1=y1;
		this.x2=x2;
		this.y2=y2;
	}
        public void transladar(double dx,double dy) {
        	this.x1+=dx; this.y1+=dy;
                this.x2+=dx; this.y2+=dy;
    	}
        public void escalar(double dx, double dy){}
	public void dibujar(
           BranchGroup bg, CylinderCreator cylinder, Appearance branchApp){
                System.out.println("en dib linea");
System.out.println("IFIF line() d1= "+x1+" d2 ="+y1+" d3= "+x2+" d4= "+y2);
		//g.drawLine(x1,y1,x2,y2);
            bg.addChild( cylinder.create(
           new Point3d(x1, y1, 0), 
           new Point3d(x2, y2, 0), 0.002f, branchApp));
	}
}
