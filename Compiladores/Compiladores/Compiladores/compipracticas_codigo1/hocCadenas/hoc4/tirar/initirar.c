#include "hoc.h"
#include "y.tab.h"
#include <stdio.h>
#include <math.h>

extern double   Log(), Log10(), Sqrt(), Exp( ) , integer ( ) ;
extern NodoL  **globals;
extern NodoL *symlist;
static struct { 
   char   *name;	/* Palabras clave */
   int    kval;
} keywords[] = {
"dim",          DIM,
"proc" ,	PROC,
"func" ,	FUNC,
"return",	RETURN,
"if",		IF,
"else" ,	ELSE,
"while",	WHILE,
"for",          FOR,
"print",	PRINT,
"read",		READ,
"struct",       ESTRUCT,
0,      0,
};
static struct {         /* Constantes */ 
   char *name; 
   double cval;
} consts[] = {
"PI",    3.14159265358979323846,
"E",     2.71828182845904523536,
"GAMMA", 0.57721566490153286060,  /* Euler */
"DEG",  57.29577951308232087680,  /* grado/radian */
"PHI",   1.6180339887498948*820,  /* proporcion dorada */
0,       0
};

static struct {	/*	Predefinidos */
   char *name;
   double (*func)();
} builtins[] =	{
"sin",	sin,
"cos" ,	cos,
"atan",	atan,
"log", Log,
"log10", Log10,
"exp", Exp,
"sqrt",	Sqrt,   /*	verifica rango */
"int" ,	integer,
"abs",	fabs,
0,	0
};
static struct {	/*	Predefinidos */
   char *name;
   void (*func)();
} conjinst[] =	{
   "constpush",  constpush,
   "varpush",  varpush,
   "whilecode", whilecode,
   "forcode", forcode,
   "ifcode", ifcode,
   "eval", eval,  
   "add", add, 
   "sub", sub, 
   "mul", mul,  
   "div", div_,  
   ///"mod", mod, 
   "negate", negate,
   "gt", gt, 
   "lt", lt, 
   "ge", ge, 
   "le", le, 
   "eq", eq, 
   "ne", ne, 
   "and", and, 
   "or", or, 
   "not", not,
   "power", power,
   "assign", assign,  
   "print_", print_, 
   "prexpr", prexpr, 
   "printIndis", printIndis,
   "bltin", bltin,
   "call", call,
   "preinc", preinc,
   "predec", predec,
   "postinc", postinc,
   "postdec", postdec,
   "addeq", addeq,
   "subeq", subeq,
   "muleq", muleq,
   "acumula", acumula,
   "acumula111", acumula111,
   "funcret", funcret,
   "procret", procret,
   "elepush", elepush,
   "memmultialloc" , memmultialloc,
   "eltomulti", eltomulti,
   "elemultiassign", elemultiassign,
   "memberpush", memberpush,
   "memberassign", memberassign,
   "pop1", pop1,
    0,      0   
};
void init( ) {
   int i;
   puts("init");
   Simbolo *s;
   symlist = creaNodoL((void *)NULL, symlist);
   globals = (NodoL**)(&(symlist->dato)); 
   for (i = 0; keywords[i].name; i++)
      install(globals, keywords[i].name, keywords[i].kval, NULL);
   //puts("1er for init");
   for (i = 0; consts[i].name; i++)
      install(globals, consts[i].name, VAR, creaDoble(consts[i].cval));
   //puts("2o for init");
   for (i = 0; builtins[i].name; i++) {
      s = install(globals, builtins[i].name, BLTIN, NULL);
      s->u.ptr = builtins[i].func;  
   }
   //puts("3er for init");
   for (i = 0; conjinst[i].name; i++) {
        //puts("dentro111");
	s = install(globals, conjinst[i].name, BLTIN, NULL);
        //puts("dentro222");   
	s->u.ci = conjinst[i].func;
        //puts("dentro333");
   }
   puts("salida init");
}
