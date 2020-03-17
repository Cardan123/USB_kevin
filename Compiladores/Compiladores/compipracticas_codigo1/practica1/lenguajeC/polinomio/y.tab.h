#define TERMINO 257
typedef union {
   NodoL *val;
   Termino *term;
   Polinomio *polino;
} YYSTYPE;
extern YYSTYPE yylval;
