#include <stdio.h>

int main() {
    int n, i, max;

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

    // Find maximum element
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Print maximum element
    printf("%d\n", max);

    return 0;
}
