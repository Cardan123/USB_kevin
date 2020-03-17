%{
import java.lang.Math;
import java.io.*;
import java.util.StringTokenizer;
%}

/* Declaracion de Tokens*/
%token NUM /*Token que indica que es un numero*/
%token VAR /*Token que indica que es una variable*/
%token INDEF /*Token para variables indefinidas*/
%token BLTIN /*Token para funciones*/
%right '='
%left '+' '-'
%left '*' '/'

/* Reglas gramaticales */
%%

input: /* empty string */
 | input line
 ;

line: '\n'
 | exp '\n' { System.out.printf("%.2f %+.2fj\n",((Complejo)$1.obj).getReal(), ((Complejo)$1.obj).getImaginario()); }
 | asgn '\n'
 ;

 asgn:
 VAR '=' exp {
 				if(tabla.lookup(nombreVariable)!=null){ 
 					tabla.lookup(nombreVariable,(Complejo)$3.obj);
 				}
 			}
 ;

 exp: '[' NUM '+' NUM 'j' ']' { $$= new ParserVal(new Complejo($2.dval,$4.dval));}
 | VAR { if(tabla.lookup(nombreVariable)!=null){
 			$$ = new ParserVal(tabla.lookup($1.sval).val);
 			}else{
 				this.yyerror("Variable no creada");
 			}
 		}
 | BLTIN '(' exp ')' {switch($1.sval){
						case "sin":
							$$ = new ParserVal(operaciones.seno((Complejo)$3.obj));
						break;
						case "cos":
							$$ = new ParserVal(operaciones.coseno((Complejo)$3.obj));
						break;
						case "ln":
							$$ = new ParserVal(operaciones.ln((Complejo)$3.obj));
						default:
							this.yyerror("Funcion no creada");
						break;
						} 
					}
 | BLTIN '(' exp ',' NUM ')'{$$ = new ParserVal(operaciones.exponencial((Complejo)$3.obj,$5.dval));}
 | exp '+' exp { $$ = new ParserVal(operaciones.suma((Complejo)$1.obj,(Complejo)$3.obj));}
 | exp '-' exp { $$ = new ParserVal(operaciones.resta((Complejo)$1.obj,(Complejo)$3.obj)); }
 | exp '*' exp { $$ = new ParserVal(operaciones.multiplicacion((Complejo)$1.obj,(Complejo)$3.obj)); }
 | exp '/' exp { 	if(((Complejo)$3.obj).getReal()==0 && ((Complejo)$3.obj).getImaginario()==0){
 						this.yyerror("Division entre 0");
 					}else{
 						$$ = new ParserVal(operaciones.division((Complejo)$1.obj,(Complejo)$3.obj));
 					} 
 				}
 | '(' exp ')' { $$ = new ParserVal((Complejo)$2.obj); }
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

String ins,nombreVariable="";
StringTokenizer st;
OperacionesComplejos operaciones = new OperacionesComplejos();
Tabla tabla=new Tabla();


void yyerror(String s){
	System.out.println("par:"+s);
}

boolean newline;
int yylex(){
	String s;
	int tok;
	Double d;
	Simbolo simbo=new Simbolo("",INDEF,new Complejo(0,0));

	if (!st.hasMoreTokens())
	if (!newline){
 		newline=true;
 		return '\n'; 
 	}else{
 		return 0;
 	}
	s = st.nextToken();

 	try{
		d = Double.valueOf(s);
		yylval = new ParserVal(d.doubleValue()); 
		tok = NUM;
	}catch (Exception e){
		if(Character.isLetter(s.charAt(0)) && !s.equals("j")){
			yylval = new ParserVal(s);
			nombreVariable=s;
			if(tabla.lookup(s)==null){tabla.install(s,VAR,new Complejo(0,0));}
			simbo=tabla.lookup(s);
	     	tok= (simbo.tipo==VAR? VAR:simbo.tipo);
	     	//System.out.println("tok:"+tok);
    	}else {
    		tok = s.charAt(0);
    	}
	}
		return tok;
}

void dotest(){
	this.tabla.install("sin",BLTIN, new Complejo(0,0));
    this.tabla.install("cos",BLTIN, new Complejo(0,0));
    this.tabla.install("expo",BLTIN, new Complejo(0,0));
    this.tabla.install("ln",BLTIN, new Complejo(0,0));
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	System.out.println("Ejemplo de expresion: '[ 1 + 2 j ] + [ 5 + 3 j ]' con todo y espacios");
	while (true){
 			System.out.print("expresion:");
		try{
			ins = in.readLine();
		}catch (Exception e){
 		}
 		st = new StringTokenizer(ins);
 		newline=false;
 		yyparse();
 	}
}

public static void main(String args[]){
	Parser par = new Parser(false);
	par.dotest();
}