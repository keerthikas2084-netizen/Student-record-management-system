#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void delete_student(struct student **head)
{
    struct student *temp, *prev;
    int roll, found = 0;
    char choice;
    char name[50];

    if(*head == NULL)
    {   
        printf("No records available!\n");
        return;
    }   

    printf("\nR : Delete by roll number\n");
    printf("N : Delete by name\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);

    if(choice == 'r' || choice == 'R')
    {   
        printf("Enter roll number: ");
        scanf("%d", &roll);
    }   
    else if(choice == 'n' || choice == 'N')
    {   
        getchar();

        printf("Enter student name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        temp = *head;

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll No: %d  Name: %s\n",
                       temp->rollno, temp->name);
                found = 1;
        }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Student not found!\n");
            return;
        }

        printf("Enter roll number to delete: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    temp = *head;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->rollno == roll)
        {
            if(choice == 'n' || choice == 'N')
            {
                if(strcmp(temp->name, name) != 0)
                {
                    printf("Selected roll number does not match name!\n");
                    return;
                }
            }

            if(prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);

             printf("Record deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Record not found!\n");
}


void delete_all(struct student **head)
{
    struct student *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *head = NULL;

    
}
