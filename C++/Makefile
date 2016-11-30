main:main.o oostk.o postk.o stack.o que2s.o queis.o
	g++ -g -o main main.o oostk.o postk.o stack.o que2s.o queis.o
.PHONY:clean cleanAll
main.o: main.cpp main.h
	g++ -g -c main.cpp -o main.o
oostk.o:OOSTK.cpp OOSTK.h
	g++ -g -c OOSTK.cpp -o oostk.o
postk.o:POSTK.cpp POSTK.h
	g++ -g -c POSTK.cpp -o postk.o
stack.o:STACK.cpp STACK.h
	g++ -g -c STACK.cpp -o stack.o
que2s.o:QUE2S.cpp QUE2S.h
	g++ -g -c QUE2S.cpp -o que2s.o
queis.o:QUEIS.cpp QUEIS.h
	g++ -g -c QUEIS.cpp -o queis.o
clean:
	rm *.o
cleanAll:
	rm *.o ./main
