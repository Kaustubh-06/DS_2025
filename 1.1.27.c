#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Detect loop using Floyd’s cycle-finding algorithm
bool hasLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}

int main() {
    int N;
    scanf("%d", &N);

    int value;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* nodes[N]; // store references to nodes

    // Build linked list
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        nodes[i] = newNode; // keep reference
    }

    int X;
    scanf("%d", &X);

    // Connect tail to X-th node if X != 0
    if (X != 0) {
        tail->next = nodes[X - 1]; // position starts from 1
    }

    // Check for loop
    if (hasLoop(head)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
