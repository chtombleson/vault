/**
 * main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "vault.h"
#include "output.h"

void print_usage() {
    printf("Usage: vault --database <database> --password <password>\n");
    printf("\t--database\tPath to vault database\n");
    printf("\t--password\tPassword for vault database\n");
    printf("\t--version \tVersion details\n");
    printf("\t--help    \tShow this message\n");
}

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

    opt = getopt_long(argc, argv, "d:p:vh", long_options, &long_index);

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
                print_usage();
                exit(0);
                break;

            default:
                break;
        }

        opt = getopt_long(argc, argv, "d:p:vh", long_options, &long_index);
    }

    // Much sure database and password option is not empty
    if (!database || !password) {
        print_usage();
        exit(1);
    }

    int initialised = vault_init(database, password);

    if (!initialised) {
        output_warning("Unable to initialise vault");
        vault_close();
        exit(1);
    }

    vault_close();

    return 0;
}

