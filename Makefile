INCLUDES=-I /usr/local/include/sqlcipher
LIB_DIR=-L /usr/local/lib/libsqlcipher.a
LIBS=-lsqlcipher

all: output.o vault.o main

output.o:
	gcc -c src/output.c -o output.o

vault.o:
	gcc -c src/vault.c -o vault.o $(INCLUDES) $(LIB_DIR) $(LIBS) -Wall

main:
	gcc src/main.c output.o vault.o $(INCLUDES) $(LIB_DIR) $(LIBS) -Wall -o bin/vault

clean:
	rm -f *.o
	rm test.db
