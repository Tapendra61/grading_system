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
    char DOB[10];
    char subject[20];
    int marks[20];
    float cgpa;
};

void viewtrecord();
void searchs();
void delete();
void calculate();
void addstudent();
void menu();

#endif