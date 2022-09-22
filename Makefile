CFLAGS=-Wall -I. -c

OBJ_FILES=main.o log.o game.o box.o

all: build/sfml-app

build/sfml-app: $(OBJ_FILES)
	g++ $(OBJ_FILES) -o build/sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lbox2d


main.o: src/main.cpp
	g++ $(CFLAGS) src/main.cpp

log.o: src/log/log.cpp
	g++ $(CFLAGS) src/log/log.cpp

game.o: src/game.cpp
	g++ $(CFLAGS) src/game.cpp

box.o: src/box.cpp
	g++ $(CFLAGS) src/box.cpp





clean:
	rm *.o
	rm -r build/*

run:
	./build/sfml-app