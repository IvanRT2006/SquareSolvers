all: main

main: build\main.o build\input.o build\tester.o build\solver.o build\utils.o
	g++ build\main.o build\input.o build\tester.o build\solver.o build\utils.o -o main

build\tester.o: source\tester.cpp
	g++ -c source\tester.cpp -o build\tester.o

build\utils.o: source\utils.cpp
	g++ -c source\utils.cpp -o build\utils.o

build\input.o: source\input.cpp
	g++ -c source\input.cpp -o build\input.o

build\solver.o: source\solver.cpp
	g++ -c source\solver.cpp -o build\solver.o

build\main.o: source\main.cpp
	g++ -c source\main.cpp -o build\main.o

clean:
	rm -rf build\*.o main.exe
