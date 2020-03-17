
#define NUMW 256
int norac;
char sujetos [NUMW] [100];
char acciones[NUMW][100];
char objsdirec[NUMW][150];
char respuesta[512];

oracion -> SN SV 
        | who
SN -> SUSTANTIVO 
   | DET SUSTANTIVO 
   | SUSTANTIVO ADJETIVO 
   | DET SUSTANTIVO ADJETIVO
SV -> VERBO 
   | VERBO SN 
who-> QUIEN VERBO 
   | QUIEN VERBO SN 

int yyerror(char const *str){
    extern char *yytext;
    fprintf(stderr, "parser error near %s\n", yytext);
    return 0;
}
char *pega(char *str1, char *str2){
char *tmp=(char *)malloc(strlen(str1)+strlen(str2)+2);
  strcpy(tmp, str1);
  strcat(tmp, " ");
  strcat(tmp, str2);
  return tmp;
}
void initialize(){
   int i;
   for (i=0; i<20; i++) {
      sujetos[i][0]   = '\0';
      acciones [i][0]   = '\0';
   }
   norac = 0;
   return;
}
void make_respuesta1_2(char *sujeto, char *verbo){
   int i; 
   //printf("norac=(%d) (%s) (%s)", norac, sujeto, verbo );
   for (i=norac-1; i >= 0; i--) {
   //printf("i=(%d) (%s) (%s)", i, objsdirec[i], acciones[i]);  
      if ( (strcmp(sujeto, objsdirec[i]) == 0) &&
          (strcmp(verbo, acciones[i]) == 0)  ) {
   //printf("i=(%d) (%s) (%s)", i, objsdirec[i], acciones[i]);        
         strcpy(respuesta, sujetos[i]); 
         return;
      }
   }
   strcpy(respuesta, "No se");
   return;
}
void make_respuesta1_1(char *verbo){
   int i;
   /* Last input norac is a where-question      */
   //printf("norac=(%d) (%s) (%s)", norac, sujeto, verbo );
   for (i=norac-1; i >= 0; i--) {
   //printf("i=(%d) (%s) (%s)", i, sujetos[i], acciones[i]);  
      if (strcmp(verbo, acciones[i]) == 0) {
   //printf("i=(%d) (%s) (%s)", i, sujetos[i], acciones[i]);  
         strcpy(respuesta, sujetos[i]);      
         return;
      }
   }
   strcpy(respuesta, "No se");
   return;
}
void main(void){
    extern int yyparse(void);

    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "Error ! Error ! Error !\n");
        exit(1);
    }
}
