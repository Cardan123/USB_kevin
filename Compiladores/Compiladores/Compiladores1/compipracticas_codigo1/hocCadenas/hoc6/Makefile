Gram=y.tab.c y.tab.h

all: $(Gram)
	@gcc -o hoc y.tab.c lex.yy.c symbol.c code.c init.c math.c doble_calc.c pilap.c -lm
	@echo Compiled

$(Gram): hoc6.y
	@yacc -d hoc6.y

lex.yy.c: hoc6.l
	@flex hoc6.l

clean:
	@rm -f hoc *.yy.*  *.tab.* 
	@echo Clean
