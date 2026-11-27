#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void save_students(struct student *head)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {   
        printf("File opening failed!\n");
        return;
    }   

    temp = head;

    while(temp != NULL)
    {   
        fwrite(&temp->rollno, sizeof(int), 1, fp);
        fwrite(temp->name, sizeof(temp->name), 1, fp);
        fwrite(&temp->percentage, sizeof(float), 1, fp);

        temp = temp->next;
    }   

    fclose(fp);

    printf("Records saved successfully!\n");
}

void load_students(struct student **head)
{
    FILE *fp;
    struct student *newnode, *temp;

    int roll;
    char name[50];
    float percentage;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
      printf("No saved records found!\n");
        return;
    }

    while(fread(&roll, sizeof(int), 1, fp) == 1)
    {
        if(fread(name, sizeof(name), 1, fp) != 1)
            break;

        if(fread(&percentage, sizeof(float), 1, fp) != 1)
            break;

        name[49] = '\0';

        newnode = malloc(sizeof(struct student));

        if(newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            break;
        }

        newnode->rollno = roll;
        for(int i = 0; i < 50; i++)
            newnode->name[i] = name[i];

        newnode->percentage = percentage;
        newnode->next = NULL;

        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            temp = *head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    fclose(fp);

    printf("Records loaded successfully!\n");
}
