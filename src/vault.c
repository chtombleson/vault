/**
 * vault.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "output.h"
#include "vault.h"

int vault_init(const char *database, const char *password) {
    printf("Database: %s\n", database);
    printf("Password: %s\n", password);

    // Connect to database
    int rc = sqlite3_open(
        database,
        &sqlite_db
    );

    char * err_msg = 0;

    if (rc != SQLITE_OK) {
        output_warning("Warning unable to open database");
        vault_close();

        return 0;
    }

    int res = sqlite3_key(sqlite_db, password, strlen(password));

    if (res != SQLITE_OK) {
        output_warning("Unable to encrypt database");
        vault_close();

        return 0;
    }

    /*res = sqlite3_exec(
        sqlite_db,
        "create table if not exists key_value(id INTEGER PRIMARY KEY, key VARCHAR(128), value TEXT);",
        0,
        0,
        &err_msg
    );

    if (res != SQLITE_OK) {
        output_warning(err_msg);
        vault_close();

        return 0;
    }*/

    return 1;
}

void vault_close() {
    if (0 != sqlite_db) {
        sqlite3_close(sqlite_db);
    }
}

void vault_print_help() {
    printf("Usage: vault --database <database> --password <password>\n");
    printf("\t--database\tPath to vault database\n");
    printf("\t--password\tPassword for vault database\n");
    printf("\t--version \tVersion details\n");
    printf("\t--help    \tShow this message\n");
}

