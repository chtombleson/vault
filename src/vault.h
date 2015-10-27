/**
 * vault.h
 */
#include <sqlite3.h>
#define VAULT_VERSION "0.1"

struct vault {
    const char *database;
    const char *password;
};

sqlite3 *sqlite_db;

struct vault vault_init(const char * database);
void vault_close();
