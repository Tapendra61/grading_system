#include"utility.h"

int is_file_empty(FILE* file) {
	fseek(file, 0, SEEK_SET);
	long initial_position = ftell(file);

	fseek(file, 0, SEEK_END);
	long end_position = ftell(file);

	fseek(file, initial_position, SEEK_SET);
	
	return (initial_position == end_position);
}

//---TODO---
//update the hashing function to use OpenSSL 3.0 non-depricated version
unsigned char* password_hash(char password[]) {
	unsigned char* hashed_password;
	
	EVP_MD_CTX* mdctx = EVP_MD_CTX_new();

	if(mdctx == NULL) {
		printf("Unable to allocate memory for message digest ctx.");
		return NULL;
	}

	return hashed_password;
}