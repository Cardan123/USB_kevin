#include <stdio.h>
#include <stdlib.h>
#include "big_calc.h"

Big *creaBig(int n){
   Big *big;
   int i;
   big=(Big *)malloc(sizeof(Big));
   big->n = n;	
   big->cifras = (int *)malloc(sizeof(int)*n);
   return big;
}
void imprimeBig(Big *b){
   int i; 
   //for(i=0; i < b->n ; i++)
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
   int sumi;
   c=creaBig(a->n);
   acarreo=0;
   for(i=0; i < a->n; i=i+1){
      sumi=a->cifras[i]+b->cifras[i]+acarreo;
      acarreo=sumi/10000;
      //printf("aca = %d , i = %d ", acarreo, i);
      c->cifras[i]=sumi%10000;
   }
   c->cifras[a->n+1]=acarreo;
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
   c=creaBig(grado1+grado2+1);
   for (s=0 ; s <= grado2; s++){
        digit=b->cifras[s];
        for(i=0; i < cta; i=i+1){
              aux[i]=0;  
        }
        for(i=cta; i <= grado1+cta; i=i+1){
              aux[i]=a->cifras[i-cta];  
        }
        if (digit != 0){
            remainder=0;
            for(t=0; t <= grado1+cta ; t++ ){
              
              sum[t] =(aux[t]* digit + multi[t] + remainder) % base;
              remainder =(aux[t] * digit  + multi[t] + remainder) / base;
              //printf("%d x %d = %d  sum = %d resi = %d ", 
              //aux[t], digit, aux[t]* digit, sum[t], remainder);
            }
            if (remainder != 0)
               sum[t] = remainder;
            for(i=0; i <= t; i=i+1){
               multi[i]=sum[i];
            }
            //putchar('\n');
        }
        cta++;
    }
   for(i= grado1+grado2+1; i >= 0 ; i=i-1){
      c->cifras[i]=multi[i];
   }
   return c;
}
/*Big *restaBig(Big *a, Big *b){
Big *c;
int i;
   c=creaBig(a->n);
   for(i=0; i< a->n;i++)
      c->vec[i]=a->vec[i]-b->vec[i];
   return c;
}*/
/*
vector : '[' NUMBER NUMBER NUMBER ']' {
      $$=creaBig(3);
      $$->cifras[0] = $2->cifras[0];
      $$->cifras[1] = $3->cifras[0];
      $$->cifras[2] = $4->cifras[0];
   }
   ;*/
