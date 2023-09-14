#include "authentication.h"

void entry()
{
	system("cls");
	int selected_option = 0;
	printf("-------Grading System-------\n");
	printf("1. Login\n");
	printf("2. Register\n");
	printf("3. Exit\n");
	scanf("%d", &selected_option);
	switch (selected_option)
	{
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

void login()
{
	char input_username[50];
	char input_password[50];
	system("cls");
	printf("-------Login-------\n");
	printf("Enter your Login ID: ");
	scanf("%[^\n]", input_username);
	printf("Enter your password: ");
	scanf("%[^\n]", input_password);
}

void account_register()
{
	fflush(stdin);
	User user;
	char user_name[31];
	char password[31];
	FILE *user_data;
	int user_exists;
	user_data = fopen("resources/user_data.DAT", "rb+");
	if (user_data == NULL)
	{
		printf("Could not read the user_data file or could not create the file.");
		Sleep(2000);
		exit_program(1);
	}

	system("cls");
	printf("--------Register Account-------\n");

re_username:
	printf("Enter a new login ID: \n");
	scanf("%s", user_name);
	fflush(stdin);

	// Check if the user is already registered
	user_exists = user_already_registered(user_name, user_data);
	if (user_exists)
	{
		printf("The user id: %s already exists! Press enter key to try again...", user_name);
		user_exists = 0;
		getchar();
		goto re_username;
	}

	// Check if username is valid
	if (!is_password_user_valid(user_name))
	{
		printf("Username can only contain AlphaNumeric values and should not exceed 30 characters. Try again!\n");
		memset(user_name, 0, sizeof(user_name));
		Sleep(1500);
		goto re_username;
	}
	strcpy(user.username, user_name);

// Take password input from user
re_password:
	printf("Enter a new password: ");
	scanf("%s", password);
	fflush(stdin);

	// Check if password is valid alpha numeric
	if (!is_password_user_valid(password))
	{
		printf("Password can only contain AlphaNumeric values and should not exceed 30 characters. Try again!\n");
		memset(password, 0, sizeof(password));
		Sleep(1500);
		goto re_password;
	}

	User read_user;
	strcpy(user.password_hash, password);
	if (is_file_empty(user_data))
	{
		fwrite(&user, sizeof(User), 1, user_data);
	}
	else
	{
		fseek(user_data, 0, SEEK_END);
		fwrite(&user, sizeof(User), 1, user_data);
	}
}

void exit_program(int error_code)
{
	exit(error_code);
}

// Check if username and password contains only alphaNumberic characters
int is_password_user_valid(char password_user[])
{
	int length = strlen(password_user);
	int i = 0;
	if (length == 0 || length > 30)
		return 0;
	for (i = 0; i < length; i++)
	{
		if (!isalnum((unsigned char)password_user[i]))
		{
			return 0;
		}
	}
	return 1;
}

int user_already_registered(char username[], FILE *file)
{
	int user_exists = 0;
	User read_user;
	while (fread(&read_user, sizeof(User), 1, file))
	{
		if (strcmp(read_user.username, username) == 0)
		{
			user_exists = 1;
			break;
		}
	}
	return user_exists;
}

int login_validator(char username[], char password[])
{
	return 0;
}