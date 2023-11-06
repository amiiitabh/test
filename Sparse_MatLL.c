#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

// Sparse Matrix structure
typedef struct SparseMatrix {
    int rows;
    int cols;
    Node** rows_heads; // Array of row heads
} SparseMatrix;

// Function to create a new Node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new SparseMatrix
SparseMatrix* createSparseMatrix(int rows, int cols) {
    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->rows_heads = (Node**)malloc(rows * sizeof(Node*));
    for (int i = 0; i < rows; i++) {
        matrix->rows_heads[i] = NULL;
    }
    return matrix;
}

// Function to insert a value into the SparseMatrix
void insertValue(SparseMatrix* matrix, int row, int col, int value) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid indices.\n");
        return;
    }

    Node* newNode = createNode(row, col, value);

    if (matrix->rows_heads[row] == NULL || col < matrix->rows_heads[row]->col) {
        newNode->next = matrix->rows_heads[row];
        matrix->rows_heads[row] = newNode;
    } else {
        Node* current = matrix->rows_heads[row];
        while (current->next && col > current->next->col) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to retrieve a value from the SparseMatrix
int getValue(SparseMatrix* matrix, int row, int col) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid indices.\n");
        return 0; // Return a default value or handle error
    }

    Node* current = matrix->rows_heads[row];
    while (current && current->col <= col) {
        if (current->col == col) {
            return current->value;
        }
        current = current->next;
    }
    return 0; // Default value for sparse matrix element not present
}

// Function to free the SparseMatrix and its Nodes
void freeSparseMatrix(SparseMatrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        Node* current = matrix->rows_heads[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(matrix->rows_heads);
    free(matrix);
}

int main() {
    int rows = 4;
    int cols = 5;
    SparseMatrix* matrix = createSparseMatrix(rows, cols);

    insertValue(matrix, 0, 1, 5);
    insertValue(matrix, 1, 2, 7);
    insertValue(matrix, 2, 3, 9);
    insertValue(matrix, 3, 4, 3);

    printf("Value at (2, 3): %d\n", getValue(matrix, 2, 3)); // Output: Value at (2, 3): 9
    printf("Value at (1, 4): %d\n", getValue(matrix, 1, 4)); // Output: Value at (1, 4): 0 (default)

    freeSparseMatrix(matrix);

    return 0;
}
