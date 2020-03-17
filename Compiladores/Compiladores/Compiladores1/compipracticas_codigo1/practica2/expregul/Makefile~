Gram=y.tab.c y.tab.h

all: $(Gram) y.tab.c
	@gcc -o regu y.tab.c 
	@echo Compiled


$(Gram): simple.y
	@yacc -d simple.y

clean:
	@rm -f *.out *.tab.* regu
	@echo Clean
