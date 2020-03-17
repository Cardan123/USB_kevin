Gram=y.tab.c y.tab.h

all: $(Gram)
	@gcc -o hoc y.tab.c lex.yy.c symbol.c code.c init.c math.c doble_calc.c pilap.c -lm
	@echo Compiled

$(Gram): hoc5.y
	@yacc -d hoc5.y

lex.yy.c: hoc5.l
	@flex hoc5.l

clean:
	@rm -f *.out  *.tab.* com
	@echo Clean
