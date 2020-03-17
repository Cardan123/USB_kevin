%{ 
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>

struct colcha {
	int alto;
	int ancho;
	char **mat;
};
typedef struct colcha Colcha;
typedef struct colcha *ColchaAP;



#define YYSTYPE ColchaAP

Colcha *crea(int n, int m);
Colcha *A();
Colcha *B();
void map(int n, int i, int j,int *i_, int *j_);
Colcha *rota(Colcha *orig);
Colcha *cose(Colcha *c1, Colcha *c2);
void print(Colcha *c1);

int yylex(); 

void yyerror(char *s); 

%} 


%token ROTA COSE

%%

list: 
| list '\n' 
| list quilt '\n' { 
	int i,j;
	//printf("%d %d",$2->ancho, $2->alto);
        print($2);
} 
;
 
quilt: 	  'a' { 
		$$=A();
		}
     	| 'b' { 
		
		$$=B(); 
		}
	| ROTA '(' quilt ')' { 
	        $$=rota($3);
		}
	| COSE '(' quilt ',' quilt ')' { 
		if($3->alto!=$5->alto){
			puts("diferente altura");
			exit(0);
		}
		
		$$=cose($3,$5);				
}
	;
%%
