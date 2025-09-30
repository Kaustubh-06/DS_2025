#include <stdio.h>

int main() {
    int n, i;

    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print reversed array in [a, b, c] format
    printf("[");
    for (i = n - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%d", arr[i]);  // last element (no comma)
        } else {
            printf("%d, ", arr[i]);
        }
    }
    printf("]\n");

    return 0;
}
