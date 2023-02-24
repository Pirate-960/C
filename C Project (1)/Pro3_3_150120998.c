#include <stdio.h>
//-------------------------------------------------------------------------------------//
// Student Name: Abdelrahman Zahran.
// Studenmt Number: 150120998.
//-------------------------------------------------------------------------------------//
/** Problem (3) **/
// A program that prints identical triangles nested each other recursively ->  the triangles are constructed by using two digits ‘_’(underscore) and ‘1’.
//-------------------------------------------------------------------------------------//
/** Data Fields **/
const int numberOfColumns = 63;
/** FillOnes Function **/
void FillOnes(char matrix[][numberOfColumns], int startRow, int startColumn, int length, int iteration) {
	if (iteration == 0) {
		int i;
		int j;
		// Using 2 iterations to fill ones -> vreate identical triangles (32 rows, 63 columns) 
		for (i = 0; i < length; i++) {
			matrix[startRow + i][startColumn] = '1';
			for (j = 1; j <= i; j++) {
				matrix[startRow + i][startColumn + j] = '1';
				matrix[startRow + i][startColumn - j] = '1';
			}
		}
	}
	else {
		// Recursion -> Create triangles. -> bases.
		FillOnes(matrix, startRow, startColumn, length / 2, iteration - 1);
		// Recursion -> Create triangles. -> sides.
		FillOnes(matrix, startRow + length / 2, startColumn - length / 2, length / 2, iteration - 1);
		// Recursion -> Create triangles -> sides.
		FillOnes(matrix, startRow + length / 2, startColumn + length / 2, length / 2, iteration - 1);
	}
}
/** End of fillOnes Function **/
/** Main Function **/
int main(void){
	// Declare variables.
	char matrix[32][63]; // (2 - Dimensional Array).
	int i;
	int j;int numberOfIterations;
	// Using 2 iterations to print a underscore net. -> (32 rows, 63 columns)
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 63; j++) {
			matrix[i][j] = '_';
		}
	}
	// Prompt the user to Enter the number of iteration.
	printf("Enter number of iteration: ");
	scanf("%d",&numberOfIterations);
	
	// Using FillOnes Function -> create triangles using 1s. -> Function Call.
	FillOnes(matrix, 0, 31, 32, numberOfIterations);
	
	// Print the net after creating the ones triangles.
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 63; j++) {
			printf("%c",matrix[i][j]);
		}
		// New line.
		printf("\n");
	}
	return 0;
}
/** End of Main Function **/
//-------------------------------------------------------------------------------------//
