/**
 * output.h
 */
#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#define OUTPUT_COLOR_RESET          "\033[0m"
#define OUTPUT_COLOR_BLACK          "\033[22;30m"
#define OUTPUT_COLOR_WHITE          "\033[01;37m"$
#define OUTPUT_COLOR_RED            "\033[22;31m"
#define OUTPUT_COLOR_GREEN          "\033[22;32m"
#define OUTPUT_COLOR_BROWN          "\033[22;33m"
#define OUTPUT_COLOR_BLUE           "\033[22;34m"
#define OUTPUT_COLOR_MAGENTA        "\033[22;35m"
#define OUTPUT_COLOR_CYAN           "\033[22;36m"
#define OUTPUT_COLOR_YELLOW         "\033[01;33m"
#define OUTPUT_COLOR_GRAY           "\033[22;37m"
#define OUTPUT_COLOR_DARK_GRAY      "\033[01;30m"
#define OUTPUT_COLOR_LIGHT_RED      "\033[01;31m"
#define OUTPUT_COLOR_LIGHT_GREEN    "\033[01;32m"
#define OUTPUT_COLOR_LIGHT_BLUE     "\033[01;34m"
#define OUTPUT_COLOR_LIGHT_MAGENTA  "\033[01;35m"
#define OUTPUT_COLOR_LIGHT_CYAN     "\033[01;36m"

void output_error(const char * msg);
void output_warning(const char * msg);
void output_debug(const char * msg);
void output_info(const char * msg);

#endif

