all:
	gcc -Wall src/*.c -o bin/mrowka

test: all
	bin/mrowka 50 50 25