#include<stdio.h>
#include "contact.h"
#include<stdlib.h>
/**
 * @brief Function to search a contact from the list
 * 
 */
void search_contacts()
{
    struct person p;
    FILE *f;
    char name[100];

    f=fopen("project","rb");
    if(f==NULL)
    {
        printf("\n error in opening\a\a\a\a");
        exit(1);
    }
    printf("\nEnter name of person to search\n");
    got(name);
    while(fread(&p,sizeof(p),1,f)==1)
    {
        if(strcmp(p.name,name)==0)
        {
            printf("\n\tDetail Information About %s",name);
            printf("\nName=%s\nAdress=%s\nMobile no=%ld\nE-mail=%s",p.name,p.address,p.mble_no,p.mail);
            
        }
            else
            printf("file not found");
            

    }
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}