solution: queen.o main.o
	g++ queen.o main.o -o solution
queen.o: queen.h queen.cpp
	g++ -c queen.cpp
main.o: main.cpp queen.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm solution
run: solution
	./solution
