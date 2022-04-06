#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "setdisplay.h"
#include "emplog.h"
#include "func.h"

#define CAR 1
#define SCOOTER 2


void first( )
{
	printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb       =============================           \xdb\n");
	printf("\t\t\xdb        VEHICLE PARKING MANAGEMENT             \xdb\n");
	printf("\t\t\xdb       =============================           \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb             FROM GROUP SIX                    \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb                 ABC MALL                      \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
	
}

void second()
{   
    system("clear");
    first();
    int input;
    printf("\t\tEMPLYOEE PORTAL");
    printf("\n\n\t\t1 >> Register new user\n\t\t2 >> Login existing user\n\t\t3 >> Exit \n\n\n");
    printf("\n\n\tPress here to continue... ");
    scanf("%d",&input);
      if(input == 1)
        {    
            system("clear");
            registration();
        }

    else if(input == 2)
        {
            system("clear");
            login();
        }
        
   else if(input == 3)
        {
            exit(EXIT_SUCCESS);
        }
   else if(input == 4)
        {
            read_emp();
        }      
    
}