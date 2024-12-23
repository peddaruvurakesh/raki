#include <stdio.h>
#include <stdlib.h>

// Function to get the cofactor matrix by excluding row p and column q
void getCofactor(int *matrix, int *temp, int p, int q, int n) {
    int i = 0, j = 0;
    
    // Iterate over every element in the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            
            // Copy the element into the cofactor matrix `temp` only if
            // it's not in the row `p` and column `q`
            if (row != p && col != q) {
                temp[i * (n - 1) + j++] = matrix[row * n + col]; // Add element to cofactor matrix
                
                // Once the column is full, move to the next row
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Recursive function to calculate the determinant of the matrix
int determinant(int *matrix, int n) {
    // Base case for a 1x1 matrix, the determinant is just the value of the single element
    if (n == 1)
        return matrix[0];

    int det = 0;  // Variable to store the determinant
    int sign = 1; // Sign multiplier, alternating between +1 and -1
    int *temp = (int *)calloc((n - 1) * (n - 1), sizeof(int)); // Allocate memory for cofactor matrix

    // Loop through the first row elements of the matrix
    for (int f = 0; f < n; f++) {
        // Get the cofactor matrix by excluding row 0 and column `f`
        getCofactor(matrix, temp, 0, f, n);
        
        // Calculate the determinant recursively and sum up
        det += sign * matrix[f] * determinant(temp, n - 1);
        
        // Alternate the sign for the next term in the expansion
        sign = -sign;
    }

    // Free the allocated memory for the temporary cofactor matrix
    free(temp);
    
    // Return the computed determinant
    return det;
}

int main() {
    int n;
    
    // Ask the user to input the size of the matrix (n x n)
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Allocate memory for the matrix dynamically as a 1D array
    // For an n x n matrix, we need space for n * n elements
    int *matrix = (int *)calloc(n * n, sizeof(int));

    // Ask the user to input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &matrix[i]);
    }

    // Call the determinant function to compute the determinant of the matrix
    int det = determinant(matrix, n);
    
    // Print the calculated determinant
    printf("Determinant of the matrix is: %d\n", det);

    // Free the dynamically allocated memory for the matrix
    free(matrix);
    
    return 0;
}

