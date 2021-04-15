#include<stdio.h>
#include "contact.h"
#include<stdlib.h>

status create_contact()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\nEnter name: ");
        got(p.name);
        printf("\nEnter the address: ");
        got(p.address);
        printf("\nEnter phone no.:");
        scanf("%ld",&p.mble_no);
        printf("\nEnter e-mail:");
        got(p.mail);
        fwrite(&p,sizeof(p),1,f);
        fflush(stdin);
        printf("\nrecord saved");
        fclose(f);
        return SUCCESS;
        printf("\nPress any key:");
        getch();
        system("cls");
        menu();
}