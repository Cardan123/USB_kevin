import java.awt.*;
import java.awt.image.*;
import java.util.*;
import java.lang.reflect.*;

import javax.vecmath.*;
import javax.media.j3d.*;
import java.io.*;
import javax.imageio.*;

class  Maquina {
   Filtradora poste;
   Tabla tabla;
   Stack pila;
   Vector prog;

   static int pc=0;
   int progbase=0;
   boolean returning=false;

   Method metodo;
   Method metodos[];
   Class c;
   Graphics g;
   double angulo;
   double x=0, y=0;
   Class parames[];
      
   BranchGroup bg;
   Appearance branchApp = new Appearance();
   CylinderCreator cylinder = new CylinderCreator();
   int cylEdges = 3;
   double cylRadius = 0.1;

   Maquina(){ 
      cylinder.setResolution(cylEdges);
      Material mat1 = new Material();
      mat1.setDiffuseColor(.9f, .2f, .05f);
      mat1.setAmbientColor(.18f, .05f, 0f);
      branchApp.setMaterial(mat1);
      poste= new Filtradora( ); 
   }
   public void setBranchGroup(BranchGroup bg){ this.bg = bg; }
   public void setTabla(Tabla t){ tabla = t; }
   public void setGraphics(Graphics g){ this.g=g; }
   Maquina(Graphics g){ 
      cylinder.setResolution(cylEdges);
      Material mat1 = new Material();
      mat1.setDiffuseColor(.9f, .2f, .05f);
      mat1.setAmbientColor(.18f, .05f, 0f);
      branchApp.setMaterial(mat1);
      this.g=g; 
   }
   public Vector getProg(){ return prog; }
   void initcode(){
      pila=new Stack();
      prog=new Vector();
   }
   Object pop(){ return pila.pop(); }
   int code(Object f){
      System.out.println("Gen ("+f+") size="+prog.size());
      prog.addElement(f);
      return prog.size()-1;
   }
   void execute(int p){
      String inst;
      System.out.println("progsize="+prog.size());
      for(pc=0;pc < prog.size(); pc=pc+1){
         System.out.println("pc="+pc+" inst "+prog.elementAt(pc));
      }
      for(pc=p; !(inst=(String)prog.elementAt(pc)).equals("STOP") && !returning;){
	 //for(pc=p;pc < prog.size();){
         try {
	    //System.out.println("111 pc= "+pc);
	    inst=(String)prog.elementAt(pc);
	    pc=pc+1;
	    System.out.println("222 pc= "+pc+" instr "+inst);
            c=this.getClass();
	    //System.out.println("clase "+c.getName());
            metodo=c.getDeclaredMethod(inst, null);
	    metodo.invoke(this, null);
	 } catch(NoSuchMethodException e){
				System.out.println("No metodo "+e);
         } catch(InvocationTargetException e){
				System.out.println(e);
         } catch(IllegalAccessException e){
				System.out.println(e);
         }
      }
   }
   void constpush(){
      Simbolo s;
      Double d;
      s=(Simbolo)prog.elementAt(pc);
      pc=pc+1;
      pila.push(new Double(s.val));
   }
   void varpush(){
      Simbolo s;
      double d;
      //System.out.println("varpush ");
      s=(Simbolo)prog.elementAt(pc);
      pc=pc+1;
      pila.push(s);
   }
   void color(){
      Color colors[]={Color.red,Color.green,Color.blue};
      double d1;
      d1=((Double)pila.pop()).doubleValue();
      if(g!=null){
         g.setColor(colors[(int)d1]);
      }
   }
   void line(){
      double d1;
      d1=((Double)pila.pop()).doubleValue();
      if(bg!=null){
         bg.addChild( cylinder.create(
           new Point3d(x, y, 0), 
           new Point3d(
  x+d1*Math.cos(angulo), y+d1*Math.sin(angulo), 0), /*cylRadius*/0.002f, branchApp));
      }
      x=(int)(x+d1*Math.cos(angulo));
      y=(int)(y+d1*Math.sin(angulo));
      System.out.println("x="+x+" y="+y+" d1="+d1);
   }
   void circulo(){
      if( bg != null ){  
         mensaje("No implementado");  
      }
   }
   void rectangulo(){
      double ancho = 0.2 , alto = 0.1 ;
      if(bg!=null){
         bg.addChild( cylinder.create(
           new Point3d(x, y, 0), 
           new Point3d(x+ancho, y, 0), /*cylRadius*/0.01f, branchApp));
         bg.addChild( cylinder.create(
           new Point3d(x, y, 0), 
           new Point3d(x, y+alto, 0), /*cylRadius*/0.01f, branchApp));
         bg.addChild( cylinder.create(
           new Point3d(x+ancho, y, 0), 
           new Point3d(x+ancho, y+alto, 0), /*cylRadius*/0.01f, branchApp));
         bg.addChild( cylinder.create(
           new Point3d(x, y+alto, 0), 
           new Point3d(x+ancho, y+alto, 0), /*cylRadius*/0.01f, branchApp));
      }
   }
   void draw(){      
      Simbolo s;
      Dibujable dibu;
               
      s=(Simbolo)pila.pop();
      System.out.println("draw ( "+s.nombre+" )");
      dibu=s.obtenDibu();
      if(bg!=null && dibu != null){
         System.out.println("draw DIBUJAR");
         dibu.dibujar(bg, cylinder, branchApp);
         pila.push(dibu);
      }
   }
   void filtro(){
      Simbolo s;
      Dibujable dibu;
      Imagen ima;
      System.err.println("FILTRO filtro");         
      s=(Simbolo)pila.pop();
      dibu=s.obtenDibu(); 
      System.out.println("draw ( "+s.nombre+" ) "+" dibu =  "+dibu);
      if(dibu != null){    
         System.out.println("if filtro");
         ima=(Imagen)dibu;
         //poste.set_Escala_de_Grises((BufferedImage)ima.ima);
         float[] kernel = new float[9];
         for (int i = 0; i < 9; i++) {
            kernel[i] = (float)(((Double)pila.pop()).doubleValue());
         }
         System.out.println("11 desp for filtro");
         poste.ponFiltro(new Kernel(3, 3, kernel));
      System.out.println("f ( "+ima+" ) "+" pict = "+ima.getPicture());
 System.out.println(
    "f ( "+ima+" ) "+" pict = "+ima.getPicture()+" image "+ima.getPicture().getImage());
         poste.procesa("User", (BufferedImage) ima.getPicture().getImage());
         //new Imagen(poste.getFoto()).dibuja(g) ;
         try {
           File outputfile = new File("saved.png");
           ImageIO.write(poste.getFoto(), "png", outputfile);
         } catch (IOException e) {
              System.out.println(e);
         }
         ima.getPicture().createSceneGraph(poste.getFoto());
         ima.dibujar(bg, cylinder, branchApp);
      }
      
      /*poste.set_Escala_de_Grises(leeImagen("Imagen.jpg"));
      System.err.println("antes dibujar ");
      new Imagen(poste.getFoto(), 100, 100, con).dibujar(g);*/        
   }
   void print(){
	Double d;
        Boolean b;
        Dibujable dibu;
        Object obj;
        Simbolo s;
        System.out.println("3d print()");
        obj=pila.pop();
	//d=(Double)pila.pop();
        if ( obj instanceof Simbolo){
           s=(Simbolo)obj;
	   System.out.println(""+s.val);
        }
        if ( obj instanceof Double ){
           d=(Double)obj;
	   System.out.println(""+d.doubleValue());
        }
        if ( obj instanceof Boolean ){
           b=(Boolean)obj;
	   System.out.println(""+b.booleanValue());
        }
        if ( obj instanceof Dibujable ){
           dibu=(Dibujable)obj;
           if(bg!=null && dibu != null){
              System.out.println("print DIBUJAR");
              dibu.dibujar(bg, cylinder, branchApp);
           }
        }
   }  
   void prexpr(){
	Double d;
        Boolean b;
        Dibujable dibu;
        Object obj;
        System.out.println("prexpr()");
        obj=pila.pop();
	//d=(Double)pila.pop(); descoment provocaba problema
        if ( obj instanceof Double ){
           d=(Double)obj;
           System.out.print("["+d.doubleValue()+"]");
        }
        if ( obj instanceof Boolean ){
           b=(Boolean)obj;
	   System.out.println(""+b.booleanValue());
        }
        if ( obj instanceof Dibujable ){
           dibu=(Dibujable)obj;
           if(bg!=null && dibu != null){
              System.out.println("print DIBUJAR");
              dibu.dibujar(bg, cylinder, branchApp);
           }
        }
   }
   public void mensaje(String mensaje) {
      Font myFont = new Font("TestFont",Font.PLAIN, 8 );
      Font3D myFont3D = new Font3D(myFont,new FontExtrusion());
      Text3D myText3D = new Text3D(myFont3D, mensaje);
      Shape3D myShape3D = new Shape3D(myText3D, branchApp);
      Transform3D myTransform3D = new Transform3D();
      myTransform3D.setTranslation(new Vector3f(0 , 0, -2.3f));
      BranchGroup contentBranchGroup = new BranchGroup();
      TransformGroup contentTransformGroup = new TransformGroup(myTransform3D);
      contentTransformGroup.addChild(myShape3D);
     
      contentBranchGroup.addChild(contentTransformGroup);
      bg.addChild(contentBranchGroup); 
   }
}
