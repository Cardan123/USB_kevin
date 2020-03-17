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
void *modDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((int)d1 % (int)d2);
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
void *gtDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((double)(d1  > d2));
} 
void *ltDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((double)(d1  < d2));
} 
void *geDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((double)(d1  >= d2));
} 
void *leDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((double)(d1  <= d2));
} 
void *eqDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((double) (d1  ==  d2));
} 
void *neDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((double)(d1 != d2));
} 
void *andDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((double)(d1   !=   0.0 && d2   !=  0.0));
} 
void *orDoble(void *dob1, void *dob2){
    double d1 = *(double *)dob1;
    double d2 = *(double *)dob2;
   return creaDoble((double)(d1 != 0.0 || d2 != 0.0));
} 
void *notDoble(void *dob){
    double d = *(double *)dob;
   return creaDoble((double)(d == 0.0));
} 
void printDoble(void *dob) {
   double d = *(double *)dob;
   printf("\t%.8g\n", d); 
}
int pilaCondDoble(void *dob){
   return *((double *)dob);
}

