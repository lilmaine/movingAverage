#include <msp430.h> 

/*
 * main.c
 *
 *  Created on: Oct 10, 2013
 *  Author: C15Tramaine.Barnett
 *  Description: Implements functions that can get a moving average, calculate max and min values as well as the range of the array set
 */

// Moving average functions
int getAverage(int i, int array[]);
void addSample(int sample, int array[], unsigned int arrayLength);

// Array functions
int max(int array[], unsigned int arrayLength);
int min(int array[], unsigned int arrayLength);
unsigned int range(int array[], unsigned int arrayLength);




int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	static int array [10] = {45, 42, 41, 40, 43, 45, 46, 47, 49, 45};
	

	int i;
	int average = 0;
	for (i = 0; i < sizeof(array)/sizeof(int); i++){
		average = getAverage(i, array);
	}

	int maximum_value = max(array, sizeof(array)/sizeof(int));
	int minimum_value = min(array, sizeof(array)/sizeof(int));
	unsigned int theRange = range(array, sizeof(array)/sizeof(int));
	return 0;
}

int getAverage(int i, int array[]){
	int c = (array[i]+array[i+1])/2;
	return c;
}

int max(int array[], unsigned int arrayLength){
	int i;
	int max = 0;
	for (i = 0; i<arrayLength; i++){
		if (array[i] > max){
			max = array[i];
		}
	}
	return max;
}

int min(int array[], unsigned int arrayLength){
	int i;
	int min = 0xFFFF;
	for (i = 0; i<arrayLength; i++){
		if (array[i] < min){
			min = array[i];
		}
	}
	return min;
}
unsigned int range(int array[], unsigned int arrayLength){
	int range = max(array, sizeof(array)) -  min(array, sizeof(array));
	return range;
}
