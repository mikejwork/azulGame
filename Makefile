.default: all

all: main

clean:
	rm -f main *.o

main: main.o Tile.o Mozaic.o TileBag.o GameManager.o Factory.o SaveManager.o \
	GameIO.o Turn.o Player.o
	g++ -Wall -Werror -std=c++14 -g -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -c $^
