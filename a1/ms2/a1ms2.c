/* -------------------------------------------
Name: Huy Lam
Student number: 114705162
Email: hlam25@myseneca.ca
Section: II
Date: 09/07/2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void) {
	// Declare variables here:
	struct Name name = { {'\0'},{'\0'},{'\0'} };
	struct Address address = { 0,{'\0'},0,{'\0'},{'\0'} };
	struct Numbers no = { {'\0'},{'\0'},{'\0'} };
	char option = '\0';
	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%s", name.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &option);
	switch (option)
	{
	case 'y':
	case 'Y':
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", name.middleInitial);
		break;
	case 'n':
	case 'N':
		break;
	default:
		break;
	}
	printf("Please enter the contact's last name: ");
	scanf("%s", name.lastName);

	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &address.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf(" %s", address.street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &option);
	switch (option)
	{
	case 'y':
	case 'Y':
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address.apartmentNumber);
		break;
	case 'n':
	case 'N':
		break;
	default:
		break;
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", address.postalCode);
	while (getchar() != '\n');
	printf("Please enter the contact's city: ");
	scanf("%s", address.city);

	// Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &option);
	switch (option)
	{
	case 'y':
	case 'Y':
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", no.cell);
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
		scanf("%s", no.home);
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
		scanf("%s", no.business);
		break;
	case 'n':
	case 'N':
		break;
	default:
		break;
	}


	// Display Contact Summary Details
	printf("\n");
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", name.firstName);
	printf("Middle initial(s): %s\n", name.middleInitial);
	printf("Last name: %s\n", name.lastName);
	printf("\n");
	printf("Address Details\n");
	printf("Street number: %d\n", address.streetNumber);
	printf("Street name: %s\n", address.street);
	printf("Apartment: %d\n", address.apartmentNumber);
	printf("Postal code: %s\n", address.postalCode);
	printf("City: %s\n", address.city);
	printf("\n");
	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", no.cell);
	printf("Home phone number: %s\n", no.home);
	printf("Business phone number: %s\n", no.business);
	printf("\n");
	printf("Structure test for Name, Address, and Numbers Done!\n");

	// Display Completion Message



	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888
Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song
Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto
Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888
Structure test for Name, Address, and Numbers Done!
*/