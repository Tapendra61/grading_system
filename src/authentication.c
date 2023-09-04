#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
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
	char user_name[31];
	char password[31];
	unsigned char* hashed_password;
	FILE* user_data;

	system("cls");
	printf("--------Register Account-------\n");

	re_username:
	printf("Enter a new login ID: \n");
	scanf("%[^\n]", user_name);
	fflush(stdin);

	if(!is_password_user_valid(user_name)){
		printf("Username can only contain AlphaNumeric values and should not exceed 30 characters. Try again!\n");
		memset(user_name, 0, sizeof(user_name));
		Sleep(1500);
		goto re_username;
	}

	strcpy(user.username, user_name);

	re_password:
	printf("Enter a new password: ");
	scanf("%[^\n]", password);
	fflush(stdin);

	if(!is_password_user_valid(password)){
		printf("Password can only contain AlphaNumeric values and should not exceed 30 characters. Try again!\n");
		memset(password, 0, sizeof(password));
		Sleep(1500);
		goto re_password;
	}

	user_data = fopen("resources/user_data.DAT", "r+");
	if(user_data == NULL) {
		printf("Could not read the user_data file or could not create the file.");
		Sleep(2000);
		exit_program(1);
	}

	//Generate Hash of the password and store that instead of plain password
	hashed_password = password_hash(password);
	if(hashed_password != NULL) {
		memcpy(user.password_hash, hashed_password, SHA512_DIGEST_LENGTH);
		printf("\n%s\n%s", hashed_password, user.password_hash);
		free(hashed_password);
	}else {
		printf("Authentication.c: line %d hashed_password is null.", __LINE__);
	}

	if(is_file_empty(user_data)) {
		fwrite(&user, sizeof(User), 1, user_data);
	}
	//
}

void exit_program(int error_code) {
	exit(error_code);
}

//Check if username and password contains only alphaNumberic characters
int is_password_user_valid(char password_user[]){
	int length = strlen(password_user);
	int i = 0;
	if(length == 0 || length > 30) return 0;
	for(i = 0; i < length; i++) {
		if(!isalnum((unsigned char)password_user[i])) {
			return 0;
		}
	}
	return 1;
}

int login_validator(char username[], char password[]) {
	return 0;
}

