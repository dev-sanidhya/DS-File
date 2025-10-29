#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;

void insert(int x) {  // Enqueue
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {   // First element
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d\n", x);
}

void dequeue() {  // Dequeue
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d\n", front->data);
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL; // queue empty
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    for (struct Node* curr = front; curr != NULL; curr = curr->next)
        printf("%d ", curr->data);
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();
    dequeue();
    display();
    insert(40);
    display();
    return 0;
}