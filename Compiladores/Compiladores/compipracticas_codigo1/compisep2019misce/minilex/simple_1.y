%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regexp.h"

int yylex(void);
int yyerror(const char*);
struct elemento {
   NodoArb  *nodo;   
   char car;
};
typedef struct elemento Elemento;
#define YYSTYPE struct elemento
char meta[]={'|','*','(',')','[',']','$','.','-','^',':', 0};
int cta=0;
Conjunto *sig[1000];
%}
%token CHAR
//%token ANYNONMETACHAR METACHAR

%left ':'
%left '|'
%left '*'
%%
input: /* vacio */ 
   | input line
   ;
line: '\n'
   | {  
        int i;
        cta = 0 ; 
        for(i=0; i < 1000 ;i++){
           sig[i]=creaConjunto(10);
        }
     } 
     re '\n' { 
          Conjunto *c1, *c2;
          cta=cta+1;
          NodoArb *raiz;
          NodoArb *gato=creaNodoArb(creaNodoI(strdup("#"), cta, 0), NULL, NULL);
          c1=creaConjunto(100);   
          ((NodoI *)gato->info)->last=insertar(c1, 
                      creaNodoI(strdup("#"), cta, 0), cmpNodoNum, copiaNodoI);
          c2=creaConjunto(100);
          ((NodoI *)gato->info)->first=insertar(c2, 
                      creaNodoI(strdup("#"), cta, 0), cmpNodoNum, copiaNodoI);
          raiz= creaNodoArb(creaNodoI(strdup(":"), 0, 0), $2.nodo, gato);
          if(((NodoI *)$2.nodo->info)->anu)
             ((NodoI *)raiz->info)->first=
                    insertar(((NodoI *)$2.nodo->info)->first, 
                     creaNodoI(strdup("#"), cta, 0), cmpNodoNum , copiaNodoI);
          else
             ((NodoI *)raiz->info)->first=((NodoI *)$2.nodo->info)->first;
          
          ((NodoI *)raiz->info)->last=((NodoI *)gato->info)->last;

          imprimeArb(raiz, imprimeNodoII); puts("*****SIGSIGSIG "); 
          followPos(raiz); impriSig(); 
          crearEstados($2.nodo);
     }
   ;
re: re ':' re {
          printf("(%d %d) and = (%d) (%s, %s)",
           ((NodoI *)$1.nodo->info)->anu,
           ((NodoI *)$3.nodo->info)->anu,
           ((NodoI *)$1.nodo->info)->anu && ((NodoI *)$3.nodo->info)->anu,
           ((NodoI *)$1.nodo->info)->id,
           ((NodoI *)$3.nodo->info)->id
          );
          $$.nodo = creaNodoArb(creaNodoI(strdup(":"), cta,
                    ((NodoI *)$1.nodo->info)->anu && ((NodoI *)$3.nodo->info)->anu),
                    $1.nodo, $3.nodo);
          if(((NodoI *)$1.nodo->info)->anu)
             ((NodoI *)$$.nodo->info)->first=
                        unirConjunto(((NodoI *)$1.nodo->info)->first,
                       ((NodoI *)$3.nodo->info)->first, cmpNodoNum, copiaNodoI);
          else
             ((NodoI *)$$.nodo->info)->first=((NodoI *)$1.nodo->info)->first;
           puts("conj");
          imprimeConjunto(((NodoI *)$$.nodo->info)->first, imprimeNodoI);
          if(((NodoI *)$3.nodo->info)->anu)
             ((NodoI *)$$.nodo->info)->last=
                        unirConjunto(((NodoI *)$1.nodo->info)->last,
                        ((NodoI *)$3.nodo->info)->last, cmpNodoNum, copiaNodoI);
          else
             ((NodoI *)$$.nodo->info)->last=((NodoI *)$3.nodo->info)->last;
   }
   | re '|' re {
       
          $$.nodo = creaNodoArb(creaNodoI(strdup("|"), cta,
                    ((NodoI *)$1.nodo->info)->anu || ((NodoI *)$3.nodo->info)->anu),
                    $1.nodo, $3.nodo);
           puts("1or conj");
           ((NodoI *)$$.nodo->info)->first=
                    unirConjunto(((NodoI *)$1.nodo->info)->first,
                    ((NodoI *)$3.nodo->info)->first, cmpNodoNum, copiaNodoI);
           puts("2or conj");
           ((NodoI *)$$.nodo->info)->last=
                    unirConjunto(((NodoI *)$1.nodo->info)->last,
                    ((NodoI *)$3.nodo->info)->last, cmpNodoNum, copiaNodoI);
   }
   | '*' re {
          $$.nodo = creaNodoArb(creaNodoI(strdup("*"), cta, 1 ),
          $2.nodo, NULL);
          ((NodoI *)$$.nodo->info)->first=((NodoI *)$2.nodo->info)->first;
          ((NodoI *)$$.nodo->info)->last=((NodoI *)$2.nodo->info)->last;
          puts("aster conj");
          imprimeConjunto(((NodoI *)$$.nodo->info)->first, imprimeNodoI);
   }
   | '(' re ')' { $$ = $2; }
   | CHAR {
       Conjunto *c1, *c2;
       char cade[2]={0,0};
       cade[0]=$1.car;
       cta=cta+1;
       $$.nodo = creaNodoArb(creaNodoI(strdup(cade), cta, 0),
                          (NodoArb *)NULL,(NodoArb *)NULL); 
    //$$.nodo->num=cta+1;
       c1=creaConjunto(100);
       ((NodoI *)$$.nodo->info)->first=insertar(c1, 
          creaNodoI(strdup(cade), cta, 0), cmpNodoNum, copiaNodoI);
       c2=creaConjunto(100);
       ((NodoI *)$$.nodo->info)->last=insertar(c2, 
          creaNodoI(strdup(cade), cta, 0), cmpNodoNum, copiaNodoI);
   }
   ;
%%
void main() {  yyparse();  }
int yyerror(const char* s) { 
   printf("%s\n", s); 
   return 0; 
}

int busca(char c){
   int i;
   for (i = 0; meta[i] ; i++)
      if (meta[i] == c) return 1;
   return 0;
}
int yylex (){
   int c;
   while ((c = getchar ()) == ' ' || c == '\t')  
  		;
   if (c == EOF) return 0;
   if(c != '\n' &&  busca(c)==0 ){
      yylval.car=c;
      return CHAR;
   }
   return c;                                
}
int esHoja(NodoArb *r){
   if(!r->izq && !r->der)
       return 1;
   return 0;
}
NodoArb *creaNodoArb(void *dato,NodoArb *izq,NodoArb *der){
   NodoArb *nvo;
   nvo=(NodoArb *)malloc(sizeof(NodoArb));
   if(!nvo){
      puts("no hay memoria para crear NodoArb");
      return (NodoArb *)NULL;
   }
   nvo->izq=izq;
   nvo->der=der;
   nvo->info=dato;
   return nvo;
}
NodoI *creaNodoI(char *dato, int num, int anu){
   NodoI *nvo;
   nvo=(NodoI *)malloc(sizeof(NodoI));
   if(!nvo){
      puts("no hay memoria para crear NodoArb");
      return (NodoI *)NULL;
   }
   nvo->num=num;
   nvo->anu=anu;
   nvo->id=dato;
   return nvo;
}
void *copiaNodoI(void *p){
   NodoI *nvo=(NodoI *)p;
   return creaNodoI(nvo->id, nvo->num, nvo->anu);
}
void imprimeArb(NodoArb *raiz, void (*f)(void *)){
   if(!raiz) return;
   imprimeArb(raiz->izq,f);
   (*f)(raiz->info);
   imprimeArb(raiz->der,f);       
}
void impriSig(){
   int i;
   for(i=0; i < cta+1 ;i++){
      printf("SIGSIG__ %d  ", i);
      imprimeConjunto(sig[i], imprimeNodoI);
   }
}
int contiene(NodoL *head,  NodoL *tail, Conjunto *ele){
   NodoL *p; 
   puts("1contiene");
   imprimeConjunto( (Conjunto *)head->info, imprimeNodoI);
   puts("2contiene");
   for(p=head; p!=tail; p=p->sig){
      puts("3contiene");
      imprimeConjunto( (Conjunto *)p->info, imprimeNodoI);
      if(iguales((Conjunto *)p->info, ele, cmpNodoNum) ) return 1; 
   }
   if(iguales((Conjunto *)p->info, ele, cmpNodoNum) ) return 1;
   return 0;
}
int cmpNodoNum(void *p1, void *p2){
   NodoI *ni1=(NodoI*)p1;
   NodoI *ni2=(NodoI*)p2;
   return ni1->num - ni2->num;
}
int cmpNodoID(void *p1, void *p2){
   NodoI *ni1=(NodoI*)p1;
   NodoI *ni2=(NodoI*)p2;
   return strcmp(ni1->id, ni2->id);
}
void imprimeNodoI(void *v){
   NodoI *ni=(NodoI *)v;
   puts("imprimeI");
   printf("%s %d ",(char *)ni->id, ni->num);
}
void imprimeNodoII(void *v){
   NodoI *ni=(NodoI *)v;
   puts("imprimeII");
   printf("%s %d %d",(char *)ni->id, ni->num, ni->anu);
}

void imprimeCade(void *s){
   printf(" %s ",(char *)s);
}



