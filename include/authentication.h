#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "Windows.h"
#include "utility.h"

typedef struct{
	char username[31];
	unsigned char password_hash[64];
}User;

void entry();
void login();
void account_register();
void exit_program(int error_code);
int is_password_user_valid(char password_user[]);
int user_already_registered(char username[], FILE* file);
int login_validator(char username[], char password[]);

#endif