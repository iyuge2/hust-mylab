mycompile: main.o syntax.o lex.o syntaxTree.o semantic.o
	gcc  -o mycompile main.o syntax.o lex.o syntaxTree.o semantic.o
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
semantic.o: semantic_analyse.c
	gcc -g -c semantic_analyse.c -o semantic.o
.PHONY:clean
clean:
	rm *.o
