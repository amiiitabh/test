#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

int countRotation(struct Node* head) {
   
    int count = 0;

    int min = head->data;

    while (head != NULL) {
       
        if (min > head->data)
            break;

        count++;

        head = head->next;
    }
    return count;
}

void push(struct Node** head, int data) {
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = *
