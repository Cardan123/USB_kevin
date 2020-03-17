package modelo.compilador;
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






//#line 2 "Gramatica.y"
	import java.lang.Math;
	import java.io.*;
	import java.util.StringTokenizer;
	import modelo.Configuracion;
//#line 22 "Parser.java"




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
public final static short IF=257;
public final static short ELSE=258;
public final static short WHILE=259;
public final static short FOR=260;
public final static short COMP=261;
public final static short DIFERENTES=262;
public final static short MAYOR=263;
public final static short MENOR=264;
public final static short MAYORI=265;
public final static short MENORI=266;
public final static short FNCT=267;
public final static short NUMBER=268;
public final static short VAR=269;
public final static short AND=270;
public final static short OR=271;
public final static short FUNC=272;
public final static short RETURN=273;
public final static short PARAMETRO=274;
public final static short PROC=275;
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    5,    5,    5,    6,    3,
    3,    3,    3,    3,    3,    3,   14,   13,   12,    4,
   15,    8,    7,    9,   10,   11,   11,   11,
};
final static short yylen[] = {                            2,
    0,    2,    3,    2,    1,    3,    2,    1,    2,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    2,    1,    4,    0,    1,    3,    0,   14,
   11,   10,   16,    7,    7,    5,    1,    1,    1,    1,
    0,    0,    1,    1,    1,    0,    1,    3,
};
final static short yydefred[] = {                         1,
    0,   43,   44,   45,   37,   10,    0,   39,    0,   24,
   38,    0,    0,    2,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,    0,    0,   23,    0,   22,    0,
    3,    0,    7,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    4,    0,    0,    0,    0,   40,    0,    0,
    0,    0,   15,    6,    0,    0,    0,    0,    0,   19,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   25,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   36,    0,
    0,    0,    0,    0,    0,    0,    0,   34,   35,    0,
    0,    0,    0,   42,    0,    0,   42,   32,    0,    0,
   31,    0,    0,    0,    0,    0,   30,    0,   42,   33,
};
final static short yydgoto[] = {                          1,
   16,   17,   18,   19,   65,  107,   20,   75,   21,   22,
   69,   23,   24,   25,    0,
};
final static short yysindex[] = {                         0,
    9,    0,    0,    0,    0,    0,  -59,    0,  -13,    0,
    0,  -13,  -13,    0,  -13,   28,  105,    0,  -26,  -22,
  -16,  -12, -258, -258,  -57,  -13,    0,  124,    0,   87,
    0,  111,    0,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
  -13,  -13,    0,  -13,  -13,  -13,  -13,    0,    5,   16,
  -13,  118,    0,    0,    8,  -81,  -97, -225, -185,    0,
  124,  124,  -55,  118,   -8,  118,  118,  118,   13,   19,
   22,  -35,    0,  -13,   31,   35,  -13,   23,  -39,  -33,
   32,  118,  -21,  -20,  118,  -13,   66,   66,    0,   66,
   66,  118,  -32,   47,   66,   66,   50,    0,    0,  -37,
   -7,  -13, -148,    0,   13,  -11,    0,    0,   72,   66,
    0,   -3,   66,   66,   14,   66,    0,   21,    0,    0,
};
final static short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,   81,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   26,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    2,    0,    0,  -28,    0,    0,    0,
  -34,  -15,    0,    0,  146,  -38,  136,   93,  100,    0,
  174,  404,  155,  -29,    0,   92,   92,  -19,   90,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    7,    0,    0,   57,    0,    0,    0,    0,    0,
    0,   90,    0,    0,   30,   30,    0,    0,    0,    0,
    0,    6,  -10,    0,   92,    0,    0,    0,    0,    0,
    0,    0,   30,    0,    0,   30,    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
   17,  393,    1,   29,  106,    0,    0,  -30,    0,    0,
   49,    0,    0,    0,    0,
};
final static int YYTABLESIZE=509;
static short yytable[];
static { yytable();}
static void yytable(){
yytable = new short[]{                         29,
   13,   26,   17,   17,   17,   17,   17,   15,   74,   26,
   48,   27,   12,   44,   27,   46,   33,   45,   14,   13,
   17,   47,   29,   46,   47,   11,   15,   47,   11,   29,
   46,   12,   73,   51,   29,   74,   76,   31,   78,   47,
   39,   13,   26,   11,   70,   26,   46,   28,   15,   46,
   28,   49,   50,   12,   17,   71,   77,   81,   26,   79,
   13,   97,   80,   27,  100,  101,    9,   15,    9,    9,
    9,   83,   12,  108,  109,   84,  111,   11,   37,   13,
   39,   86,  115,   87,    9,  118,   15,  103,  120,   88,
   89,   12,   98,   33,   33,   33,   33,   48,   13,   28,
   48,   90,   91,   93,   94,   15,   95,   96,  102,  106,
   12,  110,  112,   33,   29,   48,   33,  104,    9,  114,
   40,    8,    8,    8,    8,    8,  113,   53,   42,   40,
  116,   41,   42,   18,   18,   18,   18,   18,  117,    8,
   21,   21,   21,   21,   21,  119,   42,   40,   42,   41,
  105,   18,   42,   40,   42,   41,   72,    0,   21,   42,
   40,    0,   41,   43,    0,   42,   37,   38,   39,   54,
    0,   99,    0,    8,    0,    0,   20,   20,   20,   20,
   20,   36,   37,   38,   39,   18,   16,   16,   16,   16,
   16,    0,   21,    0,   20,   12,   12,   12,   12,   12,
    0,    0,    0,    0,   16,   34,   35,   36,   37,   38,
   39,    0,    0,   12,   13,    0,   13,   13,   13,    0,
    0,    0,   17,   17,    2,    0,    3,    4,   20,    0,
    0,    0,   13,    0,    5,    6,    7,    0,   16,    8,
    9,   10,   11,    0,    0,    0,   29,   12,   29,   29,
    0,    0,    0,    0,    6,    7,   29,   29,   29,    9,
   10,   29,   29,   29,   29,    2,   13,    3,    4,   35,
   36,   37,   38,   39,    0,    5,    6,    7,    0,    0,
    8,    9,   10,   11,    2,    0,    3,    4,    0,    0,
    0,    0,    0,    0,    5,    6,    7,    0,    0,    8,
    9,   10,   11,    2,    0,    3,    4,    0,    0,    0,
    0,    0,    0,    5,    6,    7,    0,    0,    8,    9,
   10,   11,    2,    0,    3,    4,    0,    0,    0,    0,
    0,    0,    5,    6,    7,    0,    0,    8,    9,   10,
   11,    8,    8,    8,    8,    8,    8,   34,   35,   36,
   37,   38,   39,   18,   18,   18,   18,   18,    0,    0,
   21,   21,   21,    0,   21,   34,   35,   36,   37,   38,
   39,   34,   35,   36,   37,   38,   39,    0,   34,   35,
   36,   37,   38,   39,   34,   35,   36,   37,   38,   39,
    0,    0,    0,    0,    0,    0,   20,   20,   20,    0,
    0,   27,    0,    0,   28,   29,   16,   30,   32,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   52,    0,
    0,    0,    0,    0,    0,    0,   55,   56,   57,   58,
   59,   60,   61,   62,   63,    0,   64,   66,   67,   68,
    0,    0,    0,   64,   14,    0,   14,   14,   14,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   14,    0,    0,    0,   82,    0,    0,   85,
    0,    0,    0,    0,    0,    0,    0,    0,   92,    0,
    0,    0,    0,    0,    0,   32,   32,   32,   32,    0,
    0,    0,    0,    0,   68,    0,   14,    0,    0,    0,
    0,    0,    0,    0,    0,   32,    0,    0,   32,
};
}
static short yycheck[];
static { yycheck(); }
static void yycheck() {
yycheck = new short[] {                         10,
   33,   61,   41,   42,   43,   44,   45,   40,   44,   44,
  269,   41,   45,   40,   44,   44,   16,   40,   10,   33,
   59,   41,   33,   40,   44,   41,   40,   40,   44,   40,
   59,   45,   41,   91,   45,   44,   67,   10,   69,   59,
  266,   33,   41,   59,   40,   44,   41,   41,   40,   44,
   44,   23,   24,   45,   93,   40,   44,   93,   93,   41,
   33,   92,   41,   93,   95,   96,   41,   40,   43,   44,
   45,   41,   45,  104,  105,   41,  107,   93,  264,   33,
  266,   59,  113,  123,   59,  116,   40,  125,  119,  123,
   59,   45,  125,   93,   94,   95,   96,   41,   33,   93,
   44,  123,  123,   87,   88,   40,   90,   91,   59,  258,
   45,  123,   41,  113,  125,   59,  116,  125,   93,  123,
   40,   41,   42,   43,   44,   45,  110,   41,   42,   43,
  114,   45,   41,   41,   42,   43,   44,   45,  125,   59,
   41,   42,   43,   44,   45,  125,   42,   43,   59,   45,
  102,   59,   42,   43,  125,   45,   51,   -1,   59,   42,
   43,   -1,   45,   59,   -1,   42,  264,  265,  266,   59,
   -1,  125,   -1,   93,   -1,   -1,   41,   42,   43,   44,
   45,  263,  264,  265,  266,   93,   41,   42,   43,   44,
   45,   -1,   93,   -1,   59,   41,   42,   43,   44,   45,
   -1,   -1,   -1,   -1,   59,  261,  262,  263,  264,  265,
  266,   -1,   -1,   59,   41,   -1,   43,   44,   45,   -1,
   -1,   -1,  261,  262,  257,   -1,  259,  260,   93,   -1,
   -1,   -1,   59,   -1,  267,  268,  269,   -1,   93,  272,
  273,  274,  275,   -1,   -1,   -1,  257,   93,  259,  260,
   -1,   -1,   -1,   -1,  268,  269,  267,  268,  269,  273,
  274,  272,  273,  274,  275,  257,   93,  259,  260,  262,
  263,  264,  265,  266,   -1,  267,  268,  269,   -1,   -1,
  272,  273,  274,  275,  257,   -1,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,
  273,  274,  275,  257,   -1,  259,  260,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  257,   -1,  259,  260,   -1,   -1,   -1,   -1,
   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,  274,
  275,  261,  262,  263,  264,  265,  266,  261,  262,  263,
  264,  265,  266,  261,  262,  263,  264,  265,   -1,   -1,
  261,  262,  263,   -1,  265,  261,  262,  263,  264,  265,
  266,  261,  262,  263,  264,  265,  266,   -1,  261,  262,
  263,  264,  265,  266,  261,  262,  263,  264,  265,  266,
   -1,   -1,   -1,   -1,   -1,   -1,  261,  262,  263,   -1,
   -1,    9,   -1,   -1,   12,   13,  261,   15,   16,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   26,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   34,   35,   36,   37,
   38,   39,   40,   41,   42,   -1,   44,   45,   46,   47,
   -1,   -1,   -1,   51,   41,   -1,   43,   44,   45,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   -1,   -1,   -1,   74,   -1,   -1,   77,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   86,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   94,   95,   96,   -1,
   -1,   -1,   -1,   -1,  102,   -1,   93,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  113,   -1,   -1,  116,
};
}
final static short YYFINAL=1;
final static short YYMAXTOKEN=275;
final static String yyname[] = {
"end-of-file",null,null,null,null,null,null,null,null,null,"'\\n'",null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,"'!'",null,null,null,null,null,null,"'('","')'","'*'","'+'",
"','","'-'",null,null,null,null,null,null,null,null,null,null,null,null,null,
"';'",null,"'='",null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,"'['",null,"']'",null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,"'{'",null,"'}'",null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,"IF","ELSE","WHILE","FOR","COMP",
"DIFERENTES","MAYOR","MENOR","MAYORI","MENORI","FNCT","NUMBER","VAR","AND","OR",
"FUNC","RETURN","PARAMETRO","PROC",
};
final static String yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list linea '\\n'",
"linea : exp ';'",
"linea : stmt",
"linea : linea exp ';'",
"linea : linea stmt",
"exp : VAR",
"exp : '-' exp",
"exp : NUMBER",
"exp : VAR '=' exp",
"exp : exp '*' exp",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : '(' exp ')'",
"exp : exp COMP exp",
"exp : exp DIFERENTES exp",
"exp : exp MENOR exp",
"exp : exp MENORI exp",
"exp : exp MAYOR exp",
"exp : exp MAYORI exp",
"exp : '!' exp",
"exp : RETURN exp",
"exp : PARAMETRO",
"exp : nombreProc '(' arglist ')'",
"arglist :",
"arglist : exp",
"arglist : arglist ',' exp",
"nop :",
"stmt : if '(' exp stop ')' '{' linea stop '}' ELSE '{' linea stop '}'",
"stmt : if '(' exp stop ')' '{' linea stop '}' nop stop",
"stmt : while '(' exp stop ')' '{' linea stop '}' stop",
"stmt : for '(' instrucciones stop ';' exp stop ';' instrucciones stop ')' '{' linea stop '}' stop",
"stmt : funcion nombreProc '(' ')' '{' linea '}'",
"stmt : procedimiento nombreProc '(' ')' '{' linea '}'",
"stmt : instruccion '[' arglist ']' ';'",
"instruccion : FNCT",
"procedimiento : PROC",
"funcion : FUNC",
"nombreProc : VAR",
"null :",
"stop :",
"if : IF",
"while : WHILE",
"for : FOR",
"instrucciones :",
"instrucciones : exp",
"instrucciones : instrucciones ',' exp",
};

//#line 145 "Gramatica.y"



TablaDeSimbolos tablaDeSimbolos = new TablaDeSimbolos();
MaquinaDePila maquina = new MaquinaDePila(tablaDeSimbolos);
int i = 0;
int j = 0;
double[][] auxiliar;
Funcion funcionAux;
boolean huboError;

String ins;
StringTokenizer st;

void yyerror(String s){
	huboError = true;
	System.out.println("error:"+s);
        System.exit(0);
}

boolean newline;
int yylex(){
	String s;
	int tok = 0;
	Double d;
	if (!st.hasMoreTokens()){
		if (!newline){
			newline=true;
			return '\n';
		}
		else
			return 0;
	}
	s = st.nextToken();
	try{
		d = Double.valueOf(s);/*this MAYOR fail*/
		yylval = new ParserVal(d.doubleValue()); //SEE BELOW
		return NUMBER;
	}
	catch (Exception e){}
	if(esVariable(s)){
		switch(s){
			case "procedure":
				return PROC;
			case "return":
				return RETURN;
			case "function":
				return FUNC;
			case "if":
				return IF;
			case "else":
				return ELSE;
			case "while":
				return WHILE;
			case "for":
				return FOR;
			default:
				break;
		}
		if(s.charAt(0) == '$'){
			yylval = new ParserVal((int)Integer.parseInt(s.substring(1)));
			return PARAMETRO;
		}
		boolean esFuncion = false;
		Object objeto = tablaDeSimbolos.encontrar(s);
		if(objeto instanceof Funcion){
			funcionAux = (Funcion)objeto;
			yylval = new ParserVal(objeto);
			esFuncion = true;
			return FNCT;
		}
		if(!esFuncion){
			yylval = new ParserVal(s);
			return VAR;
		}
	}
	else{
		switch(s){
			case "==":
				return COMP;
			case "!=":
				return DIFERENTES;
			case "<":
				return MENOR;
			case "<=":
				return MENORI;
			case ">":
				return MAYOR;
			case ">=":
				return MAYORI;
			default:
				break;
		}
            tok = s.charAt(0);
	}
	return tok;
}

String reservados[] = {">=", "&&", "||", "<=","==", "!=", "=", "{", "}", ",", "*", "+", "-", "(", ")", "|", "[", "]", ";", "!", "<", ">"};
public String ajustarCadena(String cadena){
    String nueva = "";
    boolean encontrado = false;
    for(int i = 0; i < cadena.length() - 1; i++){
        encontrado = false;
        for(int j = 0; j < reservados.length; j++){
            if(cadena.substring(i, i + reservados[j].length()).equals(reservados[j])){
                i += reservados[j].length()-1;
                nueva += " " + reservados[j] + " ";
                encontrado = true;
                break;
            }
        }
        if(!encontrado)
            nueva += cadena.charAt(i);
    }
    nueva += cadena.charAt(cadena.length()-1);
    return nueva;
}

boolean esVariable(String s){
	boolean cumple = true;
	for(int i = 0; i < reservados.length; i++)
		if(s.equals(reservados[i]))
			cumple = false;
	return cumple;
}
public void insertarInstrucciones(){
	tablaDeSimbolos.insertar("Rotate", new MaquinaDePila.Girar());
	tablaDeSimbolos.insertar("Move", new MaquinaDePila.Avanzar());
}


public Configuracion ejecutarCodigo(String codigo){
    st = new StringTokenizer(ajustarCadena(codigo));
    newline=false;
    yyparse();
    if(!huboError)
            maquina.ejecutar();
    return maquina.getConfiguracion();
} 

public boolean compilar(String codigo){
    st = new StringTokenizer(ajustarCadena(codigo));
    newline=false;
    yyparse();
    return !huboError;
}

public boolean ejecutarSiguiente(){
    return maquina.ejecutarSiguiente();
}

public Configuracion getConfiguracion(){
    return maquina.getConfiguracion();
}

public void limpiar(){
    tablaDeSimbolos = new TablaDeSimbolos();
    insertarInstrucciones();
    maquina = new MaquinaDePila(tablaDeSimbolos);
}

public Configuracion ejecutar(){
    maquina.ejecutar();
    return maquina.getConfiguracion();
}

void dotest() throws Exception{
	insertarInstrucciones();
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	while (true){
		huboError = false;
		try{
			ins = ajustarCadena(in.readLine());
		}
		catch (Exception e){}
		st = new StringTokenizer(ins);
		newline=false;
		yyparse();
		if(!huboError)
			maquina.ejecutar();
	}
}

public static void main(String args[]) throws Exception{
	Parser par = new Parser(false);
	par.dotest();
}
//#line 554 "Parser.java"
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
case 4:
//#line 47 "Gramatica.y"
{yyval = val_peek(1);}
break;
case 5:
//#line 48 "Gramatica.y"
{yyval = val_peek(0);}
break;
case 6:
//#line 49 "Gramatica.y"
{yyval = val_peek(2);}
break;
case 7:
//#line 50 "Gramatica.y"
{yyval = val_peek(1);}
break;
case 8:
//#line 53 "Gramatica.y"
{yyval = new ParserVal(maquina.agregarOperacion("varPush_Eval")); maquina.agregar(val_peek(0).sval);}
break;
case 9:
//#line 54 "Gramatica.y"
{yyval = new ParserVal(maquina.agregarOperacion("negativo"));}
break;
case 10:
//#line 55 "Gramatica.y"
{yyval = new ParserVal(maquina.agregarOperacion("constPush"));maquina.agregar(val_peek(0).dval);}
break;
case 11:
//#line 56 "Gramatica.y"
{yyval = new ParserVal(val_peek(0).ival);maquina.agregarOperacion("varPush");maquina.agregar(val_peek(2).sval);maquina.agregarOperacion("asignar");maquina.agregarOperacion("varPush_Eval"); 
				maquina.agregar(val_peek(2).sval);
			}
break;
case 12:
//#line 59 "Gramatica.y"
{yyval = new ParserVal(val_peek(2).ival);maquina.agregarOperacion("multiplicar");}
break;
case 13:
//#line 60 "Gramatica.y"
{yyval = new ParserVal(val_peek(2).ival);maquina.agregarOperacion("sumar");}
break;
case 14:
//#line 61 "Gramatica.y"
{yyval = new ParserVal(val_peek(2).ival);maquina.agregarOperacion("restar");}
break;
case 15:
//#line 62 "Gramatica.y"
{yyval = new ParserVal(val_peek(1).ival);}
break;
case 16:
//#line 63 "Gramatica.y"
{maquina.agregarOperacion("comparar");yyval = val_peek(2);}
break;
case 17:
//#line 64 "Gramatica.y"
{maquina.agregarOperacion("compararNot");yyval = val_peek(2);}
break;
case 18:
//#line 65 "Gramatica.y"
{maquina.agregarOperacion("menor");yyval = val_peek(2);}
break;
case 19:
//#line 66 "Gramatica.y"
{maquina.agregarOperacion("menorIgual");yyval = val_peek(2);}
break;
case 20:
//#line 67 "Gramatica.y"
{maquina.agregarOperacion("mayor");yyval = val_peek(2);}
break;
case 21:
//#line 68 "Gramatica.y"
{maquina.agregarOperacion("mayorIgual");yyval = val_peek(2);}
break;
case 22:
//#line 69 "Gramatica.y"
{maquina.agregarOperacion("negar");yyval = val_peek(0);}
break;
case 23:
//#line 70 "Gramatica.y"
{ yyval = val_peek(0); maquina.agregarOperacion("_return"); }
break;
case 24:
//#line 71 "Gramatica.y"
{ yyval = new ParserVal(maquina.agregarOperacion("push_parametro")); maquina.agregar((int)val_peek(0).ival); }
break;
case 25:
//#line 72 "Gramatica.y"
{ yyval = new ParserVal(maquina.agregarOperacionEn("invocar",(val_peek(3).ival))); maquina.agregar(null); }
break;
case 27:
//#line 76 "Gramatica.y"
{yyval = val_peek(0); maquina.agregar("Limite");}
break;
case 28:
//#line 77 "Gramatica.y"
{yyval = val_peek(2); maquina.agregar("Limite");}
break;
case 29:
//#line 80 "Gramatica.y"
{yyval = new ParserVal(maquina.agregarOperacion("nop"));}
break;
case 30:
//#line 83 "Gramatica.y"
{
				yyval = val_peek(13);maquina.agregar(val_peek(7).ival, val_peek(13).ival + 1);maquina.agregar(val_peek(2).ival, val_peek(13).ival + 2);
				maquina.agregar(maquina.numeroDeElementos() - 1, val_peek(13).ival + 3);
			}
break;
case 31:
//#line 87 "Gramatica.y"
{
				yyval = val_peek(10);maquina.agregar(val_peek(4).ival, val_peek(10).ival + 1);maquina.agregar(val_peek(1).ival, val_peek(10).ival + 2);
				maquina.agregar(maquina.numeroDeElementos() - 1, val_peek(10).ival + 3);
			}
break;
case 32:
//#line 91 "Gramatica.y"
{
				yyval = val_peek(9);maquina.agregar(val_peek(3).ival, val_peek(9).ival + 1);maquina.agregar(val_peek(0).ival, val_peek(9).ival + 2);
			}
break;
case 33:
//#line 94 "Gramatica.y"
{
				yyval = val_peek(15);maquina.agregar(val_peek(10).ival, val_peek(15).ival + 1);maquina.agregar(val_peek(7).ival, val_peek(15).ival + 2);maquina.agregar(val_peek(3).ival, val_peek(15).ival + 3);
				maquina.agregar(val_peek(0).ival, val_peek(15).ival + 4);
			}
break;
case 36:
//#line 100 "Gramatica.y"
{ 
				yyval = new ParserVal(val_peek(4).ival);maquina.agregar(null);
			}
break;
case 37:
//#line 104 "Gramatica.y"
{
			yyval = new ParserVal(maquina.agregar((Funcion)(val_peek(0).obj)));
			}
break;
case 38:
//#line 109 "Gramatica.y"
{ maquina.agregarOperacion("declaracion"); }
break;
case 39:
//#line 111 "Gramatica.y"
{ maquina.agregarOperacion("declaracion"); }
break;
case 40:
//#line 114 "Gramatica.y"
{yyval = new ParserVal(maquina.agregar(val_peek(0).sval));}
break;
case 41:
//#line 117 "Gramatica.y"
{maquina.agregar(null);}
break;
case 42:
//#line 120 "Gramatica.y"
{yyval = new ParserVal(maquina.agregarOperacion("stop"));}
break;
case 43:
//#line 123 "Gramatica.y"
{
			yyval = new ParserVal(maquina.agregarOperacion("_if_then_else"));maquina.agregarOperacion("stop");maquina.agregarOperacion("stop");
			maquina.agregarOperacion("stop");
		}
break;
case 44:
//#line 129 "Gramatica.y"
{
			yyval = new ParserVal(maquina.agregarOperacion("_while"));maquina.agregarOperacion("stop");
	        maquina.agregarOperacion("stop");
		}
break;
case 45:
//#line 135 "Gramatica.y"
{
			yyval = new ParserVal(maquina.agregarOperacion("_for"));maquina.agregarOperacion("stop");maquina.agregarOperacion("stop");
	        maquina.agregarOperacion("stop");maquina.agregarOperacion("stop");
		}
break;
case 46:
//#line 140 "Gramatica.y"
{ yyval = new ParserVal(maquina.agregarOperacion("nop"));}
break;
case 47:
//#line 141 "Gramatica.y"
{yyval = val_peek(0);}
break;
case 48:
//#line 142 "Gramatica.y"
{yyval = val_peek(2);}
break;
//#line 897 "Parser.java"
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
