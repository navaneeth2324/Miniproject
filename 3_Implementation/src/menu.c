#include<stdio.h>
#include "contact.h"
#include<stdlib.h>
void menu()
{
    system("cls");
    printf("\t\t**Contact Management System**");

    printf("\nMENU\n");
    printf("\n1.Add Contact\n2.List\n3.Exit\n4.Modify\n5.Search\n6.Delete\n");
    printf("\nEnter your Choice:");
    int choice;                                         //choices between 0-5 for operations
    scanf("%d",&choice);
    switch(choice)
    {
        case '1':
            create_contact();
            break;
        case '2':
            list_contacts();
            break;
        case '3':
            exit(0);
            break;
        case '4': 
            edit_contact();
            break;
        case '5':
            search_contacts();
            break;
        case '6':
            delete_contact();
            break;
        default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

             menu();
    }
}