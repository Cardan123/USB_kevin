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
        System.out.println("new:"+newline);
        return '\n'; //So we look like classic YACC example
    }
    else
      return 0;
  s = st.nextToken();
  System.out.println("tok:"+s);
  try {
    d = Double.valueOf(s);
    //yylval = new ParserVal(new Algo(tabla.install("", NUMBER, d.doubleValue()),0) );
    tok = NUMBER;
  } catch (Exception e) {
    if(Character.isLetter(s.charAt(0))){
                       System.out.println(" letra "+s.charAt(0));
       if (s.equals("rota")){
          System.out.println("gira "+s);
          tok = TURN;
       }
       if (s.equals("cose"))
          tok = SEW;
       if (s.equals("A")){
          System.out.println("vi A");
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
int yylex11() {
	String s;
	int tok=0;
	Double d;

	//s = st.nextToken();

	//s = ins;
	//System.out.println("Cadena leida: "+ins);

        /*if (!st.hasMoreTokens())
           if (!newline){
              newline=true;
           return '\n';
        }
        else
        return 0;*/
        //s = st.nextToken();
	while (!ins.isEmpty() && (ins.charAt(0) == ' ' || ins.charAt(0) == '\t'))
		ins = ins.substring(1);

	if (ins.isEmpty())
		return 0;

	String id = "";
	if (Character.isLetter(ins.charAt(0))) {
                System.out.println(" letra "+ins.charAt(0));
		id += ins.charAt(0);
		for (int i = 1; i < ins.length(); i++) {
			char c = ins.charAt(i);
			if (Character.isLetter(c) || Character.isDigit(c))
				id += c;
			else  {
                                System.out.println(
                               "ya no letra <"+ins.charAt(i)+">");
				break;
                        }
		}
                 System.out.println(
                               "cadena "+id);
                if (id.equals("rota"))
		   return TURN;
	        if (id.equals("cose"))
		   return SEW;
	        if (id.equals("A")){
                   System.out.println("vi A");
		   return 'A';
                }
	        if (id.equals("B"))
		   return 'B';

	} else {
		char c = ins.charAt(0);
                System.out.println("else letra "+ins.charAt(0));
		ins = ins.substring(1);
		tok = c;
	}
        return tok;
	//ins = ins.substring(id.length());

	//-----------------------
	//===yylval = new ParserVal(id);

	/*tok = ins.charAt(0);
	ins = ins.substring(1);
	switch (tok) {
		case 'r': return TURN;
		case 'c': return SEW;
	}*/

	//
}
/*void dotest() {
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	while (true) {
		System.out.print("expression:");
		try {
			ins = in.readLine()+"\n";
		}
		catch (Exception e) { }
		//st = new StringTokenizer(ins);
		newline=false;
		yyparse();
	}
}*/
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
