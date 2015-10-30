/**
 * vault.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <uuid/uuid.h>
#include "output.h"
#include "vault.h"

const char *database_key_value_schema = "CREATE TABLE IF NOT EXISTS"
                                        " key_value(uuid VARCHAR PRIMARY KEY,"
                                        " name VARCHAR UNIQUE, value TEXT)";

int vault_init(const char *database, const char *password) {
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

    // Create schema if needed
    res = sqlite3_exec(
        sqlite_db,
        database_key_value_schema,
        0,
        0,
        &err_msg
    );

    if (res != SQLITE_OK) {
        output_warning(err_msg);
        vault_close();

        return 0;
    }

    vault_add_key_value_record("hello", "world");

    return 1;
}

void vault_add_key_value_record(const char *name, const char *value) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO key_value (uuid, name, value) VALUES (?, ?, ?)";

    // Get uuid
    uuid_t uuid;
    uuid_generate_time_safe(uuid);

    char uuid_str[37];
    uuid_unparse_lower(uuid, uuid_str);

    // Prepare sql
    int res = sqlite3_prepare_v2(
        sqlite_db,
        sql,
        -1,
        &stmt,
        0
    );

    if (res == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, uuid_str, sizeof(uuid_str), 0);
        sqlite3_bind_text(stmt, 2, name, strlen(name), 0);
        sqlite3_bind_text(stmt, 3, value, strlen(value), 0);

        res = sqlite3_step(stmt);

        if (res == SQLITE_OK) {
            sqlite3_finalize(stmt);
        }
    }
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

