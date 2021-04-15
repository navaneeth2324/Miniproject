#include<stdio.h>
#include "contact.h"
#include<stdlib.h>
/**
 * @brief Function to remove a contact from the list
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
            printf("Enter CONTACT'S NAME:");
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
                printf("\nNO CONACT'S RECORD TO DELETE.");
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