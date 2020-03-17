import java.awt.*;
import javax.swing.*;
import javax.swing.text.*;
import java.awt.event.*;
import javax.swing.event.*;
import javax.swing.filechooser.*;
//import javax.imageio.*;
import java.awt.image.*;
import java.awt.geom.Rectangle2D;

public class MainWin extends JFrame implements Runnable, ActionListener {
   int TimerID = 43;
   int TimeOutDelay = 30;
   private MenuBar menubar;
   private Menu file;
   private MenuItem openBlueMenuItem;
   private MenuItem openRedMenuItem;
   private MenuItem goMenuItem;
   CoreDoc pDoc;
   Thread hilo;
   public MainWin(){
      super("CoreWars");
      pDoc = new CoreDoc();
      GetDocument().SetUpWorld(/*&r*/);
      menubar = new MenuBar();
      file = new Menu("File");
      openBlueMenuItem = new MenuItem("Open Blue");
      openBlueMenuItem.addActionListener(this);
      file.add(openBlueMenuItem);
      
      openRedMenuItem = new MenuItem("Open Red");
      openRedMenuItem.addActionListener(this);
      file.add(openRedMenuItem);

      goMenuItem = new MenuItem("Go");
      goMenuItem.addActionListener(this);
      file.add(goMenuItem);
      menubar.add(file);
      //file.add("Quit");
      this.setMenuBar(menubar);
      setSize(1225,800);//Se establece las magnitudes del JFrame.
      setVisible(true);
      this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
      hilo = new Thread(this);
      hilo.start();
   }
   public CoreDoc GetDocument() {
      return pDoc;
   }
   public void run(){
      BufferedImage Imagen_en_memoria;  
      Graphics2D g2d;
      Graphics g=getGraphics();
      Core pCore = pDoc.getMARS().GetCore(); 
      
      while(true){
         Imagen_en_memoria = new BufferedImage(this.getWidth()-0, this.getHeight()-0, BufferedImage.TYPE_INT_RGB);
        g2d = Imagen_en_memoria.createGraphics();
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        
        g2d.setColor(Color.white);
        g2d.fill(new Rectangle2D.Double(0,0,this.getWidth(), this.getHeight()));
        g2d.setColor(Color.black);
        g2d.setFont(new Font("Dialog", Font.BOLD, 12));
          for(int i=0;i<40;i++){
            g2d.drawLine(0, (i+1)*16+30, 371, (i+1)*16+30 );
            g2d.drawString(""+i*100, 6,(i+1)*16+30);
            g2d.drawString(""+((i+1)*100-1), 371,(i+1)*16+30);
            for(int j=0;j< 100; j++){
               g2d.drawLine(j*4, (i+1)*16+25, j*4, (i+1)*16+30 );
            }
            //g2d.drawLine(365, (i+1)*16+30, 370, (i+1)*16+30 );
          }
         pDoc.Run(/*pDC*/);
         g2d.setFont(new Font("Dialog", Font.BOLD, 21));
         pCore.printCore(g2d, pCore.getAB(), 0, (Core.CoreSize/4)*3, 20);
         //repaint();
         HitInfo H=new HitInfo(); 
         if(pDoc != null ){ 
            while( (pDoc.GetAHit(H)) ){
               int x = 4*(H.HitLocation % 100);
               int y = 4*( (H.HitLocation / 25 )+1 );
               g2d.setColor(H.rgb);                             
               g2d.drawLine(x, y+30, x, y+30 );
               g2d.fillOval(x, y+30, 5, 5);
               System.out.println("while paint x= "+x+" y ="+y);
            }
         }
         if(pDoc.MARS.IsRedWarriorDead()){         
            pDoc.Reset();
            JOptionPane.showInputDialog("El Rojo esta Muerto.");
            //System.exit(0);
            // "It's all over!
            //Invalidate(TRUE);
         } else {
            g2d.setColor(Color.red);
            //g2d.drawLine(5,170,64*4,170);
            g2d.drawLine(5, 680,64*4, 680);
         }        
         if(pDoc.MARS.IsBlueWarriorDead()){
            pDoc.Reset();
            JOptionPane.showInputDialog("El Azul pierde, Cuate.");
            //System.exit(0);
            //"I'm a loser, Baby!     
            //Invalidate(TRUE);
         } else {  
            g2d.setColor(Color.blue);
            g2d.drawLine(5, 696,64*4, 696);
         }   
         g.drawImage(Imagen_en_memoria, 0, 0, this);    
         try {
             Thread.sleep(100);
         } catch (Exception e){ return ;}
      }
   } 
   public void actionPerformed(ActionEvent e){
      if(e.getSource() == openBlueMenuItem){
        JFileChooser selector = new JFileChooser();
        int r = selector.showOpenDialog(null);
        if (r == JFileChooser.APPROVE_OPTION) {
           pDoc.OnFileOpenBlue(selector.getSelectedFile().getName());
        }
      }
      if(e.getSource() == openRedMenuItem){
        JFileChooser selector = new JFileChooser();
        int r = selector.showOpenDialog(null);
        if (r == JFileChooser.APPROVE_OPTION) {
            pDoc.OnFileOpenRed(selector.getSelectedFile().getName());
        }
      }
      if(e.getSource() == goMenuItem){
         if(pDoc.RedWarriorLoaded && pDoc.BlueWarriorLoaded){
           pDoc.OnCorewarGo();
         } else {
            ;
            //CDialog Bitch(IDD_DIALOG1);
            //Bitch.DoModal();
         }  
      }
    } 
   public static void main(String argv[]) {
        System.setProperty("apple.laf.useScreenMenuBar", "true");
	JFrame frame = new MainWin();
   }
}
