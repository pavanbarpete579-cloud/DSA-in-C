#include <stdio.h>
#include "../include/stack.h"
#define SIZE 5

static int stack[SIZE];
static int top = -1;

void push(int val) {
    if (top == SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    stack[++top] = val;
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void displayStack(){
    if (top == -1) {
        printf("Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void stackMenu() {
    int ch, val;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Back\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                return;
            default:
                printf("Invalid\n");
                break;
        }
    }
}