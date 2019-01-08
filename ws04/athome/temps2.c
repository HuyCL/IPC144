//--------------------------------------------------
// Name: Huy Lam	          
// Student Number: 115705162
// Email: hlam25@myseneca.ca          
// Section: II
// Workshop: 4     
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int day;
	int lowday;
	int highday;
	int NoOfDays;
	int high[10];
	int low[10];
	int highest;
	int lowest;
	int averageday;
	double average;
	double sum;
	highest = 0;
	lowest = 0;
	sum = 0;
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");			// <--------------------------------------------
	scanf("%d", &NoOfDays);													
	while (NoOfDays < 3 || NoOfDays > 10) {	
		printf("\n");																	// Forces the user input to be between 3 and 10 
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &NoOfDays);
	}																					// <---------------------------------------------
	printf("\n");
	for (day = 0; day < NoOfDays; day++) {				// <-------------------------------------------------

		printf("Day %d - High: ", day + 1);
		scanf("%d", &high[day]);						// High & low temperature input

		printf("Day %d - Low: ", day + 1);
		scanf("%d", &low[day]);							// <--------------------------------------------------


		if (highest < high[day]) {						// <--------------------------------------------------
			highest = high[day];
			highday = day + 1;
		}
														// Compare the values for highest & lowest temperature
		if (lowest > low[day]) {
			lowest = low[day];
			lowday = day + 1;
		}
	}													// <--------------------------------------------------

	printf("\n");
	printf("Day  Hi  Low\n");													// <--------------------------
	for (day = 0; day < NoOfDays; day++) {
																				// Temperature chart
		printf("%d    %d    %d\n", day + 1, high[day], low[day]);
	}																			// <--------------------------

	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highest, highday);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowday);		// <--------Output------------
	printf("\n");

	do {								// <------The-loop-repeats-until-the-input-is-negative-----
		printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &averageday);
		printf("\n");
		while (averageday < 1 || averageday > 4) {
			if (averageday < 0) {				// <---------------------------------
				printf("Goodbye!\n");
				printf("\n");				// Exits if the number is less than 0
				return 0;
			}						// <---------------------------------				 
			printf("Invalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &averageday);
			printf("\n");
		}

		for (day = 0; day < averageday; day++) {										// <-----------------------
			sum += (high[day] + low[day]);
		}
		average = sum / (2 * averageday);												// Average temperature calculation & output
		printf("The average temperature up to day %d is: %.2lf\n", averageday, average);
		printf("\n");
		sum = 0;																		// <-----------------------
	} while (averageday > 0);			// <------The-loop-repeats-until-the-input-is-negative-----
	return 0;
}
// Place your code below