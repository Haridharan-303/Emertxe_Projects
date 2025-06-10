#include <stdio.h>
#include "contact.h"
#include "file.h"

int main() 
{
	AddressBook book;
	// initialize(&book);
	book.fptr = fopen("addressbook.csv", "r+");
	if(book.fptr == NULL)
	{
		printf("ERROR: File not found\n");
		return 0;
	}

	loadContactsFromFile(&book);

	do
	{
		printf("\nAddress Book Menu : \n");
		printf("1. Create contact\n2. Search contact\n3. Edit contact\n4. Delete contact\n5. List all contact\n6. Exit\n");
		printf("\nEnter your choice : ");
		int choice;
		scanf("%d",&choice);


		//switch
		switch(choice)
		{
			case 1:
				printf("You entered 1.create contact\n\n");
				createContact(&book);
				break;
			case 2:
				printf("You entered 2.Search contact\n");
				searchContact(&book);
				break;
			case 3:
				printf("you entered 3.Edit contact\n");
				editContact(&book);
				break;
			case 4:
				printf("you entered 4.Delete contact\n");
				deleteContact(&book);
				break;
			case 5:
				printf("you entered 5.List All contact\n");
				listContacts(&book);
				break;
			case 6:
				printf("you entered 6.Exit\n");
				printf("\ndo you want to store the data to file (y/n) : ");
				char ch;
				getchar();
				scanf("%c",&ch);
				if (ch == 'y' || ch == 'Y')	
				{	
					saveContactsToFile(&book);
					break;
				}
				else
					break;
			default:
				printf("please enter valid option\n");
				break;		
		}
		if(choice == 6)
			break;	
	}while(1);

}
