%{
import java.lang.Math;
import java.io.*;
import java.util.StringTokenizer;
import java.awt.*;
import java.awt.event.*;
import javax.imageio.*;
import java.awt.image.*;
import javax.swing.*;

import com.sun.j3d.utils.geometry.Box;
import com.sun.j3d.utils.geometry.Sphere;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.behaviors.mouse.MouseRotate;
import com.sun.j3d.utils.behaviors.mouse.MouseTranslate;
import com.sun.j3d.utils.behaviors.mouse.MouseZoom;

import com.sun.j3d.utils.universe.SimpleUniverse;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.image.TextureLoader;
import com.sun.j3d.utils.universe.*;
import javax.media.j3d.*;
import javax.vecmath.*;
%}
%token NUMBER LINE CIRCULO RECTANGULO COLOR PRINT IMAGEN FILTRO
%start list
%%
list :
     | list ';'
     | list inst ';'   { 
             maq.code("print"); maq.code("STOP"); return 1 ;
     }   
     ;
inst:  NUMBER  { ((Algo)$$.obj).inst=maq.code("constpush");
                maq.code(((Algo)$1.obj).simb); }
      | RECTANGULO   { maq.code("rectangulo"); }
      | LINE NUMBER  { maq.code("constpush");
                maq.code(((Algo)$2.obj).simb); maq.code("line"); }
      | CIRCULO { maq.code("circulo"); }
      | COLOR NUMBER { maq.code("constpush");
                maq.code(((Algo)$2.obj).simb); maq.code("color"); }
      | IMAGEN NUMBER NUMBER {
              Simbolo s=new Simbolo();
              s.ponDibu( new Imagen(new Picture("dalmata.jpg"), 
                (int)((Algo)$2.obj).simb.val, 
                (int)((Algo)$3.obj).simb.val) );
              maq.code("varpush");
              maq.code(s);  
              maq.code("draw");      
      }
      | FILTRO NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER 
        NUMBER NUMBER NUMBER  {  
                      maq.code("constpush");
                      maq.code(((Algo)$2.obj).simb);
                      maq.code("constpush");
                      maq.code(((Algo)$3.obj).simb);
                      maq.code("constpush");
                      maq.code(((Algo)$4.obj).simb);
                      maq.code("constpush");
                      maq.code(((Algo)$5.obj).simb);
                      maq.code("constpush");
                      maq.code(((Algo)$6.obj).simb);
                      maq.code("constpush");
                      maq.code(((Algo)$7.obj).simb);
                      maq.code("constpush");
                      maq.code(((Algo)$8.obj).simb);
                      maq.code("constpush");
                      maq.code(((Algo)$9.obj).simb);
                      maq.code("constpush");
                      maq.code(((Algo)$10.obj).simb);
                     
                      Simbolo s=new Simbolo();
                      s.ponDibu( new Imagen( new Picture("dalmata.jpg"), 1 , 1 ) );
                      maq.code("varpush");
                      maq.code(s);  
                      maq.code("filtro");
}
      ;
%%
public BufferedImage leeImagen(String nombre){
   BufferedImage imagen;
   try {
      imagen = ImageIO.read(new File(nombre));     
   } catch (IOException e){
        System.err.println("no cargo "+nombre);
        return null;
   }
   return imagen;
   }
class Algo {
	Simbolo simb;
	int inst;
        Dibujable dibu;
	public Algo(int i){ inst=i; }
        public Algo(Dibujable d){ dibu=d; }
	public Algo(Simbolo s, int i){
		simb=s; inst=i;
	}
}

TextureLoader tex;
protected Transform3D viewTransform = new Transform3D();
protected Vector3f viewVector;
protected ViewingPlatform vp = null;
protected TransformGroup viewTG = null;
BoundingSphere bounds = new BoundingSphere(new Point3d(0.0, 0.0, 0.0),
      100.0);

public void setTokenizer(StringTokenizer st){
 	this.st= st;
}
public void setNewline(boolean newline){
 	this.newline= newline;
}
BranchGroup scene;
Appearance a1, appext, appiso;

private SimpleUniverse u = null;
Tabla tabla;
Maquina maq;

StringTokenizer st;
boolean newline;
int yylex(){
String s;
int tok;
Double d;
Simbolo simbo;
   if (!st.hasMoreTokens())
      if (!newline) {
         newline=true; 
	 return ';';  
      }
   else
      return 0;
   s = st.nextToken();
   try {
      d = Double.valueOf(s);
      yylval = new ParserVal(
             new Algo(tabla.install("", NUMBER, d.doubleValue()),0) );
      tok = NUMBER;
   } catch (Exception e){
   if(Character.isLetter(s.charAt(0))){
      System.out.println("s es = ("+s+")");
      if((simbo=tabla.lookup(s))==null)
         yylval = new ParserVal(new Algo(simbo, 0));
	 tok= simbo.tipo;	
      } else {
    	tok = s.charAt(0);
      }
   }
   return tok;
}
void yyerror(String s){
   System.out.println("parser error: "+s);
}
static Parser par = new Parser(0);
static JFrame jf;
static JLabel lmuestra=new JLabel("                                 ");
static Canvas canv;
static Graphics g;
CylinderCreator cylinder = new CylinderCreator();
Color3f skyColor = new Color3f(0.0f, 0.2f, 1f);  // (0, .6, .2)
Color3f groundColor = new Color3f(0.1f, .65f, 0.02f);


Parser(int foo){
   maq=new Maquina();
   tabla=new Tabla();
   tabla.install("line", LINE, 0.0);
   tabla.install("circulo", CIRCULO, 0.0);
   tabla.install("rectangulo", RECTANGULO, 0.0);
   tabla.install("color", COLOR, 0.0);
   tabla.install("print", PRINT, 0.0);
   tabla.install("ima", IMAGEN, 0.0);
   tabla.install("fil", FILTRO, 0.0);
   maq.setTabla(tabla);
   scene = new BranchGroup();
        
   scene.setCapability(BranchGroup.ALLOW_CHILDREN_EXTEND);
   scene.setCapability(BranchGroup.ALLOW_CHILDREN_WRITE);
	     
   appext = new Appearance();
   tex=new TextureLoader("exterior.png", null);
   appext.setTexture(tex.getTexture());
   appiso = new Appearance();
   tex=new TextureLoader("cielo.jpg", null);
   appiso.setTexture(tex.getTexture());
   a1 = new Appearance();
   Color3f eColor = new Color3f(0.0f, 0.0f, 0.0f);
   Color3f sColor = new Color3f(0.5f, 0.5f, 1.0f);
   Color3f oColor = new Color3f(0.5f, 0.5f, 0.3f);

   Material m = new Material(oColor, eColor, oColor, sColor, 100.0f);
   m.setLightingEnable(true);
   a1.setMaterial(m);
   TextureLoader myLoader = new TextureLoader( "fondo.jpg", null );
   ImageComponent2D myImage = myLoader.getImage( );
   Background myBack = new Background(skyColor );
   //myBack.setImage( myImage );
   myBack.setApplicationBounds(bounds);
   scene.addChild(myBack);
TransformGroup earthRotX;
TransformGroup earthTransX;

Sphere earth = new Sphere(0.5f, Primitive.GENERATE_NORMALS | 		
	Primitive.GENERATE_TEXTURE_COORDS, 32, appiso);

cylinder.setResolution(3);
earthRotX = Posi.rotate( cylinder.create(
       new Point3d((int)0, (int)0, 0), 
           new Point3d((int)3, (int)3, 0), (int)1, appiso), new Alpha(-1, 1250));	
earthTransX = Posi.translate(earthRotX, new Vector3f(0.0f, 3.5f, 9.0f));
TransformGroup earthRotGroupX = Posi.rotate(earthTransX, new Alpha(-1, 50000));
    scene.addChild(earthRotGroupX);
   
    GraphicsConfiguration config = SimpleUniverse.getPreferredConfiguration();
    Canvas3D canvas = new Canvas3D(config); 
    canvas.setSize(750, 750);
    u = new SimpleUniverse(canvas);
    
    u.getViewingPlatform().setNominalViewingTransform();
    vp = u.getViewingPlatform();
    viewTG = vp.getViewPlatformTransform();

    MouseRotate behavior1 = new MouseRotate(viewTG);
    scene.addChild(behavior1);
    behavior1.setSchedulingBounds(bounds);

    MouseZoom behavior2 = new MouseZoom(viewTG);
    scene.addChild(behavior2);
    behavior2.setSchedulingBounds(bounds);

    MouseTranslate behavior3 = new MouseTranslate(viewTG);
    scene.addChild(behavior3);
    behavior3.setSchedulingBounds(bounds);
   
    PointLight light1 = new PointLight();
    light1.setPosition(new Point3f(70, 20, -50));
    light1.setColor(new Color3f(1.0f, 1.0f, 1.0f));
    light1.setInfluencingBounds(bounds);
    scene.addChild(light1);

    AmbientLight ambient1 = new AmbientLight(true, new Color3f(1f, 1f, 1f));
    ambient1.setInfluencingBounds(bounds);
    scene.addChild(ambient1);

   jf=new JFrame("Calcula");
   scene.compile();
   u.addBranchGraph(scene);
   maq.setBranchGroup(scene);
   canv=new Canvas();
   canv.setSize(600,600);
   jf.add("North", new PanelEjecuta(maq, this));
   jf.add("Center", canvas);
   jf.setSize( 600, 700);
   jf.setVisible(true);
   g=canv.getGraphics();
   maq.setGraphics(g);
   
   jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);  
}
public static void main(String args[]){ new Parser(); }
