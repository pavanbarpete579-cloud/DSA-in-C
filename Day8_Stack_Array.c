#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

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

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    return 0;
}