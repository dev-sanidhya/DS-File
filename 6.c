#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    struct Student* next;
};

struct Student* head = NULL;

// Create a new student node
struct Student* createNode(int roll, char* name) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Insert at given position (1-based index)
void insertAtPosition(int roll, char* name, int pos) {
    struct Student* newNode = createNode(roll, name);
    if(pos == 1) {  // insert at head
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Student* temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++)
        temp = temp->next;
    if(temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display linked list
void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Student List:\n");
    struct Student* temp = head;
    while(temp != NULL) {
        printf("Roll: %d, Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}

int main() {
    insertAtPosition(101, "Alice", 1);
    insertAtPosition(102, "Bob", 2);
    insertAtPosition(103, "Charlie", 2); // Insert at position 2
    display();
    return 0;
}