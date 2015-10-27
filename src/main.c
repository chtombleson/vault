/**
 * main.c
 */

#include <stdio.h>
#include "output.h"
#include "../deps/commander/src/commander.h"

struct arguments {
    const char * config;
    const char * database;
    const char * password;
} args;

static void config_arg(command_t *self) {
    args.config = self->arg;
}

static void password_arg(command_t *self) {
    args.password = self->arg;
}

static void database_arg(command_t *self) {
    args.database = self->arg;
}

int main(int argc, char **argv) {
    // Parse command line arguments
    command_t cmd;
    command_init(&cmd, argv[0], "0.1");
    command_option(&cmd, "-c", "--config [arg]", "path to config file", config_arg);
    command_option(&cmd, "-p", "--password [arg]", "password for database", password_arg);
    command_option(&cmd, "-d", "--database <arg>", "path to database file", database_arg);
    command_parse(&cmd, argc, argv);
    command_free(&cmd);

    output_warning("Warning");
    output_debug("Debug");
    output_info("Info");

    // Much sure database is not empty
    if (!args.database) {
        output_error("Database is required: ./vault --database test.db\n");
    }

    return 0;
}

