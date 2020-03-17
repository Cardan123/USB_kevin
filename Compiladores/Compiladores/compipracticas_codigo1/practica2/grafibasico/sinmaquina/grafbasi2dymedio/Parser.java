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






//#line 1 "forma.y"

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
//#line 41 "Parser.java"




public class Parser
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
public final static short NUMBER=257;
public final static short LINE=258;
public final static short CIRCULO=259;
public final static short RECTANGULO=260;
public final static short COLOR=261;
public final static short PRINT=262;
public final static short IMAGEN=263;
public final static short FILTRO=264;
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,
};
final static short yylen[] = {                            2,
    0,    2,    3,    1,    1,    2,    1,    2,    3,   10,
};
final static short yydefred[] = {                         1,
    0,    4,    0,    7,    5,    0,    0,    0,    2,    0,
    6,    8,    0,    0,    3,    9,    0,    0,    0,    0,
    0,    0,    0,   10,
};
final static short yydgoto[] = {                          1,
   10,
};
final static short yysindex[] = {                         0,
  -59,    0, -256,    0,    0, -255, -254, -253,    0,  -54,
    0,    0, -251, -250,    0,    0, -249, -248, -247, -246,
 -245, -244, -243,    0,
};
final static short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
    0,
};
final static int YYTABLESIZE=205;
static short yytable[];
static { yytable();}
static void yytable(){
yytable = new short[]{                          9,
   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
   21,   22,   23,   24,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    2,    3,    4,
    5,    6,    0,    7,    8,
};
}
static short yycheck[];
static { yycheck(); }
static void yycheck() {
yycheck = new short[] {                         59,
  257,  257,  257,  257,   59,  257,  257,  257,  257,  257,
  257,  257,  257,  257,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,   -1,  263,  264,
};
}
final static short YYFINAL=1;
final static short YYMAXTOKEN=264;
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
null,null,null,null,"NUMBER","LINE","CIRCULO","RECTANGULO","COLOR","PRINT",
"IMAGEN","FILTRO",
};
final static String yyrule[] = {
"$accept : list",
"list :",
"list : list ';'",
"list : list inst ';'",
"inst : NUMBER",
"inst : RECTANGULO",
"inst : LINE NUMBER",
"inst : CIRCULO",
"inst : COLOR NUMBER",
"inst : IMAGEN NUMBER NUMBER",
"inst : FILTRO NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER",
};

//#line 77 "forma.y"

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
Filtradora poste;

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
Color3f skyColor = new Color3f(0.0f, 0.2f, 1f);  // (0, .6, .2)
Color3f groundColor = new Color3f(0.1f, .65f, 0.02f);


Parser(int foo){
   poste= new Filtradora( ); 
   tabla=new Tabla();
   tabla.install("line", LINE, 0.0);
   tabla.install("circulo", CIRCULO, 0.0);
   tabla.install("rectangulo", RECTANGULO, 0.0);
   tabla.install("color", COLOR, 0.0);
   tabla.install("print", PRINT, 0.0);
   tabla.install("ima", IMAGEN, 0.0);
   tabla.install("fil", FILTRO, 0.0);
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
   canv=new Canvas();
   canv.setSize(600,600);
   jf.add("North", new PanelEjecuta(this));
   jf.add("Center", canvas);
   jf.setSize( 600, 700);
   jf.setVisible(true);
   
   jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);  
}
public static void main(String args[]){ new Parser(); }
//#line 404 "Parser.java"
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
//#line 30 "forma.y"
{ 
            return 1 ;
     }
//break;
case 4:
//#line 34 "forma.y"
{
                }
break;
case 5:
//#line 36 "forma.y"
{ 
           (new Rectangulo(
          0.1, 0.1, 0.2, 0.1)).dibujar(scene, a1);
      }
break;
case 6:
//#line 40 "forma.y"
{        
          (new Linea(
          0.1, 0.1, 0.1+ ((Algo)val_peek(0).obj).simb.val*Math.cos(0), 
               0.1+ ((Algo)val_peek(0).obj).simb.val*Math.sin(0))).dibujar(scene, a1);
      }
break;
case 7:
//#line 45 "forma.y"
{ }
break;
case 8:
//#line 46 "forma.y"
{  }
break;
case 9:
//#line 47 "forma.y"
{
              ( new Imagen(new Picture("dalmata.jpg"), 
                (int)((Algo)val_peek(1).obj).simb.val, 
                (int)((Algo)val_peek(0).obj).simb.val) ).dibujar(scene, a1);
      }
break;
case 10:
//#line 53 "forma.y"
{  
      Imagen ima= new Imagen( new Picture("dalmata.jpg"), 1 , 1 );
      float[] kernel = new float[9];
      kernel[0] = (float)((Algo)val_peek(8).obj).simb.val;
      kernel[1] = (float)((Algo)val_peek(7).obj).simb.val;
      kernel[2] = (float)((Algo)val_peek(6).obj).simb.val;
      kernel[3] = (float)((Algo)val_peek(5).obj).simb.val;
      kernel[4] = (float)((Algo)val_peek(4).obj).simb.val;
      kernel[5] = (float)((Algo)val_peek(3).obj).simb.val;
      kernel[6] = (float)((Algo)val_peek(2).obj).simb.val;
      kernel[7] = (float)((Algo)val_peek(1).obj).simb.val;
      kernel[8] = (float)((Algo)val_peek(0).obj).simb.val;  
      poste.ponFiltro(new Kernel(3, 3, kernel));
      poste.procesa("User", (BufferedImage) ima.getPicture().getImage());
      try {
           File outputfile = new File("saved.png");
           ImageIO.write(poste.getFoto(), "png", outputfile);
      } catch (IOException e) {
              System.out.println(e);
      }
      ima.getPicture().createSceneGraph(poste.getFoto());
      ima.dibujar(scene, a1);
}
break;
//#line 621 "Parser.java"
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
