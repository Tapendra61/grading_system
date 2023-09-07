#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct {
    int marks1;
}Info;
float calculate_gpa(int marks);
char* calculate_grade(int marks);

#endif