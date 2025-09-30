#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to insert at end of DCLL
void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node *last = (*head)->prev;

    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

// Function to delete last element
void deleteLast(struct Node **head) {
    if (*head == NULL) return;

    struct Node *last = (*head)->prev;

    // only one node
    if (last == *head) {
        free(last);
        *head = NULL;
        return;
    }

    struct Node *secondLast = last->prev;
    secondLast->next = *head;
    (*head)->prev = secondLast;
    free(last);
}

// Function to traverse and print
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
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &val);
            insert(&head, val);
        } else if (op == 2) {
            deleteLast(&head);
        }
    }

    traverse(head);

    if (head != NULL) {
        struct Node *curr = head->next, *nextNode;
        while (curr != head) {
            nextNode = curr->next;
            free(curr);
            curr = nextNode;
        }
        free(head);
    }

    return 0;
}
