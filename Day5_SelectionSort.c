#include <stdio.h>

int main() {
    int arr[5] = {5, 2, 4, 1, 3};
    int i, j, min, temp;

    for (i = 0; i < 5 - 1; i++) {
        min = i;

        for (j = i + 1; j < 5; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // swap
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted array:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}