all: commander.o output.o main

output.o:
	gcc -c src/output.c -o output.o

commander.o:
	gcc -c deps/commander/src/commander.c -o commander.o -std=c99

main:
	gcc src/main.c commander.o output.o -o bin/vault

clean:
	rm -f *.o

