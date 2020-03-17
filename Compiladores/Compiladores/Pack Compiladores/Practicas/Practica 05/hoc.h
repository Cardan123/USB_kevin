#include "vector_cal.h"
#include <string.h>

typedef struct Symbol{    /*Entrada de la tabla de símbolos*/
    char * name;
    short type;           /* VAR , BLTIN , UNDEF */

    union{
      Vector * val;       /* Si es VAR */
      Vector *(*ptr)();   /* Si es BLTIN */
      double num;
    }u;

    struct Symbol * next; /* Es para ligarse a otro */
}Symbol;

Symbol * install(char * s, int t, Vector * d);
Symbol * lookup(char * s);

typedef union Datum{    /* Tipo de pila del interprete */
  Vector * val;
  double num;
  int eval;
  Symbol * sym;   /*Apunta a una entrada en la tabla de simbolos */
}Datum;

extern Datum pop();
typedef int (* Inst)(); /* Instruccion de maquina:
                          Es un apuntador a funcion*/

#define STOP (Inst) 0
extern Inst prog[];
extern Inst * progp;
extern Inst * code();

extern void assign();
extern void varpush();
extern void constpush();
extern void print();
extern void printd();
extern void constpushd();
extern void bltin();

/* Funciones con los vectores */
extern void eval();
extern void add();
extern void sub();
extern void producto_cruz();
extern void producto_punto(); 
extern void magnitud();
extern void escalar();

/* Operadores condicionales aritméticos */
extern void gt();
extern void lt();
extern void ge();
extern void le();
extern void eq();
extern void ne();
extern void and();
extern void or();
extern void not();

/* Condicion y Ciclo */
extern void whilecode();
extern void ifcode();
extern void prexpr();