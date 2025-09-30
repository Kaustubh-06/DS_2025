#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
struct Element {
    int value;
    int index;
};

// Comparison function for qsort
int cmp(const void* a, const void* b) {
    struct Element* x = (struct Element*)a;
    struct Element* y = (struct Element*)b;
    return x->value - y->value;
}

// Binary search to find first occurrence
int binarySearch(struct Element arr[], int n, int key) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].value == key) {
            result = arr[mid].index; // store original index
            high = mid - 1;          // move left to find first occurrence
        } else if (arr[mid].value < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Element arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i; // store original index
    }

    int key;
    scanf("%d", &key);

    // Sort array based on value
    qsort(arr, n, sizeof(struct Element), cmp);

    int res = binarySearch(arr, n, key);

    if (res != -1)
        printf("%d\n", res);
    else
        printf("Not found\n");

    return 0;
}
