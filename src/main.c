/**
 * main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "vault.h"
#include "output.h"

int main(int argc, char **argv) {
    // Parse command line arguments
    static struct option long_options[] = {
        {"database", required_argument, NULL, 'd'},
        {"password", required_argument, NULL, 'p'},
        {"version", no_argument, NULL, 'v'},
        {"help", no_argument, NULL, 'h'},
        {NULL, no_argument, NULL, 0}
    };

    int opt = 0;
    int long_index = 0;

    const char *database = 0;
    const char *password = 0;

    opt = getopt_long(argc, argv, "d:p::vh", long_options, &long_index);

    while (opt != -1) {
        switch (opt) {
            case 'd':
                database = optarg;
                break;

            case 'p':
                password = optarg;
                break;

            case 'v':
                printf("Version: %s\n", VAULT_VERSION);
                exit(0);
                break;

            case 'h':
                vault_print_help();
                exit(0);
                break;

            default:
                break;
        }

        opt = getopt_long(argc, argv, "d:p::vh", long_options, &long_index);
    }

    // Much sure database option is not empty
    if (!database) {
        vault_print_help();
        exit(1);
    }

    printf("Database: %s\n", database);

    if (password) {
        printf("Password: %s\n", password);
    }

    /*
    // Much sure database option is not empty
    if (!args.database) {
        output_error("Database is required: ./vault --database test.db\n");
    }

    int initialised = vault_init(args.database);
    vault_close();*/

    return 0;
}

