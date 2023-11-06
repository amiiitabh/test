#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* Temp;
};

struct Node* cloneLinkedList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* mp[10000] = {NULL};
    struct Node* temp = head;
    struct Node* nhead = NULL;
    struct Node* ntemp = NULL;
    nhead = (struct Node*)malloc(sizeof(struct Node));
    nhead->val = temp->val;
    nhead->next = NULL;
    nhead->Temp = NULL;
    mp[temp->val] = nhead;
    

    while (temp->next != NULL) {
        ntemp = (struct Node*)malloc(sizeof(struct Node));
        ntemp->val = temp->next->val;
        ntemp->next = NULL;
        ntemp->Temp = NULL;
        temp = temp->next;
        nhead->next = ntemp;
        nhead = ntemp;
        mp[temp->val] = ntemp;
    }
    
    temp = head;
    nhead = mp[temp->val];

    while (temp != NULL) {
        if (temp->Temp != NULL) {
            nhead->Temp = mp[temp->Temp->val];
        }
        temp = temp->next;
        nhead = nhead->next;
    }
    
    return mp[head->val];
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d(", temp->val);
        if (temp->Temp != NULL) {
            printf("%d", temp->Temp->val);
        }
        printf(") -> ");
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    // Creating a linked list with random pointers
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->val = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->val = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->val = 3;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->val = 5;
    head->Temp = head->next->next;
    head->next->Temp = head;
    head->next->next->Temp = head->next->next->next->next;
    head->next->next->next->Temp = head->next->next;
    head->next->next->next->next->Temp = head->next;
    head->next->next->next->next->next = NULL;

    // Print the original list
    printf("The original linked list:\n");
    printList(head);

    // Function call
    struct Node* sol = cloneLinkedList(head);

    printf("The cloned linked list:\n");
    printList(sol);

    return 0;
}
