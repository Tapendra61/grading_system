#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

typedef struct {
	char username[50];
	char password[50];
}User;

void entry();
void login();
void account_register();
void exit_program(int error_code);

#endif