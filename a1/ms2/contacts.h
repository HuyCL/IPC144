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

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #1 here...
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #1 here...
struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};