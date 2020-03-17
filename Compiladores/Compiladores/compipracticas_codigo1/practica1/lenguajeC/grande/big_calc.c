#include <stdio.h>
#include <stdlib.h>
#include "big_calc.h"

Big *creaBig(int n){
   Big *big;
   int i;
   big=(Big *)malloc(sizeof(Big));
   big->n = n;	
   big->cifras = (int *)malloc(sizeof(int)*n);
   for(i = big->n - 1; i >= 0 ; i--)
      big->cifras[i]=0;
   return big;
}
void imprimeBig(Big *b){
   int i; 
   for(i = b->n - 1; i >= 0 ; i--)
      printf("%4d ", b->cifras[i]);
   printf("\n");
}
Big *copiaBig(Big *b){
   int i;
   Big *copy=creaBig(b->n);
   for(i = 0; i< b->n; i++)
   //for(i = b->n - 1; i >= 0 ; i--)
      copy->cifras[i]=b->cifras[i];	
   return copy;	
}
Big *sumaBig(Big *a, Big *b){
   Big *c;
   int i;
   int acarreo;
   int sumi, lim=0;
   int suma[10000];
   //c=creaBig(a->n+1);  
   acarreo=0;
   //modi
   for(i=0; i < a->n; i=i+1){
      sumi=a->cifras[i]+b->cifras[i]+acarreo;
      acarreo=sumi/10000;
      suma[i]=sumi%10000;
   }
   suma[a->n]=acarreo;
   if(acarreo) lim = a->n+1;
   else lim = a->n;
   c=creaBig(lim);
   for(i=0; i < lim; i=i+1){
      c->cifras[i]=suma[i];
   }
   //quitar c->cifras[a->n]=acarreo;
   return c;
}
Big *potBig(Big *a, Big *b){
   Big *c;
    int i, s;
   c=creaBig(1);
   c->cifras[0]=1;
   for(i=0; i < b->cifras[0]; i=i+1){
       c = multiBig(a, c);
   }
   return c;
}
Big *multiBig(Big *a, Big *b){
   int multi[10000];
    
   int i, base;
   int grado1, grado2;
   int acarreo;

   int s,t , cta, digit, remainder;
   int aux[1000], sum[1000];
   Big *c;     

   cta=0;
   base= 10000;
   grado1 = a->n;
   grado2 = b->n;
   for (s=0 ; s < 1000; s++){
       multi[s]=0; aux[s]=0; sum[s]=0;
   }
   c=creaBig(grado1+grado2+1);
   for (s=0 ; s < grado2; s++){
        digit=b->cifras[s];
        for(i=0; i < cta; i=i+1){
              aux[i]=0;  
        }
        for(i=cta; i < grado1+cta; i=i+1){
              aux[i]=a->cifras[i-cta];  
        }
        if (digit != 0){
            remainder=0;
            for(t=0; t < grado1+cta ; t++ ){ 
              sum[t] =(aux[t]* digit + multi[t] + remainder) % base;   
              remainder =(aux[t] * digit  + multi[t] + remainder) / base;
            }
            if (remainder != 0)
               sum[t] = remainder;
            for(i=0; i <= t; i=i+1){
               multi[i]=sum[i];
            }
        }
        cta++;
    }
   for(i= grado1+grado2; i >= 0 ; i=i-1){
      c->cifras[i]=multi[i];
   }
   return c;
}
