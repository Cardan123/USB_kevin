import java.awt.Image.* ;
import java.awt.Toolkit.* ;
import java.awt.*;
import java.io.Serializable;
import javax.swing.*;
import javax.vecmath.*;
import javax.media.j3d.*;

public class Imagen implements Dibujable {
	private double x=0, y=0;
	//String cade ;
	ImageIcon imagen ;
        public Image ima ;
	transient Container con ;
        Picture picture;
        public Picture getPicture() {
           return picture;
        }
        public Imagen(Picture picture){
                this.picture= picture ;
	} 
        public Imagen(Picture picture, double x, double y){ 
                      
                this.picture = picture ;
		this.y = y;
		this.x = x ;
   System.out.println("Imagen x = "+this.x +" y = "+this.y+" picture = "+this.picture);
		//this.cade=cade ;
	}
	public Imagen(Image ima){
                this.ima=ima ;
	}
	public Imagen(/*String cade,*/ImageIcon imagen, double x, double y, Container con){
		this.y=y;
		this.con=con;
		this.x=x ;
                this.imagen=imagen ;	
		//this.cade=cade ;
	}
        public Imagen(Image ima, double x, double y, Container con){
		this.y=y;
		this.con=con;
		this.x=x ;
                this.ima=ima ;
		//this.cade=cade ;
	}
        public void transladar(double dx,double dy) {
        	this.x+=dx; this.y+=dy;
                //this.x2+=dx; this.y2+=dy;
    	}
        public void escalar(double dx, double dy){}
        public void dibujar(
           BranchGroup bg, CylinderCreator cylinder, Appearance branchApp){
                System.out.println("en dib texto");
                System.out.println("dibu () d1 = "+x+" d2 = "+y+" picture = "+picture);
                Transform3D myTransform3D = new Transform3D();
      myTransform3D.setTranslation(new Vector3f(0 , 0, -2.3f));
      BranchGroup contentBranchGroup = new BranchGroup();
      TransformGroup contentTransformGroup = new TransformGroup(myTransform3D);
      contentTransformGroup.addChild(picture);
     
      contentBranchGroup.addChild(contentTransformGroup);
      bg.addChild(contentBranchGroup); 
                //g.drawImage (ima, x, y, con);
	}
}
