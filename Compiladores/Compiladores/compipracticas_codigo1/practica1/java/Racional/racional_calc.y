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
   | list exp '\n'  { ((Racional)$2.obj).imprime(); }
	;
exp: rac             { $$ = $1;  }
   | exp '*' exp     { $$ = new ParserVal(
                            ((Racional)$1.obj).mult( (Racional)$3.obj ) );  
                     }
   | exp '/' exp     { $$ = new ParserVal(
                            ((Racional)$1.obj).division( (Racional)$3.obj ) );  
                     }
   | '(' exp ')'     { $$ = $2;}
   ;
rac: NUMBER '|' NUMBER { $$ = new ParserVal(new Racional($1.ival, $3.ival)); }
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




