test: Role.o Room.o main.o
	g++ Role.o Room.o main.o -o test
Role.o: Role.cpp Role.h Room.h
	g++ -c Role.cpp -o Role.o
Room.o: Room.cpp Role.h Room.h
	g++ -c Room.cpp -o Room.o
main.o: main.cpp Role.h Room.h
	g++ -c main.cpp -o main.o
clean:
	rm main.o
	rm Role.o
	rm Room.o
	rm test.exe
