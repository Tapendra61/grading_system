#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "authentication.h"

void entry() {
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
			printf("Invalid option selected. Try again!");
			entry();
		break;
	}
	fflush(stdin);
}

void login() {
	system("cls");
	printf("-------Login-------\n");

}

void account_register() {

}

void exit_program(int error_code) {
	exit(error_code);
}



