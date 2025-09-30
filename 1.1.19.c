#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to insert at the end of circular linked list
void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // point to itself
        return;
    }

    struct Node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete first occurrence of a value
void deleteNode(struct Node **head, int value) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev = NULL;

    // Case 1: head itself has the value
    if (curr->data == value) {
        // only one node in the list
        if (curr->next == *head) {
            free(curr);
            *head = NULL;
            return;
        }

        // move to last node
        struct Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        last->next = curr->next;
        *head = curr->next;
        free(curr);
        return;
    }

    // Case 2: search in the list
    prev = curr;
    curr = curr->next;
    while (curr != *head) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    // if not found, do nothing
}

// Function to traverse and print with trailing space
void traverse(struct Node *head) {
    if (head == NULL) return;

    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL;

    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d %d", &op, &val);

        if (op == 1) {
            insert(&head, val);
        } else if (op == 2) {
            deleteNode(&head, val);
        }
    }

    traverse(head);

    // Free allocated memory
    if (head != NULL) {
        struct Node *temp = head->next, *nextNode;
        while (temp != head) {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
        free(head);
    }

    return 0;
}
