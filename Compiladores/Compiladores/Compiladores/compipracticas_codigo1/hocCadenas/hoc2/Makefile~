Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o calc y.tab.c lex.yy.c doble_calc.c 
	@echo Compiled

$(Gram): hoc2.y
	@yacc -d hoc2.y

lex.yy.c: hoc2.l
	@flex hoc2.l
clean:
	@rm -f  *.tab.* *.yy.* calc
	@echo Clean
