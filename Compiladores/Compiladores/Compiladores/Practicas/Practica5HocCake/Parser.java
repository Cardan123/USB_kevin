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






//#line 3 "Hockacke.y"
import java.lang.Math;
import java.io.*;
import java.util.StringTokenizer;
//#line 21 "Parser.java"




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
public final static short PRINT=258;
public final static short VAR=259;
public final static short BLTIN=260;
public final static short INDEF=261;
public final static short WHILE=262;
public final static short IF=263;
public final static short ELSE=264;
public final static short OR=265;
public final static short AND=266;
public final static short GT=267;
public final static short GE=268;
public final static short LT=269;
public final static short LE=270;
public final static short EQ=271;
public final static short NE=272;
public final static short UNARYMINUS=273;
public final static short NOT=274;
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    1,    2,    2,    2,    2,
    2,    2,    5,    4,    7,    6,    8,    8,    8,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,
};
final static short yylen[] = {                            2,
    0,    2,    3,    3,    3,    3,    1,    2,    4,    4,
    7,    3,    3,    1,    1,    0,    0,    2,    2,    6,
    1,    1,    4,    3,    3,    3,    3,    3,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    2,
};
final static short yydefred[] = {                         1,
    0,    0,    0,    0,   14,   15,    0,    0,    2,   17,
    0,    0,    0,    0,    0,    0,    0,   22,    0,    0,
    0,   29,   38,    0,    0,    0,    3,    4,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    5,    0,    0,    0,    0,    0,   18,   12,   19,    0,
   28,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   26,   27,    0,   16,   16,   23,    0,   13,
    9,    0,    0,    0,   20,   16,   11,
};
final static short yydgoto[] = {                          1,
   18,   14,   50,   16,   43,   71,   17,   24,
};
final static short yysindex[] = {                         0,
  448,  -36,  -58,  -26,    0,    0,  -36,  -36,    0,    0,
  -36, -242,    6,    9,  462,  -18,  -18,    0,  480,  -36,
  -36,    0,    0,  412,  472,  -20,    0,    0,  -36,  -36,
  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
    0,  -36,  -33,  -33,  480,  489,    0,    0,    0,  480,
    0, -233,  378,  122,  -37,  -37,  -37,  -37,  -37,  -37,
  -29,  -29,    0,    0,  499,    0,    0,    0,  -81,    0,
    0, -238,  -66,  -33,    0,    0,    0,
};
final static short yyrindex[] = {                         0,
    0,    0,  -10,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  507,    0,    0,    0,    0,    0,  420,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  403,    0,    0,    0,    0,  438,
    0,    0,  395,  377,   43,   62,   79,   97,  114,  360,
    7,   26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  430,    0,    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
   27,  -23,  557,    0,   12,  -65,    0,    0,
};
final static int YYTABLESIZE=779;
static short yytable[];
static { yytable();}
static void yytable(){
yytable = new short[]{                         21,
   49,   72,   20,   11,   39,   37,   11,   38,    7,   40,
   77,    7,   39,   21,   26,   27,   24,   40,   28,   66,
   67,   42,   52,   69,   73,   74,   75,   13,   44,   21,
   21,   21,   21,    0,   21,   25,   21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   24,   24,    0,   24,
   76,   24,   32,    0,   12,    0,    0,   12,    0,    0,
    0,    0,    0,    0,    0,   25,   25,    0,   25,    0,
   25,   33,    0,    0,    0,    0,    0,    0,    0,    0,
   21,    0,   32,   32,    0,    0,    0,    0,   34,   10,
    0,    0,    0,    0,    0,    0,    0,   24,    0,    0,
    0,   33,   33,    0,    0,    0,   35,    0,    0,    0,
    0,    0,   21,    0,   21,    0,   25,    0,   34,   34,
    0,    0,    0,   30,    0,    0,    0,    0,    0,   24,
    0,   24,    0,   32,    0,    0,   35,   35,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   25,    0,
   25,    0,   33,   30,   30,    0,    0,    0,    0,    0,
    0,    0,    0,   39,   37,   32,   38,   32,   40,   34,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   33,    0,   33,   35,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   34,    0,   34,   30,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   35,
    0,   35,    3,    4,    2,    3,    4,    0,    5,    6,
    0,    0,    0,    0,    0,    0,   30,    8,   30,    0,
    8,    0,    0,    0,    0,    0,    0,   21,   21,   21,
    0,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,    0,   21,   24,   24,   24,    0,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,    0,
   24,    0,    0,   25,   25,   25,    0,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   25,    0,   25,
   32,   32,   32,    0,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   32,    0,   32,    0,    0,   33,
   33,   33,    0,   33,   33,   33,   33,   33,   33,   33,
   33,   33,   33,   33,    0,   33,   34,   34,   34,    0,
   34,   34,   34,   34,   34,   34,   34,   34,   34,   34,
   34,    0,   34,    0,   35,   35,   35,    0,   35,   35,
   35,   35,   35,   35,   35,   35,   35,   35,   35,   31,
   35,   30,   30,   30,    0,   30,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   30,   36,   30,   31,   32,
   33,   34,   35,   36,    0,    0,    0,    0,    0,   31,
   31,    0,    0,    0,   37,    0,    0,    0,    0,    0,
    0,    0,    6,    0,    0,    0,   36,   36,    0,   39,
   37,   47,   38,    0,   40,    0,    0,    0,    0,    8,
    0,    0,    0,    0,   37,   37,    0,    0,    0,   10,
    0,    0,    6,    6,    0,    0,    0,    7,    0,    0,
   31,   11,    0,    0,    0,    0,    7,    9,    0,    8,
    0,    0,    0,    0,    0,    0,    0,   36,    0,   10,
    0,   41,    0,    0,   10,    0,    0,    7,    0,    0,
    0,    0,   31,    0,   31,   37,    0,   11,    0,    0,
    0,    0,    7,    6,    0,    0,    0,    0,    0,   36,
    0,   36,   12,   39,   37,    0,   38,    0,   40,    0,
    8,    0,   51,   39,   37,    0,   38,   37,   40,   37,
   10,   39,   37,    0,   38,    6,   40,    6,    7,   68,
   39,   37,    0,   38,   10,   40,   48,    0,   12,   70,
   39,   37,    8,   38,    8,   40,    0,    0,   22,   22,
    0,   22,   10,   22,   10,    0,    0,   15,   19,    0,
    7,    0,    7,   22,   23,    0,    0,   25,    0,    0,
   10,    0,    0,    0,    0,    0,   45,   46,    0,    0,
    0,    0,    0,    0,    0,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   62,   63,   64,    0,   65,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,   31,   31,
    0,   31,   31,   31,   31,   31,   31,   31,   31,   31,
   31,   31,    0,   31,   36,   36,   36,    0,   36,   36,
   36,   36,   36,   30,   31,   32,   33,   34,   35,   36,
   36,    0,   37,   37,   37,    0,   37,   37,   37,   37,
    6,    6,    6,    0,    6,    6,    6,    0,   37,    2,
    3,    4,    0,    5,    6,    0,    6,    8,    8,    8,
    0,    8,    8,    8,    0,    8,    0,   10,   10,   10,
    0,   10,   10,    8,    0,    7,    7,    7,    0,    7,
    7,    7,    0,   10,    0,    2,    3,    4,    0,    5,
    6,    7,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    8,    0,    0,    0,    0,   29,   30,   31,   32,
   33,   34,   35,   36,    0,    0,   29,   30,   31,   32,
   33,   34,   35,   36,   29,   30,   31,   32,   33,   34,
   35,   36,    0,   29,   30,   31,   32,   33,   34,   35,
   36,    0,    0,   29,   30,   31,   32,   33,   34,   35,
   36,   22,   22,   22,   22,   22,   22,   22,   22,
};
}
static short yycheck[];
static { yycheck(); }
static void yycheck() {
yycheck = new short[] {                         10,
   24,   67,   61,   40,   42,   43,   40,   45,   45,   47,
   76,   45,   42,   40,  257,   10,   10,   47,   10,   43,
   44,   40,   43,  257,  106,  264,   93,    1,   17,   40,
   41,   42,   43,   -1,   45,   10,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   43,
   74,   45,   10,   -1,   91,   -1,   -1,   91,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   43,   -1,
   45,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   91,   -1,   40,   41,   -1,   -1,   -1,   -1,   10,  123,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,   -1,   -1,
   -1,   40,   41,   -1,   -1,   -1,   10,   -1,   -1,   -1,
   -1,   -1,  123,   -1,  125,   -1,   91,   -1,   40,   41,
   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,  123,
   -1,  125,   -1,   91,   -1,   -1,   40,   41,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   91,   40,   41,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   42,   43,  123,   45,  125,   47,   91,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,  125,   91,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   91,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,
   -1,  125,  259,  260,  258,  259,  260,   -1,  262,  263,
   -1,   -1,   -1,   -1,   -1,   -1,  123,  274,  125,   -1,
  274,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,
   -1,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,  274,  258,  259,  260,   -1,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,   -1,
  274,   -1,   -1,  258,  259,  260,   -1,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,   -1,  274,
  258,  259,  260,   -1,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,   -1,  274,   -1,   -1,  258,
  259,  260,   -1,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,   -1,  274,  258,  259,  260,   -1,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,   -1,  274,   -1,  258,  259,  260,   -1,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,   10,
  274,  258,  259,  260,   -1,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,   10,  274,  267,  268,
  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   40,
   41,   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   10,   -1,   -1,   -1,   40,   41,   -1,   42,
   43,   10,   45,   -1,   47,   -1,   -1,   -1,   -1,   10,
   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,   -1,   10,
   -1,   -1,   40,   41,   -1,   -1,   -1,   10,   -1,   -1,
   91,   40,   -1,   -1,   -1,   -1,   45,   10,   -1,   40,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,   -1,   40,
   -1,   10,   -1,   -1,   45,   -1,   -1,   40,   -1,   -1,
   -1,   -1,  123,   -1,  125,   91,   -1,   40,   -1,   -1,
   -1,   -1,   45,   91,   -1,   -1,   -1,   -1,   -1,  123,
   -1,  125,   91,   42,   43,   -1,   45,   -1,   47,   -1,
   91,   -1,   41,   42,   43,   -1,   45,  123,   47,  125,
   91,   42,   43,   -1,   45,  123,   47,  125,   91,   41,
   42,   43,   -1,   45,  123,   47,  125,   -1,   91,   41,
   42,   43,  123,   45,  125,   47,   -1,   -1,   42,   43,
   -1,   45,  123,   47,  125,   -1,   -1,    1,    2,   -1,
  123,   -1,  125,    7,    8,   -1,   -1,   11,   -1,   -1,
  123,   -1,   -1,   -1,   -1,   -1,   20,   21,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   29,   30,   31,   32,   33,
   34,   35,   36,   37,   38,   39,   40,   -1,   42,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,
   -1,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,  274,  258,  259,  260,   -1,  262,  263,
  264,  265,  266,  266,  267,  268,  269,  270,  271,  272,
  274,   -1,  258,  259,  260,   -1,  262,  263,  264,  265,
  258,  259,  260,   -1,  262,  263,  264,   -1,  274,  258,
  259,  260,   -1,  262,  263,   -1,  274,  258,  259,  260,
   -1,  262,  263,  264,   -1,  274,   -1,  258,  259,  260,
   -1,  262,  263,  274,   -1,  258,  259,  260,   -1,  262,
  263,  264,   -1,  274,   -1,  258,  259,  260,   -1,  262,
  263,  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,   -1,   -1,   -1,   -1,  265,  266,  267,  268,
  269,  270,  271,  272,   -1,   -1,  265,  266,  267,  268,
  269,  270,  271,  272,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,  265,  266,  267,  268,  269,  270,  271,
  272,   -1,   -1,  265,  266,  267,  268,  269,  270,  271,
  272,  265,  266,  267,  268,  269,  270,  271,  272,
};
}
final static short YYFINAL=1;
final static short YYMAXTOKEN=274;
final static String yyname[] = {
"end-of-file",null,null,null,null,null,null,null,null,null,"'\\n'",null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,"'('","')'","'*'","'+'",
null,"'-'",null,"'/'",null,null,null,null,null,null,null,null,null,null,null,
null,null,"'='",null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,"'['",null,"']'","'^'",null,null,null,null,null,null,null,null,null,null,
null,"'j'",null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,"'{'",null,"'}'",null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,"NUMBER","PRINT","VAR",
"BLTIN","INDEF","WHILE","IF","ELSE","OR","AND","GT","GE","LT","LE","EQ","NE",
"UNARYMINUS","NOT",
};
final static String yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list stmt '\\n'",
"list : list expr '\\n'",
"asgn : VAR '=' expr",
"stmt : expr",
"stmt : PRINT expr",
"stmt : while cond stmt end",
"stmt : if cond stmt end",
"stmt : if cond stmt end ELSE stmt end",
"stmt : '{' stmtlist '}'",
"cond : '(' expr ')'",
"while : WHILE",
"if : IF",
"end :",
"stmtlist :",
"stmtlist : stmtlist '\\n'",
"stmtlist : stmtlist stmt",
"expr : '[' NUMBER '+' NUMBER 'j' ']'",
"expr : VAR",
"expr : asgn",
"expr : BLTIN '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : '(' expr ')'",
"expr : '-' expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr GT expr",
"expr : expr GE expr",
"expr : expr LT expr",
"expr : expr LE expr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",
};

//#line 116 "Hockacke.y"
class Algo {
  Simbolo simb;
  int inst;

  public Algo(int i){
    inst=i;
  }
  public Algo(Simbolo s, int i){
    simb=s;
                inst=i;
  }
}

static Tabla tabla;
static Maquina maq;

static String ins;
static StringTokenizer st;

void yyerror(String s){
 System.out.println("parser:"+s);
}

static boolean newline;
int yylex(){
   String s;
   int tok = 0;
   Double d;
   Simbolo simbo;
   //revisar nva linea
   if (!st.hasMoreTokens())
      if (!newline){
   newline=true;
   return '\n'; 
      }
      else
   return 0;  
   s = st.nextToken();
   //System.out.println("tok act: ("+s+" )");
   try{
      d = Double.valueOf(s);
      yylval = new ParserVal(
new Algo(tabla.install("", NUMBER, d.doubleValue()), 0) );
      tok = NUMBER; 
   } catch (Exception e){
      if(Character.isJavaLetter(s.charAt(0)) && !s.equals("j")){
         if((simbo=tabla.lookup(s))== null)
      simbo=tabla.install(s, INDEF, 0.0);
         yylval = new ParserVal(new Algo(simbo, 0));
   tok= (simbo.tipo == INDEF ? VAR : simbo.tipo); 
      }
      else if(s.equals("==")){
                    tok= EQ;
      }
      else if(s.equals("!=")){
                    tok= NE;
      }
      else if(s.equals("<")){
                    tok= LT;
      }
      else if(s.equals("<=")){
                    tok= LE;
      }
      else if(s.equals(">")){
                    tok= GT;
      }
      else if(s.equals(">=")){
                    tok= GE;
      }
      else if(s.charAt(0) == '!'){
                    tok= NOT;
      } 
      else if(s.equals("||")){
                    tok= OR;
      }
      else if(s.equals("&&")){
                    tok= AND;
      }         
      else{
         tok = s.charAt(0);
      }
   }
   //System.out.println("Token: " + tok);
   return tok;
}
public static void main(String s[]){
   BufferedReader in = new BufferedReader(
       new InputStreamReader(System.in));
   maq=new Maquina();
   tabla=new Tabla();
   tabla.install("sin",BLTIN, 0.0);
   tabla.install("cos",BLTIN, 0.0);
   tabla.install("if", IF, 0.0);
   tabla.install("else", ELSE, 0.0);
   tabla.install("while", WHILE, 0.0);
   tabla.install("print", PRINT, 0.0);
   System.out.println("Hocake5");
   Parser par = new Parser(false);
   System.out.print("expression:");
   try{
      ins = in.readLine();
   } catch (Exception e){}
   st = new StringTokenizer(ins);
   newline=false;
   for(maq.initcode(); par.yyparse ()!=0; maq.initcode()){
      //maq.execute(maq.progbase);
      maq.execute(0);
      System.out.print("expression:");
      try{
         ins = in.readLine();
      } catch (Exception e){}
      st = new StringTokenizer(ins);  
      newline=false;
   }    
}



//#line 510 "Parser.java"
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
//#line 19 "Hockacke.y"
{ maq.code("pop"); 
                  maq.code("STOP"); return 1 ;}

case 4:
//#line 21 "Hockacke.y"
{ maq.code("STOP"); return 1 ;}

case 5:
//#line 22 "Hockacke.y"
{ maq.code("print");
                  maq.code("STOP"); return 1 ;}

case 6:
//#line 25 "Hockacke.y"
{ 
           yyval=val_peek(0); maq.code("varpush"); 
                  maq.code(((Algo)val_peek(2).obj).simb); 
      maq.code("assign");
  }
break;
case 7:
//#line 31 "Hockacke.y"
{ 
                  maq.code("pop");}
break;
case 8:
//#line 33 "Hockacke.y"
{ maq.code("prexpr"); 
        ((Algo)yyval.obj).inst = ((Algo)val_peek(0).obj).inst; }
break;
case 9:
//#line 35 "Hockacke.y"
{
             maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(1).obj).inst),
                 ((Algo)val_peek(3).obj).inst+1); 
             maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(0).obj).inst),
                 ((Algo)val_peek(3).obj).inst+2); 
     }
break;
case 10:
//#line 43 "Hockacke.y"
{   
                 maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(1).obj).inst),
                 ((Algo)val_peek(3).obj).inst+1); 
                 maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(0).obj).inst),
                 ((Algo)val_peek(3).obj).inst+3); 
                  }
break;
case 11:
//#line 51 "Hockacke.y"
{ 
                 maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(4).obj).inst),
                 ((Algo)val_peek(6).obj).inst+1); 
                 maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(1).obj).inst),
                 ((Algo)val_peek(6).obj).inst+2);             
                  maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(0).obj).inst),
                ((Algo)val_peek(6).obj).inst+3);  
    }
break;
case 12:
//#line 62 "Hockacke.y"
{  
                  yyval  =  val_peek(1); 
                  }
break;
case 13:
//#line 66 "Hockacke.y"
{   maq.code("STOP");  
         ((Algo)yyval.obj).inst = ((Algo)val_peek(1).obj).inst;
    }
break;
case 14:
//#line 70 "Hockacke.y"
{   
  yyval = new ParserVal(new Algo(maq.code("whilecode"))); 
        maq.code("STOP");maq.code("STOP");
        }
break;
case 15:
//#line 75 "Hockacke.y"
{ /*$$ = code(ifcode); code3(STOP,STOP,STOP);*/
  yyval = new ParserVal(new Algo(maq.code("ifcode"))); 
        maq.code("STOP");maq.code("STOP");maq.code("STOP");
        }
break;
case 16:
//#line 80 "Hockacke.y"
{ maq.code("STOP"); 
 yyval=new ParserVal(new Algo(maq.getProg().size()));        
        }
break;
case 17:
//#line 84 "Hockacke.y"
{                
  yyval=new ParserVal(new Algo(maq.getProg().size()));  
        }
break;
case 20:
//#line 90 "Hockacke.y"
{ 
                /*((Algo)$$.obj).inst=*/maq.code("constpush");
                maq.code(((Algo)val_peek(4).obj).simb); 
                /*((Algo)$$.obj).inst=*/maq.code("constpush");
                maq.code(((Algo)val_peek(2).obj).simb); }
break;
case 21:
//#line 95 "Hockacke.y"
{ ((Algo)yyval.obj).inst=maq.code("varpush");
                maq.code(((Algo)val_peek(0).obj).simb); maq.code("eval");}
break;
case 23:
//#line 98 "Hockacke.y"
{ yyval=val_peek(1); maq.code("bltin"); maq.code(((Algo)val_peek(3).obj).simb); }
break;
case 24:
//#line 99 "Hockacke.y"
{ maq.code("add");}
break;
case 25:
//#line 100 "Hockacke.y"
{ maq.code("sub"); }
break;
case 26:
//#line 101 "Hockacke.y"
{ maq.code("mul");}
break;
case 27:
//#line 102 "Hockacke.y"
{ maq.code("div"); }
break;
case 28:
//#line 103 "Hockacke.y"
{ yyval= val_peek(1);}
break;
case 29:
//#line 104 "Hockacke.y"
{ yyval=val_peek(0); maq.code("negate");}
break;
case 30:
//#line 105 "Hockacke.y"
{ maq.code("eq"); }
break;
case 31:
//#line 106 "Hockacke.y"
{ maq.code("ne"); }
break;
case 32:
//#line 107 "Hockacke.y"
{ maq.code("gt"); }
break;
case 33:
//#line 108 "Hockacke.y"
{ maq.code("ge"); }
break;
case 34:
//#line 109 "Hockacke.y"
{ maq.code("lt"); }
break;
case 35:
//#line 110 "Hockacke.y"
{ maq.code("le"); }
break;
case 36:
//#line 111 "Hockacke.y"
{ maq.code("and"); }
break;
case 37:
//#line 112 "Hockacke.y"
{ maq.code("or"); }
break;
case 38:
//#line 113 "Hockacke.y"
{ yyval = val_peek(0); maq.code("not"); }
break;
//#line 842 "Parser.java"
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
