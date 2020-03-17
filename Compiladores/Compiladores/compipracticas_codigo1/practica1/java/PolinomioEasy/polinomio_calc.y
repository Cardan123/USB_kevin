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
   | list exp '\n'  { System.out.println((Polynomial)$2.obj); }
   ;
rac: { j=0; } terminos
   ;
poli:  '(' rac ')' { 
                $$ = new ParserVal(new Polynomial(j, auxiliar));
	}
   ;
terminos: NUMBER { 
                 auxiliar[j] = $1.ival; j++;
	}
	| terminos NUMBER { 
                 auxiliar[j] = $2.ival; j++;
	}
   ;
exp: poli            { $$ = $1;  }
   | exp '+' exp     { $$ = new ParserVal(
                           ((Polynomial)$1.obj).add( (Polynomial)$3.obj ) );  
                     }
   | exp '-' exp     { $$ = new ParserVal(
                          ((Polynomial)$1.obj).subtract((Polynomial)$3.obj ) );  
                     }
   | exp '*' exp     { $$ = new ParserVal(
                          ((Polynomial)$1.obj).multiply((Polynomial)$3.obj ) );  
                     }
   | exp '/' exp     { $$ = new ParserVal(
                          ((Polynomial)$1.obj).divide((Polynomial)$3.obj ) );  
                     }
   | exp '%' exp     { $$ = new ParserVal(
                          ((Polynomial)$1.obj).modulo((Polynomial)$3.obj ) );  
                     }
   | '(' exp ')'     { $$ = $2;}
   ;
%%
String ins;
StringTokenizer st;
void yyerror(String s){
   System.out.println("parser error:"+s);
}
boolean newline;
int j = 0;
double [] auxiliar= new double[1000];
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




