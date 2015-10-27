/**
 * main.c
 */

#include <stdio.h>
#include "vault.h"
#include "output.h"
#include "../deps/commander/src/commander.h"

struct arguments {
    const char * database;
} args;

static void database_arg(command_t *self) {
    args.database = self->arg;
}

int main(int argc, char **argv) {
    // Parse command line arguments
    command_t cmd;
    command_init(&cmd, argv[0], VAULT_VERSION);
    command_option(&cmd, "-d", "--database <arg>", "path to database file", database_arg);
    command_parse(&cmd, argc, argv);
    command_free(&cmd);

    // Much sure database option is not empty
    if (!args.database) {
        output_error("Database is required: ./vault --database test.db\n");
    }

    struct vault vault;
    vault = vault_init(args.database);
    vault_close(&vault);

    return 0;
}

