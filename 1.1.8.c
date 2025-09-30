#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int zeroCount = 0, nonZeroCount = 0;

    // Read number of rows and columns
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    // Read matrix elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                zeroCount++;
            else
                nonZeroCount++;
        }
    }

    // Check if sparse
    if (zeroCount > nonZeroCount) {
        printf("True\n");
        // Print non-zero elements
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    printf("%d %d %d\n", i, j, matrix[i][j]);
                }
            }
        }
    } else {
        printf("False\n");
    }

    return 0;
}
