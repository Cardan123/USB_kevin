#include <stdlib.h>
#include <string.h>
#include "hoc.h"
#include "y.tab.h"

static Symbol *symlist = NULL;

Symbol *
lookup(char *s)
{
	Symbol *sp;
	for(sp = symlist; sp != NULL; sp = sp->next) {
		if(strcmp(sp->name, s) == 0) {
			return sp;
		}
	}
	return NULL;
}

Symbol *
install(char *s, int t, char d)
{
	Symbol *sp = (Symbol *)emalloc(sizeof(Symbol));
	sp->name = (char *)emalloc(strlen(s)+1);
	strcpy(sp->name, s);
	sp->type = t;
	sp->u.val = d;
	sp->next = symlist;
	symlist = sp;
	return sp;
}

void *
emalloc(unsigned int n)
{
	void *p;
	p = malloc(n);
	if(p == NULL) {
		execerror("out of memory", NULL);
	}
	return p;
}
