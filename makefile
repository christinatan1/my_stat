all: statFunctions.o
	gcc -o a.out statFunctions.o

statFunctions.o: statFunctions.c
	gcc -c statFunctions.c

run:
	./a.out

clean:
	rm *.o
	rm *~
