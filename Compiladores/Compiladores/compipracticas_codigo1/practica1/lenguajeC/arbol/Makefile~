Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o arbol y.tab.c  
	@echo Compiled

$(Gram): arboles.y
	@yacc -d arboles.y

clean:
	@rm -f *.out  *.tab.* arbol
	@echo Clean
