#pragma once

#define LEXER_OUTPUT_FILE_NAME "output.tok"
#define ERROR_LOG_FILE "errors.txt"
#include <string.h>



int lex(char* file);

/* writing lex errors into log */
void writeLexErrorsIntoLog(int fileSize);

