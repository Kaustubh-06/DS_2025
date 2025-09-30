#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    int zeroCount = 0, nonZeroCount = 0;
    int totalElements = rows * cols;

    // Read the matrix and count zeros & non-zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                zeroCount++;
            else
                nonZeroCount++;
        }
    }

    // Check sparse condition: more than half elements are zeros
    if (zeroCount > nonZeroCount && nonZeroCount > 0) {
        // Print triplet form for non-zero elements
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    printf("%d %d %d\n", i, j, matrix[i][j]); // 0-based index
                }
            }
        }
    } else {
        printf("-1\n");
    }

    return 0;
}
