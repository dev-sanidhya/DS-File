#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct College {
    int id;
    char name[50];
    struct College* next;
};

struct College* head = NULL;

// Create a new node
struct College* createNode(int id, char* name) {
    struct College* newNode = (struct College*)malloc(sizeof(struct College));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int id, char* name) {
    struct College* newNode = createNode(id, name);
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct College* temp = head;
        while(temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted %s at front\n", name);
}

// Delete at end
void deleteEnd() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct College* temp = head;
    struct College* prev = NULL;
    if(head->next == head) {  // Only one node
        printf("Deleted %s\n", head->name);
        free(head);
        head = NULL;
        return;
    }
    while(temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    printf("Deleted %s\n", temp->name);
    free(temp);
}

// Display the list
void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct College* temp = head;
    printf("College List:\n");
    do {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    } while(temp != head);
}

int main() {
    insertFront(101, "ABC College");
    insertFront(102, "XYZ College");
    insertFront(103, "PQR College");
    display();
    deleteEnd();
    display();
    return 0;
}