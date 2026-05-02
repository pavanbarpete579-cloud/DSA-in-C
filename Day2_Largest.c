#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c) {
        printf("A is largest\n");
    } else if (b >= a && b >= c) {
        printf("B is largest\n");
    } else {
        printf("C is largest\n");
    }

    return 0;
}