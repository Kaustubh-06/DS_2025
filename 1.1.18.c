#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert at the end
void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete first occurrence of a value
void deleteNode(struct Node **head, int value) {
    if (*head == NULL) return;

    struct Node *temp = *head;

    // Search for node
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If not found
    if (temp == NULL) return;

    // If node to be deleted is head
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Middle or last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to traverse and print
void traverse(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); // Always print with a trailing space
        temp = temp->next;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL;

    for (int i = 0; i < n; i++) {
        int op, value;
        scanf("%d %d", &op, &value);

        if (op == 1) {
            insert(&head, value);
        } else if (op == 2) {
            deleteNode(&head, value);
        }
    }

    traverse(head);

    // Free memory
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
