Gram=y.tab.c y.tab.h

all: $(Gram) lex.yy.c racional_cal.c
	@gcc -o racio y.tab.c lex.yy.c racional_cal.c
	@echo Compiled

racional_cal.c:
	@echo "Si esta"

$(Gram): racional_cal.y
	@yacc -d racional_cal.y

lex.yy.c: racional_cal.l
	@flex racional_cal.l

clean:
	@rm -f *.out lex.yy.c *.tab.* racio
	@echo Clean
