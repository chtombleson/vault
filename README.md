# Vault

An encrypted document and key value store.

## Depenedencies

SQLCipher

    $ git clone https://github.com/sqlcipher/sqlcipher.git
    $ cd sqlcipher
    $ ./configure --enable-tempstore=yes CFLAGS="-DSQLITE_HAS_CODEC -DSQLITE_TEMP_STORE=2" LDFLAGS="-lcrypto"
    $ make
    $ sudo make install
    $ sudo ldconfig

## Building

    $ git clone https://github.com/chtombleson/vault.git
    $ cd vault
    $ git submodule update --recursive
    $ make

## Usage

Coming soon

