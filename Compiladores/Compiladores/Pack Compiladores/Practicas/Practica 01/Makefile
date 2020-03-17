Gram=y.tab.c y.tab.h

all: $(Gram) vector_cal.c
	@gcc -o vec y.tab.c vector_cal.c -lm 
	@echo Compiled
vector_cal.c:
	@echo "Si esta"

$(Gram): vector_cal.y
	@yacc -d vector_cal.y

clean:
	@rm -f *.out *.tab.* vec
	@echo Clean
