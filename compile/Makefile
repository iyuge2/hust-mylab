mycompile: main.o syntax.o lex.o syntaxTree.o
	gcc  -o mycompile main.o syntax.o lex.o syntaxTree.o
main.o: main.c main.h
	gcc  -g -c main.c -o main.o
lex.o: word.analyse.l
	flex word.analyse.l
	gcc -g -c lex.yy.c -lfl -o lex.o
syntax.o: syntax.y
	bison -d syntax.y
	gcc  -g -c syntax.tab.c -lfl -ly -o syntax.o
syntaxTree.o: syntaxTree.c
	gcc -g -c syntaxTree.c -o syntaxTree.o
.PHONY:clean
clean:
	rm *.o
