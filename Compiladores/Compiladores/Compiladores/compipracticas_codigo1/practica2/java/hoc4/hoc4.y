%{
import java.lang.Math;
import java.io.*;
import java.util.StringTokenizer;
%}
%token NUMBER VAR BLTIN INDEF
%right '='
%left '+' '-'
%left '*' '/'
%left UNARYMINUS
%right '^'

%% /* A continuación las reglas gramaticales y las acciones */
list:   
		| list'\n'
		| list asgn '\n'  { maq.code("pop"); maq.code("STOP"); return 1 ;  }
		| list expr '\n'   { maq.code("print"); maq.code("STOP"); return 1 ;}  
	;
asgn:	VAR '=' expr { 
           $$=$3; maq.code("varpush"); 
                  maq.code(((Algo)$1.obj).simb); 
		  maq.code("assign");
	}
	;
expr:     NUMBER  { ((Algo)$$.obj).inst=maq.code("constpush");
                maq.code(((Algo)$1.obj).simb); }
        | VAR { ((Algo)$$.obj).inst=maq.code("varpush");
                maq.code(((Algo)$1.obj).simb); maq.code("eval");}
	| asgn
        | BLTIN '(' expr ')'{ $$=$3; maq.code("bltin"); maq.code(((Algo)$1.obj).simb); }
        | expr '+' expr { maq.code("add");}
        | expr '-' expr { maq.code("sub"); }
        | expr '*' expr { maq.code("mul");}
        | expr '/' expr { maq.code("div"); }
        | expr '^' expr { maq.code("power"); }	
        | '(' expr ')'  { $$= $2;}
        | '-' expr %prec UNARYMINUS { $$=$2; maq.code("negate");}
	;
%%
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
static boolean newline;

public static void main(String args[])
{
 BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
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
 System.out.println("Boolean Calculator Demo");
 Parser par = new Parser(false);
 System.out.print("expression:");
 try{
       ins = in.readLine();
 } catch (Exception e){}
 st = new StringTokenizer(ins);
 newline=false;
 for(maq.initcode(); par.yyparse ()!=0; maq.initcode()){
    maq.execute(maq.progbase);
    System.out.print("expression:");
    try{
       ins = in.readLine();
    } catch (Exception e){}
    st = new StringTokenizer(ins);  
    newline=false;
 }		
}
int yylex(){
String s;
int tok;
Double d;
Simbolo simbo;
  if (!st.hasMoreTokens())
    if (!newline){
        newline=true;
        System.out.println("new:"+newline);
        return '\n'; //So we look like classic YACC example
    }
    else
      return 0;
  s = st.nextToken();
  System.out.println("tok:"+s);
  try {
    d = Double.valueOf(s);
    yylval = new ParserVal(new Algo(tabla.install("", NUMBER, d.doubleValue()),0) );
    tok = NUMBER;
  } catch (Exception e) {
    if(Character.isLetter(s.charAt(0))){
	if((simbo=tabla.lookup(s))==null)
		simbo=tabla.install(s, INDEF, 0.0);
        yylval = new ParserVal(new Algo(simbo, 0));
	tok= (simbo.tipo == INDEF ? VAR : simbo.tipo);	
    }
    else if(s.charAt(0)=='(' || s.charAt(0)==')'){
	tok = s.charAt(0);
    }
    else {
    	tok = s.charAt(0);
    }
  }
  return tok;
}
