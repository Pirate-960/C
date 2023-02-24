#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// This function prints contents of linked list starting from 
// the given Node 
void printList(struct Node* n) 
{ 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->next; 
    } 
    printf("\n"); 
} 

struct Node* BuildOneTwoThree() 
{ 
    struct Node* head = NULL; 
    struct Node* second = NULL; 
    struct Node* third = NULL; 
  
    // allocate 3 Nodes in the heap 
    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
  
    head->data = 1; // assign data in first Node 
    head->next = second; // Link first Node with second 
  
    second->data = 2; // assign data to second Node 
    second->next = third; 
  
    third->data = 3; // assign data to third Node 
    third->next = NULL; 
  
    printList(head); 
  
    return head; 
}

/*
Given a list, return the number of Nodes in the list.
*/
int Length(struct Node* head){
	struct Node* current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;	
}

/*
Given a list and an int, return the number of times that int occurs
in the list.
*/
int Count(struct Node* head, int searchFor) {
	struct Node* current = head;
	int count = 0;
	while (current != NULL) {
		if (current->data == searchFor) count++;
		current = current->next;
	}
	return count;
}

int GetNth(struct Node* head, int index) {
	struct Node* current = head;
	int count = 0; // the index of the Node we're currently looking at
	while (current != NULL) {
		if (count == index) 
			return(current->data);
		count++;
		current = current->next;
	}
	// if we get to this line, the caller was asking for a non-existent element so we print error message!
	printf("Non-existent element!\n"); 	
}


void Push(struct Node** headRef, int newData) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); // allocate Node
	if(newNode != NULL){
		newNode->data = newData; // put in the data
		newNode->next = (*headRef); // link the old list off the new Node
		(*headRef) = newNode; // move the head to point to the new Node
	}
}

/*
A more general version of Push(). Given a list, an index 'n' in the range 0..length, and a data element, add a new Node to the list so
that it has the given index.
*/
void InsertNth(struct Node** headRef, int index, int data) {
	// position 0 is a special case...
	if (index == 0) 
		Push(headRef, data);
	else {
		struct Node* current = *headRef;
		int i;
		for (i=0; i<index-1; i++) {
			if(current != NULL)
				current = current->next;
		}
		if(current != NULL) // tricky: you have to check one last time
			Push(&(current->next), data); 
		
	}
}

void main() {
	struct Node* myList = BuildOneTwoThree(); // build {1, 2, 3}
	// part a
	int length = Length(myList); // returns 3 since there are 1,2,3 in the list.
	
	//part b
	int count = Count(myList, 2); // returns 1 since there's 1 '2' in the list
	
	//part c
	int lastNode = GetNth(myList, 2);  // returns the value 3
	
	//part d
	Push(&myList, 13); 	// Push 13 on the front, yielding {13, 1, 2, 3}
						// (The '&' is because head is passed
						// as a reference pointer.)
						
	//part e
	InsertNth(&myList, 1, 5); // build {13, 5, 1, 2, 3}	
	
	
    printList(myList); 		
}
  
