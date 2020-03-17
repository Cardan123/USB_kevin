%{
import java.io.*;
import java.util.StringTokenizer;
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%% 
list:   
   | list'\n'
   | list exp '\n'  { ((Vector)$2.obj).imprime(); }
	;
exp: vector          { $$ = $1;  }
   | exp '+' exp     { $$ = new ParserVal(
                            ((Vector)$1.obj).suma( (Vector)$3.obj ) );  
                     }
   | exp '-' exp     { $$ = new ParserVal(
                            ((Vector)$1.obj).resta( (Vector)$3.obj ) );  
                     }
   | '(' exp ')'     { $$ = $2;}
   ;
vector : '[' NUMBER NUMBER NUMBER ']' {
      double[] eltos = new double[3];
      eltos[0] = $2.ival;
      eltos[1] = $3.ival;
      eltos[2] = $4.ival;
      $$ = new ParserVal(new Vector(eltos));
   }
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




