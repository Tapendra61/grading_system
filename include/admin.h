#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char first_name[20];
    char last_name[20];
    int symbol_no;
    char grade[2];
    int DOB[3];
    char subject[8][30];
    int no_of_sub;
    int marks[20];
    float cgpa;
};

void viewtrecord();
void addstudent();
void menu();

#endif