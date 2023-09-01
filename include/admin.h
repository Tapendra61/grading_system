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
    int subject1;
    int subject2;
    int subject3;
    int subject4;
    int subject5;
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