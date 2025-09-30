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

    // read the second line (expected to contain exactly n integers)
    // large buffer to safely hold up to 1000 numbers
    char line[100000];
    if (!fgets(line, sizeof(line), stdin)) {
        printf("-1");
        return 0;
    }
    // if the line is empty (just newline), try to read next non-empty line
    while ((line[0] == '\n' || line[0] == '\r') && fgets(line, sizeof(line), stdin));

    int arr[1003];
    int count = 0;
    char *token = strtok(line, " \t\r\n");

    while (token != NULL) {
        char *endptr;
        long val = strtol(token, &endptr, 10);
        if (*endptr != '\0') { // invalid integer token
            printf("-1");
            return 0;
        }
        if (count >= 1003) { // safety, although n <= 1000 by constraints
            printf("-1");
            return 0;
        }
        arr[count++] = (int)val;
        token = strtok(NULL, " \t\r\n");
    }

    // If the number of integers on the second line is not exactly n -> -1
    if (count != n) {
        printf("-1");
        return 0;
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        if (minIndex != i) {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }

    // Print sorted array with single spaces, no trailing space/newline
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }

    return 0;
}
