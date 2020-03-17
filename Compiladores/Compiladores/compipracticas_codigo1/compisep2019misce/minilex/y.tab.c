#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "simple.y"
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
#line 23 "y.tab.c"
#define CHAR 257
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    3,    1,    2,    2,    2,    2,    2,
};
short yylen[] = {                                         2,
    0,    2,    1,    0,    3,    3,    3,    2,    3,    1,
};
short yydefred[] = {                                      1,
    0,    3,    2,    0,   10,    0,    0,    0,    8,    0,
    0,    0,    5,    9,    0,    7,
};
short yydgoto[] = {                                       1,
    3,    8,    4,
};
short yysindex[] = {                                      0,
   -1,    0,    0,  -40,    0,  -40,  -40,   -6,    0,  -36,
  -40,  -40,    0,    0, -114,    0,
};
short yyrindex[] = {                                      0,
  -39,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -4,    0,
};
short yygindex[] = {                                      0,
    0,    1,    0,
};
#define YYTABLESIZE 218
short yytable[] = {                                       7,
    4,    6,    4,   13,   14,    6,    9,   10,    2,   12,
    0,   15,   16,    0,    0,    0,    0,    0,    0,    0,
    0,   11,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    6,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   11,    0,    6,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    4,
};
short yycheck[] = {                                      40,
   40,   42,   42,   10,   41,   10,    6,    7,   10,  124,
   -1,   11,   12,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   58,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   58,   -1,   58,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  257,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 257
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CHAR",
};
char *yyrule[] = {
"$accept : input",
"input :",
"input : input line",
"line : '\\n'",
"$$1 :",
"line : $$1 re '\\n'",
"re : re ':' re",
"re : re '|' re",
"re : '*' re",
"re : '(' re ')'",
"re : CHAR",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 87 "simple.y"
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



#line 241 "y.tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d (%s)\n",
                    yystate, yytable[yyn],yyrule[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 4:
#line 30 "simple.y"
{  
        int i;
        cta = 0 ; 
        for(i=0; i < 1000 ;i++){
           sig[i]=creaConjunto(10);
        }
     }
break;
case 5:
#line 37 "simple.y"
{ 
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
          raiz= creaNodoArb(creaNodoI(strdup(":"), 0, 0), yyvsp[-1].nodo, gato);
          if(((NodoI *)yyvsp[-1].nodo->info)->anu)
             ((NodoI *)raiz->info)->first=
                    insertar(firstPos(yyvsp[-1].nodo), 
                     creaNodoI(strdup("#"), cta, 0), cmpNodoNum , copiaNodoI);
          else
             /*((NodoI *)raiz->info)->first=((NodoI *)$2.nodo->info)->first;*/
             ((NodoI *)raiz->info)->first=firstPos(yyvsp[-1].nodo);
          ((NodoI *)raiz->info)->last=((NodoI *)gato->info)->last;

          imprimeArb(raiz, imprimeNodoII); puts("*****SIGSIGSIG "); 
          followPos(raiz); impriSig(); 
          crearEstados(raiz);
     }
break;
case 6:
#line 63 "simple.y"
{
          yyval.nodo = creaNodoArb(creaNodoI(strdup(":"), cta,
             ((NodoI *)yyvsp[-2].nodo->info)->anu && ((NodoI *)yyvsp[0].nodo->info)->anu),
                    yyvsp[-2].nodo, yyvsp[0].nodo);
   }
break;
case 7:
#line 68 "simple.y"
{   
          yyval.nodo = creaNodoArb(creaNodoI(strdup("|"), cta,
              ((NodoI *)yyvsp[-2].nodo->info)->anu || ((NodoI *)yyvsp[0].nodo->info)->anu),
                    yyvsp[-2].nodo, yyvsp[0].nodo);
   }
break;
case 8:
#line 73 "simple.y"
{
          yyval.nodo = creaNodoArb(creaNodoI(strdup("*"), cta, 1 ),
                                yyvsp[0].nodo, NULL);
   }
break;
case 9:
#line 77 "simple.y"
{ yyval = yyvsp[-1]; }
break;
case 10:
#line 78 "simple.y"
{
       char cade[2]={0,0};
       cade[0]=yyvsp[0].car;
       cta=cta+1;
       yyval.nodo = creaNodoArb(creaNodoI(strdup(cade), cta, 0),
                          (NodoArb *)NULL,(NodoArb *)NULL); 
   }
break;
#line 456 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
