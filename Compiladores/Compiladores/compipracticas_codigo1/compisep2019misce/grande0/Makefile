Gram=y.tab.c y.tab.h

all: $(Gram) complejo_cal.c
	@gcc -o big y.tab.c big_calc.c
	@echo Compiled

complejo_cal.c:
	@echo "Si esta"

$(Gram): big_calc.y
	@yacc -d big_calc.y


clean:
	@rm -f *.out  *.tab.* big
	@echo Clean
