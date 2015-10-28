/**
 * vault.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "output.h"
#include "vault.h"

int vault_init(const char *database) {
    printf("Database: %s", database);

    // Get the password
    char password[64];

    while (strlen(password) < 8) {
        printf(
            "%s%s%s: ",
            OUTPUT_COLOR_YELLOW,
            "Enter database password [min 8 characters & max 32 characters]",
            OUTPUT_COLOR_RESET
        );

        scanf("%s", password);
    }

    int rc = sqlite3_open_v2(
        database,
        &sqlite_db,
        SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
        0
    );

    if (rc != SQLITE_OK) {
        output_warning("Warning unable to open database");
        sqlite3_close(sqlite_db);

        return 0;
    }

    sqlite3_key(sqlite_db, password, strlen(password));

    char * err_msg = 0;
    int res = sqlite3_exec(
        sqlite_db,
        "create table if not exists key_value(id INTEGER PRIMARY KEY, key VARCHAR(128), value TEXT);",
        0,
        0,
        &err_msg
    );

    if (res != SQLITE_OK) {
        output_warning(err_msg);
        sqlite3_close(sqlite_db);

        return 0;
    }

    return 1;
}

void vault_close() {
    if (0 != sqlite_db) {
        sqlite3_close(sqlite_db);
    }

    sqlite3_shutdown();
}

void vault_print_help() {
    printf("Usage: vault --database <database> [options]\n");
    printf("\t--database\tPath to vault database\n");
    printf("\t--password\tPassword for vault database\n");
    printf("\t--version \tVersion details\n");
    printf("\t--help    \tShow this message\n");
}

