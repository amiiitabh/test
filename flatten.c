#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* right;
    struct Node* down;
};

struct Node* head = NULL;

struct Node* merge(struct Node* a, struct Node* b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    struct Node* result;
    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    } else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}


struct Node* flatten(struct Node* root) {
    if (root == NULL || root->right == NULL)
        return root;
    
    root->right = flatten(root->right);
    root = merge(root, root->right);
    return root;
}

struct Node* push(struct Node* head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->right = NULL;
    new_node->down = head_ref;
    head_ref = new_node;
    return head_ref;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->down;
    }
    printf("\n");
}

int main() {
    
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);

    head->right = push(head->right, 20);
    head->right = push(head->right, 10);

    head->right->right = push(head->right->right, 50);
    head->right->right = push(head->right->right, 22);
    head->right->right = push(head->right->right, 19);

    head->right->right->right = push(head->right->right->right, 45);
    head->right->right->right = push(head->right->right->right, 40);
    head->right->right->right = push(head->right->right->right, 35);
    head->right->right->right = push(head->right->right->right, 20);

    head = flatten(head);

    printList(head);

    // Free 
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->down;
        free(temp);
    }

    return 0;
}
