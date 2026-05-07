#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// INSERT AT BEGIN
void insertBegin(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = head;
    head = n;
    printf("Inserted at begin: %d\n", val);
}

// INSERT AT END
void insertEnd(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;

    if (!head) { head = n; return; }

    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    printf("Inserted at end: %d\n", val);
}

// INSERT AT POSITION (1-based)
void insertAtPos(int val, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertBegin(val);
        return;
    }

    struct Node* t = head;
    for (int i = 1; i < pos - 1 && t; i++) {
        t = t->next;
    }

    if (!t) {
        printf("Position out of range\n");
        return;
    }

    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = t->next;
    t->next = n;

    printf("Inserted %d at position %d\n", val, pos);
}

// DELETE BY VALUE
void deleteByValue(int val) {
    if (!head) {
        printf("List Empty\n");
        return;
    }

    if (head->data == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted: %d\n", val);
        return;
    }

    struct Node* t = head;
    while (t->next && t->next->data != val) {
        t = t->next;
    }

    if (!t->next) {
        printf("Value not found\n");
        return;
    }

    struct Node* temp = t->next;
    t->next = temp->next;
    free(temp);
    printf("Deleted: %d\n", val);
}

// SEARCH
void searchLL(int val) {
    struct Node* t = head;
    int pos = 1;

    while (t) {
        if (t->data == val) {
            printf("Found at position %d\n", pos);
            return;
        }
        t = t->next;
        pos++;
    }

    printf("Not found\n");
}

// REVERSE
void reverseList() {
    struct Node *prev = NULL, *curr = head, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("List reversed\n");
}

// DISPLAY
void displayList() {
    if (!head) {
        printf("List Empty\n");
        return;
    }

    struct Node* t = head;
    while (t) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

// MENU
void linkedListMenu() {
    int ch, val, pos;

    while (1) {
        printf("\n--- Linked List Advanced ---\n");
        printf("1.Insert Begin\n2.Insert End\n3.Insert at Pos\n4.Delete by Value\n5.Search\n6.Reverse\n7.Display\n8.Back\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &val);
                insertBegin(val);
                break;

            case 2:
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 3:
                printf("Enter value & position: ");
                scanf("%d %d", &val, &pos);
                insertAtPos(val, pos);
                break;

            case 4:
                scanf("%d", &val);
                deleteByValue(val);
                break;

            case 5:
                scanf("%d", &val);
                searchLL(val);
                break;

            case 6:
                reverseList();
                break;

            case 7:
                displayList();
                break;

            case 8:
                return;

            default:
                printf("Invalid\n");
        }
    }
}