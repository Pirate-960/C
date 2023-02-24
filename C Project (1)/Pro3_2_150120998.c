#include <stdio.h>
//-------------------------------------------------------------------------------------//
// Student Name: Abdelrahman Zahran.
// Studenmt Number: 150120998.
//-------------------------------------------------------------------------------------//
/** Problem (2) **/
// A program to find the super digit of a number X -> concatenate the number using the repetition factor -> obtain the super digit.
//-------------------------------------------------------------------------------------//
/** Function Prototypes **/
int SuperDigit(int number, int repetitionFactor);
int add(int number);
void printConcatenated(int number, int repetitionFactor);
/** Data Fields **/
int counter = 0, sum = 0;
/** Main Function **/
int main(void) {
    // Declare variables.
    int number;
    int repetitionFactor;
    
    // Prompt the user to Enter a number.
    printf("Please enter a number (n=) : ");
    scanf("%d", &number);
    
    // Prompt the user to Enter a repititon factor.
    printf("Please enter repetition factor (k=) : ");
    scanf("%d", &repetitionFactor);
    
    // Display the result.
    printf("Super digit of number ");
    // Concatenate the number using the repetition factor. -> Function Call.
    PrintNumberAfterIteration(number, repetitionFactor);
    // Obtain the Super Digit of the number after concatenation. -> Function Call.
    printf(" is %d.", SuperDigit(number, repetitionFactor));
    return 0;
}
/** SuperDigit Function **/
int SuperDigit(int number, int repetitionFactor) {
    int totalSum = add(number);
    sum = 0;
    // only happens once to get the sum of the concatenated number
    if (counter == 0) {
        totalSum *= repetitionFactor;
        counter++;
    }
    if(totalSum < 10)
        return totalSum;
    else
        // if sum is greater than 10 then re-invoke superDigit function
        return SuperDigit(totalSum, repetitionFactor);
}
/** End of SuperDigit Function **/
/** Add Function **/ 
// -> Obtain the digits of the number after concatenation.
int add(int number) {
    int lastDigit;
    lastDigit = number % 10;
    number /= 10;
    sum += lastDigit;
    if (number == 0) {
    	return sum;
	}
	else {
		// Recursion
		return add(number);
	}
}
/** End of Add Function **/
/** PrintNumberAfterIteration Function **/
// -> Concatenation of the number using the repitition factor.
void PrintNumberAfterIteration(int number, int repetitionFactor) {
	if (repetitionFactor == 0) {
		return;
	}
	else {
		// Decrement the repetition factor.
		--repetitionFactor;
		// Display the number.
		printf("%d" , number);
		// Recursion
		PrintNumberAfterIteration(number,repetitionFactor);
		return;
	}
}
/** End of PrintNumberAfterIteration Function **/
//-------------------------------------------------------------------------------------//
