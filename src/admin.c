#include "../include/admin.h"
void menu()
{
    system("cls");
    int choice;
    printf("=======STUDENT DATABASE======= ");
    printf("\n1.Add Student Record\n");
    printf("2.View Student Record\n");
    printf("3.Search Student Record\n");
    printf("4.Delete Student Record\n");
    printf("5.Edit Student Record\n");
    printf("6.Exit\n");
    printf("------------------------------------\n");
    re_choice:
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            addstudent();
            menu();
        break;

        case 2:
            viewrecord();
        break;

        case 3:
            search();
        break;
            // case 4:
            //     delete ();
            //     getchar();
            //     break;
            // case 5:
            //     calculate();
            //     getchar();
            //     break;
        case 6:
            exit(0);
        break;

        default:
            printf("\nInvalid Choice");
            Sleep(1000);
            menu();
        break;
    }
}
void addstudent()
{
    char ch;
    char is_continue[1];
    FILE *file_ptr;
    int sub_counter = 1;
    int is_student_present = 0;
    int no_of_sub = 0;
    int i = 0;

    struct Student input_student;
    struct Student read_student;

    file_ptr = fopen("resources/student_info.txt", "r+");
    if (file_ptr == NULL)
    {
        printf("\nFILE DOESN'T EXIST\n");
        getchar();
        exit(0);
    }

    printf("\n=======Add Student input_student======\n");
    printf("\nEnter first name: ");
    scanf("%s", input_student.first_name);
    fflush(stdin);
    printf("Enter last name: ");
    scanf("%s", input_student.last_name);
    fflush(stdin);
    printf("\nEnter your symbol no: ");
    scanf("%d", &input_student.symbol_no);
    printf("\nEnter your date of birth in  DD/MM/YYYY: ");
    printf("\nEnter day: ");
    scanf("%d", &input_student.DOB[0]);
    printf("Enter month: ");
    scanf("%d", &input_student.DOB[1]);
    printf("Enter year: ");
    scanf("%d", &input_student.DOB[2]);
    printf("\nEnter how many subjects you want: ");
    scanf("%d", &no_of_sub);
    
    for (i = 0; i < no_of_sub; i++)
    {
        fflush(stdin);
        printf("\nEnter subject name: ");
        scanf("%s", input_student.subject[i]);
        fflush(stdin);
        printf("Enter  marks for %s: ", input_student.subject[i]);
        scanf("%d", &input_student.marks[i]);
    }
    while (fread(&read_student, sizeof(struct Student), 1, file_ptr))
    {
        if (read_student.symbol_no == input_student.symbol_no)
        {
            is_student_present = 1;
            break;
        }
    }
    if (!is_student_present)
    {
        fwrite(&input_student, sizeof(struct Student), 1, file_ptr);
    }
    printf("\nFILE HAS BEEN SUCCESFULLY ADDED");
    fclose(file_ptr);
    Sleep(1000);
}

void viewrecord()
{
    FILE *file_ptr;
    int i;

    file_ptr = fopen("resources/student_info.txt", "r");
    if (file_ptr == NULL)
    {
        printf("\nFILE DOESN'T EXIST\n");
        getchar();
        exit(0);
    }
    struct Student read_student;
    printf("\n=======Student Records======\n");
    printf("\n --------------------------------\n");
    while (fread(&read_student, sizeof(struct Student), 1, file_ptr))
    {
        printf("\nStudent symbol no : %d ", read_student.symbol_no);
        printf("\nStudent name : %s  %s", read_student.first_name, read_student.last_name);
        printf("\nStudent Date of birth : %d/%d/%d", read_student.DOB[0], read_student.DOB[1], read_student.DOB[2]);
        for (i = 0; i < read_student.no_of_sub; i++)
        {
            printf("\nSubject : %s ", read_student.subject[i]);
            printf("\nSubject marks: %d", read_student.marks[i]);
        }
        printf("\n-------------------------------\n");
    }
    fclose(file_ptr);
    getchar();
}


void search()
{
    int symbol_no = 0, found_student= 0;
    char first_name[20];
    FILE *file_ptr;
    int no_of_sub;
    int i;
    file_ptr= fopen("resources/student_info.txt", "r");
    if (file_ptr== NULL)
    {
        printf("\nFILE DOESN'T EXIST\n");
        exit(0);
    }
    struct Student read_student;
    printf("\n ======= Search Student ======\n\n\n ");
    find:
    printf("\nEnter first name:");
    scanf("%s",first_name);
    printf("\nEnter symbol :");
    scanf("%d", &symbol_no);

    while (fread(&read_student, sizeof(struct Student), 1, file_ptr) > 0)
    
    {   
        if(strlen(first_name)>0&&symbol_no==0)
        {
            if(strcmp(read_student.first_name,first_name)==0)
            {
                found_student = 1;
            printf("\nStudent symbol no : %d ", read_student.symbol_no);
            printf("\nStudent name : %s  %s", read_student.first_name, read_student.last_name);
            printf("\nStudent Date of birth : %d/%d/%d", read_student.DOB[0], read_student.DOB[1], read_student.DOB[2]);
            for (i = 0; i < no_of_sub; i++)
            {
                printf("\nSubject : %s ", read_student.subject[i]);
                printf("\nSubject marks: %d", read_student.marks[i]);
            }

            printf("\n-----------------------------------\n");
            }
        }
        else if (read_student.symbol_no == symbol_no)
        {
            found_student = 1;
            printf("\nStudent symbol no : %d ", read_student.symbol_no);
            printf("\nStudent name : %s  %s", read_student.first_name, read_student.last_name);
            printf("\nStudent Date of birth : %d/%d/%d", read_student.DOB[0], read_student.DOB[1], read_student.DOB[2]);
            for (i = 0; i < no_of_sub; i++)
            {
                printf("\nSubject : %s ", read_student.subject[i]);
                printf("\nSubject marks: %d", read_student.marks[i]);
            }

            printf("\n-----------------------------------\n");
        }
        else
        {
            printf("\nPlease search by first name or symbol no");
            goto find;
        }
    }
    if (found_student = 0)
    {
        printf("\n\t\t\tRecords not found_student :");
        
    }
    fclose(file_ptr);
    getchar();
}
