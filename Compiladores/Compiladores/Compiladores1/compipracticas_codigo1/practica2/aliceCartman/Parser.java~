//### This file created by BYACC 1.8(/Java extension  1.15)
//### Java capabilities added 7 Jan 97, Bob Jamison
//### Updated : 27 Nov 97  -- Bob Jamison, Joe Nieten
//###           01 Jan 98  -- Bob Jamison -- fixed generic semantic constructor
//###           01 Jun 99  -- Bob Jamison -- added Runnable support
//###           06 Aug 00  -- Bob Jamison -- made state variables class-global
//###           03 Jan 01  -- Bob Jamison -- improved flags, tracing
//###           16 May 01  -- Bob Jamison -- added custom stack sizing
//###           04 Mar 02  -- Yuval Oren  -- improved java performance, added options
//###           14 Mar 02  -- Tomas Hurka -- -d support, static initializer workaround
//### Please send bug reports to tom@hukatronic.cz
//### static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";






//#line 1 "karel.y"

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
//#line 34 "Parser.java"




public class Parser
             implements ParserTokens
{

boolean yydebug;        //do I want debug output?
int yynerrs;            //number of errors so far
int yyerrflag;          //was there an error?
int yychar;             //the current working character

//########## MESSAGES ##########
//###############################################################
// method: debug
//###############################################################
void debug(String msg)
{
  if (yydebug)
    System.out.println(msg);
}

//########## STATE STACK ##########
final static int YYSTACKSIZE = 500;  //maximum stack size
int statestk[] = new int[YYSTACKSIZE]; //state stack
int stateptr;
int stateptrmax;                     //highest index of stackptr
int statemax;                        //state when highest index reached
//###############################################################
// methods: state stack push,pop,drop,peek
//###############################################################
final void state_push(int state)
{
  try {
		stateptr++;
		statestk[stateptr]=state;
	 }
	 catch (ArrayIndexOutOfBoundsException e) {
     int oldsize = statestk.length;
     int newsize = oldsize * 2;
     int[] newstack = new int[newsize];
     System.arraycopy(statestk,0,newstack,0,oldsize);
     statestk = newstack;
     statestk[stateptr]=state;
  }
}
final int state_pop()
{
  return statestk[stateptr--];
}
final void state_drop(int cnt)
{
  stateptr -= cnt; 
}
final int state_peek(int relative)
{
  return statestk[stateptr-relative];
}
//###############################################################
// method: init_stacks : allocate and prepare stacks
//###############################################################
final boolean init_stacks()
{
  stateptr = -1;
  val_init();
  return true;
}
//###############################################################
// method: dump_stacks : show n levels of the stacks
//###############################################################
void dump_stacks(int count)
{
int i;
  System.out.println("=index==state====value=     s:"+stateptr+"  v:"+valptr);
  for (i=0;i<count;i++)
    System.out.println(" "+i+"    "+statestk[i]+"      "+valstk[i]);
  System.out.println("======================");
}


//########## SEMANTIC VALUES ##########
//public class ParserVal is defined in ParserVal.java


String   yytext;//user variable to return contextual strings
ParserVal yyval; //used to return semantic vals from action routines
ParserVal yylval;//the 'lval' (result) I got from yylex()
ParserVal valstk[];
int valptr;
//###############################################################
// methods: value stack push,pop,drop,peek.
//###############################################################
void val_init()
{
  valstk=new ParserVal[YYSTACKSIZE];
  yyval=new ParserVal();
  yylval=new ParserVal();
  valptr=-1;
}
void val_push(ParserVal val)
{
  if (valptr>=YYSTACKSIZE)
    return;
  valstk[++valptr]=val;
}
ParserVal val_pop()
{
  if (valptr<0)
    return new ParserVal();
  return valstk[valptr--];
}
void val_drop(int cnt)
{
int ptr;
  ptr=valptr-cnt;
  if (ptr<0)
    return;
  valptr = ptr;
}
ParserVal val_peek(int relative)
{
int ptr;
  ptr=valptr-relative;
  if (ptr<0)
    return new ParserVal();
  return valstk[ptr];
}
final ParserVal dup_yyval(ParserVal val)
{
  ParserVal dup = new ParserVal();
  dup.ival = val.ival;
  dup.dval = val.dval;
  dup.sval = val.sval;
  dup.obj = val.obj;
  return dup;
}
//#### end semantic value section ####
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,
};
final static short yylen[] = {                            2,
    0,    2,    3,    1,    2,    2,
};
final static short yydefred[] = {                         1,
    0,    4,    0,    0,    2,    0,    5,    6,    3,
};
final static short yydgoto[] = {                          1,
    6,
};
final static short yysindex[] = {                         0,
  -59,    0, -256, -255,    0,  -56,    0,    0,    0,
};
final static short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
    0,
};
final static int YYTABLESIZE=201;
static short yytable[];
static { yytable();}
static void yytable(){
yytable = new short[]{                          5,
    7,    8,    9,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    2,    0,    3,
    4,
};
}
static short yycheck[];
static { yycheck(); }
static void yycheck() {
yycheck = new short[] {                         59,
  257,  257,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,  259,
  260,
};
}
final static short YYFINAL=1;
final static short YYMAXTOKEN=260;
final static String yyname[] = {
"end-of-file",null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,"';'",null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,"NUMBER","PRINT","FORWARD","RIGHT",
};
final static String yyrule[] = {
"$accept : list",
"list :",
"list : list ';'",
"list : list inst ';'",
"inst : NUMBER",
"inst : FORWARD NUMBER",
"inst : RIGHT NUMBER",
};

//#line 34 "karel.y"

//byaccj -J karel.y
//javac  -cp .:MS3DLoader.jar Parser.java
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
//#line 446 "Parser.java"
//###############################################################
// method: yylexdebug : check lexer state
//###############################################################
void yylexdebug(int state,int ch)
{
String s=null;
  if (ch < 0) ch=0;
  if (ch <= YYMAXTOKEN) //check index bounds
     s = yyname[ch];    //now get it
  if (s==null)
    s = "illegal-symbol";
  debug("state "+state+", reading "+ch+" ("+s+")");
}





//The following are now global, to aid in error reporting
int yyn;       //next next thing to do
int yym;       //
int yystate;   //current parsing state from state table
String yys;    //current token string


//###############################################################
// method: yyparse : parse input and execute indicated items
//###############################################################
int yyparse()
{
boolean doaction;
  init_stacks();
  yynerrs = 0;
  yyerrflag = 0;
  yychar = -1;          //impossible char forces a read
  yystate=0;            //initial state
  state_push(yystate);  //save it
  val_push(yylval);     //save empty value
  while (true) //until parsing is done, either correctly, or w/error
    {
    doaction=true;
    if (yydebug) debug("loop"); 
    //#### NEXT ACTION (from reduction table)
    for (yyn=yydefred[yystate];yyn==0;yyn=yydefred[yystate])
      {
      if (yydebug) debug("yyn:"+yyn+"  state:"+yystate+"  yychar:"+yychar);
      if (yychar < 0)      //we want a char?
        {
        yychar = yylex();  //get next token
        if (yydebug) debug(" next yychar:"+yychar);
        //#### ERROR CHECK ####
        if (yychar < 0)    //it it didn't work/error
          {
          yychar = 0;      //change it to default string (no -1!)
          if (yydebug)
            yylexdebug(yystate,yychar);
          }
        }//yychar<0
      yyn = yysindex[yystate];  //get amount to shift by (shift index)
      if ((yyn != 0) && (yyn += yychar) >= 0 &&
          yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
        {
        if (yydebug)
          debug("state "+yystate+", shifting to state "+yytable[yyn]);
        //#### NEXT STATE ####
        yystate = yytable[yyn];//we are in a new state
        state_push(yystate);   //save it
        val_push(yylval);      //push our lval as the input for next rule
        yychar = -1;           //since we have 'eaten' a token, say we need another
        if (yyerrflag > 0)     //have we recovered an error?
           --yyerrflag;        //give ourselves credit
        doaction=false;        //but don't process yet
        break;   //quit the yyn=0 loop
        }

    yyn = yyrindex[yystate];  //reduce
    if ((yyn !=0 ) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
      {   //we reduced!
      if (yydebug) debug("reduce");
      yyn = yytable[yyn];
      doaction=true; //get ready to execute
      break;         //drop down to actions
      }
    else //ERROR RECOVERY
      {
      if (yyerrflag==0)
        {
        yyerror("syntax error");
        yynerrs++;
        }
      if (yyerrflag < 3) //low error count?
        {
        yyerrflag = 3;
        while (true)   //do until break
          {
          if (stateptr<0)   //check for under & overflow here
            {
            yyerror("stack underflow. aborting...");  //note lower case 's'
            return 1;
            }
          yyn = yysindex[state_peek(0)];
          if ((yyn != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
            if (yydebug)
              debug("state "+state_peek(0)+", error recovery shifting to state "+yytable[yyn]+" ");
            yystate = yytable[yyn];
            state_push(yystate);
            val_push(yylval);
            doaction=false;
            break;
            }
          else
            {
            if (yydebug)
              debug("error recovery discarding state "+state_peek(0)+" ");
            if (stateptr<0)   //check for under & overflow here
              {
              yyerror("Stack underflow. aborting...");  //capital 'S'
              return 1;
              }
            state_pop();
            val_pop();
            }
          }
        }
      else            //discard this token
        {
        if (yychar == 0)
          return 1; //yyabort
        if (yydebug)
          {
          yys = null;
          if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
          if (yys == null) yys = "illegal-symbol";
          debug("state "+yystate+", error recovery discards token "+yychar+" ("+yys+")");
          }
        yychar = -1;  //read another
        }
      }//end error recovery
    }//yyn=0 loop
    if (!doaction)   //any reason not to proceed?
      continue;      //skip action
    yym = yylen[yyn];          //get count of terminals on rhs
    if (yydebug)
      debug("state "+yystate+", reducing "+yym+" by rule "+yyn+" ("+yyrule[yyn]+")");
    if (yym>0)                 //if count of rhs not 'nil'
      yyval = val_peek(yym-1); //get current semantic value
    yyval = dup_yyval(yyval); //duplicate yyval if ParserVal is used as semantic value
    switch(yyn)
      {
//########## USER-SUPPLIED ACTIONS ##########
case 3:
//#line 23 "karel.y"
{ 
             maq.code("print"); maq.code("STOP"); return 1 ;
     }
//break;
case 4:
//#line 27 "karel.y"
{ ((Algo)yyval.obj).inst=maq.code("constpush");
                maq.code(((Algo)val_peek(0).obj).simb); }
break;
case 5:
//#line 29 "karel.y"
{ maq.code("constpush");
                maq.code(((Algo)val_peek(0).obj).simb); maq.code("forward");}
break;
case 6:
//#line 31 "karel.y"
{  maq.code("constpush");
                maq.code(((Algo)val_peek(0).obj).simb); maq.code("right");}
break;
//#line 616 "Parser.java"
//########## END OF USER-SUPPLIED ACTIONS ##########
    }//switch
    //#### Now let's reduce... ####
    if (yydebug) debug("reduce");
    state_drop(yym);             //we just reduced yylen states
    yystate = state_peek(0);     //get new state
    val_drop(yym);               //corresponding value drop
    yym = yylhs[yyn];            //select next TERMINAL(on lhs)
    if (yystate == 0 && yym == 0)//done? 'rest' state and at first TERMINAL
      {
      if (yydebug) debug("After reduction, shifting from state 0 to state "+YYFINAL+"");
      yystate = YYFINAL;         //explicitly say we're done
      state_push(YYFINAL);       //and save it
      val_push(yyval);           //also save the semantic value of parsing
      if (yychar < 0)            //we want another character?
        {
        yychar = yylex();        //get next character
        if (yychar<0) yychar=0;  //clean, if necessary
        if (yydebug)
          yylexdebug(yystate,yychar);
        }
      if (yychar == 0)          //Good exit (if lex returns 0 ;-)
         break;                 //quit the loop--all DONE
      }//if yystate
    else                        //else not done yet
      {                         //get next state and push, for next yydefred[]
      yyn = yygindex[yym];      //find out where to go
      if ((yyn != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn]; //get new state
      else
        yystate = yydgoto[yym]; //else go to new defred
      if (yydebug) debug("after reduction, shifting from state "+state_peek(0)+" to state "+yystate+"");
      state_push(yystate);     //going again, so push state & val...
      val_push(yyval);         //for next action
      }
    }//main loop
  return 0;//yyaccept!!
}
//## end of method parse() ######################################



//## run() --- for Thread #######################################
/**
 * A default run method, used for operating this parser
 * object in the background.  It is intended for extending Thread
 * or implementing Runnable.  Turn off with -Jnorun .
 */
public void run()
{
  yyparse();
}
//## end of method run() ########################################



//## Constructors ###############################################
/**
 * Default constructor.  Turn off with -Jnoconstruct .

 */
public Parser()
{
  //nothing to do
}


/**
 * Create a parser, setting the debug to true or false.
 * @param debugMe true for debugging, false for no debug.
 */
public Parser(boolean debugMe)
{
  yydebug=debugMe;
}
//###############################################################



}
//################### END OF CLASS ##############################
