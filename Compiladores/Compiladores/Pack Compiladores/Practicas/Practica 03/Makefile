Gram=y.tab.c y.tab.h

all: $(Gram) vector_cal.c
	@gcc -o vec y.tab.c vector_cal.c symbol.c -lm
	@echo Compiled

complejo_cal.c:
	@echo "Si esta"

$(Gram): vector.y
	@yacc -d vector.y

clean:
	@rm -f *.out *.tab.* vec
	@echo Clean
