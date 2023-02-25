#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//---------------------------------------------------------------------------------------------------------//
// Define the structure of the node (poniter variable, data).
struct Node {
    int data;
    struct Node *next;
};
// Declare head of the linked list -> Multiplicand.
struct Node *head1;
// Declare head of the linked list -> Multiplier.
struct Node *head2;
// Declare head of the linked list -> Result.
struct Node *head3;
//---------------------------------------------------------------------------------------------------------//
// Functions Prototypes
void Insert(struct Node **head, int data);
void Reverse(struct Node **head);
int FindLength(struct Node *head);
// void CheckInput(struct Node **head, int SystemBase);
void Conversion(struct Node **head, int SystemBase);
void AdditionTo(struct Node**head1, struct Node**head2);
void Multiplication(struct Node **head1, struct Node **head2, struct Node **head3, int SystemBase);
void Print(struct Node *head);
// void WriteToOutput(struct Node **head, FILE *OutputFilePtr);
//---------------------------------------------------------------------------------------------------------//
// The main() function -> Execution of the program (start + end) in this function.
int main (int argc,char* argv[]) {
	// head of the linked -> NULL
	head1 = NULL;
	head2 = NULL;
	head3 = NULL;
	
	// Display the output in the Command Prompt.
	if (argc == 1) {
		printf("Error message!");
	} else if (argc >= 2) {
		FILE *InputFilePtr = fopen(argv[1], "r");
//		FILE *InputFilePtr = fopen(argv[2], "r");
//		FILE *InputFilePtr = fopen("150120998_input_1_p1.txt", "r");
//		FILE *InputFilePtr = fopen("150120998_input_2_p1.txt", "r");
//		FILE *OutputFilePtr = fopen("150120998_output_1_p1.txt", "w");
//		FILE *OutputFilePtr = fopen("150120998_output_2_p1.txt", "w");
		char Input;
		int digit;
		int SystemBase;
		int counter = 0;
		
		// Read the Input from the .txt file and format it -> store the numbers in linked lists.
		if (InputFilePtr == NULL) {
			puts("File couldn't be opened!");
			exit(1);
		} else {
			while ((Input = getc(InputFilePtr)) != EOF) {
				digit = Input - '0';
				// Move to the next line when the current line is finished.
				if (Input == '\n' || Input == ' ') {
					counter++;
				} else {
					switch (counter)
					{
					// Store the Multiplicand in a linked list (digit by digit) using insert function.
					case 0:
						Insert(&head1, digit);
						break;
					// Store the Multiplier in a linked list (digit by digit) using insert function.
					case 1:
						Insert(&head2, digit);
						break;
					// Store the base of the system in an int variable.
					case 2:
						SystemBase = digit;
						// In case base < 2 || > 10 -> terminate.
						if (!((SystemBase >= 2) && (SystemBase <= 10))) {
							printf("The Base Number of the system is Invalid!");
							exit(1);
						}	
						break;
					default:
						break;
					}
				}
			}
		}
		
		// Close the Input File.
		fclose(InputFilePtr);
		
		// Reverse -> Multiplicand.
		Reverse(&head1);
		// Reverse -> Multiplier.
		Reverse(&head2);
	
		// printf("Check: \n");
		// CheckInput(&head1, SystemBase);
		// CheckInput(&head2, SystemBase);
		
		// length -> Multiplicand. (m)
		int length1 = FindLength(head1);
		
		// length -> Multiplier. (n)
		int length2 = FindLength(head2);
		
		// length -> Result (m + n + 1)
		int length3 = length1 + length2 + 1;
		int count = 0;
		
		// Fill the result Linked list with zeros.
		while (count < length3) {
			Insert(&head3, 0);
			count++;
		}
		
		// Multiplication -> Multiplicand * Multiplier = Result.
		Multiplication(&head1, &head2, &head3,SystemBase);
		
		// Print -> Multiplicand.
		Print(head1);
		printf("\n");
//		WriteToOutput(&head1, OutputFilePtr);

		// Print -> Multiplier. 
		Print(head2);
		printf("\n");
//		WriteToOutput(&head2, OutputFilePtr);

		// Print -> Result.
		Print(head3);
		printf("\n");
//		WriteToOutput(&head3, OutputFilePtr);
		
		// Print -> Multiplicand in base (10).
		Conversion(&head1, SystemBase);
		printf("\n");
//		WriteToOutput(&head1, OutputFilePtr);

		// Print -> Multiplier in base (10).
		Conversion(&head2, SystemBase);
		printf("\n");
//		WriteToOutput(&head1, OutputFilePtr);

		// Print -> Result in base (10).
		Conversion(&head3, SystemBase);
//		WriteToOutput(&head1, OutputFilePtr);
		
//		fclose(OutputFilePtr);
	}
}
//---------------------------------------------------------------------------------------------------------//
// The Insert() function -> Insert new node into a linked list at the end - Time Complexity = O(n). 
void Insert(struct Node **head, int data) {
	// Creation of a new node using malloc (data, NULL).
	struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1 -> data = data;
	temp1 -> next = NULL;
	
	struct Node *temp2 = *head;
	// In case the linked list is empty.
	if (*head == NULL) {
		*head = temp1;
	} else {
		// Traverse the Linked List till the last node (digit).
		while (temp2 -> next != NULL) {
			temp2 = temp2 -> next;
		}
		// Move to the next node.
		temp2 -> next = temp1;
	}
}
//---------------------------------------------------------------------------------------------------------//
// The Reverse() function -> Reverse a linked list while traversing it - Time complexity = O(n).
void Reverse(struct Node **head) {
	struct Node *current = *head;
	struct Node *next;
	struct Node *prev = NULL;
	// Traverse the linked list till the last node (digit) + change references of each node(pointer variables).
	while (current != NULL) {
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}
//---------------------------------------------------------------------------------------------------------//
// The FindLength() function -> Obtain number of nodes (digts of the number) in a linked list (Number).
int FindLength(struct Node *head) {
	int count = 0;
	struct Node *current = head;
	// In case the list is empty.
	if (head == NULL) {
		count = 0;
		printf("The Linked List is Empty!");
		return;
	} else {
		// Traverse the linked list till the last node (digit) + increment the count (Num. of digits in the number).
		while (current != NULL) {
			count++;
			current = current -> next;
		}
	}
	return count;
}
//---------------------------------------------------------------------------------------------------------//
// The CheckInput() function -> Check if the input digits of the number(input) is valid or not.
/*
void CheckInput(struct Node **head, int SystemBase) {
	struct Node *temp = *head;
	if (temp == NULL) {
		printf("The Linked List is Empty!");
		return;
	} else {
		// Digits -> smaller than the base.
		// Traverse the linked list.
		while (temp != NULL) {
			if (temp -> data <= SystemBase && temp -> data >= 0) {
				printf("The Input is Valid!\n");
			} else {
				printf("The Input is Invalid!\n");
				exit(1);
				return;
			}
			temp = temp -> next;
		}
	}
}
*/
//---------------------------------------------------------------------------------------------------------//
// The Conversion() Function -> convert any number in any base system between[2,10] to the base 10 (Decimal System).
void Conversion(struct Node **head, int SystemBase) {
	struct Node *temp1 = *head;
	struct Node *temp2 = NULL; 
	struct Node *temp3 = NULL; // result
	struct Node *temp4 = NULL;
	
	struct Node *tempMultiply1 = NULL;
	struct Node *tempMultiply2 = NULL;
	struct Node *tempMultiply3 = NULL;
	struct Node *tempMultiply4 = NULL;
	
	int iteration = 0;
	int lengthC =  2 * FindLength(*head);
	int count = 0;
	// Insert in temp4 (double length of the head(number)) 0 -> 0-> 0-> .....
	while (count < lengthC) {
		Insert(&temp4, 0);
		count++;
	}
	// Store base -> tempMultiply1
	Insert(&tempMultiply1, SystemBase); 
	// Store base ^ 0 -> tempMultiply2
	Insert(&tempMultiply2, 1);

	// Reverse -> number(input).
	Reverse(&temp1);
	
	// In case the linked list is empty.
	if (temp1 == NULL) {
		printf("The Linked List is Empty!");
		return;
	} else {
		// Traverse the linked list node by node -> To do conversion.
		while (temp1 != NULL) {
			// Multiply base pow(eg. 2^5) 1 2 3 
			if(iteration) {
			
				tempMultiply3 = NULL;
				
				// Insert in tempMultiply3 (double length of the head(number)). 0 -> 0-> 0-> .....
				count = 0;
				while (count < lengthC) {
					Insert(&tempMultiply3, 0);
					count++;
				}
				
				// Multiply Bases (depending on the length of the number): (2) -> 1 (1) -> base (3) -> result1
				Multiplication(&tempMultiply2, &tempMultiply1, &tempMultiply3, 10);
				// Multiply Bases (depending on the length of the number): (2) -> result1 (1) -> base (3) -> result2
				tempMultiply2 = tempMultiply3;
				Reverse(&tempMultiply2);	
				// tempMultiply2 = 1 initially -> tempMultiply3 = tempMultiply2 * base;
			}
			
			// Insert digits of the number in tempMultiply4
			tempMultiply4 = NULL;
			Insert(&tempMultiply4, temp1 -> data);
			tempMultiply3 = NULL;
			
			// Insert in tempMultiply3 (double length of the head(number)). 0 -> 0-> 0-> .....
			count = 0;
			while (count < lengthC) {
				Insert(&tempMultiply3, 0);
				count++;
			}
			
			// Multiply digits with the corresponding value in terms of mutliply bases.
			// (2) -> bases multiplication (4) -> digits of the number (3) -> result
			Multiplication(&tempMultiply2, &tempMultiply4, &tempMultiply3, 10);
			Reverse(&tempMultiply2);
			Reverse(&tempMultiply3);
			// Add the results of each multiplication one by one (node by node).
			AdditionTo(&tempMultiply3, &temp4);
			// Move to the next node 
			temp1 = temp1 -> next;
			iteration++;
		}
	}
	// Reverse -> result
	Reverse(&temp4);
	
	// Remove additional zeros -> in case found.
	while (temp4 -> data == 0) {
		struct Node *temp = temp4;
		// Move to the next node 
		temp4 = temp4 -> next;
		free(temp);
		// In case the linked list is empty -> terminate.
		if (temp4 == NULL)
		break;
	}
	
	// In case the linked list is empty -> Insert(0).
	if (temp4 == NULL)
	Insert(&temp4,0);
	
	Print(temp4);
}
//---------------------------------------------------------------------------------------------------------//
// The AdditionTo() function -> add digits (data of the nodes) after the multiplication in the conversion function is processed.
// -> addition of 2 numbers stored in linked lists to each other (node by node). 
void AdditionTo(struct Node**head1, struct Node**head2){
	struct Node* temp1 = *head1;
	struct Node* temp2 = *head2;

	int sum = 0;
	int carry = 0;
	int digit = 0;
	
	// Traverse the linked list till the last node.
	while (temp1 != NULL) {
		// Fill the second linked list with 0 -> in case it is empty.
		if (temp2 -> next == NULL) {
			Insert(&temp2, 0);
		}
		// First digit of the linked list (1) + First digit of the linked list (2).
		sum = temp1 -> data + temp2 -> data + carry;
		digit = sum % 10; // Obtain digits of base 10
		carry = sum /10;  // Obtain the carry to process the sum operation in a sufficient way.
		temp1 = temp1 -> next;
		temp2 -> data = digit;
		temp2 = temp2 -> next;	
	}
	if (carry != 0) {
		temp2 -> data = carry;
	}	
}
//---------------------------------------------------------------------------------------------------------//
// The multiplication() function -> Take 2 numbers (2 linked lists) -> input and mutliply them using Elementary School Multiplication Algorithm.
void Multiplication(struct Node **head1, struct Node **head2, struct Node **head3, int SystemBase) {
	struct Node *temp1 = *head1;
	struct Node *temp2 = *head2;
	struct Node *temp3 = *head3;
	struct Node *temp4 = *head3;

	int multiplication = 0;
	int carry = 0;
	while (temp2) {
		carry = 0;
		// Each time we loop or iterate we start from the next node other than the previous one of it that we used in the previous iteration.
		temp4 = temp3;
		temp1 = *head1;
		while (temp1) {
			// multiply digit by digit + carry in case found from a previous multiplication.
			multiplication = (temp1 -> data) * (temp2 -> data) + carry + (temp4 -> data);
			// Store result (remainder -> mod) in Result linked list.
			temp4 -> data = multiplication % SystemBase;
			// Update carry value.
			carry = multiplication / SystemBase + temp4 -> data / SystemBase;
			// Make each node in the result has only one digit in the result inked list.
			temp4 -> data = temp4 -> data % 10;
			// Move to the next node in temp4 linked list.
			temp4 = temp4 -> next;
			// Move to the next node in temp1 linked list. 
			temp1 = temp1 -> next;	
				
		}
		if (carry > 0) {
			temp4 -> data += carry;
		}
		// Move to the next node in temp3 linked list.
		temp3 = temp3 -> next;		
		// Move to the next node in temp2 linked list.
		temp2 = temp2 -> next;
	}
	// Reverse -> To obtain numbers in the correct order.
	Reverse(head1);
	Reverse(head2);
	Reverse(head3);
	
	// This loop removes -> additional zeros in the beginning of the result linked list in case found.
	while ((*head3) -> data == 0) {		
		struct Node *temp = *head3;
		*head3 = (*head3) -> next;
		free(temp);
		if (*head3 == NULL)
		break;
	}
	// In case Result is empty -> Insert (0).	 
	if (*head3 == NULL)
	Insert(head3,0);
}
//---------------------------------------------------------------------------------------------------------//
// The Print() function -> Print all the elements (digits -> data of the nodes) stored in a linked list
void Print(struct Node *head) {
    struct Node *temp = head;
    // In case the linked list is empty.
    if (temp == NULL) {
        printf("The Linked List is Empty!");
        return;
    }
    // Traverse the linked list till the last node while printing the values.
    while (temp != NULL) {
        printf("%d", temp -> data);
        temp = temp -> next;
    }
}
//---------------------------------------------------------------------------------------------------------//
// The WriteToOutput() function -> write the output to an output file (.txt).
/*
void WriteToOutput(struct Node **head, FILE *OutputFilePtr) {
	struct Node *temp = *head;
	
	if (temp == NULL) {
		return;
	} else {
		while (temp != NULL) {
			fprintf(OutputFilePtr, "%d", temp -> data);
			temp = temp -> next;
		}
		fprintf(OutputFilePtr, "\n");
	}
}
*/
//---------------------------------------------------------------------------------------------------------//
