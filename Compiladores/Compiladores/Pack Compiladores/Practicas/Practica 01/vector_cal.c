#include <stdio.h>
#include "vector_cal.h"
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

/*Operaciones con vectores*/

    /*--- Crear vector ---*/
    Vector *creaVector(int n){
            Vector *vec;
            int i;
            vec=(Vector *)malloc(sizeof(Vector));
            vec->n = n;	
            vec->vec = (double *)malloc(sizeof(double)*n);
            
            return vec;
    }
    
    /*--- Imprimir vector ---*/
    void imprimeVector(Vector *v){
        int i; 
        for(i=0; i< v->n; i++)
            printf("%f ", v->vec[i]);
        printf("\n");
    }
    
    /*--- Copiar un vector ---*/
    Vector *copiaVector(Vector *v){
        int i;
        Vector *copy=creaVector(v->n);
        for(i = 0; i< v->n; i++)
            copy->vec[i]=v->vec[i];	
        
        return copy;	
    }
    
    /*---- Operaciones con vectores ----*/
    
        /*--- Suma de vectores ---*/
        Vector *sumaVector(Vector *a, Vector *b){
            Vector *c;
            int i;
            c=creaVector(a->n);
            for(i=0; i< a->n;i++)
                c->vec[i]=a->vec[i]+b->vec[i];
            
            return c;
        }
    
        /*--- Resta de vectores ---*/
        Vector *restaVector(Vector *a, Vector *b){
            Vector *c;
            int i;
            c=creaVector(a->n);
            for(i=0; i< a->n;i++)
                c->vec[i]=a->vec[i] - b->vec[i];
            
            return c;
        }
        
        /*--- Multiplicación de esalar por vector ---*/
        Vector *escalarVector(double escalar, Vector *a){
            Vector *c;
            int i;
            c = creaVector(a->n);
            for(i=0; i < a->n ; i++)
                    c->vec[i] = escalar * a->vec[i];
            
            return c;
        }
        
        /*--- Producto Punto ---*/
        double productoPunto(Vector *a, Vector *b){
            double c = 0.0;
            int i ;
            for( i=0; i< a->n ; i++)
                c += a->vec[i] * b->vec[i];
            
            return c;
        }
        
        /*--- Magnitud de vector ---*/
        double magnitudVector(Vector *a){
            double m = 0.0;
            int i=0;
            for( ; i < a->n ; i++)
                m += (a->vec[i] * a->vec[i]);
            
            return sqrt(m);
        }
        
        /*--- Producto Cruz ---*/
        Vector *productoCruz(Vector *a, Vector *b){
            Vector *c;
            c = creaVector(a->n);
            
            if( a->n == 2){  /*Vector con 2 componentes*/
                    c->vec[0] = a->vec[0] * b->vec[1];
                    c->vec[1] = -(a->vec[1] * b->vec[0]);
            }else if( a->n == 3){ /*Vector con 3 componentes*/
                    c->vec[0] = a->vec[1] * b->vec[2] - a->vec[2] * b->vec[1]; 
                    //c->vec[1] = -(a->vec[0] * b->vec[2] - a->vec[2] * b->vec[0]);
                    c->vec[1] = a->vec[2] * b->vec[0] - a->vec[0] * b->vec[2];
                    c->vec[2] = a->vec[0] * b->vec[1] - a->vec[1] * b->vec[0];                    
            }
                        
            return c;            
        }
