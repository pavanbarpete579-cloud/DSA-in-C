#include <stdio.h>

int main() {
    int choice;

    while (1) {
        printf("\n--- DSA Toolkit ---\n");
        printf("1. Stack\n2. Queue\n3. Linked List\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Stack selected\n");
                break;
            case 2:
                printf("Queue selected\n");
                break;
            case 3:
                printf("Linked List selected\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}