#include <stdio.h>
#include <malloc.h>
#include "hoc.h" 

double *creaDoble(double d){
   double *nvo=(double *)malloc(sizeof(double));
   *nvo=d;
   return nvo;
}
void * addDoble(void *dob1, void *dob2){
    double d1 = *((double *)dob1);
    double d2 = *((double *)dob2);
   return creaDoble(d1 + d2);
} 
void *subDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble(d1 - d2);
} 
void *mulDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble(d1 * d2);
}
void *div_Doble(void *dob1, void *dob2){
   double d1 = *(double *)dob1;
   double d2 = *(double *)dob2;
   if(d2 ==0.0)
      execerror("division por cero", "");
   return creaDoble(d1 / d2);
}
void *powerDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble( Pow(d1, d2) );
}
void *negateDoble(void *dob){
    double d = *(double *)dob;
   return creaDoble( -d );
}
void printDoble(void *dob) {
   double d = *(double *)dob;
   printf("%.8g\n", d); 
}

