/**
 * vault.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "output.h"
#include "vault.h"

struct vault vault_init(const char * database, const char * password) {
    struct vault vault;

    vault.database = database;

    if (!password) {
        char pass[64];

        printf(
            "%s%s%s: ",
            OUTPUT_COLOR_YELLOW,
            "Enter database password [max 32 characters]",
            OUTPUT_COLOR_RESET
        );

        scanf("%s", pass);

        vault.password = pass;
    }

    sqlite3 *db;

    int rc = sqlite3_open(vault.database, &db);

    if (rc != SQLITE_OK) {
        output_warning("Warning unable to open database");
        sqlite3_close(db);

        exit(1);
    }

    //sqlite3_key(&db, vault.password, strlen(vault.password));

    vault.sqlite = db;

    return vault;
}

void vault_close(struct vault * vault) {
    sqlite3_close(vault->sqlite);
    free(vault);
}

