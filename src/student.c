#include "student.h"
#include "stdlib.h"
#include "string.h"
void write_data()
{
    struct Student std;
    strcpy(std.first_name, "Sony");
    strcpy(std.last_name, "Tamang");
    std.symbol_no = 1625672873;
    std.marks[0]=44;
    std.marks[1]=45;
    std.marks[2]=60;
    std.marks[3]=55;
    std.marks[4]=55;
    std.gpa[0]=2.55;
    std.gpa[1]=2.56;
    std.gpa[2]=3.00;
    std.gpa[3]=4.00;
    std.gpa[4]=2.00;
    strcpy(std.grade[0],"C+");
    strcpy(std.grade[1],"C+");
    strcpy(std.grade[2],"B+");
    strcpy(std.grade[3],"A+");
    strcpy(std.grade[4],"B");
    std.DOB[0] = 2001;
    std.DOB[1] = 05;
    std.DOB[2] = 22;
    strcpy(std.subject[0], "Math");
    strcpy(std.subject[1], "TC");
    strcpy(std.subject[2], "FOIT");
    strcpy(std.subject[3], "Scit");
    strcpy(std.subject[4], "C");

    FILE *dummy;
    dummy = fopen("resources/dummy.txt", "r+");
    if (dummy == NULL)
    {
        printf("Dummy file is exist");
        exit(1);
    }
    fwrite(&std, sizeof(struct Student), 1, dummy);
    fclose(dummy);
}

void view_student_record()
{
    FILE *dummy;
    unsigned int read_symbol_no;
    re_symbol_no:
    printf("\nEnter your symbol number: ");
    scanf("%d", &read_symbol_no);
    dummy = fopen("resources/dummy.txt", "r");
    if (dummy == NULL)
    {
        printf("Dummy file is exit");
        exit(1);
    }
    struct Student read_student;
    int i=0;
    int student_found=0;
    while (fread(&read_student, sizeof(struct Student), 1, dummy))
    {
        if (read_student.symbol_no == read_symbol_no)
        {
            student_found=1;
            printf("\n\tSymbol_no: %d", read_student.symbol_no);
            printf("\n---------------------------------------------");
            printf("\n\nStudent name : %s %s", read_student.first_name, read_student.last_name);
            printf("\n\nDate of Birth: %d /%d /%d", read_student.DOB[0], read_student.DOB[1], read_student.DOB[2]);
            for (i = 0; i < 5; i++)
            {
                printf("\n\n Subject: %s\t %d\t %f\t %s ", read_student.subject[i],read_student.marks[i],read_student.gpa[i],read_student.grade[i]);
            }
        }
        
    }
    if(student_found==0)
    {
        printf("\nYou have entered wrong symbol number! Try again!");
        read_symbol_no=0;
        fclose(dummy);
        goto re_symbol_no;
    }
    fclose(dummy);
}