



import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayList;
import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class JPanelDibujo extends JPanel{
    
    CurrentState currentState;
    
    public JPanelDibujo(){
        currentState = new CurrentState();  
    }
    
    public void setCurrentState(CurrentState currentState){
        this.currentState = currentState;
    }
    
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        ArrayList<Linea> lineas = currentState.getLineas();
        for(int i = 0; i < lineas.size(); i++){
            int x0 = 300 + lineas.get(i).getX0();
            int y0 = 300 - lineas.get(i).getY0();
            int x1 = 300 + lineas.get(i).getX1();
            int y1 = 300 - lineas.get(i).getY1();;
            g.setColor(lineas.get(i).getColor());
            g.drawLine(x0, y0, x1, y1);
        }
        
        BufferedImage img = null;
        try {
            img = ImageIO.read(new File("src/tuga.png"));
        } catch (Exception e){
            System.out.println(e);
        }
        
        int drawLocationX = 275+(int)currentState.getX();
        int drawLocationY = 275-(int)currentState.getY();

        double rotationRequired = Math.toRadians ((-1)*currentState.getAngulo());
        double locationX = img.getWidth() / 2 ;
        double locationY = img.getHeight() / 2;
        AffineTransform tx = AffineTransform.getRotateInstance(rotationRequired, locationX, locationY);
        AffineTransformOp op = new AffineTransformOp(tx, AffineTransformOp.TYPE_BILINEAR);

        g.drawImage(op.filter(img, null), drawLocationX, drawLocationY, 50, 50, this);
        
    }
}