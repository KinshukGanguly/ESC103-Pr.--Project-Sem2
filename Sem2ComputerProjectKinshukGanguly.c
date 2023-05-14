/*PROJECT ON EMPLOYEE MANAGEMENT SYSTEM ...
FEATURES-
CREATION OF TEXT FILE CONTAINING RECORDS
CREATING NEW RECORDS
DELETING RECORDS
MODIFYING EXISTING RECORDS
VIEWING A SPECIFIC RECORD


Submitted by Kinshuk Ganguly, Sec-D ,Roll 20, Stream-C.S.E(AIML)


*/

#include <stdio.h>
#include<string.h>


void create()
 { FILE*fptr=fopen("EmployeeData.txt","a");
   char name[50];
   char ID[10];
   char title[50];
   char salary[8];
   printf("CREATING NEW RECORD....\nEnter:\nEmployee ID\nName\nJob title\nSalary Amount \n") ;
   scanf(" %[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c",&ID, &name, title, &salary);
   fprintf(fptr,"%s,%s,%s,%s\n",ID,name,title,salary);
   printf("\nRECORD CREATED..........");
   fclose(fptr);
 }//end of createRecords
 
 
void deleteRecord()
 {char searchID[10];
  printf("Enter the employee ID\n");
  scanf("%s",&searchID);
  FILE* fptr=fopen("EmployeeData.txt","r");
  fseek(fptr,0,SEEK_END);
  int x=ftell(fptr);
  char CopyFile[100+x];
  fseek(fptr,0,SEEK_SET);
  char line[100];
   printf("DELETING RECORD.......\n");
  int flag=0;
  while(fgets(line,100,fptr)!=NULL)
     {char templine[100];
      strcpy(templine,line);//making copy of each line
      char *tok=strtok(line,",");//storing the first token
      char ID[10];
      strcpy(ID,tok);//storing employee ID in variable
	  if(strcmp(searchID,ID)==0) //found the record
	  {  flag=1;
	     
	  }
	  else
	  {
	   strcat(CopyFile,templine);
      }
	 }
  fclose(fptr);
  
  if(flag==1)
  { 
  FILE* fptr=fopen("EmployeeData.txt","w");
  fprintf(fptr,"%s",CopyFile); 
  fclose(fptr);
  printf("UPDATED RECORDS-\n");	
  printf("%s",CopyFile);
  }
  else
  {
    printf("SORRY! THE GIVEN EMPLOYEE ID IS NOT REGISTERED IN RECORDS");
  } 
 }//end of deleteRecords()
 
 
 
 
 
 
 void modifyRecord()
{
    char searchID[10];
    printf("Enter the employee ID\n");
    scanf("%s", searchID);
    FILE* fptr = fopen("EmployeeData.txt", "r");
    fseek(fptr, 0, SEEK_END);
    int x = ftell(fptr);
    char CopyFile[100 + x];
    fseek(fptr, 0, SEEK_SET);
    char line[100];
    int flag=0;
    printf("MODIFYING RECORD.......\n");
    while (fgets(line, 100, fptr) != NULL)
    {
        char templine[100];
        strcpy(templine, line); //making copy of each line
        char* tok = strtok(line, ","); //storing the first token
        char ID[10];
        strcpy(ID, tok); //storing employee ID in variable
        if (strcmp(searchID, ID) == 0) //found the record
        {   flag=1;
            char newRecord[100];
            char name[20];
            char job[20];
            char salary[8];

            tok = strtok(NULL, ",");
            strcpy(name, tok);

            tok = strtok(NULL, ",");
            strcpy(job, tok);

            tok = strtok(NULL, ",");
            strcpy(salary, tok);
           
             
            char temp;
            int uc;
            char newData[30];
            printf("Enter the field to be updated\n1.Employee ID\n2.Name\n3.Job title\n4.Salary\n");
	        scanf("%d",&uc);
	        printf("Enter new data: ");
	        scanf("%c",&temp); // temp statement to clear buffer
	        scanf("%[^\n]",newData);
            
            
            
            
            if (uc == 1)
            {
                strcpy(ID, newData);
            }
            else if (uc == 2)
            {
                strcpy(name, newData);
            }
            else if (uc == 3)
            {
                strcpy(job, newData);
            }
            else if (uc == 4)
            {
                strcpy(salary, newData);
                strcat(salary,"\n");
            
            }
            
            sprintf(CopyFile, "%s%s,%s,%s,%s", CopyFile,ID, name, job, salary);
            
        }
        else
        { strcat(CopyFile, templine);
        }
    }
    
  fclose(fptr);
  
  if(flag==1)
  {
  FILE* fpt=fopen("EmployeeData.txt","w");
  fprintf(fpt,"%s",CopyFile); 
  fclose(fpt);
  printf("UPDATED RECORDS-\n");	
  printf("%s",CopyFile);
  }
  else
  printf("SORRY! THE GIVEN EMPLOYEE ID IS NOT REGISTERED IN RECORDS\n");

  
}//end of modifyRecords()
   
 
 
 void viewRecord()
 {char searchID[10];
  printf("Enter the employee ID\n");
  scanf("%s",&searchID);
  FILE* fptr=fopen("EmployeeData.txt","r");
  fseek(fptr,0,SEEK_END);
  int x=ftell(fptr);
  char CopyFile[100+x];
  fseek(fptr,0,SEEK_SET);
  char line[100];
  int flag=0;
  printf("DISPLAYING EMPLOYEE DATA\n");
  while(fgets(line,100,fptr)!=NULL)
     {char templine[100];
      strcpy(templine,line);//making copy of each line
      char *tok=strtok(line,",");//storing the first token
      char ID[10];
      strcpy(ID,tok);//storing employee ID in variable
	  if(strcmp(searchID,ID)==0) //found the record
	  { flag=1;
	    char name[20];
	    char job[20];
	    char salary[8];
	    
	    tok=strtok(NULL,",");
	    strcpy(name,tok);
	    
	    tok=strtok(NULL,",");
	    strcpy(job,tok);
	    
	    tok=strtok(NULL,",");
	    strcpy(salary,tok);
	    printf("REQUIRED EMPLOYEE DETAILS-\n");
	    printf("EMPLOYEE ID=%s\nNAME=%s\nJOB TITLE=%s\nSALARY=%s\n",&ID,&name,&job,&salary);
	    
	    break;
	  }
	  
	 }
    if(flag==0)
    { printf("SORRY! THE GIVEN EMPLOYEE ID IS NOT REGISTERED IN RECORDS");
    }
 fclose(fptr);
}//end of viewRecords()
 
 
 int main() 
{
 printf("MENU-\n1.Initiate DataBase\n2.Create Record\n3.Delete Record\n4.View record\n5.Modify record\n6.EXIT system");
 int choice;
 for(;;)
 {

 printf("\nEnter choice\n"); 
 scanf("%d",&choice);
 
  if (choice==1)
  { FILE*fptr=fopen("EmployeeData.txt","w");
   fprintf(fptr,"EMPLOYEE ID,Name,Job Title,Salary\n");
   printf("DATABASE CREATED");
   fclose(fptr);
  }
  else if(choice==2)
  { 
 	create();
  }
  else if(choice==3)
 {  deleteRecord();
   }  
 else if(choice==4)
 { viewRecord();
  }   
  else if(choice==5)
 {  modifyRecord();
  }   
  else if(choice==6)
  { break;
    }  
 }//end of for
   return 0;
}//end of main()

