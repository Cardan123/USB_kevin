Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o emite y.tab.c  
	@echo Compiled

$(Gram): emite.y
	@yacc -d emite.y

clean:
	@rm -f *.out  *.tab.* emite
	@echo Clean
