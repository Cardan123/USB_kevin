Gram=y.tab.c y.tab.h

all: $(Gram)
	@gcc -o hoc y.tab.c lex.yy.c symbol.c code.c init.c math.c doble_calc.c pilap.c -lm
	@echo Compiled

$(Gram): hoc4.y
	@yacc -d hoc4.y

lex.yy.c: hoc4.l
	@flex hoc4.l

clean:
	@rm -f *.out  *.tab.* com
	@echo Clean
