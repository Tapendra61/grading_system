#include "../include/calculator.h"
float gpa_map[]={0,1.6,2.0,2.4,2.8,3.2,3.6,4.0};
float calculate_gpa(int marks)
{
    int index;
    if(marks<=34)
    {
        return gpa_map[0];
    } 
    else if(marks==100) {
        return gpa_map[7];
    }
    else{
        index=(marks/10)-2;
        return gpa_map[index];
    }
    
}
char grade_map[8][3]={"F","D","C","C+","B","B+","A","A+"};
char* calculate_grade(int marks)
{
    char* grade;
    grade = (char*) malloc(2*sizeof(char));
    int index;
    if(marks<=34)
    {
        strcpy(grade,grade_map[0]);
    } 
    else if(marks==100) {
        strcpy(grade,grade_map[7]);
    }
    else{
        index=(marks/10)-2;
        strcpy(grade,grade_map[index]);
    }
    return grade;
}

