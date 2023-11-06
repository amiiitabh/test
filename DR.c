#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int value;
    int priority;
    struct Node* next;
} Node;
// Priority Queue structure
typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

// Function to create a new Node
Node* createNode(int value, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new PriorityQueue
PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

// Function to check if the PriorityQueue is empty
int isEmpty(PriorityQueue* pq) {
    return pq->head == NULL;
}

// Function to enqueue an element into the PriorityQueue
void enqueue(PriorityQueue* pq, int value, int priority) {
    Node* newNode = createNode(value, priority);

    if (isEmpty(pq) || priority < pq->head->priority) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        Node* current = pq->head;
        while (current->next && priority >= current->next->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to dequeue an element from the PriorityQueue
int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("PriorityQueue is empty.\n");
        return -1; // Return a sentinel value or handle error
    }

    int value = pq->head->value;
    Node* temp = pq->head;
    pq->head = pq->head->next;
    free(temp);
    return value;
}

// Function to peek at the front element of the PriorityQueue
int peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("PriorityQueue is empty.\n");
        return -1; // Return a sentinel value or handle error
    }
    return pq->head->value;
}

// Function to free the PriorityQueue and its Nodes
void freePriorityQueue(PriorityQueue* pq) {
    Node* current = pq->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(pq);
}

int main() {
    PriorityQueue* pq = createPriorityQueue();
    enqueue(pq, 3, 2);
    enqueue(pq, 1, 2);
    enqueue(pq, 2, 3);

    printf("Peek: %d\n", peek(pq)); // Output: Peek: 1

    printf("Dequeue: %d\n", dequeue(pq)); // Output: Dequeue: 1
    printf("Dequeue: %d\n", dequeue(pq)); // Output: Dequeue: 3
    printf("Dequeue: %d\n", dequeue(pq)); // Output: Dequeue: 2

    freePriorityQueue(pq);

    return 0;
}
