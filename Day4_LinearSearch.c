#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key, i, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < 5; i++) {
        if (arr[i] == key) {
            printf("Found at index %d", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not found");
    }

    return 0;
}