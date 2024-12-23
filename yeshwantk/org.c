#include <stdio.h>
#include <stdlib.h>

void getCofactor(int **matrix, int **temp, int p, int q, int n) {
    int i = 0, j = 0;
    // Loop through all the elements of the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copy into temp matrix only those elements
            // which are not in the current row and column
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                // Row is filled, so increase row index and reset column index
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(int **matrix, int n) {
    // Base case: If the matrix is a single element
    if (n == 1)
        return matrix[0][0];

    int det = 0; // Initialize determinant
    int **temp;  // To store cofactors

    // Allocate memory for temp matrix dynamically
    temp = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
#include <stdio.h>
#include <stdlib.h>

void getCofactor(int **matrix, int **temp, int p, int q, int n) {
    int i = 0, j = 0;
    // Loop through all the elements of the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copy into temp matrix only those elements
            // which are not in the current row and column
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                // Row is filled, so increase row index and reset column index
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(int **matrix, int n) {
    // Base case: If the matrix is a single element
    if (n == 1)
        return matrix[0][0];

    int det = 0; // Initialize determinant
    int **temp;  // To store cofactors

    // Allocate memory for temp matrix dynamically
    temp = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        temp[i] = (int *)calloc(n, sizeof(int));

    int sign = 1; // To store sign multiplier

    // Loop through each element of the first row
    for (int f = 0; f < n; f++) {
        // Get cofactor of matrix[0][f]
        getCofactor(matrix, temp, 0, f, n);
        // Recursive call to calculate determinant of the submatrix
        det += sign * matrix[0][f] * determinantOfMatrix(temp, n - 1);
        // Alternate the sign for the next element
        sign = -sign;
    }

    // Free allocated memory for temp matrix
    for (int i = 0; i < n; i++)
        free(temp[i]);
    free(temp);

    return det;
}

int main() {
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)calloc(n, sizeof(int));

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and print the determinant
    int det = determinantOfMatrix(matrix, n);
    printf("Determinant of the matrix is: %d\n", det);

    // Free allocated memory for the matrix
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
        temp[i] = (int *)calloc(n, sizeof(int));

    int sign = 1; // To store sign multiplier

    // Loop through each element of the first row
    for (int f = 0; f < n; f++) {
        // Get cofactor of matrix[0][f]
        getCofactor(matrix, temp, 0, f, n);
        // Recursive call to calculate determinant of the submatrix
        det += sign * matrix[0][f] * determinantOfMatrix(temp, n - 1);
        // Alternate the sign for the next element
        sign = -sign;
    }

    // Free allocated memory for temp matrix
    for (int i = 0; i < n; i++)
        free(temp[i]);
    free(temp);

    return det;
}

int main() {
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)calloc(n, sizeof(int));

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and print the determinant
    int det = determinantOfMatrix(matrix, n);
    printf("Determinant of the matrix is: %d\n", det);

    // Free allocated memory for the matrix
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}

