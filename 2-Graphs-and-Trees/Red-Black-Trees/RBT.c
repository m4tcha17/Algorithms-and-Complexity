// Binary Search Tree Implementation
#include <stdio.h>
#include <stdlib.h>
#define SIZE 0xFF

typedef struct cell{
    int elem;
    struct cell *left;
    struct cell *right;
    int height;
} ctype, *RBT;

void initTree(RBT *);
void insertAll(RBT *, int[], int);
RBT Insert(RBT *, int);
RBT Delete(RBT *, int);

// Rotation Functions
void rightRotate(RBT *);
void leftRotate(RBT *);

// --- New Visualization Functions ---
void visualizeInorder(RBT T);
void visualizePreorder(RBT T, int level); // Helper for indented print
void Visualize(RBT T);
// -----------------------------------

int main(){
    // The base array for most tests
    int arr[] = {4, 7, 2, 3, 6, 1, 5, 8, 9, 10, 15, 28, 75, 17, 34};
    int size = sizeof(arr) / sizeof(arr[0]);
    RBT S;
    int elem;

    // --- SETUP: Full Tree for Deletion Cases ---
    printf("\n--- Test Setup: Initial Full Tree ---\n");
    initTree(&S);
    insertAll(&S, arr, size);
    Visualize(S);

    // // --- TEST 1, 2: Leaf and Simple Deletion ---
    // printf("\n\n--- TEST 1: Delete Leaf Node (1) ---\n");
    // S = Delete(&S, 1);
    // Visualize(S);

    // printf("\n\n--- TEST 2: Repeated Deletion (6, then 6 again) ---\n");
    // Delete(&S, 6); // Case 1: Leaf
    // Delete(&S, 6); // Test: Not Found
    // Visualize(S);

    // // --- TEST 10: Delete Node with 1 Child (Left Link) ---
    // printf("\n\n--- TEST 10: Delete Node with 1 Child (2) ---\n");
    // Delete(&S, 2); // Case 2: 2 has only child 3
    // Visualize(S);

    // // --- TEST 3: Delete Node with 1 Child (Right Link) ---
    // printf("\n\n--- TEST 3: Delete Node with 1 Child (7) ---\n");
    // Delete(&S, 7); // Case 2: 7 has only child 8
    // Visualize(S);

    // // --- TEST 5 & 6: Two-Child Deletion (Harder Cases) ---
    // printf("\n\n--- TEST 5: Delete Node with 2 Children (15) ---\n");
    // Delete(&S, 15); // Case 3: 15 replaced by successor 17
    // Visualize(S);

    // printf("\n\n--- TEST 6: Delete Node with 2 Children (28) ---\n");
    // Delete(&S, 28); // Case 3: 28 replaced by successor 34
    // Visualize(S);

    // // --- TEST 4: Delete the Root (The Ultimate Test) ---
    // printf("\n\n--- TEST 4: Delete the Root (4) ---\n");
    // Delete(&S, 4); // Case 3: 4 replaced by successor 5
    // Visualize(S);

    // // --- TEST 7: Element Not Found ---
    // printf("\n\n--- TEST 7: Delete Non-Existent Element (99) ---\n");
    // Delete(&S, 99); // Test: Not Found

    // // --- TEST 8: Delete from Empty Tree ---
    // printf("\n\n--- TEST 8: Delete from an Empty Tree ---\n");
    // RBT EmptyTree;
    // initTree(&EmptyTree);
    // Delete(&EmptyTree, 100); // Test: Empty Tree message
    return 0;
}

void initTree(RBT *T){
    *T = NULL;
}

void insertAll(RBT *T, int *arr, int size){
    for (int i = 0; i < size; i++){
        *T = Insert(T, arr[i]);
    }
}

RBT Insert(RBT *T, int elem){

}

RBT Delete(RBT *T, int elem){
   
}

RBT newNode(int elem){
    RBT node = (RBT)malloc(sizeof(ctype));

    if (node != NULL){
        node->elem = elem;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }

    return node;
}

void leftRotate(RBT *T){
    // Child of the Parent
    RBT child = (*T)->right;
    // Left Child of the Child Node
    RBT temp = child->left;

    // Change the Left Child of the Child to the Parent
    child->left = *T;
    // Make sure the left child of the previous child node is still linked
    (*T)->right = temp;

    // Fix height of both nodes
    (*T)->height = max(height((*T)->left), height((*T)->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;

    // Change the new Parent to the Child
    *T = child;
}

void rightRotate(RBT *T){
    RBT child = (*T)->left;
    RBT temp = child->right;

    child->right = *T;
    (*T)->left = temp;

    (*T)->height = max(height((*T)->left), height((*T)->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;

    *T = child;
}

// ----------------------------------------------------------------
// # Visualization Functions
// # NOTE: Taken From Gemini
// ----------------------------------------------------------------

void visualizeInorder(RBT T)
{
    if (T != NULL)
    {
        visualizeInorder(T->left);
        printf("%d ", T->elem);
        visualizeInorder(T->right);
    }
}

void visualizePreorder(RBT T, int level){
    if (T != NULL){
        // Print the right child first (makes the output look like a tree turned 90 degrees left)
        visualizePreorder(T->right, level + 1);

        // Print indentation
        for (int i = 0; i < level; i++){
            printf("      "); // Adjust spacing for desired look
        }

        // Print the element, marking the root of the current subtree
        printf("|---%d\n", T->elem);

        // Print the left child
        visualizePreorder(T->left, level + 1);
    }
}

void Visualize(RBT T){
    if (T == NULL){
        printf("The RBT is Empty.\n");
        return;
    }

    // 1. Inorder Traversal (Confirms Sorted Property)
    printf("\nInorder Traversal (Sorted Elements): ");
    visualizeInorder(T);
    printf("\n");

    // 2. Structural Visualization (Preorder with Indentation)
    printf("\nStructural Visualization:\n");
    visualizePreorder(T, 0);
    printf("\n");
}