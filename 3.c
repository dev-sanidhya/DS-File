#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", x);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped %d\n", top->data);
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void traverse() {
    if (top == NULL) {
        printf("Stack Empty\n");
        return;
    }
    printf("Stack: ");
    for (struct Node* curr = top; curr != NULL; curr = curr->next)
        printf("%d ", curr->data);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    traverse();
    pop();
    traverse();
    push(40);
    traverse();
    return 0;
}