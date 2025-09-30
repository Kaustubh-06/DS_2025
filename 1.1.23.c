#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to reverse the doubly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    // Swap next and prev for each node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // move to "previous" (since swapped)
    }

    // New head is the last non-null node
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) return 0;

    int value;
    scanf("%d", &value);
    struct Node* head = createNode(value);
    struct Node* tail = head;

    // Build list
    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    head = reverseList(head);

    // Print reversed list
    printList(head);

    return 0;
}
