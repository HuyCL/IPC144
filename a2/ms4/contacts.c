/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name) {
	char option = '\0';
	printf("Please enter the contact's first name: ");
	scanf("%[^\n]", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	option = yes();
	switch (option)
	{
	case 1:
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", name->middleInitial);
		break;
	case 0:
		break;
	default:
		break;
	}
	printf("Please enter the contact's last name: ");
	clearKeyboard();
	scanf("%[^\n]", name->lastName);
}
// getAddress:
void getAddress(struct Address* address) {
	char option = '\0';
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();

	printf("Please enter the contact's street name: ");
	scanf("%[^\n]", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	clearKeyboard();
	option = yes();
	switch (option)
	{
	case 1:
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		break;
	case 0:
		address->apartmentNumber = 0;
		break;
	default:
		break;
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", address->postalCode);
	clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf("%[^\n]", address->city);
}
// getNumbers:
void getNumbers(struct Numbers* numbers) {
	char option = '\0';
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();
	switch (option)
	{
	case 1:
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		break;
	case 0:
		strcpy(numbers->home, "");
		break;
	default:
		break;
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();
	switch (option)
	{
	case 1:
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
		break;
	case 0:
		strcpy(numbers->business, "");
		break;
	default:
		break;
	}
}
// getContact:
void getContact(struct Contact* contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}