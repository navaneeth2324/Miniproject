#include<stdio.h>
#include "contact.h"
#include<stdlib.h>
/**
 * @brief Function to display all the contacts stored
 * 
 */
void list_contacts()
{
    struct person p;
    FILE *f;
    f=fopen("project","rb");
    if(f==NULL)
    {
        printf("\nfile opening error in listing :");
        exit(1);
    }
    while(fread(&p,sizeof(p),1,f)==1)
    {
        printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName=%s\nAdress=%s\nMobile no=%ld\nE-mail=%s",p.name,p.address,p.mble_no,p.mail);

	    getch();
	    system("cls");
    }
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}