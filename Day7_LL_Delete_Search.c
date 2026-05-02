#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void search(int key) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Not found\n");
}

void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    // delete first node
    if (head->data == value) {
        struct Node* del = head;
        head = head->next;
        free(del);
        return;
    }

    // search node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Main
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    search(20);

    deleteNode(20);

    display();

    return 0;
}