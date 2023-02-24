/* Program to reverse a doubly linked list */
#include <stdio.h>
#include <stdlib.h>
 
/* a node of the doubly linked list */
struct node
{
  int data;
  struct Node *next;
  struct Node *prev;    
};

typedef struct node Node;
  
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the Doubly Linked List */
void addToHead(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = (Node*) malloc(sizeof(Node));
  
    /* put in the data  */
    new_node->data  = new_data;
     
    /* since we are adding at the begining, 
      prev is always NULL */
    new_node->prev = NULL;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
 
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node;    
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void addToTail(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* temp = (*head_ref);
  
    /* put in the data  */
    new_node->data  = new_data;
    
    if(temp == NULL) {
    	new_node->next = NULL;
    	new_node->prev = NULL;
    	(*head_ref) = new_node;
    	return;
	}
    
    while(temp->next != NULL)
    	temp = temp->next;
     
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL; 
 
}

void addBeforeN(Node** head_ref, int new_data, int N)
{
    /* allocate node */
    Node* temp = (*head_ref);
    Node* prev = NULL;
    
    if(temp == NULL) return;
    
    while(temp != NULL && temp->data != N) {
    	prev = temp;
    	temp = temp->next;
	}
    	
    if(temp == NULL) return;
    if(prev == NULL) {
    	addToHead(head_ref,new_data);
    	return;
	}
    
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data  = new_data;

    new_node->prev = prev;
    new_node->next = temp;
    prev->next = new_node;
    temp->prev = new_node;
    
}

void deleteN(Node** head_ref, int N)
{
    /* allocate node */
    Node* temp = (*head_ref);
    Node* prev = NULL;
    Node*next = NULL;
    
    if(temp == NULL) return;
	
	while(temp != NULL && temp->data != N) {
    	prev = temp;
    	temp = temp->next;
	}
	
	
	if(temp == NULL) return;
	if(prev == NULL) {
    	(*head_ref) = (*head_ref)->next;
    	(*head_ref)->prev = NULL;
    	free(temp);
    	return;
	}
	
	next = temp->next;
	
	if(next == NULL) {
		prev->next = NULL;
		free(temp);
		return;
	}
	
	prev->next = next;
	next->prev = prev;
	free(temp);
    
}

void printFromNForwards(Node* node, int N)
{
	while(node!=NULL)
	{
		if(node->data == N) {
			printList(node);
			return;
		}
		node = node->next;
	}
} 

void printFromNBackwards(Node* node, int N)
{
	while (node != NULL) {
		if(node->data == N) break;
		node = node->next;
	}
	while(node!=NULL)
	{
		printf("%d ", node->data);
   		node = node->prev;
	}
} 
 
/* Function to print nodes in a given doubly linked list 
   This function is same as printList() of singly linked lsit */
void printList(Node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
} 
 
/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	
	/* Let us create a sorted linked list to test the functions
	Created linked list will be 10->8->4->2 */
	addToTail(&head, 2);
	addToTail(&head, 4);
	addToHead(&head, 8);
	addToHead(&head, 10);
	
	printf("\n Original Linked list ");
	printList(head);
	
	addToTail(&head,16);
	printf("\n add to tail list ");
	printList(head);
	
	addBeforeN(&head, 87, 16);
	printf("\n add before 16 list ");
	printList(head);
	
	addBeforeN(&head, 78, 10);
	printf("\n add before 10 list ");
	printList(head);
             
	deleteN(&head, 78);
  	printf("\n deleten 78 list ");
	printList(head);
	
	deleteN(&head, 16);
  	printf("\n deleten 16 list ");
	printList(head);
	
	deleteN(&head, 2);
  	printf("\n deleten 2 list ");
	printList(head);
	
	printf("\n print from 8 forward list ");
	printFromNForwards(head,8);
	
	printf("\n print from 5 forward list ");
	printFromNForwards(head,5);
	
	printf("\n print from 10 forward list ");
	printFromNForwards(head,10);
	
	printf("\n print from 87 forward list ");
	printFromNForwards(head,87);
	
	printf("\n print from 8 backward list ");
	printFromNBackwards(head,8);
	
	printf("\n print from 5 backward list ");
	printFromNBackwards(head,5);
	
	printf("\n print from 10 backward list ");
	printFromNBackwards(head,10);
	
	printf("\n print from 87 backward list ");
	printFromNBackwards(head,87);
  
	getchar();
}

