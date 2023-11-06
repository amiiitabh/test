#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int get_max(struct Node* head) {
    int max = head->data;
    struct Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void Radix_Sort(struct Node** head) {
    int max = get_max(*head);
    int exp,i;
    for (exp = 1; max / exp > 0; exp *= 10) {
        struct Node* output = NULL;
        struct Node* temp = *head;
        struct Node* buckets[10] = { NULL };

        while (temp != NULL) {
            int digit = (temp->data / exp) % 10;
            insert(&buckets[digit], temp->data);
            temp = temp->next;
        }
        for (i = 9; i >= 0; i--) {
            while (buckets[i] != NULL) {
                struct Node* next = buckets[i]->next;
                buckets[i]->next = output;
                output = buckets[i];
                buckets[i] = next;
            }
        }

        *head = output;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val,i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&head, val);
    }

    printf("Original Linked List: ");
    printList(head);

    Radix_Sort(&head);

    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}