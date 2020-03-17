#include <stdio.h>
#include <stdlib.h>
#include "polinomio_cal.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))		
#define max(a, b) (((a) > (b)) ? (a) : (b))

NodoL *creaNodoL(void *dato, NodoL *sig) {
	NodoL *nvo;
	nvo = (NodoL *)malloc(sizeof(NodoL));
	nvo->dato = dato;
	nvo->sig = sig;
	return nvo;
}

Termino *creaTermino(int coefi, int expo) {
	Termino *nvo;
	nvo = (Termino *)malloc(sizeof(Termino));
	nvo->coefi = coefi;
	nvo->expo = expo;
	return nvo;
}

void imprimeTermino(void *dato, int fin) {
	Termino *t = (Termino *)dato;
	if (fin == 0) printf("%+d x^%d ", t->coefi, t->expo);
	else if (fin == 1) printf("%+d x^%d\n", t->coefi, t->expo);
	else printf("%d x^%d ", t->coefi, t->expo);
}

int cmpTermino(void *t1, void *t2) {
	Termino *tp1 = (Termino *)t1;
	Termino *tp2 = (Termino *)t2;
	return tp1->expo - tp2->expo;
}

Polinomio *creaPolinomio(int grado, NodoL *cab, int sgn) {
	Polinomio *nvo = (Polinomio *)malloc(sizeof(Polinomio));
	NodoL *q;
	if (!nvo) {
		puts("no hay memoria para crear Polinomio ");
		return (Polinomio *)NULL;
	}
	nvo->cab = cab;
	nvo->grado = grado;
	for (q = nvo->cab; q; q = q->sig) {
		Termino *tr = (Termino *)q->dato;
		tr->coefi = tr->coefi * sgn;
	}
	return nvo;
}
NodoL *ultimoNodo(NodoL *cab){
   NodoL *p;
   if(!cab)  return (NodoL *)0;
   for (p = cab ; p->sig ; p = p->sig)
   		;
   return (NodoL *)p;  
}
Polinomio * simplifica(Polinomio *pol) {
	NodoL *p, *q, *head = pol->cab;
        NodoL *cab = 0;
	if (pol) {
           for (p = pol->cab; p; p = p->sig) {
			Termino *act = (Termino *)p->dato;
			Termino *cont;
			if (p->sig) cont = (Termino *)p->sig->dato;
			else break;

			while (act->expo == cont->expo) {
				act->coefi += cont->coefi;
				p->sig = p->sig->sig;
				if (p->sig) cont = (Termino *)p->sig->dato;
				else break;
			}
           }      
           for (p = pol->cab; p ; p = p->sig) {
              Termino *act = (Termino *)p->dato;  
              if(act->coefi != 0) 
                insertaOrdA((void *)creaTermino(act->coefi, act->expo), &cab, cmpTermino);       
           } 
           if(!cab) return creaPolinomio(0, creaNodoL(creaTermino(0, 0), NULL), 1);
           Termino *up=(Termino *)(ultimoNodo(cab)->dato);
           //imprimeTermino(up, 1);
           return creaPolinomio(up->expo, cab, 1);
	}
        return pol;
	//pol->cab = head;
        
}
/*void simplifica(Polinomio *pol) {
	NodoL *p, *q, *head = pol->cab;
	if (pol) {
		for (p = pol->cab; p; p = p->sig) {
			Termino *act = (Termino *)p->dato;
			Termino *cont;
			if (p->sig) cont = (Termino *)p->sig->dato;
			else break;

			while (act->expo == cont->expo) {
				act->coefi += cont->coefi;
				p->sig = p->sig->sig;
				if (p->sig) cont = (Termino *)p->sig->dato;
				else break;
			}
		}
	}
	pol->cab = head;
}*/
NodoL *insertaOrdA(void *dato, NodoL **cab, int ( *cmp)(void *, void *)) {
	NodoL *p, *q;
	if (!(*cab)) {
		*cab = creaNodoL(dato,(NodoL *)NULL);
		return *cab;
	}
	if (cmp((*cab)->dato, dato) >= 0) {
		*cab = creaNodoL(dato, *cab);
		return *cab;
	}
	for (p = *cab,q = p->sig; q && cmp(q->dato, dato) < 0 ;p = q, q = q->sig)
		;
	q = creaNodoL(dato,q);
	p->sig = q;
	return *cab;
}

void imprimeL(NodoL *inicio, void ( *f)(void *, int)) {
	NodoL *p;
	if (!inicio) {
		puts("imprime:lista vacia");
		return ;
	}
	int flag = 2;
	for (p = inicio; p->sig; p = p->sig, flag = 0) f(p->dato, flag);
	if (p && !(p->sig)) {
		f(p->dato, 2);
		//puts("if impl");
	}
	else f(p->dato, 1);
}
int igualNodoL(NodoL *cab1, NodoL *cab2,
		int ( *cmp)(void *, void *)) {
	for (; cab1 && cab2; cab1 = cab1->sig,cab2 = cab2->sig) {
		if (cmp(cab1->dato, cab2->dato)) {
			return 0;
		}
	}
	if (!cab1 && !cab2)
		return 1;
	return 0;
}
Termino *ultimoTermino(Polinomio *poli){
   NodoL *p;
   
   if(!poli)  return (Termino *)0;
   p=ultimoNodo(poli->cab);
   return (Termino*)p->dato;
   
}
Termino *elevaTermino(Termino *t, int n) {
	int coef = t->coefi, tm = coef;
	int exp = t->expo;
	int N = n - 1;
	while ((N--) > 0) coef = coef * tm;
	exp = exp * n;
	return creaTermino(coef, exp);
}

Termino *multiplicaTermino(Termino *t1, Termino *t2) {
	return creaTermino(t1->coefi * t2->coefi, t1->expo + t2->expo);
}

Polinomio *binomio(Polinomio *p, Polinomio *d) {
	Termino *ter = (Termino *)(d->cab->dato);
	NodoL *nvo = 0;
	if (!ter) return creaPolinomio(0, nvo, 1);
	int n = ter->coefi;
	int tab[2][n + 1], cnt = 0;
	for (nvo = p->cab; nvo; nvo = nvo->sig, cnt++);
	if (cnt != 2) return creaPolinomio(0, p->cab, 1);

	Termino *ta = (Termino *)p->cab->dato;
	Termino *tb = (Termino *)p->cab->sig->dato;

	NodoL *rsp = 0;

	if (n == 1) {
		return copiaPolinomio(p);
	}
	else {
		int i, j;
		for (i = 0; i < n + 1; ++i) {
			for (j = 0; j <= i; ++j) {
				if (j == 0 || j == i) tab[i % 2][j] = 1;
				else if ((j - 1) >= 0)
					tab[i % 2][j] = tab[(i + 1) % 2][j] + tab[(i + 1) % 2][j - 1];
			}
		}

		for (j = 0; j <= n; ++j) {
			int mult = tab[(i + 1) % 2][j];
			Termino *nvot = multiplicaTermino(elevaTermino(ta, n - j), elevaTermino(tb, j));
			nvot->coefi = nvot->coefi * mult;
			insertaOrdA((void *)nvot, &rsp, cmpTermino);
		}
	}

	return creaPolinomio(0, rsp, 1);
}
Polinomio *deriva(Polinomio *poli) {
	NodoL *cab = 0;
	NodoL *p = 0;
	int coef, expo;

	for (p = poli->cab; p; p = p->sig) {
		Termino *ter = (Termino *)p->dato;
		coef = ter->coefi * ter->expo;
		expo = ter->expo - 1;
		if (ter->expo > 0) insertaOrdA((void *)creaTermino(coef, expo), &cab, cmpTermino);
	}

	Polinomio *rtn = creaPolinomio(expo, cab, 1);
	simplifica(rtn);

	return rtn;
}
Polinomio *geometrico(Polinomio *poli) {
	NodoL *cab = 0;
	int i;
	Termino *term = (Termino *)(poli->cab->dato);
	if (!term) {
		puts("Error");
		return creaPolinomio(0, cab, 1);
	}

	int n = term->coefi;
	for (i = 0; i <= n; ++i)
		insertaOrdA((void *)creaTermino(1, i), &cab, cmpTermino);

	return creaPolinomio(i - 1, cab, 1);
}
Polinomio *geom(Polinomio *p) {
   int i, n1,n2;
   Polinomio *acu;
   Polinomio *uno=creaPolinomio(0, creaNodoL(creaTermino(1, 0), NULL), 1);
   Polinomio *equis=creaPolinomio(1, creaNodoL(creaTermino( 1, 1), NULL), 1);
   acu=creaPolinomio(0, creaNodoL(creaTermino(1, 0), NULL), 1);
   n1=((Termino*)p->cab->dato)->coefi;
   //n2=((Termino*)p->cab->dato)->coefi;
   //puts("geom");
   //imprimePolinomio(p);
   //printf("geom  coefi=(%d) expo=(%d)", n2, n1);
   for (i=0; i< n1; i++) {
     acu=sumaPolinomio(multiplicaPolinomio(acu, equis),uno);
   }
   return acu;
}
Polinomio *sumaPolinomio(Polinomio *p, Polinomio *q) {
	NodoL *suma = NULL;
	NodoL *aux;
	NodoL *aux2;
	Termino *tp1;
	Termino *tp2;
	for (aux = p->cab; aux; aux = aux->sig) {
		tp1 = (Termino *)aux->dato;
		for (aux2 = q->cab;aux2;aux2 = aux2->sig) {
			tp2 = (Termino *)aux2->dato;
			if ((tp1->expo == tp2->expo) ) {
				insertaOrdA(
						(void *)creaTermino(tp1->coefi+tp2->coefi,tp1->expo),
						&suma, cmpTermino);
				tp1->band = 1;
				tp2->band = 1;
			}
		}
		if (tp1->band == 0)
			insertaOrdA((void *)creaTermino(tp1->coefi,tp1->expo),
					&suma, cmpTermino);
	}
	for (aux2 = q->cab;aux2;aux2 = aux2->sig) {
		tp2 = (Termino *)aux2->dato;
		if (tp2->band == 0)
			insertaOrdA((void *)creaTermino(tp2->coefi,tp2->expo),
					&suma, cmpTermino);
	}
	return creaPolinomio(max(p->grado,q->grado), suma, 1);
}

Polinomio *restaPolinomio(Polinomio *p, Polinomio *q) {
	NodoL *resta = NULL;
	NodoL *aux;
	NodoL *aux2;
	Termino *tp1;
	Termino *tp2;
	for (aux = p->cab; aux; aux = aux->sig) {
		tp1 = (Termino *)aux->dato;
		for (aux2 = q->cab;aux2;aux2 = aux2->sig) {
			tp2 = (Termino *)aux2->dato;
			if ((tp1->expo == tp2->expo)) {
                            //if((tp1->coefi-tp2->coefi)!=0)
				insertaOrdA(
						(void *)creaTermino(tp1->coefi-tp2->coefi,tp1->expo),
						&resta, cmpTermino);
			    tp1->band = 1;
			    tp2->band = 1;
         
			}
		}
		if (tp1->band == 0)
			insertaOrdA((void *)creaTermino(tp1->coefi,tp1->expo),
					&resta, cmpTermino);
	}
	for (aux2 = q->cab;aux2;aux2 = aux2->sig) {
		tp2 = (Termino *)aux2->dato;
		if (tp2->band == 0)
			insertaOrdA((void *)creaTermino(-tp2->coefi,tp2->expo), &resta, cmpTermino);
	}
	return creaPolinomio(max(p->grado,q->grado), resta, 1);
}

Polinomio *multiplicaPolinomio(Polinomio *p, Polinomio *q) {
	NodoL *producto = NULL;
	NodoL *aux;
	NodoL *aux2;
	Termino *tp1;
	Termino *tp2;
        Termino *nvo;
        //puts("q dentro multi");
        //imprimePolinomio(q);
        Termino *up=ultimoTermino(p);
        Termino *uq=ultimoTermino(q);
        int grado=up->expo+uq->expo;
        //printf("mult grado =(%d, %d, %d, %d, %d) ", up->expo,  uq->expo, p->grado , q->grado, grado);
	for (aux = p->cab; aux; aux = aux->sig) {
		tp1 = (Termino *)aux->dato;
		for (aux2 = q->cab; aux2 ; aux2 = aux2->sig) {
			tp2 = (Termino *)aux2->dato;
                        nvo=creaTermino(tp1->coefi * tp2->coefi, tp1->expo+tp2->expo);
                        //imprimeTermino(nvo, 0);
			insertaOrdA((void *)nvo, &producto, cmpTermino);
		}
	}
	//return creaPolinomio(p->grado+q->grado, producto, 1);
        return creaPolinomio(grado, producto, 1);
}
Polinomio *dividePolinomio(Polinomio *p, Polinomio *q) {
   NodoL *division = NULL;
   //imprimePolinomio(p);
   //imprimePolinomio(q);
   Termino *up=ultimoTermino(p);
   Termino *uq=ultimoTermino(q);
   int grado=up->expo-uq->expo;
   //printf("11 coefi =(%d, %d) ", up->coefi,  uq->coefi);
   //printf("22 grado =(%d, %d, %d, %d) ", up->expo,  uq->expo, p->grado , q->grado);
   
   if (up->expo <  uq->expo) 
      return (Polinomio *)NULL;
     /*Termino *tp1=creaTermino(  up->coefi/uq->coefi, up->expo-uq->expo);
     Polinomio * tempPoli = creaPolinomio(up->expo-uq->expo, creaNodoL(tp1,NULL), 1);
     return tempPoli;*/
     while(up->expo >  uq->expo){
     up=ultimoTermino(p);
     uq=ultimoTermino(q);
      Termino *tp1=creaTermino( up->coefi/ uq->coefi , up->expo-uq->expo);
     //printf("11 coefi =(%d, %d, %d) ", up->coefi,  uq->coefi, up->coefi/ uq->coefi);
     //printf("22 grado =(%d, %d) ", up->expo,  uq->expo);
     insertaOrdA((void *)tp1, &division, cmpTermino);
     Polinomio * tempPoli = creaPolinomio(up->expo-uq->expo, creaNodoL(tp1,NULL), 1);
     //puts("div 1er");
     //imprimePolinomio(tempPoli);    
     Polinomio * nuevoPoli = multiplicaPolinomio(tempPoli, q);
     //puts("multi");
     //imprimePolinomio(nuevoPoli);
     p = restaPolinomio(p, nuevoPoli);
     //puts("resta111");
     //imprimePolinomio(p);
     //puts("simpli");
     p = simplifica(p);
     //imprimePolinomio(p);
   }
   return creaPolinomio(grado, division, 1);
}
/*
public static Poly operator /(Poly p1, Poly p2)
{
    p1.Terms.Sort(TermCollection.SortType.DES);
    p2.Terms.Sort(TermCollection.SortType.DES);
    TermCollection resultTerms = new TermCollection();
    if (p1.Terms[0].Power < p2.Terms[0].Power)
        throw new Exception("Invalid Division: P1.MaxPower is Lower than P2.MaxPower");
    while(p1.Terms[0].Power > p2.Terms[0].Power)
    {
        Term NextResult = new Term(p1.Terms[0].Power - 
	p2.Terms[0].Power, p1.Terms[0].Coefficient / p2.Terms[0].Coefficient);
        resultTerms.Add(NextResult);
        Poly TempPoly = NextResult;
        
        Poly NewPoly = TempPoly * p2;
        p1 = p1 - NewPoly;
    }
    return new Poly(resultTerms);
}
*/
int esIgualPolinomio(Polinomio *p, Polinomio *q) {
	return igualNodoL(p->cab, p->cab, cmpTermino);
}

void imprimePolinomio(Polinomio *p) {
	imprimeL(p->cab, imprimeTermino);
}

Polinomio *copiaPolinomio(Polinomio *p) {
	NodoL *copia = NULL;
	NodoL *aux;
	Termino *tp;
	for (aux = p->cab; aux ; aux = aux->sig) {
		tp = (Termino *)aux->dato;
		insertaOrdA((void *)creaTermino(tp->coefi,tp->expo), &copia, cmpTermino);
	}
	return creaPolinomio(p->grado, copia, 1);
}

