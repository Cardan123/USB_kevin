Gram=y.tab.c y.tab.h

all: $(Gram) lex.yy.c quilt.c
	@gcc -o quil y.tab.c lex.yy.c quilt.c
	@echo Compiled

quilt.c:
	@echo "Si esta"

$(Gram): quilt.y
	@yacc -d quilt.y

lex.yy.c: quilt.l
	@flex quilt.l

clean:
	@rm -f *.out lex.yy.c *.tab.* quil
	@echo Clean
