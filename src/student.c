#include "student.h"
#include "stdlib.h"
#include "string.h"

void view_student_record()
{
    char empty_string[] = " ";
    system("cls");
    FILE *student_info;
    unsigned int read_symbol_no;
    printf("-------View Student Record-------");
    printf("\nEnter your symbol number: ");
    scanf("%d", &read_symbol_no);
    fflush(stdin);
    student_info = fopen("resources/student_info.txt", "rb");
    if (student_info == NULL)
    {
        printf("Student_info file is exit");
        exit(1);
    }
    struct Student read_student;
    int i = 0;
    int student_found = 0;
    while (fread(&read_student, sizeof(struct Student), 1, student_info))
    {
        if (read_student.symbol_no == read_symbol_no)
        {
            student_found = 1;
            printf("\n\tSymbol_no: %d", read_student.symbol_no);
            printf("\n---------------------------------------------");
            printf("\n\nStudent name : %s %s", read_student.first_name, read_student.last_name);
            printf("\n\nDate of Birth: %d /%d /%d", read_student.DOB[0], read_student.DOB[1], read_student.DOB[2]);
            printf("\n\nSubjects:");
            for (i = 0; i < read_student.no_of_sub; i++)
            {
                printf("\n%-30s%10d%10.2f%10s ", read_student.subject[i], read_student.marks[i], read_student.gpa[i], read_student.grade[i]);
            }
            printf("\n\nCGPA:%.2f", read_student.cgpa);
        }
    }
    if (student_found == 0)
    {
        printf("\nYou have entered wrong symbol number! Try again!");
        read_symbol_no = 0;
        fclose(student_info);
        return;
    }
    fclose(student_info);
}