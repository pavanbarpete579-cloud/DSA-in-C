#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

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

    printf("Deleted: %d\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}