#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to find middle node (second middle in even case)
int findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // move by 1
        fast = fast->next->next;   // move by 2
    }
    return slow->data;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int value;
    scanf("%d", &value);
    struct Node* head = createNode(value);
    struct Node* curr = head;

    // Build linked list
    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        curr->next = createNode(value);
        curr = curr->next;
    }

    printf("%d\n", findMiddle(head));

    return 0;
}
 