#include <stdio.h>
int tran[][2]={
   1,0,
   1,2,
   1,3,
   1,0,
};

void lex(){
   char c;
   int sig;
   c=getchar();
   sig=0;
   while(c !='#'){
      sig=tran[sig][c-'a'];
      printf("%d \n", sig);
      c=getchar();
   }
   if(sig==3)
      puts("reconocido");
   else
      puts("no recono");
}
void main(){
   lex();
}
