#include "vector_cal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 102
#define ASCII 26

Vector * cubeta[MAX];

/*Operaciones con vectores*/

    /*--- Crear vector ---*/
    Vector *creaVector(int n){
            Vector * vec;
            vec = (Vector *)malloc(sizeof(Vector));
            vec->n = n;
            vec->vec = (double *)malloc(sizeof(double) * n);

            return vec;
    }

    /*--- Imprimir vector ---*/
    void imprimeVector(Vector * v){
        int i = 0;
        printf("[ ");
        for( ; i < v->n-1; i++)
            printf("%f ", v->vec[i]);
        printf("%lf ]\n", v->vec[v->n-1]);
    }

    /*--- Copiar un vector ---*/
    void copiaVector(Vector * v, Vector * copy){
        int i = 0;
        copy = creaVector(v->n);
        for( ; i < v->n ; i++)
            copy->vec[i] = v->vec[i];

        //return copy;
    }

    /*---- Operaciones con vectores ----*/

        /*--- Suma de vectores ---*/
        Vector * sumaVector(Vector * a, Vector * b){
            Vector * c;
            int i = 0;
            c = creaVector(a->n);
            for( ; i < a->n ; i++)
                c->vec[i] = a->vec[i] + b->vec[i];

            return c;
        }

        /*--- Resta de vectores ---*/
        Vector * restaVector(Vector * a, Vector * b){
            Vector * c;
            int i = 0;
            c = creaVector(a->n);
            for( ; i < a->n ; i++)
                c->vec[i] = a->vec[i] - b->vec[i];

            return c;
        }

        /*--- Multiplicación de escalar por vector ---*/
        Vector * escalarVector(double escalar, Vector * a){
            Vector * c;
            int i = 0;
            c = creaVector(a->n);
            for( ; i < a->n ; i++)
                    c->vec[i] = escalar * a->vec[i];

            return c;
        }

        /*--- Producto Punto ---*/
        double productoPunto(Vector * a, Vector * b){
            double c = 0.0;
            int i = 0;
            for( ; i < a->n ; i++)
                c += a->vec[i] * b->vec[i];

            return c;
        }

        /*--- Magnitud de vector ---*/
        double magnitudVector(Vector *a){
            double m = 0.0;
            int i = 0;
            for( ; i < a->n ; i++)
                m += (a->vec[i] * a->vec[i]);

            return sqrt(m);
        }

        /*--- Producto Cruz ---*/
        Vector * productoCruz(Vector * a, Vector * b){
            Vector * c;
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

    int obtenID(char var){
      if ( 'A' <= var && var <= 'Z' )
        return ( var - 'A' );
      return ( var - 'a' + ASCII );
    }

    Vector * obtenValor(char var){
      int ID = obtenID(var);
      Vector * c = cubeta[ ID ];

      return c;
    }

    void actualizaValor(char var, Vector * a){
      int ID = obtenID(var);
      cubeta[ ID ] = a;
    }
