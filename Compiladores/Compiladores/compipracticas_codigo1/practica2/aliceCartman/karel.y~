%{
import java.lang.Math;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;
import javax.swing.*;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.image.TextureLoader;
import com.sun.j3d.utils.universe.*;
import javax.media.j3d.*;
import javax.vecmath.*;
import com.sun.j3d.loaders.*;
import com.glyphein.j3d.loaders.milkshape.MS3DLoader;

import java.util.*;
%}
%token NUMBER PRINT FORWARD RIGHT 
%start list
%%
list :
     | list ';'
     | list inst ';'   { 
             maq.code("print"); maq.code("STOP"); return 1 ;
     }   
     ;
inst: NUMBER  { ((Algo)$$.obj).inst=maq.code("constpush");
                maq.code(((Algo)$1.obj).simb); }
    | FORWARD NUMBER  { maq.code("constpush");
                maq.code(((Algo)$2.obj).simb); maq.code("forward");}
    | RIGHT NUMBER  {  maq.code("constpush");
                maq.code(((Algo)$2.obj).simb); maq.code("right");}
    ;
%%
//byaccj -J karel.y
//javac -cp :MS3DLoader.jar:portfolio.jar  Parser.java
//java  -cp .:MS3DLoader.jar Parser
class Algo {
	Simbolo simb;
	int inst;
	public Algo(int i){ inst=i; }
	public Algo(Simbolo s, int i){
		simb=s;
                inst=i;
	}
}
private int mapa[][];
        private TransformGroup tgDesplazamiento=new TransformGroup();
	private JComboBox jcb;	
        private Modelo mod;
   	TextureLoader tex;
        Texture texture;
	JFrame frame;
        JTextArea cmd;
        TransformGroup viewerTG;
Cartman body;       
Tabla tabla;
Maquina maq;

StringTokenizer st;
boolean newline;
private String etiqs[]={"Ejecuta"};
private Paleta pal;
int yylex(){
String s;
int tok;
Double d;
Simbolo simbo;
  if (!st.hasMoreTokens())
    if (!newline){
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
   } catch (Exception e) {
      if(Character.isLetter(s.charAt(0))){
	 if((simbo=tabla.lookup(s))!=null){
             yylval = new ParserVal(new Algo(simbo, 0));
	     tok= simbo.tipo;	
         } else { tok = s.charAt(0); }
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
static Frame f;
static Label lmuestra=new Label("                                 ");
static Canvas canv;
static Graphics g;
Canvas3D canvasPerspectiva;
public static void main(String a[]) { new Parser();}
public Modelo getModelo(){
        if (mod==null){
            int noPisar[]={1/*,6,7,8,9<*/};
            mod=new Modelo(mapa,2,7, 270, noPisar);
        }
        return mod;
    }
public Parser(int foo){
        maq=new Maquina(g);
	tabla=new Tabla();

	tabla.install("forward", FORWARD, 0.0);
	tabla.install("right", RIGHT, 0.0);
	tabla.install("print", PRINT, 0.0);	
        this.mapa=getMatriz();
	this.mod=getModelo();
        tgDesplazamiento.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
	BranchGroup group = new BranchGroup();
	Appearance appsol = new Appearance();
        
	tex=new TextureLoader("puerta1.jpg", null);
	appsol.setTexture(tex.getTexture());
Sphere sol = new Sphere(0.35f, Primitive.GENERATE_NORMALS | Primitive.GENERATE_TEXTURE_COORDS, 32, appsol);
TransformGroup solRotXformGroup = Gira.rotate(sol, new Alpha(-1, 5000));
TransformGroup solTransX = Posi.translate(solRotXformGroup, 
        new Vector3f(2.0f, 0.0f, 6.0f));
	//tgDesplazamiento.addChild(solTransX);
        
    GraphicsConfiguration config = SimpleUniverse.getPreferredConfiguration();
    Canvas3D canvasPerspectiva = new Canvas3D(config);
    
    SimpleUniverse universe = new SimpleUniverse(canvasPerspectiva);

    universe.getViewingPlatform().setNominalViewingTransform();

    ViewingPlatform vp = universe.getViewingPlatform();
    viewerTG = vp.getViewPlatformTransform();

    JFrame f = new JFrame("Planetario");
    frame=f; 
    f.add("West", creaCmdPanel()); 
    Color3f light1Color = new Color3f(0.5F, 0.5F, 0.5F);

    BoundingSphere bounds1 =
new BoundingSphere(new Point3d(0.0, 0.0, 0.0), 100.0);
    AmbientLight ambientlight = new AmbientLight(new Color3f(0.9F, 0.9F, 0.9F));
    ambientlight.setInfluencingBounds(bounds1);
    Vector3f light1Direction = new Vector3f(4.0f, -7.0f, -12.0f);
    DirectionalLight light1 = new DirectionalLight(light1Color, light1Direction);
    light1.setInfluencingBounds(bounds1);
    group.addChild(light1);
    group.addChild(ambientlight);
        //tgDesplazamiento.addChild(directionallight);
    group.addChild(getCasa(f));
    
    universe.addBranchGraph(group);
    f.setLocation(300,0);
    f.setSize(600,600);
    canvasPerspectiva.setBounds(0,0,f.getWidth(), f.getHeight());
    update(null,null);
    
    f.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);  
    //f.setLayout(new BorderLayout());
    f.add("Center", canvasPerspectiva); 
    f.setVisible(true);
}
JPanel creaCmdPanel(){	
        JPanel p=new JPanel();
        p.setLayout(new GridLayout(2,1));
	cmd = new JTextArea(15,20);  // was 15,50   
        JScrollPane qScroller = new JScrollPane(cmd);
	p.add(qScroller);
        pal=new Paleta(etiqs,new GridLayout(1, etiqs.length), new ManejaAccionInt()); 
	p.add(pal);
	return p;
}
public javax.media.j3d.BranchGroup getCasa(java.awt.Component observer){
        cargarTexturas(observer);
        BranchGroup bg=new BranchGroup();
        bg.addChild(tgDesplazamiento);

        TransformGroup tPrincipal=new TransformGroup();
        Transform3D t3d;
        TransformGroup tg;
        int tipo;
        //Pone el suelo
      
        tgDesplazamiento.addChild(new objetos3D.Suelo(Texturas.getObjeto().getApariencia("Suelo"),
                                    mapa.length,
                                    mapa[0].length).getTransformGroup());
        tgDesplazamiento.addChild(new objetos3D.Techo(Texturas.getObjeto().getApariencia("Techo"),
                                    mapa.length,
                                    mapa[0].length).getTransformGroup());
        
        objetos3D.Puerta p;

        for (int n=0;n<mapa.length;n++){
            for (int m=0;m<mapa[0].length;m++){
                switch(mapa[n][m]) {
                    case 1:
                        tgDesplazamiento.addChild((new objetos3D.Pared(Texturas.getObjeto().getApariencia("Pared"),
                                                            n,m)).getTransformGroup());
                        break;
		     case 2:
                        body= new Cartman(0f,0f,0f);
			TransformGroup cartTransX = Posi.escatrans(
                        body.mybody(), new Vector3f(2.0f, -0.5f, 5.0f),
                       	new Vector3d(0.4f, 0.4f, 0.4f));
                       	tgDesplazamiento.addChild(cartTransX);
   			maq.setBody(body);
			break;
                                                                                             
                }
            }
        }
        return bg;
    }
public void cargarTexturas(java.awt.Component observer){
        Texturas.getObjeto().cargaTextura("pared1.jpg","Pared",observer);
        Texturas.getObjeto().cargaTextura("suelo1.jpg","Suelo",observer);
        Texturas.getObjeto().cargaTextura("puerta1.jpg","Puerta",observer);
        Texturas.getObjeto().cargaTextura("marco1.jpg","Marco",observer);
        Texturas.getObjeto().cargaTextura("techo1.jpg","Techo",observer);
        Texturas.getObjeto().cargaTextura("muebles.jpg","Muebles",observer);
        Texturas.getObjeto().cargaTextura("sabana.jpg","Sabana",observer);
        Texturas.getObjeto().cargaTextura("almohada.jpg","Almohada",observer);
        Texturas.getObjeto().cargaTextura("canal.jpg","Canal",observer);
    }
public int[][] getMatriz(){ 
int m[][]= {{1,1,1,1,1,1,1,1},
		//{1,0,0,0,0,0,0,1},
                    {1,7,0,0,0,0,9,1},
                    {1,0,0,0,0,9,2,1},
                    {1,0,0,0,0,0,0,1},
                    {1,3,1,1,1,1,1,1},
                   };          
        return m;
    }
public void update(java.util.Observable observable, java.lang.Object obj) {
        Transform3D t=new Transform3D();
        Transform3D t2=new Transform3D();
        Transform3D t3=new Transform3D();
        t.set(new Vector3d(0,0,2));
        t2.rotY(mod.getAnguloRadianes()+Math.PI/2);
        t3.set(new Vector3d(-mod.getX(),0, -mod.getY()));
        t2.mul(t3);
        t.mul(t2);
        tgDesplazamiento.setTransform(t);
        //casa.automatismo(x/100.0f, z/100.0f);
}
class ManejaAccionInt implements AccionInt {
	public void accion(int n){ 
	if(n==0){ 
		st = new StringTokenizer(cmd.getText());
    		newline=false;
		for(maq.initcode(); par.yyparse ()!=0; maq.initcode())
			maq.execute(maq.progbase);
        }  
     }
}
