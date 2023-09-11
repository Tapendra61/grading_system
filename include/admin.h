#ifndef ADMIN_H
#define ADMIN_H
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"
#include "ctype.h"
#include "calculator.h"
#include "modify.h"

struct Student
{
    char first_name[20];
    char last_name[20];
    unsigned int symbol_no;
    int DOB[3];
    int no_of_sub;
    char subject[8][30];
    int marks[8];
    float gpa[8];
    char grade[8][2];
    float cgpa;
};

void menu();
void addstudent();
void viewrecord();
void search();
int name_is_valid(char[],char[]);
int check_DOB(int*);

#endif