#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    // Re-open the file in "w" mode to overwrite it
    addressBook->fptr = fopen("addressbook.csv", "w");
    if (addressBook->fptr == NULL) {
        printf("ERROR: Could not open file for writing\n");
        return;
    }

    // Write the contact count on the first line with delimiters
    fprintf(addressBook->fptr, "#%d#\n", addressBook->contactCount);

    // Write each contact's details (name, phone, email)
    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(addressBook->fptr, "%s,%s,%s\n", 
                addressBook->contacts[i].name, 
                addressBook->contacts[i].phone, 
                addressBook->contacts[i].email);
    }

    // Close the file after writing
    fclose(addressBook->fptr);

    printf("Contacts saved to file successfully.\n");

}

void loadContactsFromFile(AddressBook *addressBook) 
{

    char str[100];  
    if (fgets(str, sizeof(str), addressBook->fptr) == NULL) {
        printf("ERROR: Failed to read the first line\n");
        return;
    }

    int num = atoi(str+1);  // Skip the first character (#) and get the number
    addressBook->contactCount = num;
    addressBook->contacts = malloc(num * sizeof(Contact));  // Allocate memory for contacts

    for (int i = 0; i < num; i++) {
        if (fgets(str, sizeof(str), addressBook->fptr) == NULL) {
            printf("ERROR: Failed to read contact data\n");
            return;
        }

        // Remove newline character from the string if it's present
        str[strcspn(str, "\n")] = 0;

        // Parse the contact details
        strcpy(addressBook->contacts[i].name, strtok(str, ","));
        strcpy(addressBook->contacts[i].phone, strtok(NULL, ","));
        strcpy(addressBook->contacts[i].email, strtok(NULL, ","));
    }
}
