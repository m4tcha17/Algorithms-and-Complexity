#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* new_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* merge(Node* left, Node* right) {
    Node* result = NULL;
    Node** tail = &result;        // ppn — tail points to the pointer we want to write into

    while (left && right) {
        if (left->data <= right->data) {
            *tail = left;         // write left node into wherever tail is pointing
            left = left->next;    // advance left
        } else {
            *tail = right;        // write right node into wherever tail is pointing
            right = right->next;  // advance right
        }
        tail = &(*tail)->next;    // advance tail to point to the next pointer slot
    }

    *tail = left ? left : right;  // attach remaining nodes
    return result;                // return head of merged list
}

Node* split(Node* head, int size) {
    for (int i = 1; i < size && head->next; i++)
        head = head->next;        // walk forward size-1 steps

    Node* second = head->next;    // second is the start of the right chunk
    head->next = NULL;            // sever the chain — left chunk ends with NULL
    return second;                // return head of right chunk
}

void merge_sort(Node** ptr) {    // ppn — takes address of head so we can change it directly
    if (!*ptr || !(*ptr)->next) return;  // empty or single node list is already sorted

    int length = 0;
    Node* curr = *ptr;
    while (curr) { length++; curr = curr->next; }  // count total nodes

    for (int size = 1; size < length; size *= 2) {  // outer loop — doubles merge size each pass
        Node** prev = ptr;       // ppn — prev points to head pointer itself at start of each pass
        curr = *ptr;             // curr starts at first node

        while (curr) {
            Node* left  = curr;              // left chunk starts at curr
            Node* right = split(left, size); // sever left chunk, right is what comes after

            if (!right) {
                *prev = left;      // no right chunk — attach left remainder and stop
                break;
            }

            curr = split(right, size);  // sever right chunk, curr is next unmerged portion
            *prev = merge(left, right); // merge and write result directly into prev slot

            while (*prev) prev = &(*prev)->next;  // advance prev to end of merged chunk
        }   
    }
}

void print_list(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

int main() {
    Node* head = new_node(5);
    head->next = new_node(3);
    head->next->next = new_node(8);
    head->next->next->next = new_node(1);
    head->next->next->next->next = new_node(9);
    head->next->next->next->next->next = new_node(2);
    head->next->next->next->next->next->next = new_node(7);
    head->next->next->next->next->next->next->next = new_node(4);

    printf("Before: "); print_list(head);
    merge_sort(&head);   // pass address of head — no return value needed
    printf("After:  "); print_list(head);

    return 0;
}
// Before: 5 -> 3 -> 8 -> 1 -> 9 -> 2 -> 7 -> 4 -> NULL
// After:  1 -> 2 -> 3 -> 4 -> 5 -> 7 -> 8 -> 9 -> NULL