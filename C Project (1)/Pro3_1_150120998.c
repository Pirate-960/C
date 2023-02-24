#include <stdio.h>
//-------------------------------------------------------------------------------------//
// Student Name: Abdelrahman Zahran.
// Studenmt Number: 150120998.
//-------------------------------------------------------------------------------------//
/** Problem (1) **/
// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) have 3 ears, because they each have a raised foot. 
// Recursively return the number of “ears” in the bunny line 1, 2, ... n.
//-------------------------------------------------------------------------------------//
/** Functions Prototypes **/
void NumberOfEars (int numberOfLines);
/** Data Fields **/
unsigned int numberOfEars = 0;
unsigned int numberOfLines;
/** Main Function **/
int main (void) {	
	// Prompt the user to enter the number of lines (number of Bunnies).
	printf("%s" , "Please enter the number of lines (n=): ");
	scanf("%u" , &numberOfLines);
	
	// Function Call.
	NumberOfEars(numberOfLines);
	return 0;
}
/** End of Main Function **/
/** NumberOfEars Function **/
void NumberOfEars (int numberOfLines) {
	if (numberOfLines == 0) {
		printf("\nbunnyEars2(%d) -> %d\n" , numberOfLines , numberOfEars);
	}
	else {  
		// Recursion
		NumberOfEars(numberOfLines - 1);
		// If Number of bunnies is odd. -> increae number of ears by 2.
		if (numberOfLines % 2 != 0) { 
			numberOfEars = numberOfEars + 2;
			// Print
			printf("\nbunnyEars2(%d) -> %d\n" , numberOfLines , numberOfEars);
		}
		// If number of bunnies is even. -> increase number of ears by 3.
		else if (numberOfLines % 2 == 0) {
			numberOfEars = numberOfEars + 3;
			// Print
			printf("\nbunnyEars2(%d) -> %d\n" , numberOfLines , numberOfEars);
		}
	}	
}
/** End of NumberOfEars Function **/
//-------------------------------------------------------------------------------------//
