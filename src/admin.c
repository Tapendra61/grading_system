#include "admin.h"
#include "stdlib.h"

void menu(){
 int choice;
 
 while(1)
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
    scanf("%d,&choice");
    switch(choice){
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
        delete();
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
 void addstudent(){
  char ch;
  FILE *file_ptr;
  
  
  struct Student student;
   file_ptr=fopen("grading_system/app/student_info.txt","r");
  if(file_ptr==NULL)
  {
     printf("\n\t\tFILE DOESN'T EXIST\n");
     exit(0);
  }
  
  do{
    printf("\t\t\t =======Add Student student======\n\n\n ");
    
    printf("\n\t\t\tEnter first name :");
    gets(student.first_name);
    printf("\n\t\t\tEnter last name :");
    gets(student.last_name);
    printf("\n\t\t\tEnter grade :");
    gets(student.grade);
    fflush(stdin);
    printf("\n\t\t\tEnter  :");

    printf("\n\t\t\tEnter  subject1 name :");
    gets(student.subject1);
printf("\n\t\t\tEnter  %s grade :",student.subject1);
    scanf("%d",&student.grade1);


    printf("\n\t\t\t-------------------------------\n");
    fflush(stdin);
    
    fread(&student,sizeof(struct read_student),1,file_ptr);
    {
  
    fwrite(&student,sizeof( struct input_student ),1,file_ptr);
    }
    printf("\n\t\t\tFILE HAS BEEN SUCCESFULLY ADDED");
    fclose(file_ptr);
    printf("\t\t\tDo you want to add another record?(y\n): ");
    scanf("%s",&ch);
 

    


  }while(ch=='y'||ch=='Y');
}
 

 