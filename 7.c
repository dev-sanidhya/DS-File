#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define doubly linked list node
struct Employee {
    int id;
    char name[50];
    struct Employee* prev;
    struct Employee* next;
};

struct Employee* head = NULL;

// Create a new node
struct Employee* createNode(int id, char* name) {
    struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int id, char* name) {
    struct Employee* newNode = createNode(id, name);
    if(head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %s at front\n", name);
}

// Display the list
void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Employee* temp = head;
    printf("Employee List:\n");
    while(temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

int main() {
    insertFront(101, "Alice");
    insertFront(102, "Bob");
    insertFront(103, "Charlie");
    display();
    return 0;
}