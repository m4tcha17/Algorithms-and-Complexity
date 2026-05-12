// Binary Search Tree Implementation
#include <stdio.h>
#include <stdlib.h>
#define SIZE 0xFF

typedef struct cell{
    int elem;
    struct cell *left;
    struct cell *right;
    int height;
} ctype, *AVL;

void initTree(AVL *);
void insertAll(AVL *, int[], int);
AVL Insert(AVL *, int);
AVL Delete(AVL *, int);

// Helper Functions
int height(AVL);
int max(int, int);
int getBalance(AVL);
AVL newNode(int);
AVL minValueNode(AVL);

// Rotation Functions
void rightRotate(AVL *);
void leftRotate(AVL *);

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
    Visualize(S);

    // --- TEST 1, 2: Leaf and Simple Deletion ---
    printf("\n\n--- TEST 1: Delete Leaf Node (1) ---\n");
    S = Delete(&S, 1);
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

void insertAll(AVL *T, int *arr, int size){
    for (int i = 0; i < size; i++){
        *T = Insert(T, arr[i]);
    }
}

AVL Insert(AVL *T, int elem){
    // Once reaches the bottom of the tree
    if (*T == NULL) return newNode(elem);

    // Traversal to find corrrect spot on AVL Tree
    if ((*T)->elem < elem){
        (*T)->right = Insert(&(*T)->right, elem);
    }
    else if ((*T)->elem > elem){
        (*T)->left = Insert(&(*T)->left, elem);
    }
    else return *T;

    // Update Height of the ancestor node
    (*T)->height = max(height((*T)->left), height((*T)->right)) + 1;

    // Get Balance Factor of the Node to see if it's balanced
    int balance = getBalance(*T);

    // Rotation Logic and Cases
    // Left-Heavy
    if (balance > 1){
        if (getBalance((*T)->left) < 0) leftRotate(&(*T)->left);
        rightRotate(T);
    }

    // Right-Heavy
    if (balance < -1){
        if (getBalance((*T)->right) > 0) rightRotate(&(*T)->right);
        leftRotate(T);
    }

    return *T;
}

AVL Delete(AVL *T, int elem){
    // 1ST CASE: Reaching Leaf Node
    if (*T == NULL) return *T;
    // Traverse Down via Recursion
    if ((*T)->elem < elem){
        (*T)->right = Delete(&(*T)->right, elem);
    }
    else if ((*T)->elem > elem){
        (*T)->left = Delete(&(*T)->left, elem);
    }
    else{
        // one child and no child conditions
        if ((*T)->left == NULL || (*T)->right == NULL){
            // temp will be the node that is NOT NULL
            AVL temp = (*T)->left ? (*T)->left : (*T)->right;

            // if there are no children
            if (temp == NULL){
                temp = *T;
                *T = NULL;
                free(temp);
            }
            // if there was one child
            else{
                // Value-Copy Deletion
                temp = (*T)->left ? (*T)->left : (*T)->right;
                free(*T);
                *T = temp;
            }
        }
        else{
            // Both Children Exist
            AVL temp = minValueNode((*T)->right);
            (*T)->elem = temp->elem;
            (*T)->right = Delete(&(*T)->right, temp->elem);
        }
    }

    if (*T == NULL) return *T;

    // Update Height of the ancestor node
    (*T)->height = max(height((*T)->left), height((*T)->right)) + 1;

    // Get Balance Factor of the Node to see if it's balanced
    int balance = getBalance(*T);

    // Rotation Logic and Cases
    // Left-Heavy
    if (balance > 1){
        if (getBalance((*T)->left) < 0) leftRotate(&(*T)->left);
        rightRotate(T);
    }

    // Right-Heavy
    if (balance < -1){
        if (getBalance((*T)->right) > 0) rightRotate(&(*T)->right);
        leftRotate(T);
    }

    return *T;
}

AVL newNode(int elem){
    AVL node = (AVL)malloc(sizeof(ctype));

    if (node != NULL){
        node->elem = elem;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }

    return node;
}

void leftRotate(AVL *T){
    // Child of the Parent
    AVL child = (*T)->right;
    // Left Child of the Child Node
    AVL temp = child->left;

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

void rightRotate(AVL *T){
    AVL child = (*T)->left;
    AVL temp = child->right;

    child->right = *T;
    (*T)->left = temp;

    (*T)->height = max(height((*T)->left), height((*T)->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;

    *T = child;
}

AVL minValueNode(AVL T){
    if (T == NULL) return NULL;

    while (T->left != NULL){
        T = T->left;
    }

    return T;
}

int height(AVL T){
    if (T == NULL) return -1;
    return T->height;
}

int max(int left, int right){
    return (left < right) ? right : left;
}

int getBalance(AVL T){
    return height(T->left) - height(T->right);
}

// ----------------------------------------------------------------
// # Visualization Functions
// # NOTE: Taken From Gemini
// ----------------------------------------------------------------

void visualizeInorder(AVL T)
{
    if (T != NULL)
    {
        visualizeInorder(T->left);
        printf("%d ", T->elem);
        visualizeInorder(T->right);
    }
}

void visualizePreorder(AVL T, int level){
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