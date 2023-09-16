#ifndef UTILITY_H
#define UTILITY_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"

int is_file_empty(FILE *file);
void exit_program(int error_code);

#endif