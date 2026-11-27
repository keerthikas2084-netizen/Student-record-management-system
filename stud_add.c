#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void add_student(struct student **head)
{
    struct student *newnode, *temp;
    int roll = 1, found;

    newnode = malloc(sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    // Find smallest unused roll number
    while(1)
    {
        found = 0;
        temp = *head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if(found == 0)
            break;

        roll++;
    }

    newnode->rollno = roll;

    getchar();

     printf("Enter student name: ");
    if(fgets(newnode->name, sizeof(newnode->name), stdin) == NULL)
    {
        free(newnode);
        return;
    }

    newnode->name[strcspn(newnode->name, "\n")] = '\0';

    if(strlen(newnode->name) == 0)
    {
        printf("Name cannot be empty!\n");
        free(newnode);
        return;
    }

    printf("Enter percentage: ");

    if(scanf("%f", &newnode->percentage) != 1 ||
       newnode->percentage < 0 ||
       newnode->percentage > 100)
    {
        printf("Invalid percentage!\n");
        free(newnode);
        return;
    }

    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
       temp->next = newnode;
    }

    printf("Student added successfully!\n");
    printf("Assigned Roll Number: %d\n", roll);
}
