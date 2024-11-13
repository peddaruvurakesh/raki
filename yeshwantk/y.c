#include <stdio.h>
#include <stdlib.h>

// Function to calculate the determinant of a matrix
double determinant(double **matrix, int n) {
    // Base case for 1x1 matrix
    if (n == 1) {
        return matrix[0][0];
    }

    // Base case for 2x2 matrix
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;
    double **subMatrix = (double **)calloc(n, sizeof(double *));
    for (int i = 0; i < n; i++) {
        subMatrix[i] = (double *)calloc(n, sizeof(double));
    }

    // Recursive case
    for (int x = 0; x < n; x++) {
        // Create submatrix
        int subi = 0; // Submatrix row index
        for (int i = 1; i < n; i++) {
            int subj = 0; // Submatrix column index
            for (int j = 0; j < n; j++) {
                if (j == x) {
                    continue; // Skip the column for the current element
                }
                subMatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        // Calculate the determinant using the formula
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(subMatrix, n - 1);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(subMatrix[i]);
    }
    free(subMatrix);

    return det;
}

// Function to input the matrix
double **inputMatrix(int n) {
    double **matrix = (double **)calloc(n, sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)calloc(n, sizeof(double));
    }

    printf("Enter the elements of the matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}

// Function to free allocated memory for the matrix
void freeMatrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n;

    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);

    double **matrix = inputMatrix(n);
    double det = determinant(matrix, n);

    printf("The determinant of the matrix is: %.2lf\n", det);

    freeMatrix(matrix, n);
    return 0;
}

