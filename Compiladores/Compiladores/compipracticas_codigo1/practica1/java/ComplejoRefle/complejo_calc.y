%{
import java.io.*;
import java.util.StringTokenizer;
import java.lang.reflect.*;
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%% 
list:   
   | list'\n'
   | list exp '\n'  { ejecuta1("imprime", $2.obj);}
	;
exp: rac             { $$ = $1;  }
   | exp '*' exp     {  
                       $$ = new ParserVal(
                            ejecuta2("mult", $1.obj, $3.obj)); 
                     }
   | exp '+' exp     { 
                       $$ = new ParserVal(
                            ejecuta2("sumar", $1.obj, $3.obj));  
                     }
   | '(' exp ')'     { $$ = $2;}
   ;
rac: NUMBER '|' NUMBER { $$ = new ParserVal(new Complejo($1.ival, $3.ival)); }
        ;
%%
String ins;
StringTokenizer st;
void yyerror(String s){
   System.out.println("parser error:"+s);
}
boolean newline;
int yylex(){
   String s;
   int tok;
   Integer ii;
   if (!st.hasMoreTokens())
   if (!newline){
      newline=true;
      return '\n';
   }
   else
      return 0;
   s = st.nextToken();
   //System.out.println("tok:"+s);
   try{
      ii = Integer.valueOf(s);
      yylval = new ParserVal(ii.intValue()); 
      tok = NUMBER;
   } catch (Exception e){ tok = s.charAt(0); }
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
public static void main(String args[]){
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





