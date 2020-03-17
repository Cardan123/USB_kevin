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
char *alfab[]={ "a", "b", NULL};
int tran[100][100];
NodoL *head=(NodoL *)NULL,*tail=(NodoL *)NULL;
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
          sigArb(raiz); impriSig(); 
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
void sigArb(NodoArb *raiz){
   int i, j;
   if(!raiz) return;
   sigArb(raiz->izq);
   if(((NodoI *)raiz->info)->id[0]==':'){
      Conjunto *c1, *c2;
      puts("CAT");
      //if(((NodoI *)raiz->der->info)->id[0]=='#') return;
      c1 = ((NodoI *)raiz->izq->info)->last;
      for(i=0; i < c1->cardinal;i++){
         //((NodoI *)raiz->info)->sig[c1->eltos[i]]=creaConjunto(10);
         puts("CAT c2");
         c2=((NodoI *)raiz->der->info)->first;
         for(j=0; j < c2->cardinal;j++){
            puts("CAT for c2");
            insertar(sig[((NodoI *)c1->eltos[i])->num], 
             c2->eltos[j], cmpNodoNum, copiaNodoI);
         }
      }
   }
   if(((NodoI *)raiz->info)->id[0]=='*'){
      Conjunto *c1, *c2;
      puts("AST1");

      c1 = ((NodoI *)raiz->info)->last;
      puts("AST2 c1");
      imprimeConjunto(c1, imprimeNodoI);
      for(i=0; i < c1->cardinal;i++){
         //((NodoI *)raiz->info)->sig[c1->eltos[i]]=creaConjunto(10);
         c2=((NodoI *)raiz->info)->first;
         puts("AST2 c2");
         imprimeConjunto(c2, imprimeNodoI);
         for(j=0; j < c2->cardinal;j++){
            insertar(sig[ ((NodoI *)c1->eltos[i])->num], 
                     c2->eltos[j], cmpNodoNum, copiaNodoI);
         }
      }
   }
   if(((NodoI *)raiz->info)->id[0]=='|'){
      puts("OROROR");
   }
   //if(((NodoI *)raiz->der->info)->id[0]=='#') return;
   sigArb(raiz->der);       
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
void crearEstados(NodoArb *raiz){
   //Conjunto *estadosD[100];
   Conjunto *c1, *c2, *cobj, *tempi;
   NodoI *ni;
   int indexEstadoInicio=0;
   int indexEstados=1;
   int i, j, cta, enc;
   //puts("1111 crearEstados");
   Conjunto *estadosD=creaConjunto(100);
   //printf("AFD 0 (%s)  ",  alfab[0]);
   c2=((NodoI *)raiz->info)->first;
   insertarSet(estadosD, c2, cmpNodoNum, copiaNodoI);
   c2->id = 0;
   //printf("AFD card (%d)  ", ((NodoI *)raiz->info)->first->cardinal );
   creaCola(&head, &tail);
   put_(&head,&tail,(void *)copiaConjunto(c2, copiaNodoI));
   //imprimeConjunto( (Conjunto *)head->info, imprimeNodoI);
   while(!empty(head)){
      cobj=(Conjunto *)(get(&head)->info);
      for (i=0; alfab[i] ;i++){
         tempi=creaConjunto(100);
         //printf("AFD AFD AFD (%s)  ", alfab[i]);    
         for (j=0; j < cobj->cardinal ;j++){
            ni=((NodoI *)cobj->eltos[j]);
        //printf("AFD (%d, %d) id=%s num=%d ", i, j, ni->id, ni->num);
            if(ni->id[0] == alfab[i][0]){
              tempi=unirConjunto(tempi, sig[ni->num], cmpNodoNum, copiaNodoI);
            }
         }     
         //puts("Conj transi");
         //imprimeConjunto(tempi, imprimeNodoI);
         if (!contains(estadosD, tempi, &enc, cmpNodoNum)){ 
            //puts("Conj nuevo");
            //imprimeConjunto(tempi, imprimeNodoI);
            tempi->id = indexEstados;
            put(&head,&tail,(void *)tempi);
            //insertar(estadosD, tempi, cmpNodoNum, copiaNodoI);
            insertarSet(estadosD, tempi, cmpNodoNum, copiaNodoI);
            printf("IFIF %d->%d con %s \n", 
                  indexEstadoInicio, indexEstados, alfab[i]);
            tran[indexEstadoInicio][alfab[i][0]-'a']=indexEstados;
            indexEstados++;
         } else {    
            int sig=((Conjunto *)estadosD->eltos[enc])->id;  
            printf("ELSE %d->%d con %s \n", 
                   indexEstadoInicio, sig, alfab[i]);
            tran[indexEstadoInicio][alfab[i][0]-'a']=sig;
         }
         //printf("%d->%d con %s ", indexEstados, indexEstados+1, alfab[i]);
      }
      indexEstadoInicio++;
      printf("%d \n", indexEstadoInicio);
   }
   for(i=0; i < indexEstadoInicio ;i++){
      for(j=0; alfab[j] ;j++){
         printf(" %d, ", tran[i][j]);
      }
      printf("\n");
   }
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



