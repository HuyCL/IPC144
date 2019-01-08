/*
Name:      Huy Lam
Student#:  115705162
Section:   II
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	double tax, amount;
	int balance, loonies, quarters, dimes, nickels, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	tax = amount * 0.13 + 0.005;
	printf("GST: %.2lf\n", tax);
	amount = amount + tax;

	balance = amount * 100;		/*Converting amount to a whole number*/
	printf("Balance owing: $%.2lf\n", (double)balance / 100);	/*Casting 'int' to 'double' for the variable 'balance'*/

	loonies = balance / 100;
	balance = balance % 100;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (double)balance / 100);

	quarters = balance / 25;
	balance = balance % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)balance / 100);

	dimes = balance / 10;
	balance = balance % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (double)balance / 100);

	nickels = balance / 5;
	balance = balance % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, (double)balance / 100);

	pennies = balance / 1;
	balance = balance % 1;
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (double)balance / 100);

	return 0;
}