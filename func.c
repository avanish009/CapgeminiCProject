#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "setdisplay.h"
#include "emplog.h"
#include "func.h"

#define CAR 1
#define SCOOTER 2

int parkinfo[4][10] ; 



void display( )
{ 
    system("clear");
    first();
  FILE *ptr;

    ptr = fopen("data.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  int r, c ;

  printf ( "\t\t\t==== CARS ====\n\n" ) ;
  while(fread(&parkinfo,sizeof(parkinfo),1,ptr))
        {
  for ( r = 0 ; r < 4 ; r++ )
  {
    if ( r == 2 )
		  printf ( "\t\t\t==== SCOOTERS ====\n\n" ) ;

    for ( c = 0 ; c < 10 ; c++ )
      printf ( "%d\t", parkinfo[r][c] ) ;
    printf ( "\n\n" ) ;
	}
	}
   fclose(ptr);
   

   printf(" \n\t Press Enter Key To Continue:");
   getchar();
   getchar(); 
   menu();
   
} 


void reset( )
{ 
   FILE *ptr;

    ptr = fopen("data.dat","wb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  int r=0, c = 0 ;


  for ( r = 0 ; r < 4 ; r++ )
  {

    for ( c = 0 ; c < 10 ; c++ )
       parkinfo[r][c] = 0 ;
        
	}
   fwrite(&parkinfo,sizeof(parkinfo),1,ptr);
   
   fclose(ptr);
}  

void add()
{   
         system("clear");
         first( );
         FILE *ptr;
         int type;
         int number;
         int flag =0;
         int r, c,r1,c1 ;
   
    pos p2;

    ptr = fopen("data.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  

     
     pos p1;

    
         printf ( "\n\t\t\t==== ADD VEHICLE ==== \n\n" ) ;

          type = 0 ;

         
          while ( type != CAR && type != SCOOTER )
          {
					  printf ( "\t\tEnter vehicle type (1 for Car / 2 for Scooter ):  " ) ;
            scanf ( "%d", &type ) ;
	          if ( type != CAR && type != SCOOTER )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }

				  printf ( "\n\t\tEnter vehicle number:  " ) ;
				  scanf ( "%d", &number ) ;

				  
				  if ( type == CAR )
				  {
					while(fread(&parkinfo,sizeof(parkinfo),1,ptr))
                               {
                               for ( r = 0 ; r < 2 ; r++ )
                             {
               
                                   for ( c = 0 ; c < 10 ; c++ )
                                      if( parkinfo[r][c] == 0){  
                                      r1 =r;
                                      c1 =c;
                                      
                                      append(r1,c1,number);
                                      flag = 1;
                                      break;
	}
	                if(flag==1);
	                { 
	                 break;
	                }
					  }
					
					  }       
           
               }  
               
                          			  if ( type == SCOOTER )
				  {
					while(fread(&parkinfo,sizeof(parkinfo),1,ptr))
                               {
                               for ( r = 2 ; r < 4 ; r++ )
                             {
               
                                   for ( c = 0 ; c < 10 ; c++ )
                                      if( parkinfo[r][c] == 0){  
                                      r1 =r;
                                      c1 =c;
                                      
                                      append(r1,c1,number);
                                      flag = 1;
                                      break;
	}
	                if(flag==1);
	                { 
	                 break;
	                }
					  }
					
					  }       
           
               } 
               
   printf(" \n\t Succesfully updated the list...");           
   printf(" \n\t Press Enter Key To Continue:");
   getchar();
   getchar(); 
   menu(); 
  }       
           

void append(int row,int col,int number)
{
FILE *ptr;

         ptr = fopen("data.dat","rb+");
         if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  
    
    parkinfo[row][col] = number ;

 
   fwrite(&parkinfo,sizeof(parkinfo),1,ptr);
   
   fclose(ptr);
}



void totalcount()
{   
    system("clear");
    first( );
    FILE *ptr;
    int total;
    int ccount=0;
    int scount=0;

    ptr = fopen("data.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  int r, c ;

  
  while(fread(&parkinfo,sizeof(parkinfo),1,ptr))
        {
  for ( r = 0 ; r < 2 ; r++ )
  {

    for ( c = 0 ; c < 10 ; c++ ){
          if(parkinfo[r][c]!=0){
              ccount++;
          }
    
    }
      
	}
	
	 for ( r = 2 ; r < 4 ; r++ )
  {

    for ( c = 0 ; c < 10 ; c++ ){
          if(parkinfo[r][c]!=0){
              scount++;
          }
    
    }
      
	}
	printf ( "\n\t\t\t====  VEHICLE PARKED ==== \n\n" ) ;
	total =scount + ccount;
	printf ( "\n\t\tTotal Vehicle Parked:  %d",total ) ;
	printf ( "\n\t\tTotal Car Parked:  %d",ccount ) ;
	printf ( "\n\t\tTotal Scooter Parked:  %d",scount ) ;
	
	}
   fclose(ptr);
   
   printf(" \n\n\t Press Enter Key To Continue:");
   getchar();
   getchar(); 
   menu();

}	
   
void carcount()
{   
    system("clear");
    first( );
    FILE *ptr;
    int total;
    int ccount=0;
    

    ptr = fopen("data.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  int r, c ;

  
  while(fread(&parkinfo,sizeof(parkinfo),1,ptr))
        {
  for ( r = 0 ; r < 2 ; r++ )
  {

    for ( c = 0 ; c < 10 ; c++ ){
          if(parkinfo[r][c]!=0){
              ccount++;
          }
    
    }
      
	}
	
        printf ( "\n\t\t\t====  CAR PARKED ==== \n\n" ) ;

	printf ( "\n\t\tTotal Car Parked:  %d",ccount ) ;
	
	
	}
   fclose(ptr);
   
   printf(" \n\n\t Press Enter Key To Continue:");
   getchar();
   getchar(); 
   menu();
   
   
	
	

}

void scootercount()
{   
    system("clear");
    first( );
    FILE *ptr;
    int total;
    int scount=0;
    

    ptr = fopen("data.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  int r, c ;

  
  while(fread(&parkinfo,sizeof(parkinfo),1,ptr))
        {
  for ( r = 2 ; r < 4 ; r++ )
  {

    for ( c = 0 ; c < 10 ; c++ ){
          if(parkinfo[r][c]!=0){
              scount++;
          }
    
    }
      
	}
	
	}
	 printf ( "\n\t\t\t====  SCOOTER PARKED ==== \n\n" ) ;
	

	printf ( "\n\t\tTotal Scooter Parked:  %d",scount ) ;
	
	
	
   fclose(ptr);
   
   printf(" \n\n\t Press Enter Key To Continue:");
   getchar();
   getchar(); 
   menu();
   

}

void del()
{   
         system("clear");
         first( );
         FILE *ptr;
         int type;
         int number;
         int flag =0;
         int r, c,r1,c1 ;
   
    pos p2;

    ptr = fopen("data.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  

     
     pos p1;

    
         printf ( "\n\t\t==== REMOVE VEHICLE ==== \n" ) ;

          type = 0 ;

         
          while ( type != CAR && type != SCOOTER )
          {
					  printf ( "\t\tEnter vehicle type (1 for Car / 2 for Scooter ):  " ) ;
            scanf ( "%d", &type ) ;
	          if ( type != CAR && type != SCOOTER )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }

				  printf ( "\n\t\tEnter vehicle number: " ) ;
				  scanf ( "%d", &number ) ;

				  
				  if ( type == CAR )
				  {
					while(fread(&parkinfo,sizeof(parkinfo),1,ptr))
                               {
                               for ( r = 0 ; r < 2 ; r++ )
                             {
               
                                   for ( c = 0 ; c < 10 ; c++ )
                                      if( parkinfo[r][c] == number){  
                                      r1 =r;
                                      c1 =c;
                                      
                                      detach(r1,c1);
                                      flag = 1;
                                      break;
	}
	                if(flag==1);
	                { 
	                 break;
	                }
					  }
					
					  }       
           
               }  
               
                          			  if ( type == SCOOTER )
				  {
					while(fread(&parkinfo,sizeof(parkinfo),1,ptr))
                               {
                               for ( r = 2 ; r < 4 ; r++ )
                             {
               
                                   for ( c = 0 ; c < 10 ; c++ )
                                      if( parkinfo[r][c] == number){  
                                      r1 =r;
                                      c1 =c;
                                      
                                      detach(r1,c1);
                                      flag = 1;
                                      break;
	}
	                if(flag==1);
	                { 
	                 break;
	                }
					  }
					
					  }       
           
               }  
               
   printf(" \n\t Succesfully updated the list...");           
   printf(" \n\t Press Enter Key To Continue:");
   getchar();
   getchar(); 
   menu(); 
  } 
  
 void detach(int row,int col)
{
FILE *ptr;

         ptr = fopen("data.dat","rb+");
         if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
  
    
    parkinfo[row][col] = 0 ;

 
   fwrite(&parkinfo,sizeof(parkinfo),1,ptr);
   
   fclose(ptr);
}      	