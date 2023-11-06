#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next_row;
    struct Node* next_col;
} Node;

typedef struct SparseMatrix {
    int rows;
    int cols;
    Node** row_heads;
    Node** col_heads;
} SparseMatrix;

SparseMatrix* createSparseMatrix(int rows, int cols) {
    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    
    matrix->row_heads = (Node**)calloc(rows, sizeof(Node*));
    matrix->col_heads = (Node**)calloc(cols, sizeof(Node*));
    
    return matrix;
}

void insert(SparseMatrix* matrix, int row, int col, int value) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid row or column index\n");
        return;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->value = value;
    new_node->next_row = NULL;
    new_node->next_col = NULL;
    
    // Insert into row list
    if (!matrix->row_heads[row] || matrix->row_heads[row]->col > col) {
        new_node->next_row = matrix->row_heads[row];
        matrix->row_heads[row] = new_node;
    } else {
        Node* curr = matrix->row_heads[row];
        while (curr->next_row && curr->next_row->col <= col) {
            curr = curr->next_row;
        }
        new_node->next_row = curr->next_row;
        curr->next_row = new_node;
    }
    
    // Insert into column list
    if (!matrix->col_heads[col] || matrix->col_heads[col]->row > row) {
        new_node->next_col = matrix->col_heads[col];
        matrix->col_heads[col] = new_node;
    } else {
        Node* curr = matrix->col_heads[col];
        while (curr->next_col && curr->next_col->row <= row) {
            curr = curr->next_col;
        }
        new_node->next_col = curr->next_col;
        curr->next_col = new_node;
    }
}

int display(SparseMatrix* matrix, int row, int col) {
    Node* curr = matrix->row_heads[row];
    while (curr) {
        if (curr->col == col) {
            return curr->value;
        }
        curr = curr->next_row;
    }
    return 0; 
}

int main() {
    int n,m,i,j,t;
    printf("Enter the no. of rows in matrix");
    scanf("%d",&n);
     printf("Enter the no. of columns in matrix");
    scanf("%d",&m);
    SparseMatrix* matrix = createSparseMatrix(n,m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("Enter the data for M%d%d",i,j);
            scanf("%d",&t);
            insert(matrix, i, j, t);
        }
        
         printf("%d\n", display(matrix,i,j));  
    }
   
    return 0;
}
