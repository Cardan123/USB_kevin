//byaccj -J hoc5j.y
%{
import java.lang.Math;
import java.io.*;
import java.util.StringTokenizer;
%}
%token  NUMBER PRINT VAR BLTIN INDEF WHILE IF ELSE
%right '='
%left OR
%left AND
%left GT LT EQ
%left '+' '-'
%left '*' '/'
%left UNARYMINUS NOT
%right '^'
%%
list:   
    | list'\n'  
    | list asgn '\n'  { maq.code("pop"); 
                  maq.code("STOP"); return 1 ;}
    | list stmt '\n' { maq.code("STOP"); return 1 ;}
    | list expr '\n'   { maq.code("print"); 
                  maq.code("STOP"); return 1 ;}  
    ;
asgn:	VAR '=' expr { 
           $$=$3; maq.code("varpush"); 
                  maq.code(((Algo)$1.obj).simb); 
		  maq.code("assign");
	}
	;
stmt:     expr   { 
                  maq.code("pop");}
    | PRINT expr { maq.code("prexpr"); 
        ((Algo)$$.obj).inst = ((Algo)$2.obj).inst; } 
    | while cond stmt end {
             maq.getProg().setElementAt(
                 new Integer(((Algo)$3.obj).inst),
                 ((Algo)$1.obj).inst+1); 
             maq.getProg().setElementAt(
                 new Integer(((Algo)$4.obj).inst),
                 ((Algo)$1.obj).inst+2); 
		 }    
        | if cond stmt end {   
                 maq.getProg().setElementAt(
                 new Integer(((Algo)$3.obj).inst),
                 ((Algo)$1.obj).inst+1); 
                 maq.getProg().setElementAt(
                 new Integer(((Algo)$4.obj).inst),
                 ((Algo)$1.obj).inst+3); 
                  }  
	| if cond stmt end ELSE stmt end { 
                 maq.getProg().setElementAt(
                 new Integer(((Algo)$3.obj).inst),
                 ((Algo)$1.obj).inst+1); 
                 maq.getProg().setElementAt(
                 new Integer(((Algo)$6.obj).inst),
                 ((Algo)$1.obj).inst+2);             
                  maq.getProg().setElementAt(
                 new Integer(((Algo)$7.obj).inst),
                ((Algo)$1.obj).inst+3);  
	  } 
	|   '{'  stmtlist  '}' {  
                  $$  =  $2; 
                  }
        ;
cond: '(' expr ')'  {   maq.code("STOP");  
         ((Algo)$$.obj).inst = ((Algo)$2.obj).inst;
    }
;
while:	WHILE   {   
  $$ = new ParserVal(new Algo(maq.code("whilecode"))); 
        maq.code("STOP");maq.code("STOP");
        }
	;
if:IF   { //$$ = code(ifcode); code3(STOP,STOP,STOP);
  $$ = new ParserVal(new Algo(maq.code("ifcode"))); 
        maq.code("STOP");maq.code("STOP");maq.code("STOP");
        }
	;
end:     { maq.code("STOP"); 
 $$=new ParserVal(new Algo(maq.getProg().size()));        
        }
	;
stmtlist: 	{                
  $$=new ParserVal(new Algo(maq.getProg().size()));  
        }
	| stmtlist '\n' 
	| stmtlist stmt 
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
        |expr EQ expr  { maq.code("eq"); }
        |expr GT expr  { maq.code("gt"); }
	|expr LT expr  { maq.code("lt"); }
	|expr AND expr { maq.code("and"); }
	|expr OR expr  { maq.code("or"); }
	|NOT expr      { $$ = $2; maq.code("not"); }
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
      if(Character.isJavaLetter(s.charAt(0))){
         if((simbo=tabla.lookup(s))== null)
	    simbo=tabla.install(s, INDEF, 0.0);
         yylval = new ParserVal(new Algo(simbo, 0));
	 tok= (simbo.tipo == INDEF ? VAR : simbo.tipo);	
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
   System.out.println("Hoc5");
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



