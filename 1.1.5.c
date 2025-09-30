#include <stdio.h>

int main() {
    int n, i, search, count = 0;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read element to search
    scanf("%d", &search);

    // Count occurrences
    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            count++;
        }
    }

    // Print result
    printf("%d\n", count);

    return 0;
}
