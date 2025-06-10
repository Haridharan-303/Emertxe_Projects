#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"


void listContacts(AddressBook *addressBook) 
{
	printf("\n\t--------------------------------------\n");
	printf("\tName\t\tphone\t\tEmail\n");
	printf("\t--------------------------------------\n");
	for(int i=0; i<addressBook->contactCount; i++)
	{
		printf("\t");
		printf("%s\t",addressBook->contacts[i].name);
		printf("%s\t",addressBook->contacts[i].phone);
		printf("%s\n",addressBook->contacts[i].email);
	}
}

void initialize(AddressBook *addressBook) 
{
	populateAddressBook(addressBook);
}

void saveAndExit(AddressBook *addressBook) 
{
}


void createContact(AddressBook *addressBook) 
{
	addressBook->contacts = realloc(addressBook->contacts, (addressBook->contactCount+1) * sizeof(Contact));

	if (addressBook->contacts == NULL) 
	{
        printf("ERROR: Memory allocation failed\n");
        return;
    }

	// fflush(stdin);

	char name[20],phone[20],email[20];
	printf("\tEnter the name : ");
	getchar();
	scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].name);
	
	while(1)
	{
		printf("\tEnter the phone : ");
		getchar();
		scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].phone);
		
		int flag=0;
		for(int i=0; i<addressBook->contactCount; i++)
		{
			if(strcmp(addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[i].phone) == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("\tPhone number already exists\n");
		else
		{
			break;
		}
	}

	while(1)
	{
		printf("\tEnter the email : ");
        getchar();
        scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].email);

        int flag=0;
            for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp(addressBook->contacts[addressBook->contactCount].email,addressBook->contacts[i].email) == 0)
                    {
                        flag = 1;
						break;
                    }
                }
        if(flag)
            printf("\temail number already exists\n");
        else
            break;
		
	}

	printf("\tContact created successfully...\n");
	addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
	char name[20];
	printf("\n\tEnter the name to search : ");
	do
	{
		getchar();
		scanf("%[^\n]",name);
		int res;
		for(int i=0; i<addressBook->contactCount; i++)
		{
			res = strcmp(name,addressBook->contacts[i].name);
			if(res == 0)
			{
				printf("\n\t-----------------------------------------------------------------------\n");
				printf("\tName : %s\t",addressBook->contacts[i].name);
				printf("Phone : %s\t",addressBook->contacts[i].phone);
				printf("Email : %s\n",addressBook->contacts[i].email);
				printf("\t-----------------------------------------------------------------------\n");
				break;
			}
		}
	
		if(res == 0)
			break;
		else
			printf("Please Enter the valid name : ");
			
	}while(1);
}

void editContact(AddressBook *addressBook)
{
	char name[20];
        printf("\n\tEnter the name to search : ");
        do
        {
                getchar();
                scanf("%[^\n]",name);
                int res, flag = 0;
                for(int i=0; i<addressBook->contactCount; i++)
                {
                        res = strcmp(name,addressBook->contacts[i].name);
                        if(res == 0)
                        {
				char new_name[20];
				char new_phone[20];
				char new_email[20];
                        printf("\n\tEnter the New name : ");
				getchar();
				scanf("%[^\n]",new_name);
				printf("\tEnter the New phone :");
			        getchar();
				scanf("%[^\n]",new_phone);
				printf("\tEnter the New email : ");	
				getchar();
				scanf("%[^\n]",new_email);
					strcpy(addressBook->contacts[i].name, new_name);
					strcpy(addressBook->contacts[i].phone, new_phone);
					strcpy(addressBook->contacts[i].email, new_email);
				printf("\tEdit contact saved Successfully...\n");
				flag = 1;
                        }
                }
        if(flag)
            break;
		else
			printf("Enter the Valid name : ");
	}while(1);
}

void deleteContact(AddressBook *addressBook) 
{
	char name[20];
	printf("\n\tEnter the name to delete : ");

	do{
		getchar();
		scanf("%[^\n]",name);
		int flag = 0;
		for(int i=0; i<addressBook->contactCount; i++)
		{
			if(strcmp(name,addressBook->contacts[i].name) == 0)
			{
				for(int j=i; j<addressBook->contactCount-1; j++)
				{
					addressBook->contacts[j] = addressBook->contacts[j+1];
				}
				addressBook->contactCount--;
				addressBook->contacts = realloc(addressBook->contacts, addressBook->contactCount * sizeof(Contact));
				printf("\tContact deleted successfully...\n");
				flag = 1;
			}
		}
		if(flag)
			break;
		else
			printf("Enter the valid name :");

	}while(1);	
}
