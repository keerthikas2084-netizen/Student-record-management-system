#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define STUDENT_H

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

void add_student(struct student **head);
void delete_student(struct student **head);
void show_students(struct student *head);
void modify_student(struct student *head);
void save_students(struct student *head);
void load_students(struct student **head);
void sort_students(struct student **head);
void reverse_students(struct student **head);
void delete_all(struct student **head);

#endif
