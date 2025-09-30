#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Push
void push(struct Stack* s, int value) {
    s->arr[++(s->top)] = value;
}

// Pop
int pop(struct Stack* s) {
    if (s->top == -1) return -1;
    return s->arr[(s->top)--];
}

// Insert element at bottom using recursion
void insertAtBottom(struct Stack* s, int value) {
    if (s->top == -1) {
        push(s, value);
        return;
    }
    int temp = pop(s);
    insertAtBottom(s, value);
    push(s, temp);
}

// Reverse stack using recursion
void reverseStack(struct Stack* s) {
    if (s->top == -1) return;
    int temp = pop(s);
    reverseStack(s);
    insertAtBottom(s, temp);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Stack s;
    s.top = -1;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(&s, value);
    }

    // Reverse the stack
    reverseStack(&s);

    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.arr[i]);
        if (i < s.top) printf(" ");
    }
    printf("\n");

    return 0;
}
