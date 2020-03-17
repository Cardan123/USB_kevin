Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o calc y.tab.c  
	@echo Compiled

$(Gram): hoc1.y
	@yacc -d hoc1.y

clean:
	@rm -f *.out  *.tab.* calc
	@echo Clean
