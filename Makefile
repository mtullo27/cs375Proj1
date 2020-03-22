CFLAGS=-DDEBUG -g -std=c++17
proj=program1

all: $(proj).o
	g++ -g $(proj).o -o $(proj)

$(proj).o: program1.cpp
	g++ -c $(CFLAGS) program1.cpp -o program1.o

run: all
	./$(proj) filex.txt filey.txt

clean:
	rm -rf *.o $(proj)
