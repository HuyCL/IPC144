// Name: Huy Lam
// Student Number: 115705162
// Email: hlam25@myseneca.ca
// Section: II
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Put your code below:
#define NUMS 3
#define lowtemp -40
#define hightemp 40

int main(void) {

	int input;
	int high;
	int low;
	double sum;
	double average;
	sum = 0;
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
			printf("\n");
			printf("Enter the high value for day %d: ", input + 1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", input + 1);
			scanf("%d", &low);
			printf("\n");
		}
		sum += high + low;
	}
	average = sum / (NUMS * 2);
	printf("The average (mean) temperature was: %.2lf\n", average);
	return 0;
}