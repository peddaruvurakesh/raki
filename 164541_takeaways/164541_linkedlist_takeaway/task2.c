#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
typedef struct Node {
    int row, column;    // Row and column indices
    double value;       // Value at this position
    struct Node *rowPtr, *colPtr; // Pointers to the next nodes in row and column
} node;

// Matrix structure
typedef struct Matrix {
    int rows, columns;  // Dimensions of the matrix
    node **rowList;     // Array of row headers
    node **columnList;  // Array of column headers
} matrix;

// Function to allocate a sparse matrix
matrix* allocateMatrix(int rows, int columns) {
    // Step 1: Allocate memory for the matrix structure
    matrix* M = (matrix*)malloc(sizeof(matrix));
    if (!M) return NULL; // If memory allocation fails, return NULL

    // Step 2: Assign rows and columns to the matrix
    M->rows = rows;
    M->columns = columns;

    // Step 3: Allocate arrays for row and column headers, initialized to NULL
    M->rowList = (node**)calloc(rows, sizeof(node*));
    M->columnList = (node**)calloc(columns, sizeof(node*));

    // Step 4: Check for memory allocation errors and clean up if necessary
    if (!M->rowList || !M->columnList) {
        free(M->rowList);
        free(M->columnList);
        free(M);
        return NULL;
    }

    // Step 5: Return the allocated matrix
    return M;
}

// Function to insert a node into the matrix
void insertNode(matrix* M, int row, int col, double value) {
    if (!M || row >= M->rows || col >= M->columns || value == 0) return;

    // Step 1: Create a new node with the given row, column, and value
    node* newNode = (node*)malloc(sizeof(node));
    newNode->row = row;
    newNode->column = col;
    newNode->value = value;
    newNode->rowPtr = NULL;
    newNode->colPtr = NULL;

    // Step 2: Insert the node into the row list
    if (!M->rowList[row]) {
        M->rowList[row] = newNode; // If row is empty, set the node as the first element
    } else {
        node* temp = M->rowList[row];
        while (temp->rowPtr) temp = temp->rowPtr; // Traverse to the end of the row
        temp->rowPtr = newNode; // Insert the new node at the end
    }

    // Step 3: Insert the node into the column list
    if (!M->columnList[col]) {
        M->columnList[col] = newNode; // If column is empty, set the node as the first element
    } else {
        node* temp = M->columnList[col];
        while (temp->colPtr) temp = temp->colPtr; // Traverse to the end of the column
        temp->colPtr = newNode; // Insert the new node at the end
    }
}

// Function to check for duplicate value in the matrix
int duplicateValue(matrix* M, double value) {
    if (!M) return 0;

    // Step 1: Loop through each row
    for (int i = 0; i < M->rows; ++i) {
        node* current = M->rowList[i];
        // Step 2: Traverse each node in the current row
        while (current) {
            if (current->value == value) return 1; // If value is found, return 1
            current = current->rowPtr; // Move to the next node in the row
        }
    }
    return 0; // Return 0 if the value is not found
}

// Function to resize the matrix
int resize(matrix** M) {
    if (!M || !(*M)) return 1;

    // Step 1: Store old matrix and calculate new dimensions
    matrix* oldMatrix = *M;
    int newRows = oldMatrix->rows * 2;
    int newCols = oldMatrix->columns * 2;

    // Step 2: Allocate a new matrix with updated dimensions
    matrix* newMatrix = allocateMatrix(newRows, newCols);
    if (!newMatrix) return 1;

    // Step 3: Copy all nodes from the old matrix to the new matrix
    for (int i = 0; i < oldMatrix->rows; ++i) {
        node* current = oldMatrix->rowList[i];
        while (current) {
            insertNode(newMatrix, current->row, current->column, current->value);
            current = current->rowPtr;
        }
    }

    // Step 4: Free memory of the old matrix
    free(oldMatrix->rowList);
    free(oldMatrix->columnList);
    free(oldMatrix);

    // Step 5: Update the matrix pointer to point to the new matrix
    *M = newMatrix;
    return 0;
}

// Function to transpose the matrix
int transpose(matrix** M) {
    if (!M || !(*M)) return 1;

    // Step 1: Store old matrix and allocate a new matrix with swapped dimensions
    matrix* oldMatrix = *M;
    matrix* transposedMatrix = allocateMatrix(oldMatrix->columns, oldMatrix->rows);
    if (!transposedMatrix) return 1;

    // Step 2: Loop through each node in the old matrix and insert it transposed into the new matrix
    for (int i = 0; i < oldMatrix->rows; ++i) {
        node* current = oldMatrix->rowList[i];
        while (current) {
            insertNode(transposedMatrix, current->column, current->row, current->value);
            current = current->rowPtr;
        }
    }

    // Step 3: Free memory of the old matrix
    free(oldMatrix->rowList);
    free(oldMatrix->columnList);
    free(oldMatrix);

    // Step 4: Update the matrix pointer to point to the transposed matrix
    *M = transposedMatrix;
    return 0;
}

// Function to print the matrix
void printMatrix(matrix* M) {
    if (!M) return;

    // Step 1: Loop through each row
    for (int i = 0; i < M->rows; ++i) {
        node* current = M->rowList[i];
        // Step 2: Loop through each column in the current row
        for (int j = 0; j < M->columns; ++j) {
            if (current && current->column == j) {
                printf("%.2f ", current->value); // Print the node value if it exists
                current = current->rowPtr;
            } else {
                printf("0.00 "); // Print 0 for empty positions
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    matrix* M = NULL;
    int rows, columns;
    int choice;
    double value;
    int row, col;

    // Step 1: Input rows and columns from the user
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &columns);

    // Step 2: Allocate memory for the matrix
    M = allocateMatrix(rows, columns);

    do {
        // Step 3: Display menu and get user's choice
        printf("\nOptions:\n");
        printf("1. CreateMatrix.\n");
        printf("2. PrintMatrix.\n");
        printf("3. DuplicateValue.\n");
        printf("4. Transpose.\n");
        printf("5. Resize.\n");
        printf("6. Exit.\n");
        printf("Choose your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Step 4: Input values for the matrix
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        printf("Enter (%d,%d) value: ", i, j);
                        scanf("%lf", &value);
                        insertNode(M, i, j, value);
                    }
                }
                break;

            case 2:
                // Step 5: Print the matrix
                printMatrix(M);
                break;

            case 3:
                // Step 6: Check for duplicate value
                printf("Enter value to check: ");
                scanf("%lf", &value);
                if (duplicateValue(M, value)) {
                    printf("Found\n");
                } else {
                    printf("Not found\n");
                }
                break;

            case 4:
                // Step 7: Transpose the matrix
                transpose(&M);
                printf("Transposed successfully.\n");
                break;

            case 5:
                // Step 8: Resize the matrix
                if (!resize(&M)) {
                    printf("Resized successfully.\n");
                } else {
                    printf("Resize failed.\n");
                }
                break;

            case 6:
                // Step 9: Exit the program
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    // Step 10: Free memory of the matrix
    free(M->rowList

