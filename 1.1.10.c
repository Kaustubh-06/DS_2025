#include <stdio.h>

int main() {
    int n, key;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;  // stop at the first occurrence
        }
    }

    if (found != -1) {
        printf("%d\n", found);
    } else {
        printf("Not found\n");
    }

    return 0;
}
