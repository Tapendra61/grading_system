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
	fflush(stdin);
    switch (choice)
    {
        case 1:
            addstudent();
            menu();
        break;

        case 2:
			fflush(stdin);
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
    char is_continue[1];
    FILE *file_ptr;
    int sub_counter = 1;
    int is_student_present = 0;
    int date_is_valid;
    int name_valid;

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
    again_name:
    printf("\nEnter first name: ");
    scanf("%s", input_student.first_name);
    fflush(stdin);
    printf("Enter last name: ");
    scanf("%s", input_student.last_name);
    fflush(stdin);
    name_valid = name_is_valid(input_student.first_name,input_student.last_name);
    if(!name_valid){
        goto again_name;
    }
    again_symbol:
    printf("\nEnter your symbol no: ");
    scanf("%d", &input_student.symbol_no);
    while (fread(&read_student, sizeof(struct Student), 1, file_ptr))
    {
        if (read_student.symbol_no == input_student.symbol_no)
        {
            is_student_present = 1;
            printf("\nStudent with %d symbol number already exists.\n",input_student.symbol_no);
            goto again_symbol;
            menu();
        }
    }
    again_DOB:
    printf("\nEnter your date of birth in  DD/MM/YYYY: ");
    printf("\nEnter day: ");
    scanf("%d", &input_student.DOB[0]);
    printf("Enter month: ");
    scanf("%d", &input_student.DOB[1]);
    printf("Enter year: ");
    scanf("%d", &input_student.DOB[2]);
    date_is_valid=check_DOB( input_student.DOB);
    if(!date_is_valid)
    {
        goto again_DOB;
    }
    again_subject:
    printf("\nEnter how many subjects you want: ");
    scanf("%d", &input_student.no_of_sub);
    if(input_student.no_of_sub>8)
    {
        printf("\nsubjects cannot be more than 8.");
        goto again_subject;
    }
    
    for (int i = 0; i <input_student.no_of_sub; i++)
    {
        fflush(stdin);
        printf("\nEnter subject name: ");
        scanf("%s", input_student.subject[i]);
        fflush(stdin);
        again_marks:
        printf("\nEnter  marks for %s: ", input_student.subject[i]);
        scanf("%d", &input_student.marks[i]);
        if(input_student.marks[i]<0 || input_student.marks[i]>100)
        {
            printf("\nInvalid input for marks.");
            goto again_marks;
        }
    }
  
    if (!is_student_present)
    {
        fwrite(&input_student, sizeof(struct Student), 1, file_ptr);
    }
    printf("\nFILE HAS BEEN SUCCESFULLY ADDED");
    fclose(file_ptr);
    Sleep(3000);
}

void viewrecord()
{
	char quit;
    struct Student read_student;
    FILE *file_ptr;
    int i;

    file_ptr = fopen("resources/student_info.txt", "r");
    if (file_ptr == NULL)
    {
        printf("\nFILE DOESN'T EXIST\n");
        getchar();
        exit(0);
    }
   
    printf("\n=======Student Record======\n");
  
    while (fread(&read_student, sizeof(struct Student), 1, file_ptr))
    {
        printf("\nStudent symbol no : %d ", read_student.symbol_no);
        printf("\nStudent name : %s  %s", read_student.first_name, read_student.last_name);
        printf("\nStudent Date of birth : %d/%d/%d", read_student.DOB[0], read_student.DOB[1], read_student.DOB[2]);
        for (i = 0; i < read_student.no_of_sub; i++)
        {
            printf("\nSubject: %s ", read_student.subject[i]);
            printf("\nSubject marks: %d", read_student.marks[i]);
        }
        printf("\n-------------------------------\n");
    }
    fclose(file_ptr);
	again_quit:
	printf("\n Enter Y to exit the program and N to go back to menu: ");
    quit=getchar();
	fflush(stdin);
	tolower(quit);
	switch (quit)
	{
		case 'y':
			exit(0);
		break;
		case 'n':
			menu();
		break;
		default:
			printf("invalid option");
			goto again_quit;
		break;
	}
}


void search()
{
    struct Student read_student;
    int symbol_no = 0, found_student= 0;
    FILE *file_ptr;
    int no_of_sub;
    int i;
    file_ptr= fopen("resources/student_info.txt", "r");
    if (file_ptr== NULL)
    {
        printf("\nFILE DOESN'T EXIST\n");
        exit(0);
    }
    
    printf("\n\n ======= Search Records ======\n\n");
    //printf("\nEnter first name:");
    //scanf("%s",first_name);
    find:
    printf("\nEnter symbol number: ");
    scanf("%d", &symbol_no);
    if(symbol_no>999)
    {
         while (fread(&read_student, sizeof(struct Student), 1, file_ptr))
        {   
           /* if(strcmp(read_student.first_name,first_name)==0)
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
            }*/
        
            if (read_student.symbol_no == symbol_no)
            {
                found_student = 1;
                printf("\nStudent symbol number: %d ", read_student.symbol_no);
                printf("\nStudent name: %s  %s", read_student.first_name, read_student.last_name);
                printf("\nStudent Date of birth: %d/%d/%d", read_student.DOB[0], read_student.DOB[1], read_student.DOB[2]);
                printf("\n no of subjects = %d",read_student.no_of_sub);
                for (i = 0; i <read_student.no_of_sub; i++)
                {
                    printf("\nSubject: %s ", read_student.subject[i]);
                    printf("\nSubject marks: %d", read_student.marks[i]);
                }

                printf("\n-----------------------------------\n");
            }
        
       
        }
        if (found_student == 0)
        {
            printf("\nRecord not found.");
        
        }
        
    }
    else
    {
        printf("\nPlease enter a valid symbol number.");
        goto find;
    }
    fclose(file_ptr);
    getchar();
}

int check_DOB(int* date)
{
    if(*date<1 || *date>32)
    {
        printf("\n Invalid input for day.");
        Sleep(2000);
        return 0;
    }
    else if (*(date+1)<1 || *(date+1)>12)
    {
        printf("\n Invalid input for month.");
        Sleep(2000);
        return 0;
    }
    else if(*(date+2)<2050||*(date+2)>2065)
    {
        printf("\n Invalid input for age.");
        Sleep(2000);
       return 0;
    }
    return 1;
}
int name_is_valid(char firstname[], char lastname[]){
    for(int i=0; i<strlen(firstname);i++)
    {
            if(!isalpha(firstname[i]))
            {
                printf("\nInvalid input! Only alphabets are accepted.\n");
                return 0;
            }
            
    }
    for(int i=0; i<strlen(lastname);i++)
    {
            if(!isalpha(lastname[i]))
            {
                printf("\nInvalid input! Only alphabets are accepted.\n");
                return 0;
            }
            
    }
    return 1;
    
}