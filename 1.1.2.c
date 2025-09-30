#include <stdio.h>

int main() {
    int n, i, sum = 0;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array in [a, b, c] format
    printf("[");
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", arr[i]);  // last element without comma
        } else {
            printf("%d, ", arr[i]);
        }
    }
    printf("]\n");

    // Calculate sum
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Print sum of elements
    printf("%d\n", sum);

    return 0;
}
