INCLUDES=-I /usr/local/include/sqlcipher
LIB_DIR=-L /usr/local/lib/libsqlcipher.a
LIBS=-lsqlcipher

all: commander.o output.o vault.o main

output.o:
	gcc -c src/output.c -o output.o

commander.o:
	gcc -c deps/commander/src/commander.c -o commander.o -std=c99

vault.o:
	gcc -c src/vault.c -o vault.o $(INCLUDES) $(LIB_DIR) $(LIBS)

main:
	gcc src/main.c commander.o output.o vault.o $(INCLUDES) $(LIB_DIR) $(LIBS) -g -o bin/vault

clean:
	rm -f *.o

