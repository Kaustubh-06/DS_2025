#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int stack[MAX];
    int top = -1; // empty stack
    int op, value;

    int peek_outputs[MAX];
    int peek_count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &op);

        if (op == 1) {
            // Push operation
            scanf("%d", &value);
            if (top < MAX - 1) {
                top++;
                stack[top] = value;
            }
        } else if (op == 2) {
            // Pop operation
            if (top >= 0) {
                top--;
            }
        } else if (op == 3) {
            // Peek operation
            if (top >= 0) {
                peek_outputs[peek_count++] = stack[top];
            }
        }
    }

    // Print all peek outputs
    for (int i = 0; i < peek_count; i++) {
        printf("%d\n", peek_outputs[i]);
    }

    if (top < 0) {
        printf("Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d", stack[i]);
            if (i > 0) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
