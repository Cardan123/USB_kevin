#include "hoc.h"
#include <stdio.h>
#include <math.h>
double Complejo_fase(Complejo *c){
	double fase;
	if(c->valR==0)
		fase=0;
	else
	   	fase=(double)atan(c->valI/ c->valR);
	//printf("fase: %lf",fase);
	return fase;
}
double Complejo_modulo(Complejo * c){
	double res=sqrt(pow(c->valR,2)+pow(c->valI,2));
	//printf("res %lf",res);
	return res;
	
}
Complejo *Complejo_negate(Complejo* c1){
	Complejo *nvo = (Complejo*)malloc(sizeof(Complejo));
	nvo -> valR=c1 -> valR*-1;
	nvo -> valI=c1 -> valI*-1;
	return nvo;
}
Complejo *creaComplejo(double real, double imaginario){
   Complejo *nvo = (Complejo*)malloc(sizeof(Complejo));
   nvo -> valR = real;
   nvo -> valI = imaginario;
   return nvo;
}
Complejo *Complejo_add(Complejo *c1, Complejo *c2){
  return creaComplejo(c1->valR + c2->valR, c1->valI + c2->valI);
}
Complejo *Complejo_sub(Complejo *c1, Complejo *c2){
  return creaComplejo(c1->valR - c2->valR, c1->valI - c2->valI);
}
Complejo *Complejo_mul(Complejo *c1, Complejo *c2){
  return creaComplejo( c1->valR*c2->valR - c1->valI*c2->valI,
                       c1->valI*c2->valR + c1->valR*c2->valI);
}
Complejo *Complejo_div(Complejo *c1, Complejo *c2){
   double d = c2->valR*c2->valR + c2->valI*c2->valI;
   return creaComplejo( (c1->valR*c2->valR + c1->valI*c2->valI) / d,
                        (c1->valI*c2->valR - c1->valR*c2->valI) / d);
}
void imprimirC(Complejo *c){
   if(c==NULL)
	  return;
   if(c->valI != 0)
      printf("%f%+fj\n", c->valR, c->valI);
   else
      printf("%f\n", c->valR);
}
