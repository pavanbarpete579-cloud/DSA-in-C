#include <stdio.h>
#include "queue.h"

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// EMPTY
int isEmpty() {
    return (front == -1);
}

// FULL (circular condition)
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// ENQUEUE
void enqueue(int val) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = val;
    printf("Inserted: %d\n", val);
}

// DEQUEUE
void dequeue() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    printf("Removed: %d\n", queue[front]);

    if (front == rear) {
        // last element removed
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// DISPLAY
void  displayQueue() {
    if (isEmpty()) {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue elements:\n");
    int i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// MENU
void queueMenu() {
    int ch, val;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}