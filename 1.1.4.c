#include <stdio.h>

int main() {
    int n, i, isSorted = 1;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if array is sorted in ascending order
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = 0;
            break;
        }
    }

    // Print result
    if (isSorted) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
