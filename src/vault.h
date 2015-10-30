/**
 * vault.h
 */
#include <sqlite3.h>
#define VAULT_VERSION "0.1"
#define VAULT_DATABASE_KEY_VALUE_SCHEMA "CREATE TABLE IF NOT EXISTS key_value(uuid VARCHAR PRIMARY KEY, name VARCHAR UNIQUE, value TEXT)"

// Variables
sqlite3 *sqlite_db;

// API
int vault_init(const char *database, const char *password);
void vault_add_key_value_record(const char *name, const char *value);
void vault_close();

void vault_print_help();

