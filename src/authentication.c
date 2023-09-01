#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Windows.h"
#include "authentication.h"
#include "utility.h"

void entry() {
	system("cls");
	int selected_option = 0;
	printf("-------Grading System-------\n");
	printf("1. Login\n");
	printf("2. Register\n");
	printf("3. Exit\n");
	scanf("%d", &selected_option);

	switch(selected_option) {
		case 1:
			printf("logging in");
			login();
		break;

		case 2:
			printf("registering");
			account_register();
		break;

		case 3:
			exit_program(0);
		break;

		default:
			printf("Invalid option selected. Try again");
			Sleep(666);
			printf(".");
			Sleep(666);
			printf(".");
			Sleep(666);
			printf(".");
			Sleep(666);
			entry();
		break;
	}
	fflush(stdin);
}

void login() {
	char input_username[50];
	char input_password[50];
	system("cls");
	printf("-------Login-------\n");
	printf("Enter your Login ID: ");
	scanf("%[^\n]", input_username);
	printf("Enter your password: ");
	scanf("%[^\n]", input_password);

}

void account_register() {
	fflush(stdin);
	User user;
	char password[50];
	FILE* user_data;

	system("cls");
	printf("--------Register Account-------\n");
	printf("Enter a new login ID: \n");
	scanf("%[^\n]", user.username);
	fflush(stdin);
	printf("Enter a new password: ");
	scanf("%[^\n]", password);

	user_data = fopen("resources/user_data.DAT", "r+");
	if(user_data == NULL) {
		printf("Could not read the user_data file or could not create the file.");
		Sleep(3000);
		exit_program(1);
	}

	//---TODO--- Generate Hash of the password and store that instead of plain password
	strcpy(user.password_hash, password);
	if(is_file_empty(user_data)) {
		fwrite(&user, sizeof(User), 1, user_data);
	}
	//
}

void exit_program(int error_code) {
	exit(error_code);
}

int login_validator(char username[], char password[]) {
	return 0;
}

