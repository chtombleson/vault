/**
 * shell.h
 */
#ifndef _SHELL_H_
#define _SHELL_H_

#define SHELL_ACTION_ADD        "add"
#define SHELL_ACTION_DELETE     "delete"
#define SHELL_ACTION_GET        "get"
#define SHELL_ACTION_UPDATE     "update"
#define SHELL_ACTION_HELP       "help"
#define SHELL_ACTION_EXIT       "exit"

void shell_run();
void shell_close();

#endif
