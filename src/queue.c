#include <stdio.h>
#define SIZE 5

static int queue[SIZE];
static int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) front = 0;

    queue[++rear] = val;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        return;
    }
    printf("Removed: %d\n", queue[front++]);
}

void displayQ() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void queueMenu() {
    int ch, val;

    while (1) {
        printf("\n--- Queue Menu ---\n");
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
                displayQ();
                break;
            case 4:
                return;
            default:
                printf("Invalid\n");
                break;
        }
    }
}