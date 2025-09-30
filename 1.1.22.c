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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Reverse a linked list
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
    return prev;
}

// Check palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Find middle using slow & fast
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct Node* secondHalf = reverseList(slow->next);

    // Compare both halves
    struct Node* firstHalf = head;
    struct Node* temp = secondHalf;
    bool palindrome = true;

    while (temp != NULL) {
        if (firstHalf->data != temp->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // (Optional) Restore list
    slow->next = reverseList(secondHalf);

    return palindrome;
}

int main() {
    int t;
    scanf("%d", &t);

    char results[t][6]; // store "true"/"false"

    for (int i = 0; i < t; i++) {
        int value;
        struct Node* head = NULL;
        struct Node* tail = NULL;

        while (1) {
            scanf("%d", &value);
            if (value == -1) break;

            struct Node* newNode = createNode(value);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        if (isPalindrome(head)) {
            sprintf(results[i], "true");
        } else {
            sprintf(results[i], "false");
        }
    }

    // Print results at once
    for (int i = 0; i < t; i++) {
        printf("%s\n", results[i]);
    }

    return 0;
}
