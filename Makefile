INCLUDES=-I /usr/local/include/sqlcipher
LIB_DIR=-L /usr/local/lib/libsqlcipher.a
LIBS=-lsqlcipher -luuid

all: linenoise.o output.o vault.o shell.o main

linenoise.o:
	gcc -c deps/linenoise/linenoise.c -o linenoise.o

shell.o:
	gcc -c src/shell.c -o shell.o

output.o:
	gcc -c src/output.c -o output.o

vault.o:
	gcc -c src/vault.c -o vault.o $(INCLUDES) $(LIB_DIR) $(LIBS) -Wall

main:
	gcc src/main.c linenoise.o output.o vault.o shell.o $(INCLUDES) $(LIB_DIR) $(LIBS) -Wall -o bin/vault

clean:
	rm -f *.o
	if [ -f "test.db" ]; then rm test.db; fi;

