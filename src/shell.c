/**
 * shell.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../deps/linenoise/linenoise.h"
#include "output.h"
#include "vault.h"
#include "shell.h"

int shell_running = 0;

void shell_run() {
    shell_running = 1;

    printf("Vault version %s\n", VAULT_VERSION);
    printf("Enter \"help\" for list of commands\n");

    char *line;

    while(shell_running) {
        while ((line = linenoise("vault> ")) != 0) {
            if (line[0] != '\0') {
                printf("%s", line);
                linenoiseHistoryAdd(line);

                if (line == SHELL_ACTION_HELP) {

                }

                if (line == SHELL_ACTION_EXIT) {
                    shell_close();
                }
            }
        }

        free(line);
    }
}

void shell_close() {
    shell_running = 0;
}

