Gram=y.tab.c y.tab.h

all: $(Gram)
	@gcc -o hoc y.tab.c symbol.c code.c init.c math.c -lm
	@echo Compiled

$(Gram): hoc.y
	@yacc -d hoc.y
clean:
	@rm -f *.out  *.tab.* com
	@echo Clean
