#include <stdio.h>
#include <string.h>
#include "student.h"

void modify_student(struct student *head)
{
    struct student *temp;
    int roll, count = 0;
    char choice, name[50];
    float percentage;
    int found = 0;

    if(head == NULL)
    {   
        printf("No records available!\n");
        return;
    }   

    printf("\nR : Search by roll number\n");
    printf("N : Search by name\n");
    printf("P : Search by percentage\n");

    printf("Enter choice: ");
    scanf(" %c", &choice);

    if(choice == 'r' || choice == 'R')
    {   
        printf("Enter roll number: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }   

    else if(choice == 'n' || choice == 'N')
     {
        getchar();

        printf("Enter student name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        temp = head;

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll: %d Name: %s Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                count++;
            }

            temp = temp->next;
        }

        if(count == 0)
        {
            printf("Student not found!\n");
            return;
        }

        printf("Enter roll number to modify: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll &&
               strcmp(temp->name, name) == 0)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }

    else if(choice == 'p' || choice == 'P')
    {
        printf("Enter percentage: ");
        scanf("%f", &percentage);

        if(percentage < 0 || percentage > 100)
        {
            printf("Invalid percentage!\n");
            return;
        }

        temp = head;

        while(temp != NULL)
        {
            if(temp->percentage >= percentage - 0.005 &&
               temp->percentage <= percentage + 0.005)
            {
                printf("Roll: %d Name: %s Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                count++;
            }

            temp = temp->next;
        }

        if(count == 0)
        {
            printf("Student not found!\n");
            return;
        }

        printf("Enter roll number to modify: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll &&
               temp->percentage >= percentage - 0.005 &&
               temp->percentage <= percentage + 0.005)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }

    else
    {
        printf("Invalid choice!\n");
        return;
    }

    if(found == 0)
    {
        printf("Record not found!\n");
        return;
    }

    printf("\nCurrent Details:\n");
    printf("Roll No: %d\n", temp->rollno);
    printf("Name: %s\n", temp->name);
    printf("Percentage: %.2f\n", temp->percentage);

    getchar();

    printf("Enter new name: ");
    if(fgets(name, sizeof(name), stdin) == NULL)
        return;

    name[strcspn(name, "\n")] = '\0';

    if(strlen(name) == 0)
    {
        printf("Name cannot be empty!\n");
        return;
    }

    printf("Enter new percentage: ");

    if(scanf("%f", &percentage) != 1 ||
       percentage < 0 || percentage > 100)
    {
        printf("Invalid percentage!\n");
        return;
    }
      strcpy(temp->name, name);
    temp->percentage = percentage;

    printf("Record modified successfully!\n");
}
