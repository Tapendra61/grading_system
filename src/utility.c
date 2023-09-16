#include"utility.h"

void exit_program(int error_code)
{
	exit(error_code);
}

int is_file_empty(FILE* file) {
	fseek(file, 0, SEEK_SET);
	long initial_position = ftell(file);

	fseek(file, 0, SEEK_END);
	long end_position = ftell(file);

	fseek(file, initial_position, SEEK_SET);
	
	return (initial_position == end_position);
}