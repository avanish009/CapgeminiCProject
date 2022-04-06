#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "setdisplay.h"
#include "emplog.h"
#include "func.h"

#define CAR 1
#define SCOOTER 2



void registration()
{
    system("clear");
    first( );
    FILE *ptr;

    ptr = fopen("emp.dat","ab");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    emp d1;
    
    printf("\t\tCREATING AN ACCOUNT");
    printf("\n\n\n\t\tEnter Name: ");
    scanf("%s",d1.name);
    fflush(stdin);   
    printf("\n\t\tEnter User Name: ");
    scanf("%s",d1.id);
    printf("\n\t\tEnter Password: ");
    scanf("%s",d1.pass);


    fwrite(&d1,sizeof(d1),1,ptr);
    
    fclose(ptr);
    
    second();
    
}

void read_emp()
{
   
    FILE *ptr;

    ptr = fopen("emp.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    emp  d1;
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
    printf("Name : %s\n",d1.name);
    printf("Uname : %s\n",d1.id);
    printf("Password : %s\n\n",d1.pass);
    }   	
       
    fclose(ptr);   
         
}

void login()
{
    system("clear");
    first( );
    FILE *ptr;
    
    char uname[20];
    char pword [20];

    ptr = fopen("emp.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    emp d1;
   
 
        printf(" \n                      ENTER USERNAME:-");
	scanf("%s", uname); 
	printf(" \n                      ENTER PASSWORD:-");
	scanf("%s",pword);
	
	
	 while(fread(&d1,sizeof(d1),1,ptr))
        {
		if(strcmp(uname,d1.id)==0 && strcmp(pword,d1.pass)==0)
	{       
	        fclose(ptr);
	        menu();
	        break;
	}
	
}
	 
	
}       

void menu()
{       
        system("clear");
        first( );
        int input;
        printf ( "\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb VEHICLE PARKING \xdb\xdb\xdb\xdb\xdb\xdb\xdb\n" ) ;	
        printf ( "\n\t1 >> Arrival Of Vehicle\n" ) ;
	printf ( "\n\t2 >> Total No. Of Vehicles Parked\n" ) ;
	printf ( "\n\t3 >> Total No. Of Cars Parked\n" ) ;
	printf ( "\n\t4 >> Total No. Of Scooters Parked\n" ) ;
	printf ( "\n\t5 >> Display Vehicles Parked (Order)\n" ) ;
	printf ( "\n\t6 >> Departure Of Vehicle\n" ) ;
	printf ( "\n\t7 >> Exit\n" ) ;
	printf ("\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	printf(" \n\n Enter Your Choice Here:");
	scanf("%d",&input);
	
        if(input == 1)
        {    
            add();
        }
        else if(input == 2)
        {
            totalcount();
        }
        else if(input == 3)
        {    
            carcount();
        }
        else if(input == 4)
        {
            scootercount();
        }
        else if(input == 5)
        {
            display();
        }
        else if(input == 6)
        {
            del();
        }
        else if(input == 7)
        {
            exit(EXIT_SUCCESS);
        }
        else if(input == 9)
        {
            reset( );
        }
} 