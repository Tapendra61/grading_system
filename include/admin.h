#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char first_name[20];
    char last_name[20];
    int symbol_no[15];
    char grade[2];
    int DOB[15];
    char subject1;
    char subject2;
    char subject3;
    char subject4;
    char subject5;
    int marks1;
    int marks2;
    int marks3;
    int marks4;
    int marks5;
    char grade1;
    char grade2;
    char grade3;
    char grade4;
    char grade5;
    float gpa;
    float gpa1;
    float gpa2;
    float gpa3;
    float gpa4;
    float gpa5;
};

void menu();
void addstudent();
void viewtrecord();
void searchs();




#endif