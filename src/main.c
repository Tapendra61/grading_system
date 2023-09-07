#include"../include/calculator.h"

int main() {
	Info subject;
	subject.marks1=50;
	float gpa;
	char* grade;
	gpa=calculate_gpa(subject.marks1);
	printf("%.1f",gpa);
	grade=calculate_grade(subject.marks1);
	printf("%s",grade);
	free(grade);
	getchar();
	return 0;
}