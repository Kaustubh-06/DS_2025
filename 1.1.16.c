#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("-1");
        return 0;
    }

    // consume rest of line
    int ch = getchar();
    while (ch != '\n' && ch != EOF) ch = getchar();

    char line[100000];
    if (!fgets(line, sizeof(line), stdin)) {
        printf("-1");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    int count = 0;

    char *token = strtok(line, " \t\r\n");
    while (token != NULL) {
        char *endptr;
        long val = strtol(token, &endptr, 10);
        if (*endptr != '\0') { // invalid input
            printf("-1");
            free(arr);
            return 0;
        }
        arr[count++] = (int)val;
        token = strtok(NULL, " \t\r\n");
    }

    if (count != n) {
        printf("-1");
        free(arr);
        return 0;
    }

    // ---- Counting Sort ----
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int *countArr = (int *)calloc(range, sizeof(int));

    // Count frequency
    for (int i = 0; i < n; i++) {
        countArr[arr[i] - min]++;
    }

    // Output sorted array
    int printed = 0;
    for (int i = 0; i < range; i++) {
        while (countArr[i] > 0) {
            if (printed) printf(" ");
            printf("%d", i + min);
            printed = 1;
            countArr[i]--;
        }
    }

    free(arr);
    free(countArr);
    return 0;
}
