#include "hoc.h"
#include "y.tab.h"
#include <stdio.h>
#include <malloc.h>
#define NSTACK  256
Pila *pila;
#define NPROG  2000
Inst   prog[NPROG];   /* la Máquina */
Inst   *progp;        /* siguiente sitio libre para la generación de código */
Inst   *pc;              /* contador de programa durante la ejecución */

extern NodoL **globals;
#define NFRAME  100 

void *(*add_)(void *dob1, void *dob2)=addDoble;
void *(*sub_)(void *dob1, void *dob2)=subDoble;
void *(*mul_)(void *dob1, void *dob2)=mulDoble;
void *(*div__)(void *dob1, void *dob2)=div_Doble;
void *(*mod_)(void *dob1, void *dob2)=modDoble;
void *(*power_)(void *dob1, void *dob2)=powerDoble;
void *(*negate_)(void *dob)=negateDoble;
void (*print_)(void *dob)=printDoble;

Datum *creaDatumVal(void  *val){
Datum *nvo=(Datum *)malloc(sizeof(Datum));
nvo->val = val;
return nvo;
}
Datum *creaDatumSym(Simbolo  *sym){
Datum *nvo=(Datum *)malloc(sizeof(Datum));
nvo->sym = sym;
return nvo;
}
void initcode(){
   pila=creaPila(NSTACK);
   progp = prog; 
}
void pop1( ) {
   pop(pila);
}
void constpush( ){
Datum d;
//puts("constpush");
d.val  =  ((Simbolo  *)*pc)->u.val;
pc = pc + 1;
push(pila, creaDatumVal(d.val));
}
void varpush(){
Datum d;
d.sym  =  (Simbolo *)(*pc);
pc = pc + 1;
push(pila, creaDatumSym(d.sym));
}
void eval( ){
Datum  d;
d   =  *(Datum *)pop(pila);
if (d.sym->tipo != VAR && d.sym->tipo != INDEF)
execerror("attempt to evaluate non-variable", d.sym->nombre); 
if   (d.sym->tipo   ==   INDEF)
execerror("undefined variable", d.sym->nombre); 
d.val   =  d.sym->u.val; 
push(pila, creaDatumVal(d.val));
}
void add( ){
Datum d1,   d2; 
//puts("add");
d2  =  *(Datum *)pop(pila); 
d1  =  *(Datum *)pop(pila);   
d1.val = add_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void sub(){
Datum d1,  d2; 
d2  = *(Datum *)pop(pila); 
d1  = *(Datum *)pop(pila); 
d1.val = sub_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void mul(){
Datum d1, d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val = mul_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void div_( ){
Datum d1, d2;
d2 = *(Datum *)pop(pila);
if ( *((double *)d2.val) == 0.0)
execerror("division by zero", (char *)0);
d1 = *(Datum *)pop(pila); 
d1.val = div__(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void mod( ){
Datum d1, d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val = mod_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void negate(){
Datum d; 
d = *(Datum *)pop(pila); 
d.val  =  negate_(d.val); 
push(pila, creaDatumVal(d.val));
}
void power(){
   Datum d1, d2;
   extern double Pow();
   d2 = *(Datum *)pop(pila);
   d1 = *(Datum *)pop(pila);
   d1.val = power_(d1.val, d2.val);
   push(pila, creaDatumVal(d1.val));
}
void assign( ){
Datum d1, d2;
d1 = *(Datum *)pop(pila);
d2 = *(Datum *)pop(pila);
if (d1.sym->tipo != VAR && d1.sym->tipo != INDEF) 
execerror("assignment to non-variable", d1.sym->nombre);
d1.sym->u.val = d2.val;
d1.sym->tipo = VAR;
push(pila, creaDatumVal(d2.val)); 
} 
void print( ){
   Datum d;
   puts("print");
   d = *(Datum *)pop(pila);
   print_(d.val);
   //printf("\t%.8g\n",   *((double *)d.val) );
}
void bltin( ){
   Datum d;
   d  =  *(Datum *)pop(pila);
   //printf("\t%.8g\n",   *((double *)d.val) );
   d.val  =  ((void * (*)(void *))(*pc))( d.val) ;
   pc = pc + 1;
   push(pila, creaDatumVal(d.val));
} 
Inst *code(Inst f){   /* lnstalar una lnstrucción u operando */ 
   Inst *oprogp = progp;
   if (progp >= &prog[NPROG])
      execerror("program too big", (char *)0);
   *progp++ = f;
   return oprogp;
}
void execute(Inst *p){
   Simbolo *s;
   /*}for  (pc = p; strcmp(*pc, "STOP") ; ) {
         printf("000cta = (%d, %s)\n", pc-p , *pc);
         pc = pc + 1; 
   }*/
   for  (pc = p ; strcmp(*pc, "STOP"); ) {
        puts(*pc);
        if((s=lookup(*globals, *pc))==(Simbolo *)NULL){
           puts("error ejec");
           printf("cta = ( %d ) pc=(%s) \n", pc-p, *pc );
        } else {
           pc = pc + 1;
           (s->u.ci)();
           //puts("regreso");
        }
        
   }
}
