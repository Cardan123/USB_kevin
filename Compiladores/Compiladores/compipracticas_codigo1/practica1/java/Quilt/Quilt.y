%{
import java.io.*;
import java.lang.Math;
import java.util.HashMap;
import java.util.StringTokenizer;
%}
%token TURN NUMBER
%token SEW
%%
list:
	| list '\n'
	| list quilt '\n' { ((Quilt)$2.obj).print(); }
	;
quilt:	  'A'	{ $$ = new  ParserVal( Quilt.A() )	; }
	| 'B'	{ $$ = new  ParserVal( Quilt.B() ); }
	| TURN '(' quilt ')' 	{ 
              $$ = new  ParserVal( ((Quilt)$3.obj).rota() ); }
	| SEW '(' quilt ',' quilt ')'	
             { $$ = new  ParserVal( 
              ((Quilt)$3.obj).cose( (Quilt)$5.obj  )); }
	;
%%
String ins;
StringTokenizer st;

void yyerror(String s) {
	System.out.println("par:"+s);
}

boolean newline;

int yylex(){
String s;
int tok=NUMBER;
Double d;
  if (!st.hasMoreTokens())
    if (!newline){
        newline=true;
        //System.out.println("new:"+newline);
        return '\n'; //So we look like classic YACC example
    }
    else
      return 0;
  s = st.nextToken();
  //System.out.println("tok:"+s);
  try {
    d = Double.valueOf(s);
    //yylval = new ParserVal(new Algo(tabla.install("", NUMBER, d.doubleValue()),0) );
    tok = NUMBER;
  } catch (Exception e) {
    if(Character.isLetter(s.charAt(0))){
       //System.out.println(" letra "+s.charAt(0));
       if (s.equals("rota")){
          //System.out.println("gira "+s);
          tok = TURN;
       }
       if (s.equals("cose"))
          tok = SEW;
       if (s.equals("A")){
          //System.out.println("vi A");
          tok = 'A';
       }
       if (s.equals("B"))
           tok = 'B';
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
void dotest(){
   BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
   while (true){
      System.out.print("expression:");
      try {
         ins = in.readLine();
      } catch (Exception e){}
      st = new StringTokenizer(ins);
      newline=false;
      yyparse();
   }
}
public static void main(String args[]) {
        Parser par = new Parser(false);
        par.dotest();
}
