#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("-1");
        return 0;
    }

    // consume rest of line after n
    int ch = getchar();
    while (ch != '\n' && ch != EOF) ch = getchar();

    // read next line containing array elements
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

    // check if the number of inputs matches n
    if (count != n) {
        printf("-1");
        return 0;
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Print sorted array (space separated, no trailing space)
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }

    return 0;
}
