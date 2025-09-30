#include <stdio.h>

int main() {
    int rows, cols, i, j;

    // Read rows and columns
    scanf("%d %d", &rows, &cols);

    int arr[rows][cols];

    // Read array elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Print column-major order
    for (j = 0; j < cols; j++) {
        for (i = 0; i < rows; i++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
