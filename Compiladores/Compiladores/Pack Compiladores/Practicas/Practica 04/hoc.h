#include "vector_cal.h"
#include <string.h>

typedef struct Symbol{    /*Entrada de la tabla de símbolos*/
    char * name;
    short type;           /* VAR , BLTIN , UNDEF */

    union{
      Vector * val;       /* Si es VAR */
      double num;
    }u;

    struct Symbol * next; /* Es para ligarse a otro */
}Symbol;

Symbol * install(char * s, int t, Vector * d);
Symbol * lookup(char * s);

typedef union Datum{
  Vector * val;
  double num;
  Symbol * sym;   /*Apunta a una entrada en la tabla de simbolos */
}Datum;

extern Datum pop();
typedef int (* Inst)(); /* Instruccion de maquina:
                          Es un apuntador a funcion*/

#define STOP (Inst) 0
extern Inst prog[];

extern void assign();
extern void varpush();
extern void constpush();
extern void print();
extern void printd();
extern void constpushd();

extern void eval();
extern void add();
extern void sub();
extern void producto_cruz();
extern void producto_punto(); 
extern void magnitud();
extern void escalar();
