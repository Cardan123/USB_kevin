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

%%

line: '\n'
 | exp '\n' { maquina.code("imprime"); maquina.code("STOP"); }
 | asgn '\n' { maquina.code("STOP"); }
 ;

 asgn:
 VAR '=' exp { maquina.code($1.sval); maquina.code("asignar"); }
 ;

 exp: '<' NUM ',' NUM 'j' '>' {maquina.code(new Complejo($2.dval,$4.dval));}

 | VAR { maquina.code($1.sval); maquina.code("valorVariable");}
 | BLTIN '(' exp ')' {maquina.code($1.sval);}
 | exp '+' exp { maquina.code("suma");}
 | exp '-' exp { maquina.code("resta"); }
 | exp '*' exp { maquina.code("multiplicacion"); }
 | exp '/' exp { maquina.code("division"); }
 | '(' exp ')' { $$ = new ParserVal((Complejo)$2.obj); }
 ; 

%%

String ins,nombreVariable="";
StringTokenizer st;
Maquina maquina;

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
			if(maquina.tabla.lookup(s)==null){
				tok=VAR;
			}else{
				tok=(maquina.tabla.lookup(s)).tipo;
			}
    	}else {
    		tok = s.charAt(0);
    	}
	}
		return tok;
}

void dotest(){
	maquina.tabla.install("sin",BLTIN, new Complejo(0,0));
    maquina.tabla.install("cos",BLTIN, new Complejo(0,0));
    maquina.tabla.install("exp",BLTIN, new Complejo(0,0));
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	System.out.println("Calculadora de complejos.\nEj de expresion:   sin ( <2,3j> )\n");
	while (true){
 			System.out.print(":   ");
		try{
			ins = in.readLine();
		}catch (Exception e){
 		}
 		st = new StringTokenizer(makeSt(ins));
 		newline=false;
 		yyparse();
 		maquina.execute();
 	}
}

String makeSt(String ins){
	int i=0;char c;
	String st="";
	while(i<ins.length()){
		c=ins.charAt(i);
		if(c=='<'){
			st+=c+" ";
			while(true){
				i++;
				c=ins.charAt(i);
				if(c=='>'||i==(ins.length()-1)){
					st+=c+" ";
					i++;
					break;
				}else if(c=='-'||Character.isDigit(c)){
					while(c=='-'||Character.isDigit(c)){
						st+=c+"";
						i++;
						c=ins.charAt(i);
					}
					st+=" "+c+" ";
				}else{
					st+=c+" ";
				}
			}
		}else{
			st+=c;
			i++;
		}
	}
	return st;
}

public static void main(String args[]){
	Parser par = new Parser(false);
	par.maquina=new Maquina();
	par.dotest();
}