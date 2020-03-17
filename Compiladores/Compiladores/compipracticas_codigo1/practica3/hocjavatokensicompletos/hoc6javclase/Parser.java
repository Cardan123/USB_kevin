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






//#line 3 "hoc6j.y"
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
public final static short FUNCTION=265;
public final static short PROCEDURE=266;
public final static short RETURN=267;
public final static short FUNC=268;
public final static short PROC=269;
public final static short ARG=270;
public final static short OR=271;
public final static short AND=272;
public final static short GT=273;
public final static short LT=274;
public final static short EQ=275;
public final static short UNARYMINUS=276;
public final static short NOT=277;
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    9,    8,   11,
    5,   10,   12,   12,   12,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    7,    7,   14,    1,   15,    1,
   13,   13,   13,    6,    6,    6,
};
final static short yylen[] = {                            2,
    0,    2,    3,    3,    3,    3,    3,    3,    1,    1,
    2,    5,    2,    4,    4,    7,    3,    3,    1,    1,
    0,    0,    0,    2,    2,    1,    1,    1,    1,    5,
    4,    3,    3,    3,    3,    3,    3,    2,    3,    3,
    3,    3,    3,    2,    1,    3,    0,    6,    0,    6,
    1,    1,    1,    0,    1,    3,
};
final static short yydefred[] = {                         1,
    0,   26,    0,    0,    0,   19,   20,   21,   21,    0,
    0,    0,    0,    0,    0,    2,    0,   23,    0,    0,
    0,    0,    0,    0,   29,    0,    0,    0,    0,    0,
    0,    0,   51,   52,   53,   47,   49,    0,    0,    0,
    0,    0,    3,    4,    5,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    6,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   37,   24,   17,
   25,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   22,   22,    0,   31,    0,    0,    0,
    0,    0,   18,   14,    0,   30,    0,   12,    0,    0,
    0,    0,   48,   50,   22,   16,
};
final static short yydgoto[] = {                          1,
   19,   25,   21,   72,   30,   89,   27,   23,   58,   94,
   24,   42,   36,   65,   66,
};
final static short yysindex[] = {                         0,
  812,    0,  -32,  -60,  -36,    0,    0,    0,    0,  -32,
 -250, -250,  -55,  -32,  -32,    0,  -32,    0,  -52,    2,
   18,  138,    4,    4,    0,  538,   -8,  -32,  -32,    5,
    6,  538,    0,    0,    0,    0,    0,  -32,  -54,  -54,
  172,  921,    0,    0,    0,  -32,  -32,  -32,  -32,  -32,
  -32,  -32,  -32,  -32,  -32,    0,  -32,  892,  892,  -32,
  538,  504,  -32,  -32,    7,    8,  538,    0,    0,    0,
    0,  538,  848,  150,   -4,   -4,   -4,  -37,  -37,  -54,
  -54,  -54,  517,    0,    0,  538,    0,  538,  -30,  -24,
    9,   21,    0,    0, -200,    0,  -32,    0,  892,  892,
  892,  538,    0,    0,    0,    0,
};
final static short yyrindex[] = {                         0,
    0,    0,    0,  -10,    0,    0,    0,    0,    0,  701,
    0,    0,   11,    0,    0,    0,    0,    0,    0,  813,
    0,    0,    0,    0,    0,  759,  775,    0,    0,    0,
    0,  833,    0,    0,    0,    0,    0,    0,   32,   53,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  722,    0,  -19,  -19,    0,    0,  743,    0,    0,    0,
    0,  849,  484,  463,  398,  419,  442,  356,  377,   76,
   97,  118,    0,    0,    0,  791,    0,  -17,    0,    0,
    0,    0,    0,    0,  870,    0,    0,    0,    0,    0,
    0,  -15,    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
    0,   64,  -40, 1189,   57,    3,    0,    0,   44,  -82,
    0,    0,   59,    0,    0,
};
final static int YYTABLESIZE=1286;
static short yytable[];
static { yytable();}
static void yytable(){
yytable = new short[]{                         27,
   28,   71,   95,   29,   53,   38,   43,   17,   33,   54,
   96,   44,   14,   97,   34,   35,   98,   84,   85,   97,
   28,   54,  106,   55,   54,   56,   55,   45,   56,   27,
   27,   27,   27,   27,   27,   60,   27,   53,   51,   55,
   52,   38,   54,   57,   63,   64,   91,   92,   27,   99,
   28,   28,   28,   28,   28,   28,   55,   28,  103,  104,
  105,  100,   44,  101,   20,   31,   90,   59,    0,   28,
   37,   38,   38,   38,   38,   38,   38,    0,   38,    0,
    0,    0,    0,   27,    0,   34,    0,    0,    0,   55,
   38,    0,   44,   44,   44,   44,   44,   44,    0,   44,
    0,    0,    0,    0,   28,    0,   35,    0,    0,    0,
    0,   44,   27,    0,   27,   34,   34,   34,   34,   34,
   34,    0,   34,    0,    0,    0,    0,   36,    0,    0,
    0,    0,    0,   28,   34,   28,   35,   35,   35,   35,
   35,   35,    0,   35,    0,    0,    0,   56,    0,    0,
    0,    0,    0,    0,   38,   35,   38,   36,   36,   36,
   36,   36,   36,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   44,   36,   44,    0,   53,
   51,    0,   52,    0,   54,    0,    0,    0,    0,    0,
    0,   53,   51,    0,   52,    0,   54,    0,   34,    0,
   34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   68,   53,   51,    0,   52,    0,   54,   35,
    0,   35,    0,    0,    2,    0,    4,    5,    0,    0,
    0,   55,    8,    0,    0,    0,    0,   13,    0,    0,
   36,    0,   36,   55,   15,    0,   27,   27,   27,   27,
    0,   27,   27,   27,   27,   27,   27,    0,    0,   27,
   27,   27,   27,   27,   27,   55,   27,   28,   28,   28,
   28,    0,   28,   28,   28,   28,   28,   28,    0,    0,
   28,   28,   28,   28,   28,   28,    0,   28,   38,   38,
   38,   38,    0,   38,   38,   38,   38,   38,   38,    0,
    0,   38,   38,   38,   38,   38,   38,    0,   38,   44,
   44,   44,   44,    0,   44,   44,   44,   44,   44,   44,
    0,    0,   44,   44,   44,   44,   44,   44,    0,   44,
    0,    0,   34,   34,   34,   34,    0,   34,   34,   34,
   34,   34,   34,    0,    0,   34,   34,   34,   34,   34,
   34,    0,   34,   35,   35,   35,   35,    0,   35,   35,
   35,   35,   35,   35,    0,   32,   35,   35,   35,   35,
   35,   35,    0,   35,   36,   36,   36,   36,    0,   36,
   36,   36,   36,   36,   36,    0,   33,   36,   36,   36,
   36,   36,   36,    0,   36,   32,   32,    0,   32,   32,
   32,    0,    0,    0,    0,    0,    0,   40,   46,   47,
   48,   49,   50,    0,   32,    0,   33,   33,    0,   33,
   33,   33,   48,   49,   50,    0,    0,    0,   41,    0,
    0,    0,    0,    0,    0,   33,    0,   40,   40,    0,
    0,   40,   46,   47,   48,   49,   50,    0,    0,    0,
    0,   39,    0,    0,    0,    0,   40,    0,   41,   41,
    0,    0,   41,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   42,    0,    0,    0,    0,   41,   32,    0,
   32,   39,   39,    0,    0,   39,    0,    0,    0,    0,
    0,    0,    0,   43,    0,    0,    0,    0,    0,   33,
   39,   33,   42,   42,    0,    0,   42,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   40,   42,   40,   43,   43,    0,    0,   43,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   41,   43,   41,   87,   53,   51,    0,   52,    0,
   54,    0,    0,    0,    0,    0,    0,   93,   53,   51,
    0,   52,    0,   54,   39,    0,   39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   53,
   51,    0,   52,    0,   54,   42,    0,   42,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   55,    0,    0,
    0,    0,    0,    0,    0,    0,   43,    0,   43,    0,
   55,    0,   32,   32,   32,   32,    0,   32,   32,   32,
   32,   32,   32,    0,    0,   32,   32,   32,   32,   32,
   32,   55,   32,   33,   33,   33,   33,    0,   33,   33,
   33,   33,   33,   33,    0,    0,   33,   33,   33,   33,
   33,   33,    0,   33,   40,   40,   40,   40,    0,   40,
   40,   40,   40,   40,   40,    0,    0,   40,   40,   40,
   40,   40,   40,    0,   40,   41,   41,   41,   41,    0,
   41,   41,   41,   41,   41,   41,    0,    0,   41,   41,
   41,   41,   41,   41,    0,   41,    0,    0,   39,   39,
   39,   39,    0,   39,   39,   39,   39,   39,   39,    0,
   10,   39,   39,   39,   39,   39,   39,    0,   39,   42,
   42,   42,   42,    0,   42,   42,   42,   42,   42,   42,
    0,    7,   42,   42,   42,    0,    0,    0,    0,   42,
   43,   43,   43,   43,    0,   43,   43,   43,   43,   43,
   43,    0,    8,   43,   43,    0,    0,    0,    0,   10,
   43,    7,    7,    0,    0,    7,    0,    0,   45,    0,
    0,    0,    0,    0,   46,   47,   48,   49,   50,    0,
    7,    0,    8,    8,   13,    0,    8,   46,   47,   48,
   49,   50,    0,    0,    0,    0,    0,    0,   45,    0,
   46,    8,   45,    0,    0,    0,    0,    0,   46,   47,
   48,   49,   50,    0,   13,    0,    0,   45,    0,   13,
    0,   16,    0,   10,    0,   10,    0,    0,    0,    0,
   46,    0,    0,   13,   46,    0,    0,    0,    0,    0,
    0,    0,   11,    0,    7,    0,    7,    0,    0,   46,
    0,   17,    0,    0,   29,   29,   14,   29,    9,   29,
    0,    0,    0,    0,    0,    8,    0,    8,    0,    0,
    0,    0,   11,    0,    0,    0,    0,    0,    0,   15,
    0,   45,    0,   45,    0,    0,    0,    0,    9,   53,
   51,   11,   52,    0,   54,    0,    0,   13,    0,   13,
    0,    0,    0,    0,    0,    0,   29,    9,    0,   15,
    0,    0,    0,   46,   15,   46,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   15,    0,
   69,   17,    0,    0,   18,    0,   14,    0,    0,    0,
    0,   55,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   11,    0,   11,   10,    0,
   17,    0,   10,   10,   10,   14,   10,   10,    0,    0,
    0,    9,    0,    9,    0,    0,    0,    0,    7,    7,
    7,    7,    0,    7,    7,    7,    7,    7,    7,    0,
    0,    7,   15,    0,   15,    0,    0,    0,    7,    8,
    8,    8,    8,    0,    8,    8,    8,    8,    8,    8,
    0,    0,    8,    0,   18,   45,   45,   45,   45,    8,
   45,   45,   45,   45,   45,   45,    0,    0,   45,    0,
    0,   13,   13,   13,   13,   45,   13,   13,   13,   13,
   13,   13,    0,   18,   13,   70,    0,   46,   46,   46,
   46,   13,   46,   46,   46,   46,   46,   46,    0,    0,
   46,    0,    0,    0,    0,    0,    0,   46,    2,    3,
    4,    5,    0,    6,    7,    0,    8,    9,   10,   11,
   12,   13,    0,   29,   29,   29,   29,   29,   15,   11,
   11,   11,   11,    0,   11,   11,   11,   11,   11,   11,
    0,    0,   11,    0,    0,    9,    9,    9,    9,   11,
    9,    9,    9,    9,    9,    9,    0,    0,    9,   47,
   48,   49,   50,    0,    0,    9,   15,   15,   15,   15,
    0,   15,   15,    0,   15,   15,   15,    0,    0,   15,
    0,    0,    0,    0,    0,    0,   15,    0,    2,    3,
    4,    5,    0,    6,    7,    0,    8,    9,   10,    0,
    0,   13,    0,    0,    0,    0,    0,    0,   15,    0,
    0,    0,    0,    0,    0,    0,    0,    2,    3,    4,
    5,    0,    6,    7,    0,    8,    9,   10,    0,   22,
   13,   26,    0,    0,    0,    0,    0,   15,   32,    0,
    0,    0,   39,   40,    0,   41,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   61,   62,    0,    0,
    0,    0,    0,    0,    0,    0,   67,    0,    0,    0,
    0,    0,    0,    0,   73,   74,   75,   76,   77,   78,
   79,   80,   81,   82,    0,   83,    0,    0,   86,    0,
    0,   88,   88,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  102,
};
}
static short yycheck[];
static { yycheck(); }
static void yycheck() {
yycheck = new short[] {                         10,
   61,   42,   85,   40,   42,   61,   59,   40,  259,   47,
   41,   10,   45,   44,  265,  266,   41,   58,   59,   44,
   10,   41,  105,   41,   44,   41,   44,   10,   44,   40,
   41,   42,   43,   44,   45,   44,   47,   42,   43,   94,
   45,   10,   47,   40,   40,   40,   40,   40,   59,   41,
   40,   41,   42,   43,   44,   45,   94,   47,   99,  100,
  101,   41,   10,  264,    1,    9,   64,   24,   -1,   59,
   12,   40,   41,   42,   43,   44,   45,   -1,   47,   -1,
   -1,   -1,   -1,   94,   -1,   10,   -1,   -1,   -1,   94,
   59,   -1,   40,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   94,   -1,   10,   -1,   -1,   -1,
   -1,   59,  123,   -1,  125,   40,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,   10,   -1,   -1,
   -1,   -1,   -1,  123,   59,  125,   40,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   10,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   59,  125,   40,   41,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  123,   59,  125,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,  123,
   -1,  125,   -1,   -1,  257,   -1,  259,  260,   -1,   -1,
   -1,   94,  265,   -1,   -1,   -1,   -1,  270,   -1,   -1,
  123,   -1,  125,   94,  277,   -1,  257,  258,  259,  260,
   -1,  262,  263,  264,  265,  266,  267,   -1,   -1,  270,
  271,  272,  273,  274,  275,   94,  277,  257,  258,  259,
  260,   -1,  262,  263,  264,  265,  266,  267,   -1,   -1,
  270,  271,  272,  273,  274,  275,   -1,  277,  257,  258,
  259,  260,   -1,  262,  263,  264,  265,  266,  267,   -1,
   -1,  270,  271,  272,  273,  274,  275,   -1,  277,  257,
  258,  259,  260,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,  277,
   -1,   -1,  257,  258,  259,  260,   -1,  262,  263,  264,
  265,  266,  267,   -1,   -1,  270,  271,  272,  273,  274,
  275,   -1,  277,  257,  258,  259,  260,   -1,  262,  263,
  264,  265,  266,  267,   -1,   10,  270,  271,  272,  273,
  274,  275,   -1,  277,  257,  258,  259,  260,   -1,  262,
  263,  264,  265,  266,  267,   -1,   10,  270,  271,  272,
  273,  274,  275,   -1,  277,   40,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   10,  271,  272,
  273,  274,  275,   -1,   59,   -1,   40,   41,   -1,   43,
   44,   45,  273,  274,  275,   -1,   -1,   -1,   10,   -1,
   -1,   -1,   -1,   -1,   -1,   59,   -1,   40,   41,   -1,
   -1,   44,  271,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,   10,   -1,   -1,   -1,   -1,   59,   -1,   40,   41,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   10,   -1,   -1,   -1,   -1,   59,  123,   -1,
  125,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,  123,
   59,  125,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   59,  125,   40,   41,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   59,  125,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   41,   42,   43,
   -1,   45,   -1,   47,  123,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,
   94,   -1,  257,  258,  259,  260,   -1,  262,  263,  264,
  265,  266,  267,   -1,   -1,  270,  271,  272,  273,  274,
  275,   94,  277,  257,  258,  259,  260,   -1,  262,  263,
  264,  265,  266,  267,   -1,   -1,  270,  271,  272,  273,
  274,  275,   -1,  277,  257,  258,  259,  260,   -1,  262,
  263,  264,  265,  266,  267,   -1,   -1,  270,  271,  272,
  273,  274,  275,   -1,  277,  257,  258,  259,  260,   -1,
  262,  263,  264,  265,  266,  267,   -1,   -1,  270,  271,
  272,  273,  274,  275,   -1,  277,   -1,   -1,  257,  258,
  259,  260,   -1,  262,  263,  264,  265,  266,  267,   -1,
   10,  270,  271,  272,  273,  274,  275,   -1,  277,  257,
  258,  259,  260,   -1,  262,  263,  264,  265,  266,  267,
   -1,   10,  270,  271,  272,   -1,   -1,   -1,   -1,  277,
  257,  258,  259,  260,   -1,  262,  263,  264,  265,  266,
  267,   -1,   10,  270,  271,   -1,   -1,   -1,   -1,   59,
  277,   40,   41,   -1,   -1,   44,   -1,   -1,   10,   -1,
   -1,   -1,   -1,   -1,  271,  272,  273,  274,  275,   -1,
   59,   -1,   40,   41,   10,   -1,   44,  271,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   10,   59,   44,   -1,   -1,   -1,   -1,   -1,  271,  272,
  273,  274,  275,   -1,   40,   -1,   -1,   59,   -1,   45,
   -1,   10,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,
   40,   -1,   -1,   59,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   10,   -1,  123,   -1,  125,   -1,   -1,   59,
   -1,   40,   -1,   -1,   42,   43,   45,   45,   10,   47,
   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,
   -1,   -1,   40,   -1,   -1,   -1,   -1,   -1,   -1,   10,
   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   40,   42,
   43,   59,   45,   -1,   47,   -1,   -1,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   94,   59,   -1,   40,
   -1,   -1,   -1,  123,   45,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   -1,
   10,   40,   -1,   -1,  123,   -1,   45,   -1,   -1,   -1,
   -1,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,  258,   -1,
   40,   -1,  262,  263,  264,   45,  266,  267,   -1,   -1,
   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,   -1,  262,  263,  264,  265,  266,  267,   -1,
   -1,  270,  123,   -1,  125,   -1,   -1,   -1,  277,  257,
  258,  259,  260,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,  270,   -1,  123,  257,  258,  259,  260,  277,
  262,  263,  264,  265,  266,  267,   -1,   -1,  270,   -1,
   -1,  257,  258,  259,  260,  277,  262,  263,  264,  265,
  266,  267,   -1,  123,  270,  125,   -1,  257,  258,  259,
  260,  277,  262,  263,  264,  265,  266,  267,   -1,   -1,
  270,   -1,   -1,   -1,   -1,   -1,   -1,  277,  257,  258,
  259,  260,   -1,  262,  263,   -1,  265,  266,  267,  268,
  269,  270,   -1,  271,  272,  273,  274,  275,  277,  257,
  258,  259,  260,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,  270,   -1,   -1,  257,  258,  259,  260,  277,
  262,  263,  264,  265,  266,  267,   -1,   -1,  270,  272,
  273,  274,  275,   -1,   -1,  277,  257,  258,  259,  260,
   -1,  262,  263,   -1,  265,  266,  267,   -1,   -1,  270,
   -1,   -1,   -1,   -1,   -1,   -1,  277,   -1,  257,  258,
  259,  260,   -1,  262,  263,   -1,  265,  266,  267,   -1,
   -1,  270,   -1,   -1,   -1,   -1,   -1,   -1,  277,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,   -1,  262,  263,   -1,  265,  266,  267,   -1,    1,
  270,    3,   -1,   -1,   -1,   -1,   -1,  277,   10,   -1,
   -1,   -1,   14,   15,   -1,   17,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   28,   29,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   46,   47,   48,   49,   50,   51,
   52,   53,   54,   55,   -1,   57,   -1,   -1,   60,   -1,
   -1,   63,   64,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   97,
};
}
final static short YYFINAL=1;
final static short YYMAXTOKEN=277;
final static String yyname[] = {
"end-of-file",null,null,null,null,null,null,null,null,null,"'\\n'",null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,"'('","')'","'*'","'+'",
"','","'-'",null,"'/'",null,null,null,null,null,null,null,null,null,null,null,
"';'",null,"'='",null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,"'^'",null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,"'{'",null,"'}'",null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,"NUMBER","PRINT","VAR","BLTIN",
"INDEF","WHILE","IF","ELSE","FUNCTION","PROCEDURE","RETURN","FUNC","PROC","ARG",
"OR","AND","GT","LT","EQ","UNARYMINUS","NOT",
};
final static String yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list defn ';'",
"list : list asgn '\\n'",
"list : list stmt '\\n'",
"list : list expr '\\n'",
"asgn : VAR '=' expr",
"asgn : ARG '=' expr",
"stmt : expr",
"stmt : RETURN",
"stmt : RETURN expr",
"stmt : PROCEDURE begin '(' arglist ')'",
"stmt : PRINT prlist",
"stmt : while cond stmt end",
"stmt : if cond stmt end",
"stmt : if cond stmt end ELSE stmt end",
"stmt : '{' stmtlist '}'",
"cond : '(' expr ')'",
"while : WHILE",
"if : IF",
"begin :",
"end :",
"stmtlist :",
"stmtlist : stmtlist '\\n'",
"stmtlist : stmtlist stmt",
"expr : NUMBER",
"expr : VAR",
"expr : ARG",
"expr : asgn",
"expr : FUNCTION begin '(' arglist ')'",
"expr : BLTIN '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '^' expr",
"expr : '(' expr ')'",
"expr : '-' expr",
"expr : expr EQ expr",
"expr : expr GT expr",
"expr : expr LT expr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",
"prlist : expr",
"prlist : prlist ',' expr",
"$$1 :",
"defn : FUNC procname $$1 '(' ')' stmt",
"$$2 :",
"defn : PROC procname $$2 '(' ')' stmt",
"procname : VAR",
"procname : FUNCTION",
"procname : PROCEDURE",
"arglist :",
"arglist : expr",
"arglist : arglist ',' expr",
};

//#line 166 "hoc6j.y"
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
boolean indef;
static Tabla tabla;
static Maquina maq;

static String ins;
static StringTokenizer st;

void yyerror(String s){
 System.out.println("parser:"+s);
}
void defnonly(String s){
	if(!indef)
		System.out.println(s+" usado fuera de la definicion");
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
      if(Character.isJavaLetter(s.charAt(0))&& s.charAt(0)!='$'){
         if((simbo=tabla.lookup(s))== null)
	    simbo=tabla.install(s, INDEF, 0.0);
         yylval = new ParserVal(new Algo(simbo, 0));
         //System.out.println("tok act tipo: ("+simbo.tipo+" )");
	 tok= (simbo.tipo == INDEF ? VAR : simbo.tipo);	
      }
      else if(s.charAt(0) == '$'){
 //System.out.println("tok act tipo: ARG < "+s.substring(1)+" >");
	yylval = new ParserVal((int)Integer.parseInt(s.substring(1)));
                    tok= ARG;
      }
      else if(s.charAt(0) == '#'){
                    tok= EQ;
      }
      else if(s.charAt(0) == '<'){
                    tok= LT;
      }
      else if(s.charAt(0) == '>'){
                    tok= GT;
      }
      else if(s.charAt(0) == '!'){
                    tok= NOT;
      }	
      else if(s.charAt(0) == '|'){
                    tok= OR;
      }
      else if(s.charAt(0) == '&'){
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
   tabla.install("tan",BLTIN, 0.0);
   tabla.install("asin",BLTIN, 0.0);
   tabla.install("acos",BLTIN, 0.0);
   tabla.install("atan",BLTIN, 0.0);
   tabla.install("exp",BLTIN, 0.0);
   tabla.install("log",BLTIN, 0.0);
   tabla.install("sqrt",BLTIN, 0.0);
   tabla.install("if", IF, 0.0);
   tabla.install("else", ELSE, 0.0);
   tabla.install("while", WHILE, 0.0);
   tabla.install("print", PRINT, 0.0);
   tabla.install("proc", PROC, 0.0);
   tabla.install("func", FUNC, 0.0);
   tabla.install("return", RETURN, 0.0);
   System.out.println("Hoc6");
   Parser par = new Parser(false);
   System.out.print("expression:");
   try{
      ins = in.readLine();
   } catch (Exception e){}
   st = new StringTokenizer(ins);
   newline=false;
   for(maq.initcode(); par.yyparse ()!=0; maq.initcode()){
      //maq.execute(maq.progbase);
      maq.execute(maq.getProgBase());
      System.out.print("expression:");
      try{
         ins = in.readLine();
      } catch (Exception e){}
      st = new StringTokenizer(ins);  
      newline=false;
   }		
}



//#line 658 "Parser.java"
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
//#line 22 "hoc6j.y"
{ maq.code("pop"); 
                  maq.code("STOP"); return 1 ;}
//break;
case 5:
//#line 24 "hoc6j.y"
{ maq.code("STOP"); return 1 ;}
//break;
case 6:
//#line 25 "hoc6j.y"
{ maq.code("print"); 
                  maq.code("STOP"); return 1 ;}
//break;
case 7:
//#line 28 "hoc6j.y"
{ 
           yyval=val_peek(0); maq.code("varpush"); 
                  maq.code(((Algo)val_peek(2).obj).simb); 
		  maq.code("assign");
	}
break;
case 8:
//#line 34 "hoc6j.y"
{ 
        defnonly("$");     
        /*code2(argassign,(Inst)$1); */
        maq.code("argassign"); 
        maq.code(val_peek(2).ival+"");
        yyval=val_peek(0);
      }
break;
case 9:
//#line 42 "hoc6j.y"
{ 
                  maq.code("pop");}
break;
case 10:
//#line 44 "hoc6j.y"
{ defnonly("return"); maq.code("procret"); }
break;
case 11:
//#line 46 "hoc6j.y"
{ defnonly( "return" ); yyval = val_peek(0); maq.code("funcret") ; }
break;
case 12:
//#line 48 "hoc6j.y"
{ yyval = val_peek(3); 
            maq.code("call"); 
            maq.code(((Algo)val_peek(4).obj).simb); 
            maq.code(val_peek(1).ival+"");
    }
break;
case 13:
//#line 53 "hoc6j.y"
{ yyval = val_peek(0); }
break;
case 14:
//#line 54 "hoc6j.y"
{
             maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(1).obj).inst),
                 ((Algo)val_peek(3).obj).inst+1); 
             maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(0).obj).inst),
                 ((Algo)val_peek(3).obj).inst+2); 
		 }
break;
case 15:
//#line 62 "hoc6j.y"
{   
                 maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(1).obj).inst),
                 ((Algo)val_peek(3).obj).inst+1); 
                 maq.getProg().setElementAt(
                 new Integer(((Algo)val_peek(0).obj).inst),
                 ((Algo)val_peek(3).obj).inst+3); 
                  }
break;
case 16:
//#line 70 "hoc6j.y"
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
case 17:
//#line 81 "hoc6j.y"
{  
                  yyval  =  val_peek(1); 
                  }
break;
case 18:
//#line 85 "hoc6j.y"
{   maq.code("STOP");  
         ((Algo)yyval.obj).inst = ((Algo)val_peek(1).obj).inst;/*checar*/
    }
break;
case 19:
//#line 89 "hoc6j.y"
{   
  yyval = new ParserVal(new Algo(maq.code("whilecode"))); 
        maq.code("STOP");maq.code("STOP");
        }
break;
case 20:
//#line 94 "hoc6j.y"
{ /*$$ = code(ifcode); code3(STOP,STOP,STOP);*/
  yyval = new ParserVal(new Algo(maq.code("ifcode"))); 
        maq.code("STOP");maq.code("STOP");maq.code("STOP");
        }
break;
case 21:
//#line 99 "hoc6j.y"
{ 
        yyval=new ParserVal(new Algo(maq.getProgP()));
        /*$$ = new ParserVal(maq.getProgP()); */
        }
break;
case 22:
//#line 104 "hoc6j.y"
{ maq.code("STOP"); 
 yyval=new ParserVal(new Algo(maq.getProgP()));
 /*$$=new ParserVal(maq.getProgP());        */
        }
break;
case 23:
//#line 109 "hoc6j.y"
{   
  yyval=new ParserVal(new Algo(maq.getProgP()));          
  /*$$=new ParserVal(maq.getProgP());  */
        }
break;
case 26:
//#line 116 "hoc6j.y"
{ ((Algo)yyval.obj).inst=maq.code("constpush");
                maq.code(((Algo)val_peek(0).obj).simb); }
break;
case 27:
//#line 118 "hoc6j.y"
{ ((Algo)yyval.obj).inst=maq.code("varpush");
                maq.code(((Algo)val_peek(0).obj).simb); maq.code("eval");}
break;
case 28:
//#line 120 "hoc6j.y"
{   
          defnonly("$"); 
          /*$$ = code2(arg, (Inst)$1);      */
          /*erroneo ((Algo)$$.obj).inst= maq.code("arg"); */
          yyval = new ParserVal(new Algo(maq.code("arg"))); 
          maq.code(val_peek(0).ival+"");
          }
break;
case 30:
//#line 129 "hoc6j.y"
{ yyval = val_peek(3); 
             maq.code("call"); 
             maq.code(((Algo)val_peek(4).obj).simb); 
             maq.code(val_peek(1).ival+"");
        }
break;
case 31:
//#line 134 "hoc6j.y"
{ yyval=val_peek(1); maq.code("bltin"); maq.code(((Algo)val_peek(3).obj).simb); }
break;
case 32:
//#line 135 "hoc6j.y"
{ maq.code("add");}
break;
case 33:
//#line 136 "hoc6j.y"
{ maq.code("sub"); }
break;
case 34:
//#line 137 "hoc6j.y"
{ maq.code("mul");}
break;
case 35:
//#line 138 "hoc6j.y"
{ maq.code("div"); }
break;
case 36:
//#line 139 "hoc6j.y"
{ maq.code("power"); }
break;
case 37:
//#line 140 "hoc6j.y"
{ yyval= val_peek(1);}
break;
case 38:
//#line 141 "hoc6j.y"
{ yyval=val_peek(0); maq.code("negate");}
break;
case 39:
//#line 142 "hoc6j.y"
{ maq.code("eq"); }
break;
case 40:
//#line 143 "hoc6j.y"
{ maq.code("gt"); }
break;
case 41:
//#line 144 "hoc6j.y"
{ maq.code("lt"); }
break;
case 42:
//#line 145 "hoc6j.y"
{ maq.code("and"); }
break;
case 43:
//#line 146 "hoc6j.y"
{ maq.code("or"); }
break;
case 44:
//#line 147 "hoc6j.y"
{ yyval = val_peek(0); maq.code("not"); }
break;
case 45:
//#line 149 "hoc6j.y"
{   maq.code("prexpr"); }
break;
case 46:
//#line 150 "hoc6j.y"
{   maq.code("prexpr"); }
break;
case 47:
//#line 152 "hoc6j.y"
{ ((Algo)val_peek(0).obj).simb.tipo=FUNCTION; indef=true; }
break;
case 48:
//#line 153 "hoc6j.y"
{ maq.code("procret"); maq.define(((Algo)val_peek(4).obj).simb); indef=false; }
break;
case 49:
//#line 154 "hoc6j.y"
{ ((Algo)val_peek(0).obj).simb.tipo=PROCEDURE; indef=true; }
break;
case 50:
//#line 155 "hoc6j.y"
{ maq.code("procret"); maq.define(((Algo)val_peek(4).obj).simb); indef=false; }
break;
case 54:
//#line 161 "hoc6j.y"
{ yyval = new ParserVal(0); }
break;
case 55:
//#line 162 "hoc6j.y"
{ yyval = new ParserVal(1); }
break;
case 56:
//#line 163 "hoc6j.y"
{ yyval =  new ParserVal(val_peek(2).ival + 1); }
break;
//#line 1067 "Parser.java"
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
