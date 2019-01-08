/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Contact *contact) {
	char option = '\0';
	printf("Please enter the contact's first name: ");
	scanf("%s", contact->name.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &option);
	switch (option)
	{
	case 'y':
	case 'Y':
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", contact->name.middleInitial);
		break;
	case 'n':
	case 'N':
		break;
	default:
		break;
	}
	printf("Please enter the contact's last name: ");
	scanf("%s", contact->name.lastName);
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Contact *contact) {
	char option = '\0';
	printf("Please enter the contact's street number: ");
	scanf("%d", &contact->address.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf(" %s", contact->address.street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &option);
	switch (option)
	{
	case 'y':
	case 'Y':
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &contact->address.apartmentNumber);
		break;
	case 'n':
	case 'N':
		break;
	default:
		break;
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", contact->address.postalCode);
	while (getchar() != '\n');
	printf("Please enter the contact's city: ");
	scanf("%s", contact->address.city);
}
// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Contact *contact) {
	char option = '\0';
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &option);
	switch (option)
	{
	case 'y':
	case 'Y':
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", contact->numbers.cell);
		break;
	case 'n':
	case 'N':
		break;
	default:
		break;
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &option);
	switch (option)
	{
	case 'y':
	case 'Y':
		printf("Please enter the contact's home phone number: ");
		scanf("%s", contact->numbers.home);
		break;
	case 'n':
	case 'N':
		break;
	default:
		break;
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &option);
	switch (option)
	{
	case 'y':
	case 'Y':
		printf("Please enter the contact's business phone number: ");
		scanf("%s", contact->numbers.business);
		break;
	case 'n':
	case 'N':
		break;
	default:
		break;
	}
}
