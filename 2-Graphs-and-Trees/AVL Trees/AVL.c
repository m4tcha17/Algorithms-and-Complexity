// Binary Search Tree Implementation
#include <stdio.h>
#include <stdlib.h>
#define SIZE 0xFF

typedef struct cell{
    int elem;
    struct cell *LC;
    struct cell *RC;
    int height;
} ctype, *AVL;

void initTree(AVL*);
void insertAll(AVL*, int[], int);
AVL Insert(AVL, int);
void Delete(AVL*, int);

// Helper Functions
int height(AVL);
int max(int, int);
// --- New Visualization Functions ---
void visualizeInorder(AVL T);
void visualizePreorder(AVL T, int level); // Helper for indented print
void Visualize(AVL T);
// -----------------------------------

int main(){
    // The base array for most tests
    int arr[] = {4, 7, 2, 3, 6, 1, 5, 8, 9, 10, 15, 28, 75, 17, 34};
    int size = sizeof(arr) / sizeof(arr[0]);
    AVL S;
    int elem;

    // --- SETUP: Full Tree for Deletion Cases ---
    printf("\n--- Test Setup: Initial Full Tree ---\n");
    initTree(&S);
    insertAll(&S, arr, size);

    // --- TEST 1, 2: Leaf and Simple Deletion ---
    printf("\n\n--- TEST 1: Delete Leaf Node (1) ---\n");
    Delete(&S, 1);
    Visualize(S);

    printf("\n\n--- TEST 2: Repeated Deletion (6, then 6 again) ---\n");
    Delete(&S, 6); // Case 1: Leaf
    Delete(&S, 6); // Test: Not Found
    Visualize(S);

    // --- TEST 10: Delete Node with 1 Child (Left Link) ---
    printf("\n\n--- TEST 10: Delete Node with 1 Child (2) ---\n");
    Delete(&S, 2); // Case 2: 2 has only child 3
    Visualize(S);

    // --- TEST 3: Delete Node with 1 Child (Right Link) ---
    printf("\n\n--- TEST 3: Delete Node with 1 Child (7) ---\n");
    Delete(&S, 7); // Case 2: 7 has only child 8
    Visualize(S);

    // --- TEST 5 & 6: Two-Child Deletion (Harder Cases) ---
    printf("\n\n--- TEST 5: Delete Node with 2 Children (15) ---\n");
    Delete(&S, 15); // Case 3: 15 replaced by successor 17
    Visualize(S);

    printf("\n\n--- TEST 6: Delete Node with 2 Children (28) ---\n");
    Delete(&S, 28); // Case 3: 28 replaced by successor 34
    Visualize(S);

    // --- TEST 4: Delete the Root (The Ultimate Test) ---
    printf("\n\n--- TEST 4: Delete the Root (4) ---\n");
    Delete(&S, 4); // Case 3: 4 replaced by successor 5
    Visualize(S);

    // --- TEST 7: Element Not Found ---
    printf("\n\n--- TEST 7: Delete Non-Existent Element (99) ---\n");
    Delete(&S, 99); // Test: Not Found

    // --- TEST 8: Delete from Empty Tree ---
    printf("\n\n--- TEST 8: Delete from an Empty Tree ---\n");
    AVL EmptyTree;
    initTree(&EmptyTree);
    Delete(&EmptyTree, 100); // Test: Empty Tree message

    return 0;
}

void initTree(AVL *T){
    *T = NULL;
}

void insertAll(AVL *T, int* arr, int size){
    for(int i = 0; i < size; i++){
        *T = Insert(*T, arr[i]);
    }
}

AVL Insert(AVL T, int elem){
    // Insert at Base Level
    if(T == NULL){
        AVL temp = (AVL)malloc(sizeof(AVL));
        temp->elem = elem;
        temp->LC = NULL;
        temp->RC = NULL;
        temp->height = 0;
        T = temp;
    }
    // If not base level continue going down through recursion
    else{
        if(T->elem > elem){
            T->LC = Insert(T->LC, elem);
        }
        else{
            T->RC = Insert(T->RC, elem);
        } 
    }

    T->height = 1 + (max(height(T->LC), height(T->RC)));

    // Rotation Logic
    int BF = height(T->LC) - height(T->RC);

    //Left-Left Case
    if(BF >? )

    return T;
}

int height(AVL T){
    if(T != NULL) return T->height;
    return -1;
}

int max(int LC, int RC){
    return (LC < RC) ? RC : LC; 
}

// ----------------------------------------------------------------
// # Visualization Functions
// # NOTE: Taken From Gemini
// ----------------------------------------------------------------

void visualizeInorder(AVL T){
    if (T != NULL){
        visualizeInorder(T->LC);
        printf("%d ", T->elem);
        visualizeInorder(T->RC);
    }
}

void visualizePreorder(AVL T, int level){
    if(T != NULL){
        // Print the right child first (makes the output look like a tree turned 90 degrees left)
        visualizePreorder(T->RC, level + 1);

        // Print indentation
        for (int i = 0; i < level; i++){
            printf("      "); // Adjust spacing for desired look
        }

        // Print the element, marking the root of the current subtree
        printf("|---%d\n", T->elem);

        // Print the left child
        visualizePreorder(T->LC, level + 1);
    }
}

void Visualize(AVL T){
    if (T == NULL){
        printf("The AVL is Empty.\n");
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