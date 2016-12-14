#update-time:2016-12-12 19:58
CC=gcc
CFLAGS=-Wall -g -c

VPATH = syntax:word:semantic:translate

Objects = main.o syntax.o lex.o syntaxTree.o semantic.o translate.o

mycompile: $(Objects)
	$(CC) -o $@ $(Objects)
main.o: main.c main.h
	$(CC) $(CFLAGS) -o $@ main.c
lex.o: lex.yy.c
	$(CC) $(CFLAGS) -o $@ $< -lfl
syntax.o: syntax.tab.c
	$(CC) $(CFLAGS) -o $@ $< -lfl -ly
syntaxTree.o: syntaxTree.c
	$(CC) $(CFLAGS) -o $@ $<
semantic.o: semantic_analyse.c
	$(CC) $(CFLAGS) -o $@ $<
translate.o: trans.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY:clean all
all:
	@cd ./syntax;\
	bison -d syntax.y;\
	cd ../word;\
	flex word.analyse.l;\
	cd ../;\
	make
clean:
	rm *.o
