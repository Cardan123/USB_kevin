%{
import java.io.*;
import java.lang.Math;
import java.util.StringTokenizer;
import java.lang.reflect.*;
%}
%token TURN NUMBER
%token SEW
%%
list:
	| list '\n'
	| list quilt '\n' { ejecuta1("print", $2.obj); }
	;
quilt:	  'A'	{ $$ = new  ParserVal( ejecuta11_("A", "Quilt") ); }
	| 'B'	{ $$ = new  ParserVal( ejecuta11_("B", "Quilt") ); }
	| TURN '(' quilt ')' 	{ 
              $$ = new  ParserVal( ejecuta11("rota", $3.obj) ); }
	| SEW '(' quilt ',' quilt ')'	
             {
              $$ = new  ParserVal(ejecuta2("cose", $3.obj, $5.obj)); 
             }
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
void ejecuta1(String oper, Object opdo){
   Method metodo;
   Object ret;
   try {
      metodo=opdo.getClass().getDeclaredMethod(oper, null);
      metodo.invoke(opdo, null);
   } catch(NoSuchMethodException e){
      System.out.println("No metodo "+e+ "instru "+oper);
   } catch(InvocationTargetException e){
      System.out.println(e);
   }  catch(IllegalAccessException e){
      System.out.println(e);
   } 
}
Object ejecuta11(String oper, Object opdo){
   Method metodo;
   Object ret;
   try {
      metodo=opdo.getClass().getDeclaredMethod(oper, null);
      ret = metodo.invoke(opdo, null);
   } catch(NoSuchMethodException e){
      System.out.println("No metodo "+e+ "instru "+oper);
      return null;
   } catch(InvocationTargetException e){
      System.out.println(e);
      return null;
   }  catch(IllegalAccessException e){
      System.out.println(e);
      return null;
   } 
   return ret;
}
Object ejecuta11_(String oper, String className){
   Method metodo;
   Object ret;
   try {
      metodo=Class.forName(className).getDeclaredMethod(oper, null);
      ret = metodo.invoke(null, null);
   } catch(ClassNotFoundException e){
      System.out.println(e);
      return null;
   } catch(NoSuchMethodException e){
      System.out.println("No metodo "+e+ "instru "+oper);
      return null;
   } catch(InvocationTargetException e){
      System.out.println(e);
      return null;
   }  catch(IllegalAccessException e){
      System.out.println(e);
      return null;
   } 
   return ret;
}
Object ejecuta2(String oper, Object opdo1, Object opdo2){
   Method metodo;
   Object ret;
   Class paramC[] ;
   Object param[] = new Object[1];

   paramC = new Class[1];
   paramC[0] = opdo2.getClass();
   param[0] = opdo2;
   try {
      metodo=opdo1.getClass().getDeclaredMethod(oper, paramC);
      ret=metodo.invoke(opdo1, param);
   } catch(NoSuchMethodException e){
      System.out.println("No metodo "+e+ "instru "+oper);
      return null;
   } catch(InvocationTargetException e){
      System.out.println(e);
      return null;
   } catch(IllegalAccessException e){
      System.out.println(e);
      return null;
   }
   return ret;
}

