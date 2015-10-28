/**
 * vault.h
 */
#include <sqlite3.h>
#define VAULT_VERSION "0.1"

sqlite3 *sqlite_db;

int vault_init(const char *database);
void vault_close();

void vault_print_help();
