Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o calc y.tab.c lex.yy.c symbol.c init.c math.c doble_calc.c -lm
	@echo Compiled

$(Gram): hoc3.y
	@yacc -d hoc3.y

lex.yy.c: hoc3.l
	@flex hoc3.l
clean:
	@rm -f  *.tab.* *.yy.* calc
	@echo Clean
