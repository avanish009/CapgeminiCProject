#ifndef STRUCTURE_H
#define STRUCTURE_H

struct emp                          
{
    char name[30];
    char id[20];
    char pass[20];
};

  struct pos
     {
	int row ;
	int col ;
        
     }; 
     
typedef struct pos pos;
typedef struct emp emp;


#endif