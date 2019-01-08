/* -------------------------------------------
Name: Huy Lam	          
Student number: 114705162
Email: hlam25@myseneca.ca
Section: II       
Date: 07/31/2018          
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	int value;
	char NL = 'x';
	while (NL != '\n')
	{
		scanf("%d%c", &value, &NL);
		if (NL != '\n')
		{
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	}
	return value;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int value = getInt();
	while (value > max || value < min)
	{
		printf("*** OUT OF RANGE *** <Enter a number between [%d] and [%d]>: ", min, max);
		value = getInt();
	}
	return value;
}

// yes:
int yes(void)
{
	char option = '\0';
	char NL = 'x';
	int value = 0;
	while (NL != '\n')
	{
		scanf(" %c%c", &option, &NL);
		if (NL != '\n')
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
	}
	switch (option)
	{
	case 'y':
	case 'Y':
		value = 1;
		break;
	case 'n':
	case 'N':
		value = 0;
		break;
	default:
		break;
	}
	return value;
}

// menu:
int menu(void)
{
	int option = 0;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);

	return option;
}

// ContactManagerSystem:
void ContactManagerSystem(void)
{
	struct Contact contact[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
											  { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
											  { "4161112222", "4162223333", "4163334444" } },
											{
											  { "Maggie", "R.", "Greene" },
											  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
											  { "9051112222", "9052223333", "9053334444" } },
											{
											  { "Morgan", "A.", "Jones" },
											  { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
											  { "7051112222", "7052223333", "7053334444" } },
											{
											  { "Sasha", {'\0'}, "Williams" },
											  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
											  { "9052223333", "9052223333", "9054445555" } },
										  };
	char option = '\0';
	do
	{
		option = menu();
		switch (option)
		{
		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			scanf(" %c", &option);
			printf("\n");
		default:
			break;
		}
	} while (option != 'y' && option != 'Y');
	printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contact[], int size, const char cellNum[])
{
	int i;
	int index = -1;
	for (i = 0; i < size; i++)
	{
		if (strcmp (contact[i].numbers.cell, cellNum) == 0)
		{
			index = i;
		}
	}
	return index;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int NofContacts)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", NofContacts);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	if (contact->name.middleInitial[0] == '\0')
	{
	printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	}
	else
	{
	printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	}
	if (contact->address.apartmentNumber > 0) 
	{
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	}
	else 
	{
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
	}
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size)
{
	int i;
	int count = 0;
	printf("\n");
	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (contact[i].numbers.cell[0] > 0)
		{
			displayContact(&contact[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size)
{
	char cellnum[11];
	int index;
	printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellnum);
	index = findContactIndex(contact, MAXCONTACTS, cellnum);
	if (index > 0)
	{
		printf("\n");
		displayContact(&contact[index]);
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
}

// addContact:
void addContact(struct Contact contact[], int size)
{
	int i;
	int count = 0;
	for (i = 0; i < size; i++)
	{
		if (strlen(contact[i].numbers.cell) == 0)
		{
			printf("\n");
			getContact(&contact[i]);
			printf("--- New contact added! ---\n");
			i = size;
		}
		else
		{
			count++;
		}
	}
	if (count == size)
	{
		printf("\n*** ERROR: The contact list is full! ***\n");
	}
}

// updateContact:
void updateContact(struct Contact contact[], int size)
{
	char cellnum[11];
	int index;
	char option;
	printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellnum);
	index = findContactIndex(contact, MAXCONTACTS, cellnum);
	if (index < 0)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contact[index]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		option = yes();
		switch (option)
		{
		case 0:
			break;
		case 1:
			getName(&contact[index].name);
			break;
		default:
			break;
		}
		printf("Do you want to update the address? (y or n): ");
		option = yes();
		switch (option)
		{
		case 0:
			break;
		case 1:
			getAddress(&contact[index].address);
			break;
		default:
			break;
		}
		printf("Do you want to update the numbers? (y or n): ");
		option = yes();
		switch (option)
		{
		case 0:
			break;
		case 1:
			getNumbers(&contact[index].numbers);
			break;
		default:
			break;
		}
		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contact[], int size)
{
	char cellnum[11];
	int index;
	char option;
	printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellnum);
	index = findContactIndex(contact, MAXCONTACTS, cellnum);
	if (index < 0)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contact[index]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		option = yes();
		switch (option)
		{
		case 0:
			break;
		case 1:
			contact[index].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
			break;
		default:
			break;
		}
	}

}

// sortContacts:
void sortContacts(struct Contact contact[], int size)
{
	int i;
	int j;
	char temp;

	for (i = size - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (contact[j].numbers.cell[j] > contact[j + 1].numbers.cell[j + 1])
			{
				temp = contact[j].numbers.cell[j];
				contact[j].numbers.cell[j] = contact[j + 1].numbers.cell[j + 1];
				contact[j + 1].numbers.cell[j + 1] = temp;
			}
		}
	}
}