#ifndef STUDENT_H
#define STUDENT_H
#include<stdio.h>
struct Student
{
    char first_name[20];
    char last_name[20];
    unsigned int symbol_no;
    int DOB[3];
    char subject[5][50];
    int marks[5];
    char grade[5][3];
    float gpa[5];
};
void write_data();
void view_student_record();
#endif