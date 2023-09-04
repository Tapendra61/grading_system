#ifndef UTILITY_H
#define UTILITY_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "openssl/evp.h"

int is_file_empty(FILE* file);
unsigned char* password_hash(char password[]);

#endif