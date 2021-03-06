#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include <conio.h>
#include "../inc/contact.h"
/**
 * @brief Function to Create a contact object
 * 
 */
void create_contact()
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
        printf("\n!!Contact saved");
        fclose(f);
        printf("\nPress any key:");
        getch();
        system("cls");
        menu();
}
/**
 * @brief Function to delete a contact
 * 
 */
void delete_contact()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("\nCONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)
            printf("\nfile opaning error");
		else
        {
            printf("\nEnter CONTACT'S NAME:");
            got(name);

            fflush(stdin);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(p.name,name)!=0)
                    fwrite(&p,sizeof(p),1,ft);
                if(strcmp(p.name,name)==0)
                    flag=1;
            }
            fclose(f);
            fclose(ft);
            if(flag!=1)
            {
                printf("\nNO SUCH CONTACT TO DELETE.");
                remove("temp.txt");
            }
            else
            {
                remove("project");
                rename("temp.txt","project");
                printf("\nRECORD DELETED SUCCESSFULLY.");

            }
	    }
    } 

 printf("\nPress any key");

	getch();
    system("cls");
    menu();
}
/**
 * @brief Functon to Edit the contact information.
 * 
 */
void edit_contact()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			//exit(1);


		}
	else
	{
            system("cls");
            printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter name:");
                    got(s.name);
                    printf("\nEnter the address:");
                    got(s.address);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mble_no);
                    printf("Enter e-mail:");
                    got(s.mail);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n your data id modified");
              
            }
            else
            {
                    printf(" \n data is not found");
                    
            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	menu();

}

void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}

/**
 * @brief Function to view to list the contacts stored.
 * 
 */
void list_contacts()
{
    struct person p;
    FILE *f;
    f=fopen("project","rb");
    if(f==NULL)
    {
        printf("\nNo contacts!");
        //3menu();
    }
    printf("\n----------------CONTACTS LIST-------------------------");
    while(fread(&p,sizeof(p),1,f)==1)
    {
        
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

/**
 * @brief Function to diplay the main menu of the application
 * 
 */
void menu()
{
    system("cls");
    printf("\t\t**Contact Management System**");

    printf("\nMENU\n");
    printf("\n1.Add Contact\n2.List\n3.Exit\n4.Modify\n5.Search\n6.Delete\n");
    printf("\nEnter your Choice:");
    //int choice;                                         //choices between 0-5 for operations
    //
    //scanf("%d",&choice);
    switch(getch())
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

/**
 * @brief Function to search for a contact in the stored list 
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
        printf("\n !No Contacts\a\a\a\a");
        
    }
    else{
        printf("\nEnter name of person to search\n");
        got(name);
        while(fread(&p,sizeof(p),1,f)==1)
        {
            if(strcmp(p.name,name)==0)
            {
                printf("\n\tDetail Information About %s",name);
                printf("\nName=%s\nAdress=%s\nMobile no=%ld\nE-mail=%s",p.name,p.address,p.mble_no,p.mail);
                
            }
            
        }
    }
    
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}