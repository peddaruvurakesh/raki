#include <stdio.h>
#include <stdlib.h>

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
    matrix* M = (matrix*)malloc(sizeof(matrix));
    if (!M) return NULL;

    M->rows = rows;
    M->columns = columns;

    M->rowList = (node**)calloc(rows, sizeof(node*));
    M->columnList = (node**)calloc(columns, sizeof(node*));

    if (!M->rowList || !M->columnList) {
        free(M->rowList);
        free(M->columnList);
        free(M);
        return NULL;
    }

    return M;
}

// Function to insert a node into the matrix
void insertNode(matrix* M, int row, int col, double value) {
    if (!M || row >= M->rows || col >= M->columns || value == 0) return;

    node* newNode = (node*)malloc(sizeof(node));
    newNode->row = row;
    newNode->column = col;
    newNode->value = value;
    newNode->rowPtr = NULL;
    newNode->colPtr = NULL;

    // Insert into the row list
    if (!M->rowList[row]) {
        M->rowList[row] = newNode;
    } else {
        node* temp = M->rowList[row];
        while (temp->rowPtr) temp = temp->rowPtr;
        temp->rowPtr = newNode;
    }

    // Insert into the column list
    if (!M->columnList[col]) {
        M->columnList[col] = newNode;
    } else {
        node* temp = M->columnList[col];
        while (temp->colPtr) temp = temp->colPtr;
        temp->colPtr = newNode;
    }
}

// Function to check for duplicate value in the matrix
int duplicateValue(matrix* M, double value) {
    if (!M) return 0;

    for (int i = 0; i < M->rows; ++i) {
        node* current = M->rowList[i];
        while (current) {
            if (current->value == value) return 1;
            current = current->rowPtr;
        }
    }
    return 0;
}

// Function to resize the matrix
int resize(matrix** M) {
    if (!M || !(*M)) return 1;

    matrix* oldMatrix = *M;
    int newRows = oldMatrix->rows * 2;
    int newCols = oldMatrix->columns * 2;

    matrix* newMatrix = allocateMatrix(newRows, newCols);
    if (!newMatrix) return 1;

    for (int i = 0; i < oldMatrix->rows; ++i) {
        node* current = oldMatrix->rowList[i];
        while (current) {
            insertNode(newMatrix, current->row, current->column, current->value);
            current = current->rowPtr;
        }
    }

    free(oldMatrix->rowList);
    free(oldMatrix->columnList);
    free(oldMatrix);

    *M = newMatrix;
    return 0;
}

// Function to transpose the matrix
int transpose(matrix** M) {
    if (!M || !(*M)) return 1;

    matrix* oldMatrix = *M;
    matrix* transposedMatrix = allocateMatrix(oldMatrix->columns, oldMatrix->rows);
    if (!transposedMatrix) return 1;

    for (int i = 0; i < oldMatrix->rows; ++i) {
        node* current = oldMatrix->rowList[i];
        while (current) {
            insertNode(transposedMatrix, current->column, current->row, current->value);
            current = current->rowPtr;
        }
    }

    free(oldMatrix->rowList);
    free(oldMatrix->columnList);
    free(oldMatrix);

    *M = transposedMatrix;
    return 0;
}

// Function to print the matrix
void printMatrix(matrix* M) {
    if (!M) return;

    for (int i = 0; i < M->rows; ++i) {
        node* current = M->rowList[i];
        for (int j = 0; j < M->columns; ++j) {
            if (current && current->column == j) {
                printf("%.2f ", current->value);
                current = current->rowPtr;
            } else {
                printf("0.00 ");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    matrix* M = NULL;
    int rows, columns, choice;
    double value;
    int row, col;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &columns);

    M = allocateMatrix(rows, columns);

    do {
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
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        printf("Enter (%d,%d) value: ", i, j);
                        scanf("%lf", &value);
                        insertNode(M, i, j, value);
                    }
                }
                break;

            case 2:
                printMatrix(M);
                break;

            case 3:
                printf("Enter value to check: ");
                scanf("%lf", &value);
                if (duplicateValue(M, value)) {
                    printf("Found\n");
                } else {
                    printf("Not found\n");
                }
                break;

            case 4:
                transpose(&M);
                printf("Transposed successfully.\n");
                break;

            case 5:
                if (!resize(&M)) {
                    printf("Resized successfully.\n");
                } else {
                    printf("Resize failed.\n");
                }
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 6);

    free(M->rowList);
    free(M->columnList);
    free(M);
    return 0;
}
