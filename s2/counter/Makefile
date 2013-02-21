CFLAGS=-Wall -pedantic

counter.out: main.o ccounter.o
	g++ main.o ccounter.o -o counter.out

main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp -o main.o

ccounter.o: ccounter.cpp
	g++ -c $(CFLAGS) ccounter.cpp -o ccounter.o

clean:
	rm -f *.o*