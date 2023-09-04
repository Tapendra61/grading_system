#include"utility.h"

int is_file_empty(FILE* file) {
	fseek(file, 0, SEEK_SET);
	long initial_position = ftell(file);

	fseek(file, 0, SEEK_END);
	long end_position = ftell(file);

	fseek(file, initial_position, SEEK_SET);
	
	return (initial_position == end_position);
}

unsigned char* password_hash(char password[]) {
	unsigned char* hashed_password;
	hashed_password = (unsigned char*) malloc(SHA512_DIGEST_LENGTH * sizeof(unsigned char));
	if(hashed_password == NULL) {
		printf("\nFailed to allocate memory: hashed_password!");
		printf("\nEnter any key to continue...");
		getchar();
		return NULL;
	}

	SHA512_CTX sha512;
	SHA512_Init(&sha512);
	SHA512_Update(&sha512, password, strlen(password));
	SHA512_Final(hashed_password, &sha512);

	return hashed_password;
}