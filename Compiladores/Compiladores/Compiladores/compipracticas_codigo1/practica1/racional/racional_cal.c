
int main() { return yyparse(); }
int yyerror(const char* s) { 
  printf("%s\n", s); 
  return 0; 
}
Racional *creaRacional(int num, int den){
   Racional *nvo;
   if(den==0)
	return (Racional *)NULL;
   nvo=(Racional *)malloc(sizeof(Racional));
   if(!nvo){
	puts("no hay memoria para crear Racional ");
        return (Racional *)NULL;
   }  
   nvo->num=num;
   nvo->den=den;
   return nvo;
}
void asignar(Racional *r, int num, int den){
   r -> num = num; r -> den = den;
}
int numerador(Racional *r){ return r ->num; }
int denominador(Racional *r){ return r ->den; }
Racional* racionalSuma(Racional *r, Racional *s){
	int nvonum = (r -> num * s -> den) + (s -> num * r -> den);
	int nvoden = r -> den * s -> den;
	Racional *nvo = creaRacional(nvonum, nvoden);
	return nvo; 
}
Racional* racionalResta(Racional *r, Racional *s){
	int nvonum = (r -> num * s -> den) - (s -> num * r -> den);
	int nvoden = r -> den * s -> den;
	Racional *nvo = creaRacional(nvonum, nvoden);
	return nvo; 
}
Racional* racionalMultiplicar(Racional *r, Racional *s){
	int nvonum = r -> num * s -> num;
	int nvoden = r -> den * s -> den;
	Racional *nvo = creaRacional(nvonum, nvoden);
	return nvo; 
}
Racional* racionalDividir(Racional *r, Racional *s){
	int nvonum = r -> num * s -> den;
	int nvoden = r -> den * s -> num;
	Racional *nvo = creaRacional(nvonum, nvoden);
	return nvo; 
}
int esIgual(Racional *r, Racional *s){
	return (r -> num * s -> den) == (r -> den * s -> num);
}
void imprimirR(void *r){
	Racional *p = (Racional*)r;
	printf("(%d / %d)\n",p -> num, p -> den);
}
Racional *copiar(Racional *r){
	return creaRacional(r -> num, r -> den);
}

