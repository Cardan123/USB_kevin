#include <math.h> 
#include <errno.h>

double *creaDoble(double d);
extern  int    errno;
   double  errcheck();

void *sin_(void *x){
   double d = *(double *)x;
   return creaDoble(sin(d));
}
void *cos_(void *x){
   double d = *(double *)x;
   return creaDoble(cos(d));
}
void *atan_(void *x){
   double d = *(double *)x;
   return creaDoble(atan(d));
}
void *fabs_(void *x){
   double d = *(double *)x;
   return creaDoble(fabs(d));
}
void *Log(void *x){
   double d = *(double *)x;
return creaDoble(errcheck(log(d) , "log"));
}
void *Log10(void *x){
   double d = *(double *)x;
return  creaDoble(errcheck(log10(d), "log10"));
}
void * Sqrt(void *x){
   double d = *(double *)x;
return creaDoble(errcheck(sqrt(d), "sqrt")); 
}
void *Exp(void *x){
   double d = *(double *)x;
return creaDoble(errcheck( exp(d) , "exp" )) ;
}
double Pow(x, y)
double x, y;
{
return errcheck(pow(x,y), "exponentiation");
}
void *integer(void *x){
   double d = *(double *)x;
return creaDoble((double)(long)d);
}
double errcheck(d, s)   /* comprobar resultado de llamada a biblioteca */ 
double d; 
char *s; 
{
if (errno == EDOM) { 
errno = 0;
execerror(s, "argument out of domain"); 
} else if (errno == ERANGE) 
{ errno = 0;
execerror(s, "result out of range"); 
} 
return d;
}


