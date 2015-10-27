/**
 * vault.h
 */
#define VAULT_VERSION "0.1"

struct vault {
    const char * database;
    const char * password;
};

struct vault vault_init(const char * database, const char * password);

