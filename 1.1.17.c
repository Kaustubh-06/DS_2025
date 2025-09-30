#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to insert at the end
void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete first occurrence of a value
void deleteNode(struct Node **head, int value) {
    if (*head == NULL) return;

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If head node is to be deleted
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to traverse and print
void traverse(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);  // Print number + space
        temp = temp->next;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

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
