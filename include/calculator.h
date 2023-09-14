#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
float calculate_gpa(int marks);
char *calculate_grade(int marks);
float calculate_cgpa(int no_of_subjects,float gpa[]);
#endif