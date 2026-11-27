#include <stdio.h>
#include <string.h>
#include "student.h"

void sort_students(struct student **head)
{
    struct student *i, *j; 
    int choice;
    int roll;
    float percentage;
    char name[50];

    if(*head == NULL || (*head)->next == NULL)
    {   
        printf("Not enough records to sort!\n");
        return;
    }   

    printf("\nN : Sort by name\n");
    printf("P : Sort by percentage\n");
    printf("Enter choice: ");

    char ch; 
    scanf(" %c", &ch);

    if(ch == 'n' || ch == 'N')
        choice = 1;
    else if(ch == 'p' || ch == 'P')
        choice = 2;
    else
    {   
        printf("Invalid choice!\n");
        return;
    }   

    for(i = *head; i->next != NULL; i = i->next)
    {   
        for(j = i->next; j != NULL; j = j->next)
        {
            int swap = 0;

            if(choice == 1 &&
               strcmp(i->name, j->name) > 0)
                swap = 1;
            if(choice == 2 &&
                i->percentage < j->percentage)
                  swap = 1;
  
             if(swap)
              {
                  roll = i->rollno;
                  i->rollno = j->rollno;
                  j->rollno = roll;
  
                  strcpy(name, i->name);
                  strcpy(i->name, j->name);
                  strcpy(j->name, name);
 
                  percentage = i->percentage;
                  i->percentage = j->percentage;
                  j->percentage = percentage;
              }
          }
     }
  
      printf("Sorting completed successfully!\n");
}
