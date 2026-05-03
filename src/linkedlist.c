#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void deleteNode() {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void displayLL() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void linkedListMenu() {
    int ch;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Back\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                displayLL();
                break;
            case 4:
                return;
            default:
                printf("Invalid\n");
        }
    }
}