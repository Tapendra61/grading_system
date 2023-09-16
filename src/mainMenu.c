#include "mainMenu.h"

void main_menu()
{
	while (1)
	{
	re_main_menu:
		system("cls");
		int choice = 0;
		printf("--------Main Menu-------");
		printf("\n1. Admin");
		printf("\n2. Student");
		printf("\n3. Exit");
		printf("\nPlease enter your choice: ");
		scanf("%d", &choice);
		fflush(stdin);

		switch (choice)
		{
		case 1:
			entry();
			break;

		case 2:
			view_student_record();
			fflush(stdin);
			getchar();
			break;
		case 3:
			exit_program(0);
			break;
		default:
			printf("The entered choice is not valid. Please try again....");
			Sleep(2000);
			goto re_main_menu;
			break;
		}
	}
}