#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("-1");
        return 0;
    }

    int ch = getchar();
    while (ch != '\n' && ch != EOF) ch = getchar();

    // read second line
    char line[100000];
    if (!fgets(line, sizeof(line), stdin)) {
        printf("-1");
        return 0;
    }

    int arr[1003], count = 0;
    char *token = strtok(line, " \t\r\n");

    while (token != NULL) {
        char *endptr;
        long val = strtol(token, &endptr, 10);
        if (*endptr != '\0') { // invalid integer
            printf("-1");
            return 0;
        }
        arr[count++] = (int)val;
        token = strtok(NULL, " \t\r\n");
    }

    if (count != n) {
        printf("-1");
        return 0;
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }

    return 0;
}
