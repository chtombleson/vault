/**
 * output.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "output.h"

void output_error(const char * msg) {
    printf("%s%s%s\n", OUTPUT_COLOR_RED, msg, OUTPUT_COLOR_RESET);
    exit(1);
}

void output_warning(const char * msg) {
    printf("%s%s%s\n", OUTPUT_COLOR_YELLOW, msg, OUTPUT_COLOR_RESET);
}

void output_debug(const char * msg) {
    printf("%s%s%s\n", OUTPUT_COLOR_GREEN, msg, OUTPUT_COLOR_RESET);
}

void output_info(const char * msg) {
    printf("%s%s%s\n", OUTPUT_COLOR_LIGHT_GREEN, msg, OUTPUT_COLOR_RESET);
}
