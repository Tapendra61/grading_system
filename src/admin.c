
#include "stdlib.h"
#include "string.h"
#include"../include/admin.h"

void viewtrecord(){}
void searchs(){}
void delete(){}
void calculate(){}

void addstudent()
{
    char ch;
    char is_continue;
    FILE *file_ptr;
    int sub_counter = 1;

    struct Student input_student;
    struct Student read_student;

    file_ptr = fopen("grading_system/app/student_info.txt", "a+");
    if (file_ptr == NULL)
    {
        printf("\n\t\tFILE DOESN'T EXIST\n");
        exit(0);
    }

    do
    {
        printf("\t\t\t =======Add Student input_student======\n\n\n ");
        printf("\n\t\t\t Enter your symbol no :");
        scanf("%d",&input_student.symbol_no);
        fflush(stdin);
        printf("\n\t\t\tEnter first name :");
        gets(input_student.first_name);
        printf("\n\t\t\tEnter last name :");
        gets(input_student.last_name);
        printf("\n\t\t\tEnter your date of birth in  DD/MM/YYYY:");
        gets(input_student.DOB);

        fflush(stdin);
      

        printf("\n\t\t\tEnter  subject name :");
        gets(input_student.subject[0]);
        printf("\n\t\t\tEnter  %s grade :", input_student.subject[0]);
        scanf("%d", &input_student.marks[0]);

        printf("\n\t\t\tDo you want to continue adding new subject(y/Y) :");
        scanf("%c", &is_continue);
        strupr(is_continue);
        while (is_continue != 'Y')
        {
        add_new_sub:
            printf("\n\t\t\tEnter  subject name :");
            gets(input_student.subject[sub_counter]);
            printf("\n\t\t\tEnter  %d grade :", input_student.subject[sub_counter]);
            scanf("%d", &input_student.marks[sub_counter]);
            printf("\n\t\t\tDo you want to continue adding new subject(y/Y) :");
            scanf("%c", &is_continue);
            strupr(is_continue);
            if (is_continue == 'Y')
            {
                sub_counter++;
            }
            else
            {
            reask:
                printf("\n\t\t\tAre you sure you want to exit(y/n):");
                scanf("%c", &is_continue);
                strupr(is_continue);
                if (is_continue == 'Y')
                {
                    break;
                }
                else if (is_continue == 'N')
                {
                    goto add_new_sub;
                }
                else
                {
                    printf("\n\t\t\tPlease press Y or N. ");
                    goto reask;
                }
            }
        }

        printf("\n\t\t\t-------------------------------\n");
        fflush(stdin);

    //    while (fread(&read_student, sizeof(struct Student), 1, file_ptr))
    //     {
    //         if
    //     }

        fwrite(&input_student, sizeof(struct Student), 1, file_ptr);

        printf("\n\t\t\tFILE HAS BEEN SUCCESFULLY ADDED");
        fclose(file_ptr);
        printf("\t\t\tDo you want to add another record?(y\n): ");
        scanf("%s", &ch);

    } while (ch == 'y' || ch == 'Y');
}


void menu()
{
    int choice;

    while (1)
    {

        printf("\t\t\t=======STUDENT DATABASE======= ");
        printf("\n\n\n\t\t\t 1.Add Student Record\n ");
        printf("\t\t\t 2.View Student Record\n ");
        printf("\t\t\t 3.Search Student Record\n ");
        printf("\t\t\t 4.Delete Student Record\n ");
        printf("\t\t\t 5.Calculate Student Record\n ");
        printf("\t\t\t 6.Exit\n ");
        printf("\t\t ------------------------------------------------------\n ");
        printf("\t\t\t Enter your choice \n ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            addstudent();

            break;
        case 2:
            viewtrecord();
            break;
        case 3:
            searchs();
            break;
        case 4:
            delete ();
            break;
        case 5:
            calculate();
            break;
        case 6:
            exit(0);
            break;
        }
    }
}
