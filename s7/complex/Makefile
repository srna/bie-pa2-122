CFLAGS=-Wall -pedantic

complex.out: main.o complex.o
	g++ main.o complex.o -o complex.out

main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp -o main.o

complex.o: complex.cpp
	g++ -c $(CFLAGS) complex.cpp -o complex.o

clean:
	rm -f *.o*