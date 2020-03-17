Gram=y.tab.c y.tab.h

all: $(Gram) lex.yy.c polinomio_cal.c
	@gcc -o poli y.tab.c lex.yy.c polinomio_cal.c
	@echo Compiled

polinomio_cal.c:
	@echo "Si esta"

$(Gram): polinomio_cal.y
	@yacc -d polinomio_cal.y

lex.yy.c: polinomio_cal.l
	@flex polinomio_cal.l

clean:
	@rm -f *.out lex.yy.c *.tab.* poli
	@echo Clean
