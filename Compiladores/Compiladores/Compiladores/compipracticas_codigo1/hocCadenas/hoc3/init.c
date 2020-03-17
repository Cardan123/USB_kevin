#include "hoc.h"
#include "y.tab.h"
#include <stdio.h>
#include <math.h>

extern void *sin_(void *x);
extern void *cos_(void *x);
extern void *atan_(void *x);
extern void *fabs_(void *x);
extern void * Log(void *);
extern void *Log10(void *);
extern void *Sqrt(void *);
extern void *Exp(void * );
extern void *integer (void * ) ;
extern NodoL  **globals;
extern NodoL *symlist;

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
   void	*(*func)(void *);
} builtins[] =	{
"sin",	sin_,
"cos" ,	cos_,
"atan",	atan_,
"log", Log,
"log10", Log10,
"exp", Exp,
"sqrt",	Sqrt,   /*	verifica rango */
"int" ,	integer,
"abs",	fabs_,
0,	0
};
void init( ) {
   int i;
   puts("init");
   Simbolo *s;
   symlist = creaNodoL((void *)NULL, symlist);
   globals = (NodoL**)(&(symlist->dato)); 
   for (i = 0; consts[i].name; i++)
      install(globals, consts[i].name, VAR, creaDoble(consts[i].cval));
   //puts("2o for init");
   for (i = 0; builtins[i].name; i++) {
      s = install(globals, builtins[i].name, BLTIN, NULL);
      s->u.ptr = builtins[i].func;  
   }
   puts("salida init");
}
