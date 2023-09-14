#include "../include/modify.h"
#include "../include/admin.h"
#include "calculator.h"
void modify()
{
    int symbol_no = 0, found_student= 0,is_student_present=0,date_is_valid=0,name_valid=0;
    struct Student read_student,temp_record;
    FILE *file_ptr;
    FILE *tempfile_ptr;
    file_ptr= fopen("resources/student_info.txt", "rb");
    tempfile_ptr=fopen("resources/dummy_student_info.txt","wb");
    if (file_ptr== NULL || tempfile_ptr== NULL )
    {
        printf("\nFILE DOESN'T EXIST\n");
        getchar();
        exit(0);
    }
    
    printf("\n\n ======= Modify Records ======\n\n");
    find:
    printf("\nEnter symbol number: ");
    scanf("%d", &symbol_no);
    if(symbol_no>999)
    {
        while (fread(&read_student, sizeof(struct Student), 1, file_ptr))
        {   
            if (read_student.symbol_no == symbol_no)
            {
                found_student = 1;
                again_name:
                printf("\nEnter New first name: ");
                scanf("%s", temp_record.first_name);
                fflush(stdin);
                printf("Enter New last name: ");
                scanf("%s", temp_record.last_name);
                fflush(stdin);
                name_valid = name_is_valid(temp_record.first_name,temp_record.last_name);
                if(!name_valid)
                {
                    goto again_name;
                }
                temp_record.symbol_no=read_student.symbol_no;
                again_DOB:
                printf("\nEnter your New date of birth in  DD/MM/YYYY: ");
                printf("\nEnter day: ");
                scanf("%d", &temp_record.DOB[0]);
                printf("Enter month: ");
                scanf("%d", &temp_record.DOB[1]);
                printf("Enter year: ");
                scanf("%d", &temp_record.DOB[2]);
                date_is_valid=check_DOB( temp_record.DOB);
                if(!date_is_valid)
                {
                    goto again_DOB;
                }
                again_subject:
                printf("\nEnter how many subjects you want: ");
                scanf("%d", &temp_record.no_of_sub);
                if(temp_record.no_of_sub>8)
                {
                    printf("\nsubjects cannot be more than 8.");
                    goto again_subject;
                }
                
                for (int i = 0; i <temp_record.no_of_sub; i++)
                {
                    fflush(stdin);
                    printf("\nEnter subject name: ");
                    scanf("%s", temp_record.subject[i]);
                    fflush(stdin);
                    again_marks:
                    printf("Enter  marks for %s: ", temp_record.subject[i]);
                    scanf("%d", &temp_record.marks[i]);
                    if(temp_record.marks[i]<0 || temp_record.marks[i]>100)
                    {
                        printf("\nInvalid input for marks.");
                        goto again_marks;
                    }
                    temp_record.gpa[i]=calculate_gpa(temp_record.marks[i]);
                    strcpy(temp_record.grade[i],calculate_grade(temp_record.marks[i]));
                }
                fwrite(&temp_record, sizeof(struct Student), 1, tempfile_ptr);
            
            }
            else
            {
                fwrite(&read_student, sizeof(struct Student), 1, tempfile_ptr);
            }      
        }
        fclose(tempfile_ptr);
        fclose(file_ptr);
        remove("resources/student_info.txt");
        rename("resources/dummy_student_info.txt","resources/student_info.txt");
    } 
    else
    {
        printf("\nPlease enter a valid symbol number.");
        goto find;
    }
    printf("\nThe students' record was successfully modified!!");
    getchar();
}

void delete()
{
    int input_id_to_remove=0;
    FILE *file_ptr;
    FILE *newfile_ptr;
    struct Student read_student;
    file_ptr = fopen("resources/student_info.txt", "rb");
    newfile_ptr = fopen("resources/new_student_info.txt", "wb");
    if (file_ptr == NULL|| newfile_ptr == NULL )
    {
        fflush(stdin);
        printf("\nFILE DOESN'T EXIST\n");
        getchar();
        menu();
    }
    printf("Enter the symbol of student to remove the data: ");
    scanf("%d",&input_id_to_remove);
    while(fread(&read_student,sizeof(struct Student),1,file_ptr))
    {
        if(read_student.symbol_no != input_id_to_remove)
        {
            fwrite(&read_student,sizeof(struct Student),1,newfile_ptr);
        }
    }
    fclose(file_ptr);
    fclose(newfile_ptr);
    remove("resources/student_info.txt");
    rename("resources/new_student_info.txt","resources/student_info.txt");
    printf("Removed entry with Symbol no: %d from the records.", input_id_to_remove);
    getchar();
}
