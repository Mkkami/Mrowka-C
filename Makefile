all:
	gcc -Wall src/*.c -o bin/mrowka

test: all clean
	bin/mrowka -m 25 -n 25 -i 100 -p plik -d E

test_czarne: all clean
	bin/mrowka -m 50 -n 50 -i 10 -p plik -d E -r 100

test_r: all clean
	bin/mrowka -m 25 -n 25 -i 10 -p plik -d N -r 25

test_10000: all clean
	bin/mrowka -m 50 -n 50 -i 10000 -p plik -d N

clean:
	rm -f wyniki/*