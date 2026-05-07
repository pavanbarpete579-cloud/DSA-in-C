#include <stdio.h>
#include "searching.h"

// LINEAR SEARCH
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// ITERATIVE BINARY SEARCH
int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// RECURSIVE BINARY SEARCH
int binarySearchRec(int arr[], int l, int r, int key) {
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRec(arr, mid + 1, r, key);
    else
        return binarySearchRec(arr, l, mid - 1, key);
}

// MENU
void searchingMenu() {
    int arr[100], n, key, ch, result;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("1. Linear Search\n2. Binary Search\n3. Recursive Binary Search\n");
    scanf("%d", &ch);

    if (ch == 1)
        result = linearSearch(arr, n, key);
    else if (ch == 2)
        result = binarySearch(arr, 0, n - 1, key);
    else
        result = binarySearchRec(arr, 0, n - 1, key);

    if (result == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", result);
}
int firstOccurrence(int arr[], int n, int key) {
    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key) {
            ans = mid;
            r = mid - 1;
        } else if (arr[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int lastOccurrence(int arr[], int n, int key) {
    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key) {
            ans = mid;
            l = mid + 1;
        } else if (arr[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int countOccurrence(int arr[], int n, int key) {
    int first = firstOccurrence(arr, n, key);
    if (first == -1) return 0;

    int last = lastOccurrence(arr, n, key);
    return last - first + 1;
}