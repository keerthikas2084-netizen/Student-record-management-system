#include <stdio.h>
#include "student.h"

int main()
{
    struct student *head = NULL;
    char choice, option;

    load_students(&head);

    while (1) 
    {   
        printf("\n===== STUDENT RECORD MANAGEMENT =====\n");
        printf("A : Add Student\n");
        printf("D : Delete Student\n");
        printf("S : Show Students\n");
        printf("M : Modify Student\n");
        printf("V : Save Students\n");
        printf("T : Sort Students\n");
        printf("L : Delete All Students\n");
        printf("R : Reverse List\n");
        printf("E : Exit\n");

        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'A':
            case 'a':
                add_student(&head);
                break;

            case 'D':
            case 'd':
                delete_student(&head);
                break;

            case 'S':
            case 's':
                show_students(head);
                break;

            case 'M':
            case 'm':
                modify_student(head);
                break;

            case 'V':
            case 'v':
                save_students(head);
                break;

            case 'T':
            case 't':
                sort_students(&head);
                break;

            case 'L':
            case 'l':
                delete_all(&head);
                break;

            case 'R':
            case 'r':
                reverse_students(&head);
                break;

            case 'E':
            case 'e':
                printf("S : Save and Exit\n");
                printf("E : Exit without saving\n");
                printf("Enter choice: ");
                scanf(" %c", &option);

                if (option == 'S' || option == 's')
                    save_students(head);
                else if (option != 'E' && option != 'e')
                {
                    printf("Invalid choice!\n");
                    break;
                }

                delete_all(&head);
                printf("Thank you!\n");
                return 0;
       
                default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
