// Name: Huy Lam
// Student Number: 115705162
// Email: hlam25@myseneca.ca
// Section: II
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Put your code below:
#define NUMS 4
#define lowtemp -40
#define hightemp 40

int main(void) {

	int input;
	int high, highest;
	int low, lowest;
	int highday;
	int lowday;
	double sum;
	double average;
	
	sum = 0;
	highest = 0;
	lowest = 0;

	printf("---=== IPC Temperature Analyzer ===---\n");
	for (input = 0; input < NUMS; input++) {

		printf("Enter the high value for day %d: ", input + 1);
		scanf("%d", &high);
		printf("\n");
		printf("Enter the low value for day %d: ", input + 1);
		scanf("%d", &low);
		printf("\n");

		while (high < low || high > hightemp || low < lowtemp)
		{
			printf("Incorrect values, temperatures must be in the range %d to %d, high must be greater than low.\n", lowtemp, hightemp);
			printf("Enter the high value for day %d: ", input + 1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", input + 1);
			scanf("%d", &low);
			printf("\n");
		}

		sum += high + low;

		if (highest < high) {				// <=====================================================
			highest = high;
			highday = input + 1;
		}
											// Replaces the variables when the 'if' statement is true
		if (lowest > low) {
			lowest = low;
			lowday = input + 1;				// <=====================================================
		}

	}	/* 'for' loop ends and repeat */
	
	average = sum / (NUMS * 2);
	printf("The average (mean) temperature was: %.2lf\n", average);
	printf("The highest temperature was %d, on day %d\n", highest, highday);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowday);
	return 0;
}