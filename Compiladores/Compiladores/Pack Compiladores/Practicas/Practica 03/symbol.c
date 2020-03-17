#include "hoc.h"
#include "y.tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static Symbol * symb_list = 0;    /* Tabla de simbolos : Lista ligada */

Symbol * lookup(char * s){        /* Encontrar 's' en la Tabla de simbolos */
    Symbol * sp;
    for (sp = symb_list ; sp != (Symbol *)0; sp = sp->next)
        if ( strcmp( sp->name, s) == 0 )
            return sp;

    return 0;         /* 0 ==> No se encontró */
}

char * emalloc(unsigned n){         /*Se revisa el regreso desde malloc*/
    char * p;
    p = malloc(n);
    if (p == 0)
        execerror("Out of memory", (char *)0);

    return p;
}

Symbol * install(char * s, int t, Vector * d){  //Se instala 's'
    Symbol * sp;                                //en la tabla de simbolos
    char * emalloc();
    sp = (Symbol *)emalloc(sizeof(Symbol));

    sp->name = emalloc( strlen(s) + 1);   /* '\0' es +1 */
    strcpy( sp->name, s);
    sp->type = t;
    sp->u.val = d;
    sp->next = symb_list;         /* Se pone al frente de la lista */
    symb_list = sp;

    return sp;
}
