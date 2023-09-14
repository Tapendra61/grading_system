#include "../include/calculator.h"
float gpa_map[] = {0.00, 1.75, 2.50, 3.00, 3.5, 3.75, 4.0};
float calculate_gpa(int marks)
{
    int index;
    if (marks <= 39)
    {
        return gpa_map[0];
    }
    else if (marks == 100)
    {
        return gpa_map[6];
    }
    else
    {
        index = (marks / 10) - 3;
        return gpa_map[index];
    }
}
char grade_map[8][3] = {"F", "D", "C", "B", "B+", "A", "A+"};
char *calculate_grade(int marks)
{
    char *grade;
    grade = (char *)malloc(3 * sizeof(char));
    int index = 0;
    if (marks <= 39)
    {
        strcpy(grade, grade_map[0]);
        return grade;
    }
    else if (marks == 100)
    {
        strcpy(grade, grade_map[6]);
        return grade;
    }
    else
    {
        index = (marks / 10) - 3;
        strcpy(grade, grade_map[index]);
        return grade;
    }
}
float calculate_cgpa(int no_of_subjects, float gpa[]);
{
    float sum_gpa;
    for (int i = 0; i < no_of_subjects; i++)
    {
        sum_gpa += gpa[i];
    }
    return sum_gpa / no_of_subjects;
}
