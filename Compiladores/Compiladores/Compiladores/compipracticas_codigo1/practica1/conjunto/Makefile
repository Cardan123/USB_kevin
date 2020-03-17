Gram=y.tab.c y.tab.h

all: $(Gram) lex.yy.c conjunto_cal.c
	@gcc -o conj y.tab.c lex.yy.c conjunto_cal.c
	@echo Compiled

conjunto_cal.c:
	@echo "Si esta"

$(Gram): conjunto_cal.y
	@yacc -d conjunto_cal.y

lex.yy.c: conjunto_cal.l
	@flex conjunto_cal.l

clean:
	@rm -f *.out lex.yy.c *.tab.* conj
	@echo Clean
