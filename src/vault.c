/**
 * vault.c
 */
#include <stdio.h>
#include <unistd.h>
#include "vault.h"

struct vault vault_init(const char * database, const char * password) {
    struct vault vault;

    // Check if database file exists
    if (access(database, 0) == 0) {

    } else {

    }
}

