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
Inst   *progbase = prog; /* Inicie del subprograaa actual */
int    returning;      /* 1 si se ve la proposiolón de retorno */

#define NFRAME  100 

Pila *pilaLlama;
extern NodoL **globals;
#define NFRAME  100 

void *(*add_)(void *dob1, void *dob2)=addDoble;
void *(*sub_)(void *dob1, void *dob2)=subDoble;
void *(*mul_)(void *dob1, void *dob2)=mulDoble;
void *(*div__)(void *dob1, void *dob2)=div_Doble;
void *(*mod_)(void *dob1, void *dob2)=modDoble;
void *(*power_)(void *dob1, void *dob2)=powerDoble;
void *(*gt_)(void *dob1, void *dob2)=gtDoble;
void *(*lt_)(void *dob1, void *dob2)=ltDoble;
void *(*ge_)(void *dob1, void *dob2)=geDoble;
void *(*le_)(void *dob1, void *dob2)=leDoble;
void *(*eq_)(void *dob1, void *dob2)=eqDoble;
void *(*ne_)(void *dob1, void *dob2)=neDoble;
void *(*and_)(void *dob1, void *dob2)=andDoble;
void *(*or_)(void *dob1, void *dob2)=orDoble;
void *(*not_)(void *dob)=notDoble;
void *(*negate_)(void *dob)=negateDoble;
void (*print_)(void *dob)=printDoble;
int (*pilaCond)(void *dob) = pilaCondDoble;

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
Frame *creaFrame(Simbolo  *sp, int nargs, Inst *retpc, void  **argn){
   Frame *nvo=(Frame *)malloc(sizeof(Frame));
   nvo->sp = sp;
   nvo->nargs = nargs;
   nvo->retpc = retpc;
   nvo->argn  = argn;  
   return nvo;
}
void initcode(){
   puts("initcode");
   progp = progbase;
   pila=creaPila(NSTACK);
   pilaLlama=creaPila(NSTACK);
   returning = 0;
}
void pop1( ) {
   pop(pila);
}
void constpush( ){
Datum d;
//puts("constpush");
d.val  =  ((Simbolo  *)*pc)->u.val;
printDoble(d.val);
pc = pc + 1;
push(pila, creaDatumVal(d.val));
}
void varpush(){
Datum d;
d.sym  =  (Simbolo *)(*pc);
pc = pc + 1;
push(pila, creaDatumSym(d.sym));
}
void whilecode() {
   Datum d;
   Inst  *savepc  = pc;	
   execute(savepc+2);     /*   condición   */ 
   d  =  *(Datum *)pop(pila); 
   //printf("\t__while__cond (%.8g)\n",  *((double *)d.val));
   while   ( pilaCond(d.val) )   {
      execute(*((Inst  **)(savepc)));     /*  cuerpo  */
      if (returning) break;
      execute(savepc+2);
      d  = *(Datum *)pop(pila); 
   } 
   if (!returning)
   pc  =  *((Inst  **)(savepc+1));     /*   siguiente proposición   */
}
void ifcode(){
   Datum d;
   Inst  *savepc  = pc;
   execute(savepc+3);	/*  condición   */
   d  =  *(Datum *)pop(pila); 
   //printf("\t__if__cond (%.8g)\n",  *((double *)d.val));
   if (pilaCond(d.val)){
      execute(*((Inst   **)(savepc))); 
   } else if (*((Inst **)(savepc+1))) /* ¿parte else? */
      execute(*(( Inst  **) (savepc+1)));
   if (!returning)
      pc  =  *((Inst  **)(savepc+2));	/*  siguiente proposición   */ 
}
void define(Simbolo *sp) {
   sp->u.defn = progbase;    /* lnlolo de código */ 
   puts("define");
   //printf("000cta = (%d, %s)\n", progp-prog , *pc);
   printf("000cta = (%d)\n", progp-prog);
/*for  (pc = progbase; pc <=  progp; ) {
         printf("000cta = (%d, %s)\n", pc-progbase , *pc);
         pc = pc + 1; 
   }*/
   progbase = progp;      /* el siguiente código comienza aquí */
}
void call() {
//puts("call");
Simbolo  *sp  =   (Simbolo *)pc[0];   
//if   (fp++   >=  &frame[NFRAME-1])
//execerror(sp->name,   "call  nested too deeply");
if(estaLlena(pilaLlama))
   execerror(sp->nombre, "call  nested too deeply");
push(pilaLlama, creaFrame(
         sp, (int)pc[1], pc  + 2, topDir(pila) ));
execute(sp->u.defn);
returning = 0; 
} 
void ret( ) {
   int i;
   Frame *cima=(Frame *)top(pilaLlama);
   //puts("ret");
   for (i = 0; i < cima->nargs; i++)
      pop(pila);
   pc = (Inst *)cima->retpc;
   printf("888dir ret = (%d)\n", pc-prog);
   pop(pilaLlama);
   returning = 1; 
}
void funcret() {
   Datum d;
   //puts("funcret");
   Frame *cima=(Frame *)top(pilaLlama);
   if (cima->sp->tipo == PROCEDURE)
      execerror(cima->sp->nombre, "(proc) returns value");
    d = *(Datum *)pop(pila);
    ret(); 
    push(pila, creaDatumVal(d.val));
}
void procret( ){ 
   Frame *cima=(Frame *)top(pilaLlama);     
   //puts("procret");
   if (cima->sp->tipo  ==  FUNCTION)
      execerror(cima->sp->nombre, "(func) returns no value"); 
   ret(); 
}
void **getarg( ) {
   Frame *cima=(Frame *)top(pilaLlama);
   //puts("getarg");
   int nargs = (int) *pc++;
   if (nargs > cima->nargs)
	execerror(cima-> sp->nombre, "not enough arguments");
   return &(((Datum *)cima->argn[nargs - cima->nargs])->val); 
}
void arg( ) {
   Datum d;
   d.val = *getarg(); 
   push(pila, creaDatumVal(d.val));
}
void argassign() {
   Datum d;
   d = *(Datum *)pop(pila);  
   push(pila, creaDatumVal(d.val));    
   *getarg() = d.val; 
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
printDoble(d1.val);
push(pila, creaDatumVal(d1.val));
}
void mul(){
Datum d1, d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val = mul_(d1.val, d2.val);
printDoble(d1.val);
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
void gt() {
Datum d1,  d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val  =   gt_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void lt(){
Datum d1,  d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val  =   lt_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void ge( ) {
Datum d1,  d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val  =   ge_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void le() {
Datum d1,  d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val  =   le_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void eq( ) {
Datum d1,  d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val  =   eq_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void ne(){
Datum d1, d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val  =   ne_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void and(){
Datum d1,   d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val  =   and_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void or(){
Datum d1, d2;
d2 = *(Datum *)pop(pila); 
d1 = *(Datum *)pop(pila); 
d1.val  =   or_(d1.val, d2.val);
push(pila, creaDatumVal(d1.val));
}
void not( ){
Datum d;
d = *(Datum *)pop(pila);
d.val = not_(d.val);
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
printDoble(d1.sym->u.val);
d1.sym->tipo = VAR;
push(pila, creaDatumVal(d2.val)); 
} 
void print( ){
   Datum d;
   puts("66++++print");
   d = *(Datum *)pop(pila);
   print_(d.val);
   //printf("\t%.8g\n",   *((double *)d.val) );
}
void printVal( ){
   Datum d;
   puts("printVal");
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
   /*for  (pc = p; strcmp(*pc, "STOP") ; ) {
         printf("000cta = (%d, %s)\n", pc-p , *pc);
         pc = pc + 1; 
   }*/
   printf("entre  execute= ( %d )\n", p-prog);
   for  (pc = p ; strcmp(*pc, "STOP"); ) {
        //puts(*pc);
        printf("cta1 = ( %d ) pc=(%s) \n", pc-p, *pc );
        printf("cta2 = ( %d ) pc=(%s) \n", pc-prog, *pc );
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
