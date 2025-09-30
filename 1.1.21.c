#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse the linked list in place
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // new head
}

// Function to print the linked list (with trailing space)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);  // always print space after number
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        return 0; // nothing to print
    }

    int value;
    scanf("%d", &value);

    // Create the linked list
    struct Node* head = createNode(value);
    struct Node* curr = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        curr->next = createNode(value);
        curr = curr->next;
    }

    // Reverse the linked list
    head = reverseList(head);

    // Print reversed linked list
    printList(head);

    return 0;
}
