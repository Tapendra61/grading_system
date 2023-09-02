#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

typedef struct{
	char username[50];
	unsigned char password_hash[64];
}User;

void entry();
void login();
void account_register();
void exit_program(int error_code);
int is_password_user_valid(char password[])

int login_validator(char username[], char password[]);

#endif