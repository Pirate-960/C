//-------------------------------------------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//-------------------------------------------------------------------------------------------//
// AVL_Tree Structure:-
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode {
    int data;
    int height;
    int frequency;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
};
int AVLTree_NumberOfComparisons;
int AVLTree_NumberOfRotations;
//-------------------------------------------------------------------------------------------//
// Splay Structure: -
//-------------------------------------------------------------------------------------------//
struct SplayTreeNode {
    int data;
    int height;
    int frequency;
    struct SplayTreeNode *left;
    struct SplayTreeNode *right;
    struct SplayTreeNode *parent;
};
int SplayTree_NumberOfComparisons;
int SplayTree_NumberOfRotations;
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVL_Tree_Root;
struct SplayTreeNode *Splay_Tree_Root;
//-------------------------------------------------------------------------------------------//
// AVL-Tree: Function Prototypes
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_Search(struct AVLTreeNode *node, int data);
struct AVLTreeNode *AVLTree_Insert(struct AVLTreeNode *root, int data);
struct AVLTreeNode *AVLTree_Balance(struct AVLTreeNode *root, int data);
struct AVLTreeNode *AVLTreeViolation_Left_Left_Imbalance(struct AVLTreeNode *node);
struct AVLTreeNode *AVLTreeViolation_Right_Right_Imbalance(struct AVLTreeNode *node);
struct AVLTreeNode *AVLTreeViolation_Left_Right_Imbalance(struct AVLTreeNode *node);
struct AVLTreeNode *AVLTreeViolation_Right_Left_Imbalance(struct AVLTreeNode *node);
struct AVLTreeNode *AVLTree_LeftRotation(struct AVLTreeNode *node);
struct AVLTreeNode *AVLTree_RightRotation(struct AVLTreeNode *node);
struct AVLTreeNode *AVLTree_Preorder_Traversal(struct AVLTreeNode *root);
struct AVLTreeNode *AVLTree_Inorder_Traversal(struct AVLTreeNode *root);
struct AVLTreeNode *AVLTree_Postorder_Traversal(struct AVLTreeNode *root);
int AVLTree_BalanceFactor(struct AVLTreeNode *node);
int AVLTree_Height(struct AVLTreeNode *node);
//-------------------------------------------------------------------------------------------//
// Splay Tree: Function Prototypes
//-------------------------------------------------------------------------------------------//
struct SplayTreeNode *SplayTree_Search_Node(struct SplayTreeNode *root, int data);
struct SplayTreeNode *SplayTree_Insert(struct SplayTreeNode *node, int data);
struct SplayTreeNode *SplayTree_Splay(struct SplayTreeNode *root, struct SplayTreeNode *node);
void SplayTree_Zig_Case(struct SplayTreeNode *parent);
void SplayTree_Zag_Case(struct SplayTreeNode *parent);
void SplayTree_Left_ZigZig_Case(struct SplayTreeNode *parent, struct SplayTreeNode *grandparent);
void SplayTree_Right_ZigZig_Case(struct SplayTreeNode *parent, struct SplayTreeNode *grandparent);
void SplayTree_Left_ZigZag_Case(struct SplayTreeNode *parent, struct SplayTreeNode *grandparent);
void SplayTree_Right_ZigZag_Case(struct SplayTreeNode *parent, struct SplayTreeNode *grandparent);
struct SplayTreeNode *SplayTree_LeftRotation(struct SplayTreeNode *node);
struct SplayTreeNode *SplayTree_RightRotation(struct SplayTreeNode *node);
struct SplayTreeNode *SplayTree_Preorder_Traversal(struct SplayTreeNode *root);
struct SplayTreeNode *SplayTree_Inorder_Traversal(struct SplayTreeNode *root);
struct SplayTreeNode *SplayTree_Postorder_Traversal(struct SplayTreeNode *root);
int SplayTree_Search_Value(struct SplayTreeNode *node, int data);
int SplayTree_Height(struct SplayTreeNode *key);
//-------------------------------------------------------------------------------------------//
/*
(1) The main function of this program appears to be implementing a comparison of two tree data structures, AVL trees and splay trees, using input data from a file. 
The function first declares a number of variables to store tree roots, input data, counters, and various totals related to the operation of the two tree data structures.

(2) The function then opens an input file and begins reading in integer values, one at a time, until the end of the file is reached. For each integer value read, the function inserts it into both the AVL tree and the splay tree.
If the value already exists in the splay tree, the frequency of the node containing the value is incremented instead.

(3) Once the input file has been fully processed, the function performs a preorder traversal of both the AVL tree and the splay tree, printing out the data values of the nodes as it goes.
The function also calculates and prints out the total number of comparisons and rotations performed for each tree, as well as the overall total cost of operations for each tree.
Finally, the function closes the input file and resets all relevant variables for the next iteration (if applicable).
*/
// The main() function -> Execution of the program (start + end) in this function.
int main(int argc, char *argv[]) {
    // Root of AVL-Tree
    AVL_Tree_Root = NULL;
    // Root of Splay Tree
    Splay_Tree_Root = NULL;

    int Input1;
    int Input2;

    int counter1 = 0;
    int counter2 = 0;

    int AVLTree_TotalCostOfOperations = 0;
    int SplayTree_TotalCostOfOperations = 0;

    struct AVLTreeNode *AVLTree_Traversal = NULL;
    struct SplayTreeNode *SplayTree_Traversal = NULL;
    struct SplayTreeNode *Splay_Tree_Duplicate = NULL;
//    if (argc == 1) {
//       printf("Error message!");
//    } else if (argc >= 2) {
//    FILE *InputFilePtr1 = fopen(argv[1], "r");
    FILE *InputFilePtr1 = fopen("input1.txt", "r");
    // Read the Input from the .txt file
    if (InputFilePtr1 == NULL) {
        printf("File couldn't be opened!");
        exit(1);
    } else {
    	printf("*****************************************\n");
    	printf("Input (1):- \n");
    	printf("*****************************************\n");
    	
        while ((fscanf(InputFilePtr1, "%d", &Input1)) != -1) {
            Input1 = ((int)Input1);
            printf("%d ",Input1);
            
            //printf("%d \n", AVLTree_NumberOfComparisons);
            //printf("%d \n", AVLTree_NumberOfRotations);
            //printf("%d \n", SplayTree_NumberOfComparisons);
            //printf("%d \n", SplayTree_NumberOfRotations);
            
			AVL_Tree_Root = AVLTree_Insert(AVL_Tree_Root, Input1);

            if (SplayTree_Search_Value(Splay_Tree_Root, Input1) == -1) {
                Splay_Tree_Root = SplayTree_Insert(Splay_Tree_Root, Input1);
            } else {
                Splay_Tree_Duplicate = SplayTree_Search_Node(Splay_Tree_Root, Input1);
                Splay_Tree_Duplicate -> frequency++;
                Splay_Tree_Root = SplayTree_Splay(Splay_Tree_Root, Splay_Tree_Duplicate);
            }
            counter1++;
        }
        
        printf("\n\n");
        
        printf("--------------------------------------------------------------------------------\n");
        printf("AVL Tree: \n");
        printf("--------------------------------------------------------------------------------\n");
        AVLTree_Traversal = AVLTree_Preorder_Traversal(AVL_Tree_Root);
        AVLTree_TotalCostOfOperations = AVLTree_NumberOfComparisons + AVLTree_NumberOfRotations;
        printf("\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("AVL Tree number of Comparisons: %d\n", AVLTree_NumberOfComparisons);
        printf("AVL Tree number of Rotations: %d\n", AVLTree_NumberOfRotations);
        printf("--------------------------------------------------------------------------------\n");
        printf("Total Cost: %d\n", AVLTree_TotalCostOfOperations);
        printf("--------------------------------------------------------------------------------\n");
        
        printf("\n");
        
        printf("--------------------------------------------------------------------------------\n");
        printf("Splay Tree: \n");
        printf("--------------------------------------------------------------------------------\n");
        SplayTree_Traversal = SplayTree_Preorder_Traversal(Splay_Tree_Root);
        SplayTree_TotalCostOfOperations = SplayTree_NumberOfComparisons + SplayTree_NumberOfRotations;
		printf("\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Splay Tree number of Comparisons: %d\n", SplayTree_NumberOfComparisons);
        printf("Splay Tree number of Rotations: %d\n", SplayTree_NumberOfRotations);
        printf("--------------------------------------------------------------------------------\n");
		printf("Total Cost: %d\n", SplayTree_TotalCostOfOperations);
		printf("--------------------------------------------------------------------------------\n");
    }

    // Close the Input File.
    fclose(InputFilePtr1);

    // Reset tree roots and counters
    AVL_Tree_Root = NULL;
    AVLTree_NumberOfComparisons = 0;
    AVLTree_NumberOfRotations = 0;
    AVLTree_Traversal = NULL;

    Splay_Tree_Root = NULL;
    SplayTree_NumberOfComparisons = 0;
    SplayTree_NumberOfRotations = 0;
    SplayTree_Traversal = NULL;
    
    printf("\n");

//    FILE *InputFilePtr2 = fopen(argv[2], "r");
    FILE *InputFilePtr2 = fopen("input2.txt", "r");
    if (InputFilePtr2 == NULL) {
        printf("File couldn't be opened!");
        exit(1);
    } else {
    	printf("*****************************************\n");
    	printf("Input (2):- \n");
    	printf("*****************************************\n");
    	
        while ((fscanf(InputFilePtr2, "%d", &Input2)) != -1) {
            Input2 = ((int) Input2);
            printf("%d ",Input2);
            
            //printf("%d \n", AVLTree_NumberOfComparisons);
            //printf("%d \n", AVLTree_NumberOfRotations);
            //printf("%d \n", SplayTree_NumberOfComparisons);
            //printf("%d \n", SplayTree_NumberOfRotations);
            
            AVL_Tree_Root = AVLTree_Insert(AVL_Tree_Root, Input2);
            
            if (SplayTree_Search_Value(Splay_Tree_Root, Input2) == -1) {
                Splay_Tree_Root = SplayTree_Insert(Splay_Tree_Root, Input2);
            } else {
                Splay_Tree_Duplicate = SplayTree_Search_Node(Splay_Tree_Root, Input2);
                Splay_Tree_Duplicate -> frequency++;
                Splay_Tree_Root = SplayTree_Splay(Splay_Tree_Root, Splay_Tree_Duplicate);
            }
            counter2++;
        }
        
        printf("\n\n");
        
        printf("--------------------------------------------------------------------------------\n");
        printf("AVL Tree: \n");
        printf("--------------------------------------------------------------------------------\n");
        AVLTree_Traversal = AVLTree_Preorder_Traversal(AVL_Tree_Root);
        AVLTree_TotalCostOfOperations = AVLTree_NumberOfComparisons + AVLTree_NumberOfRotations;
        printf("\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("AVL Tree number of Comparisons: %d\n", AVLTree_NumberOfComparisons);
        printf("AVL Tree number of Rotations: %d\n", AVLTree_NumberOfRotations);
        printf("--------------------------------------------------------------------------------\n");
        printf("Total Cost: %d\n", AVLTree_TotalCostOfOperations);
        printf("--------------------------------------------------------------------------------\n");
        
        printf("\n");
        
        printf("--------------------------------------------------------------------------------\n");
        printf("Splay Tree: \n");
        printf("--------------------------------------------------------------------------------\n");
        SplayTree_Traversal = SplayTree_Preorder_Traversal(Splay_Tree_Root);
        SplayTree_TotalCostOfOperations = SplayTree_NumberOfComparisons + SplayTree_NumberOfRotations;
        printf("\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("Splay Tree number of Comparisons: %d\n", SplayTree_NumberOfComparisons);
        printf("Splay Tree number of Rotations: %d\n", SplayTree_NumberOfRotations);
        printf("--------------------------------------------------------------------------------\n");
        printf("Total Cost: %d\n", SplayTree_TotalCostOfOperations);
        printf("--------------------------------------------------------------------------------\n");
    }

    // Close the Input File.
    fclose(InputFilePtr2);

    return 0;
//    }
}
//-------------------------------------------------------------------------------------------//
// AVL-Tree:-
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_Insert(struct AVLTreeNode *root, int data) {
    // Allocate memory for the new node + initialize values.
    struct AVLTreeNode *temp = (struct AVLTreeNode *) malloc(sizeof(struct AVLTreeNode));
    temp -> data = data;
    temp -> height = 1;
    temp -> frequency = 1;
    temp -> left = NULL;
    temp -> right = NULL;

    // If the tree is empty -> make the new node the root
    if (root == NULL) {
        root = temp;
        return root;
        // If the data is less than the root node's data, insert it in the left subtree
    } else if (temp -> data < root -> data) {
        AVLTree_NumberOfComparisons++;
        root -> left = AVLTree_Insert(root -> left, data);
        // If the data is greater than the root node's data, insert it in the right subtree
    } else if (temp -> data > root -> data) {
        AVLTree_NumberOfComparisons++;
        root -> right = AVLTree_Insert(root -> right, data);
        // If the data is equal to the root node's data, increment the frequency of the root node
    } else if (root -> data == temp -> data) {
        root -> frequency++;
        AVLTree_NumberOfComparisons++;
        return root;
    }
    // Balance the tree if necessary and return the root node
    root = AVLTree_Balance(root, data);
    return root;
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_Balance(struct AVLTreeNode *node, int data) {
    // Get the left and right children of the node
    struct AVLTreeNode *left = node -> left;
    struct AVLTreeNode *right = node -> right;

    // Initialize variables for left and right child heights and balance factor
    int left_height = 0;
    int right_height = 0;
    int BalanceFactor = 0;

    // Get the heights of the left and right children
    left_height = AVLTree_Height(node -> left);
    right_height = AVLTree_Height(node -> right);

    // Update the height of the node
    node -> height = (left_height > right_height ? left_height : right_height) + 1;

    // Calculate the balance factor of the node
    BalanceFactor = AVLTree_BalanceFactor(node);

    // If the balance factor is greater than 1, there is a violation on the left side
    if (BalanceFactor > 1) {
        // If the data to be inserted is less than the left child's data, it is a left-left imbalance
        if (data < left -> data) {
            node = AVLTreeViolation_Left_Left_Imbalance(node);
            // If the data to be inserted is greater than the left child's data, it is a left-right imbalance
        } else if (data > left -> data) {
            node = AVLTreeViolation_Left_Right_Imbalance(node);
        }
    // If the balance factor is less than -1, there is a violation on the right side
    } else if (BalanceFactor < -1) {
        // If the data to be inserted is less than the right child's data, it is a right-left imbalance
        if (data < right -> data) {
            node = AVLTreeViolation_Right_Left_Imbalance(node);
            // If the data to be inserted is greater than the right child's data, it is a right-right imbalance
        } else if (data > right -> data) {
            node = AVLTreeViolation_Right_Right_Imbalance(node);
        }
        // If the balance factor is within the acceptable range, return the node
    } else {
        return node;
    }
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_Search(struct AVLTreeNode *node, int data) {
    struct AVLTreeNode *temp = (struct AVLTreeNode*)malloc(sizeof(struct AVLTreeNode));
    temp -> data = data;
    temp -> height = 1;
    temp -> frequency = 1;
    temp -> left = NULL;
    temp -> right = NULL;
    // If the node is NULL, return
    if (node == NULL) {
        node = temp;
        return node;
        // If the data to be searched for is less than the node's data, search in the left subtree
    } else if (node -> data < data) {
        node = node -> left;
        AVLTree_Search(node, data);
        // If the data to be searched for is greater than the node's data, search in the right subtree
    } else if (node -> data > data) {
        node = node -> right;
        AVLTree_Search(node, data);
        // If the data to be searched for is equal to the node's data, increment the frequency of the node and return it
    } else if (node -> data == data) {
        node -> frequency++;
        printf("Data is found!");
        return node;
    }
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTreeViolation_Left_Left_Imbalance(struct AVLTreeNode *node) {
    // Perform a right rotation and update the number of rotations
    AVLTree_NumberOfRotations++;
    return AVLTree_RightRotation(node);
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTreeViolation_Right_Right_Imbalance(struct AVLTreeNode *node) {
    // Perform a left rotation and update the number of rotations
    AVLTree_NumberOfRotations++;
    return AVLTree_LeftRotation(node);
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTreeViolation_Left_Right_Imbalance(struct AVLTreeNode *node) {
    // Perform a left rotation on the left child and a right rotation on the node, updating the number of rotations each time
    node -> left = AVLTree_LeftRotation(node -> left);
    AVLTree_NumberOfRotations++;
    AVLTree_NumberOfRotations++;
    return AVLTree_RightRotation(node);
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTreeViolation_Right_Left_Imbalance(struct AVLTreeNode *node) {
    // Perform a right rotation on the right child and a left rotation on the node, updating the number of rotations each time
    node -> right = AVLTree_RightRotation(node -> right);
    AVLTree_NumberOfRotations++;
    AVLTree_NumberOfRotations++;
    return AVLTree_LeftRotation(node);
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_LeftRotation(struct AVLTreeNode *node) {
    // Initialize variables for left and right child heights
    int left_height = 0;
    int right_height = 0;

    // Perform left rotation
    struct AVLTreeNode *temp1 = node -> right;
    struct AVLTreeNode *temp2 = temp1 -> left;
    
    temp1 -> left = node;
    node -> right = temp2;

    // Update the heights of the rotated nodes
    left_height = AVLTree_Height(node -> left);
    right_height = AVLTree_Height(node -> right);
    node -> height = (left_height > right_height ? left_height : right_height) + 1;

    left_height = AVLTree_Height(temp1 -> left);
    right_height = AVLTree_Height(temp1 -> right);
    temp1 -> height = (left_height > right_height ? left_height : right_height) + 1;

    return temp1;
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_RightRotation(struct AVLTreeNode *node) {
    // Initialize variables for left and right child heights
    int left_height = 0;
    int right_height = 0;

    // Perform right rotation
    struct AVLTreeNode *temp1 = node -> left;
    struct AVLTreeNode *temp2 = temp1 -> right;

    temp1 -> right = node;
    node -> left = temp2;

    // Update the heights of the rotated nodes
    left_height = AVLTree_Height(node -> left);
    right_height = AVLTree_Height(node -> right);
    node -> height = (left_height > right_height ? left_height : right_height) + 1;

    left_height = AVLTree_Height(temp1 -> left);
    right_height = AVLTree_Height(temp1 -> right);
    temp1 -> height = (left_height > right_height ? left_height : right_height) + 1;

    return temp1;
}
//-------------------------------------------------------------------------------------------//
int AVLTree_Height(struct AVLTreeNode *node) {
    // If the node is NULL, return -1
    if (node == NULL) {
        return -1;
    } else {
        // Otherwise, return the height of the node by calculating the maximum height of the left and right children and adding 1
        int left_height = AVLTree_Height(node -> left);
        int right_height = AVLTree_Height(node -> right);
        return (left_height > right_height ? left_height : right_height) + 1;
    }
}
//-------------------------------------------------------------------------------------------//
int AVLTree_BalanceFactor(struct AVLTreeNode *node) {
    // calculate the balance factor by subtracting the height of the right child from the height of the left child
    int BalanceFactor = AVLTree_Height(node -> left) - AVLTree_Height(node -> right);
    // If the node is NULL, return 0
    if (node == NULL) {
        return 0;
    } else {
        return BalanceFactor;
    }
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_Preorder_Traversal(struct AVLTreeNode *root) {
    // If the root node is NULL, return NULL
    if (root == NULL) {
        return NULL;
        // Otherwise, print the root node data, traverse the left subtree, and traverse the right subtree
    } else {
        // Allocate memory for a new node
        struct AVLTreeNode *node = malloc(sizeof(struct AVLTreeNode));
        // Print the root node data
        printf("%d ", root -> data);
        // Set the data of the new node to the root node data
        node -> data = root -> data;
        // Traverse the left subtree
        node -> left = AVLTree_Preorder_Traversal(root -> left);
        // Traverse the right subtree
        node -> right = AVLTree_Preorder_Traversal(root -> right);
        return node;
    }
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_Inorder_Traversal(struct AVLTreeNode *root) {
    // If the root node is NULL, return NULL
    if (root == NULL) {
        return NULL;
        // Otherwise, traverse the left subtree, print the root node data, and traverse the right subtree
    } else {
        // Allocate memory for a new node
        struct AVLTreeNode *node = malloc(sizeof(struct AVLTreeNode));
        // Traverse the left subtree
        node -> left = AVLTree_Inorder_Traversal(root -> left);
        // Print the root node data
        printf("%d", root->data);
        // Set the data of the new node to the root node data
        node -> data = root->data;
        // Traverse the right subtree
        node -> right = AVLTree_Inorder_Traversal(root -> right);
        return node;
    }
}
//-------------------------------------------------------------------------------------------//
struct AVLTreeNode *AVLTree_Postorder_Traversal(struct AVLTreeNode *root) {
    // If the root node is NULL, return NULL
    if (root == NULL) {
        return NULL;
        // Otherwise, traverse the left subtree, traverse the right subtree, and print the root node data
    } else {
        // Allocate memory for a new node
        struct AVLTreeNode *node = malloc(sizeof(struct AVLTreeNode));
        // Traverse the left subtree
        node -> left = AVLTree_Postorder_Traversal(root -> left);
        // Traverse the right subtree
        node -> right = AVLTree_Postorder_Traversal(root -> right);
        // Print the root node data
        printf("%d ", root -> data);
        // Set the data of the new node to the root node data
        node -> data = root -> data;
        return node;
    }
}
//-------------------------------------------------------------------------------------------//
// Splay Tree:-
//-------------------------------------------------------------------------------------------//
// SplayTree_Search_Node: Search for a node with the given data in a splay tree.
//
// Parameters:
// - root: Pointer to the root of the splay tree.
// - data: Data value to search for.
//
// Returns: Pointer to the node with the given data if found, or NULL if not found.
struct SplayTreeNode *SplayTree_Search_Node(struct SplayTreeNode *root, int data) {
    // Return NULL if the tree is empty.
    if (root == NULL) {
        return root;
    }
    // Increment the number of comparisons performed.
    SplayTree_NumberOfComparisons++;

    // Search for the node with the given data recursively.
	if (data < root -> data) {
        return SplayTree_Search_Node(root -> left, data);
    } else if (data > root -> data) {
        return SplayTree_Search_Node(root -> right, data);
    } else if (data == root -> data) {
        // Found the node, return it.
        return root;
    }
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Search_Value: Search for a value in a splay tree and increment the frequency of the node containing the value if found.
//
// Parameters:
// - node: Pointer to the root of the splay tree.
// - data: Value to search for.
//
// Returns: 1 if the value was found, or -1 if not found.
int SplayTree_Search_Value(struct SplayTreeNode *node, int data) {
    // Return -1 if the tree is empty or if we have reached a leaf node without finding the value
    if (node == NULL) {
        return -1;
        // Recursively search the left subtree.
    } else if (SplayTree_Search_Value(node -> left, data) == 1) {
        return 1;
        // Recursively search the right subtree.
    } else if (SplayTree_Search_Value(node -> right, data) == 1) {
        return 1;
        // Check if the current node contains the value.
    } else if (node -> data == data) {
        // Increment the frequency of the node.
        node -> frequency++;
    	return 1;
    } else {
        return -1;
    }
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Insert: Insert a new node with the given data into a splay tree.
//
// Parameters:
// - node: Pointer to the root of the splay tree.
// - data: Data value to insert.
//
// Returns: Pointer to the root of the splay tree after insertion.
struct SplayTreeNode *SplayTree_Insert(struct SplayTreeNode *node, int data) {
    // Find the correct place to insert the new node.
    struct SplayTreeNode *temp1 = node;
    struct SplayTreeNode *temp2 = NULL;

    // Create the new node to insert.
    struct SplayTreeNode *temp3 = (struct SplayTreeNode*)malloc(sizeof(struct SplayTreeNode));
    temp3 -> data = data;
    temp3 -> height = 1;
    temp3 -> frequency = 1;
    temp3 -> left = NULL;
    temp3 -> right = NULL;
    temp3 -> parent = NULL;

    while (temp1 != NULL) {
        temp2 = temp1;
        if (temp1 -> data > temp3 -> data) {
            SplayTree_NumberOfComparisons++;
            temp1 = temp1 -> left;
        } else {
            SplayTree_NumberOfComparisons++;
            temp1 = temp1 -> right;
        }
    }

    // Update the parent of the new node.
    temp3 -> parent = temp2;

    // Insert the new node into the tree.
    if (temp2 == NULL) {
        // The tree is empty, the new node becomes the root.
        return temp3;
    } else if (temp2 -> data > temp3 -> data) {
        temp2 -> left = temp3;
    } else {
        temp2 -> right = temp3;
    }

    // Splay the tree to bring the new node to the root.
    return SplayTree_Splay(node, temp3);
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Splay: Splay a splay tree around a given node.
//
// Parameters:
// - root: Pointer to the root of the splay tree.
// - node: Pointer to the node to splay the tree around.
//
// Returns: Pointer to the root of the splay tree after splaying.
struct SplayTreeNode *SplayTree_Splay(struct SplayTreeNode *root, struct SplayTreeNode *node) {
    // Keep splaying the tree until the node becomes the root.
    while (node -> parent != NULL) {
        // Handle the different splay cases.
        if (node -> parent == root) {
            // Zig or Zag case.
            if (node == node -> parent -> left) {
                SplayTree_Zig_Case(node -> parent);
            } else if (node == node -> parent -> right) {
                SplayTree_Zag_Case(node -> parent);
            }

        } else {

            struct SplayTreeNode *parent = node -> parent;
            struct SplayTreeNode *grandparent = parent -> parent;

            if (node == node -> parent -> left) {
                // Zig-Zig or Zig-Zag case.
                if (parent == parent -> parent -> left) {
                    SplayTree_Left_ZigZig_Case(parent, grandparent);

                } else if (parent == parent -> parent -> right) {
                    SplayTree_Right_ZigZag_Case(parent, grandparent);
                }
            } else if (node == node -> parent -> right) {
                // Zag-Zig or Zag-Zag case.
                if (parent == parent -> parent -> left) {
                    SplayTree_Left_ZigZag_Case(parent, grandparent);

                } else if (parent == parent -> parent -> right) {
                    SplayTree_Right_ZigZig_Case(parent, grandparent);
                }
            }
        }
    }
    // Return the root of the splay tree after splaying.
    return node;
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Zig_Case: Handle a splay tree Zig case.
//
// Parameters:
// - parent: Pointer to the parent node of the node being splayed.
void SplayTree_Zig_Case(struct SplayTreeNode *parent) {
    // Perform a right rotation.
    SplayTree_NumberOfRotations++;
    SplayTree_RightRotation(parent);
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Zag_Case: Handle a splay tree Zag case.
//
// Parameters:
// - parent: Pointer to the parent node of the node being splayed.
void SplayTree_Zag_Case(struct SplayTreeNode *parent) {
    // Perform a left rotation.
    SplayTree_NumberOfRotations++;
    SplayTree_LeftRotation(parent);
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Left_ZigZig_Case: Handle a splay tree Zig-Zig case where the parent is the left child of the grandparent.
//
// Parameters:
// - parent: Pointer to the parent node of the node being splayed.
// - grandparent: Pointer to the grandparent node of the node being splayed.
void SplayTree_Left_ZigZig_Case(struct SplayTreeNode *parent, struct SplayTreeNode *grandparent) {
    // Perform two right rotations.
    SplayTree_NumberOfRotations++;
    SplayTree_RightRotation(grandparent);
    SplayTree_NumberOfRotations++;
    SplayTree_RightRotation(parent);
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Right_ZigZig_Case: Handle a splay tree Zig-Zig case where the parent is the right child of the grandparent.
//
// Parameters:
// - parent: Pointer to the parent node of the node being splayed.
// - grandparent: Pointer to the grandparent node of the node being splayed.
void SplayTree_Right_ZigZig_Case(struct SplayTreeNode *parent, struct SplayTreeNode *grandparent) {
    // Perform two left rotations.
    SplayTree_NumberOfRotations++;
    SplayTree_LeftRotation(grandparent);
    SplayTree_NumberOfRotations++;
    SplayTree_LeftRotation(parent);
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Left_ZigZag_Case: Handle a splay tree Zig-Zag case where the parent is the left child of the grandparent.
//
// Parameters:
// - parent: Pointer to the parent node of the node being splayed.
// - grandparent: Pointer to the grandparent node of the node being splayed.
void SplayTree_Left_ZigZag_Case(struct SplayTreeNode *parent, struct SplayTreeNode *grandparent) {
    // Perform a left rotation on the parent and a right rotation on the grandparent.
    SplayTree_NumberOfRotations++;
    SplayTree_LeftRotation(parent);
    SplayTree_NumberOfRotations++;
    SplayTree_RightRotation(grandparent);

}
//-------------------------------------------------------------------------------------------//
// SplayTree_Right_ZigZag_Case: Handle a splay tree Zig-Zag case where the parent is the right child of the grandparent.
//
// Parameters:
// - parent: Pointer to the parent node of the node being splayed.
// - grandparent: Pointer to the grandparent node of the node being splayed.
void SplayTree_Right_ZigZag_Case(struct SplayTreeNode *parent, struct SplayTreeNode *grandparent) {
    // Perform a right rotation on the parent and a left rotation on the grandparent.
    SplayTree_NumberOfRotations++;
    SplayTree_RightRotation(parent);
    SplayTree_NumberOfRotations++;
    SplayTree_LeftRotation(grandparent);
}
//-------------------------------------------------------------------------------------------//
// SplayTree_LeftRotation: Perform a left rotation on a splay tree.
//
// Parameters:
// - node: Pointer to the node to rotate around.
//
// Returns: Pointer to the root of the subtree after rotating.
struct SplayTreeNode *SplayTree_LeftRotation(struct SplayTreeNode *node) {
    // Save a reference to the right child of the node.
    struct SplayTreeNode *temp = node -> right;
    // Make the left child of the right child the new right child of the node.
    node -> right = temp -> left;

    // Update the parent of the new right child.
    if (node -> right != NULL) {
        node -> right -> parent = node;
    }

    // Update the parent of the temp node.
    temp -> parent = node -> parent;

    // Update the child of the temp node's parent to be the temp node.
    if (node -> parent != NULL) {
        if (node -> parent -> data > temp -> data) {
            node -> parent -> left = temp;
        } else {
            node -> parent -> right = temp;
        }
    }
    
    // Make the node the left child of the temp node.
    temp -> left = node;

    // Update the parent of the node to be the temp node.
    node -> parent = temp;

    // Return the temp node, which is now the root of the subtree.
    return temp;
}
//-------------------------------------------------------------------------------------------//
// SplayTree_RightRotation: Perform a right rotation on a splay tree.
//
// Parameters:
// - node: Pointer to the node to rotate around.
//
// Returns: Pointer to the root of the subtree after rotating.
struct SplayTreeNode *SplayTree_RightRotation(struct SplayTreeNode *node) {
    // Save a reference to the left child of the node.
    struct  SplayTreeNode *temp = node -> left;
    // Make the right child of the left child the new left child of the node.
    node -> left = temp -> right;

    // Update the parent of the new left child.
    if (node -> left != NULL) {
        node -> left -> parent = node;
    }

    // Update the parent of the temp node.
    temp -> parent = node -> parent;

    // Update the child of the temp node's parent to be the temp node.
    if (node -> parent != NULL) {
        if (node -> parent -> data > temp -> data) {
            node -> parent -> left = temp;
        } else {
            node -> parent -> right = temp;
        }
    }

    // Make the node the right child of the temp node.
    temp -> right = node;

    // Update the parent of the node to be the temp node.
    node -> parent = temp;

    // Return the temp node, which is now the root of the subtree.
    return temp;
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Height: Calculate the height of a splay tree.
//
// Parameters:
// - key: Pointer to the root node of the tree.
//
// Returns: The height of the tree.
int SplayTree_Height(struct SplayTreeNode *key) {
    // If the tree is empty, return -1.
    if (key == NULL) {
        return -1;
    } else {
        // Calculate the height of the left and right subtrees.
        int left_height = SplayTree_Height(key -> left);
        int right_height = SplayTree_Height(key -> right);
        // Return the maximum of the left and right heights, plus 1 for the root node.
        return (left_height > right_height ? left_height : right_height) + 1;
    }
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Preorder_Traversal: Perform a preorder traversal of a splay tree and print the data of each node.
//
// Parameters:
// - root: Pointer to the root node of the tree.
//
// Returns: Pointer to the root node of a copy of the tree.
struct SplayTreeNode *SplayTree_Preorder_Traversal(struct SplayTreeNode *root) {
    // If the tree is empty, return NULL.
    if (root == NULL) {
        return NULL;
    } else {
        // Allocate memory for a new node.
        struct SplayTreeNode *node = malloc(sizeof(struct SplayTreeNode));
        // Print the data of the root node.
        printf("%d ", root -> data);
        // Recursively traverse the left and right subtrees and assign the returned nodes to the left and right children of the new node.
        node -> data = root-> data;
        node -> left = SplayTree_Preorder_Traversal(root -> left);
        node -> right = SplayTree_Preorder_Traversal(root -> right);

        // Return the new node, which is a copy of the root node.
        return node;
    }
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Inorder_Traversal: Perform an inorder traversal of a splay tree and print the data of each node.
//
// Parameters:
// - root: Pointer to the root node of the tree.
//
// Returns: Pointer to the root node of a copy of the tree.
struct SplayTreeNode *SplayTree_Inorder_Traversal(struct SplayTreeNode *root) {
    // If the tree is empty, return NULL.
    if (root == NULL) {
        return NULL;
    } else {
        // Allocate memory for a new node.
        struct SplayTreeNode *node = malloc(sizeof(struct SplayTreeNode));
        // Recursively traverse the left subtree and assign the returned node to the left child of the new node.
        node -> left = SplayTree_Inorder_Traversal(root -> left);
        // Assign the data of the root node to the new node.
        node -> data = root -> data;
        // Print the data of the root node.
        printf("%d ", root -> data);
        // Recursively traverse the right subtree and assign the returned node to the right child of the new node.
        node -> right = SplayTree_Inorder_Traversal(root -> right);

        // Return the new node, which is a copy of the root node.
        return node;
    }
}
//-------------------------------------------------------------------------------------------//
// SplayTree_Postorder_Traversal: Perform a postorder traversal of a splay tree and print the data of each node.
//
// Parameters:
// - root: Pointer to the root node of the tree.
//
// Returns: Pointer to the root node of a copy of the tree.
struct SplayTreeNode *SplayTree_Postorder_Traversal(struct SplayTreeNode *root) {
    // If the tree is empty, return NULL.
    if (root == NULL) {
        return NULL;
    } else {
        // Allocate memory for a new node.
        struct SplayTreeNode *node = malloc(sizeof(struct SplayTreeNode));
        // Recursively traverse the left and right subtrees and assign the returned nodes to the left and right children of the new node
        node -> left = SplayTree_Postorder_Traversal(root -> left);
        node -> right = SplayTree_Postorder_Traversal(root -> right);

        // Assign the data of the root node to the new node.
        node -> data = root -> data;
        // Print the data of the root node.
        printf("%d ", root -> data);

        // Return the new node, which is a copy of the root node.
        return node;
    }
}
//-------------------------------------------------------------------------------------------//
