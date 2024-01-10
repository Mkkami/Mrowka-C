all:
	gcc -Wall src/*.c -o bin/mrowka

test: all
	bin/mrowka -m 50 -n 50 -i 100 -p plik -d E

clean:
	rm -f wyniki/*