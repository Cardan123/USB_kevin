Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o calc y.tab.c lex.yy.c doble_calc.c 
	@echo Compiled

$(Gram): hoc1.y
	@yacc -d hoc1.y

lex.yy.c: hoc1.l
	@flex hoc1.l
clean:
	@rm -f  *.tab.* *.yy.* calc
	@echo Clean
