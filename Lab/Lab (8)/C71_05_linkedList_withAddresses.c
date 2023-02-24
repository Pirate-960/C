 #include <stdio.h>
 #include <stdlib.h>

 // self-referential structure
 struct listNode {
    char data;  // each listNode contains a character 
    struct listNode *nextPtr;  // pointer to next node
 }; 

 typedef struct listNode ListNode;  // synonym for struct listNode
 typedef ListNode * ListNodePtr;  // synonym for ListNode*

 // prototypes
 void insert(ListNodePtr *sPtr, char value);
 char delete(ListNodePtr *sPtr, char value);
 int isEmpty(ListNodePtr sPtr);
 void printList(ListNodePtr currentPtr);
 void instructions(void);

 int main(void) {
    ListNodePtr startPtr = NULL;  // initially there are no nodes
    printf("\nline 22: @startPtr -> %d\n", &startPtr);
    printf("\nstartPtr -> %d\n", startPtr);
    char item;  // char entered by user
    printf("\n@item -> %d\n", &item);
    instructions();  // display the menu
    printf("%s", "? ");
    unsigned int choice;  // user's choice
    printf("\nline 29: @choice -> %d\n", &choice);
    scanf("%u", &choice);

    // loop while user does not choose 3
    while (choice != 3) {
       switch (choice) {
          case 1:
             printf("%s", "Enter a character: ");
             scanf("\n%c", &item);
             printf("\nline 38: @startPtr -> %d\n", &startPtr);
             printf("\nstartPtr -> %d\n", startPtr);
             insert(&startPtr, item);  // insert item in list
             printf("\nline 41: @startPtr -> %d\n", &startPtr);
             printf("\nstartPtr -> %d\n", startPtr);
             printList(startPtr);
             break;
          case 2:  // delete an element
             // if list is not empty
             if (!isEmpty(startPtr)) {
                printf("\nline 48: @startPtr -> %d\n", &startPtr);
                printf("\nstartPtr -> %d\n", startPtr);
                printf("%s", "Enter character to be deleted: ");
                scanf("\n%c", &item);
                // if character is found, remove it
                if (delete(&startPtr, item)) {  // remove item
                   printf("\nline 54: @startPtr -> %d\n", &startPtr);
                   printf("\nstartPtr -> %d\n", startPtr);
                   printf("%c deleted.\n", item);
                   printf("\nline 57: @startPtr -> %d\n", &startPtr);
                   printf("\nstartPtr -> %d\n", startPtr);
                   printList(startPtr);
                }
                else {
                   printf("%c not found.\n\n", item);
                }
             }
             else {
                puts("List is empty.\n");
             }
             break;
          default:
             puts("Invalid choice.\n");
             instructions();
             break;
       }  // end switch
       printf("%s", "? ");
       scanf("%u", &choice);
    }
    puts("End of run.");
 }

 // display program instructions to user
 void instructions(void) {
    puts("Enter your choice:\n"
       "   1 to insert an element into the list.\n"
       "   2 to delete an element from the list.\n"
       "   3 to end.");
 }

 // insert a new value into the list in sorted order
 void insert(ListNodePtr *sPtr, char value) {
    printf("\nline 90: @sPtr -> %d\n", &sPtr);
    printf("\nsPtr -> %d\n", sPtr);
    ListNodePtr newPtr = malloc(sizeof(ListNode));  // create node
    printf("\nline 93: @newPtr -> %d\n", &newPtr);
    printf("\nnewPtr -> %d\n", newPtr);
    if (newPtr != NULL) {  // is space available
       newPtr->data = value;  // place value in node
       newPtr->nextPtr = NULL;  // node does not link to another node
       printf("\nline 98: @newPtr -> %d\n", &newPtr);
      printf("\nnewPtr -> %d\n", newPtr);
      ListNodePtr previousPtr = NULL;
      printf("\nline 101: @previousPtr -> %d\n", &previousPtr);
      printf("\npreviousPtr -> %d\n", previousPtr);
      ListNodePtr currentPtr = *sPtr;
      printf("\nline 104: @currentPtr -> %d\n", &currentPtr);
      printf("\ncurrentPtr -> %d\n", currentPtr);

      // loop to find the correct location in the list
      while (currentPtr != NULL && value > currentPtr->data) {
         previousPtr = currentPtr;  // walk to ...
         printf("\nline 110: @previousPtr -> %d\n", &previousPtr);
         printf("\npreviousPtr -> %d\n", previousPtr);
         currentPtr = currentPtr->nextPtr;  // ... next node
         printf("\nline 113: @currentPtr -> %d\n", &currentPtr);
         printf("\ncurrentPtr -> %d\n", currentPtr);
      }

      // insert new node at beginning of list
      if (previousPtr == NULL) {
         printf("\nline 119: @sPtr -> %d\n", &sPtr);
         printf("\nsPtr -> %d\n", sPtr);
         newPtr->nextPtr = *sPtr;
         printf("\nline 122: @newPtr -> %d\n", &newPtr);
         printf("\nnewPtr -> %d\n", newPtr);
         *sPtr = newPtr;
         printf("\nline 125: @sPtr -> %d\n", &sPtr);
         printf("\nsPtr -> %d\n", sPtr);
      }
      else {  // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         printf("\nline 130: @previousPtr -> %d\n", &previousPtr);
         printf("\npreviousPtr -> %d\n", previousPtr);
         newPtr->nextPtr = currentPtr;
         printf("\nline 133: @newPtr -> %d\n", &newPtr);
         printf("\nnewPtr -> %d\n", newPtr);
      }
   }
   else {
      printf("%c not inserted. No memory available.\n", value);
   }
 }

 // delete a list element
 char delete(ListNodePtr *sPtr, char value) {
   printf("\nline 144: @sPtr -> %d\n", &sPtr);
   printf("\nsPtr -> %d\n", sPtr);
   // delete first node if a match is found
   if (value == (*sPtr)->data) {
      printf("\nline 148: @sPtr -> %d\n", &sPtr);
      printf("\nsPtr -> %d\n", sPtr);
      ListNodePtr tempPtr = *sPtr;  // hold onto node being removed
      printf("\nline 151: @tempPtr -> %d\n", &tempPtr);
      printf("\ntempPtr -> %d\n", tempPtr);
      *sPtr = (*sPtr)->nextPtr;  // de-thread the node
      printf("\nline 154: @sPtr -> %d\n", &sPtr);
      printf("\nsPtr -> %d\n", sPtr);  
      free(tempPtr);  // free the de-threaded node
      return value;
   }
   else {
      ListNodePtr previousPtr = *sPtr;
      printf("\nline 161: @previousPtr -> %d\n", &previousPtr);
      printf("\npreviousPtr -> %d\n", previousPtr);
      ListNodePtr currentPtr = (*sPtr)->nextPtr;
      printf("\nline 164: @currentPtr -> %d\n", &currentPtr);
      printf("\ncurrentPtr -> %d\n", currentPtr);

      // loop to find the correct location in the list
      while (currentPtr != NULL && currentPtr->data != value) {
         previousPtr = currentPtr;  // walk to ...
         printf("\nline 170: @previousPtr -> %d\n", &previousPtr);
         printf("\npreviousPtr -> %d\n", previousPtr);
         currentPtr = currentPtr->nextPtr;  // ... next node
         printf("\nline 173: @currentPtr -> %d\n", &currentPtr);
         printf("\ncurrentPtr -> %d\n", currentPtr);
      }

      // delete node at currentPtr
      if (currentPtr != NULL) {
         ListNodePtr tempPtr = currentPtr;
         printf("\nline 180: @tempPtr -> %d\n", &tempPtr);
         printf("\ntempPtr -> %d\n", tempPtr);
         previousPtr->nextPtr = currentPtr->nextPtr;
         printf("\nline 183: @previousPtr -> %d\n", &previousPtr);
         printf("\npreviousPtr -> %d\n", previousPtr);
         free(tempPtr);
         return value;
      }
   }

   return '\0';
 }

 // return 1 if the list is empty, 0 otherwise
 int isEmpty(ListNodePtr sPtr) {
   printf("\nline 195: @sPtr -> %d\n", &sPtr);
   printf("\nsPtr -> %d\n", sPtr);
   return sPtr == NULL;
 }

 // print the list
 void printList(ListNodePtr currentPtr) {
   printf("\nline 202: @currentPtr -> %d\n", &currentPtr);
   printf("\ncurrentPtr -> %d\n", currentPtr);
   // if list is empty
   if (isEmpty(currentPtr)) {
      puts("List is empty.\n");
   }
   else {
      puts("The list is:");

      // while not the end of the list
      while (currentPtr != NULL) {
         printf("\nline 213: @currentPtr -> %d\n", &currentPtr);
         printf("\ncurrentPtr -> %d\n", currentPtr);
         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }
      puts("NULL\n");
   }
 }

