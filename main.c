#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "bst.h"
#include "sorting.h"
#include "graph.h"
#include "hash.h"
#include "heap.h"
#include "trie.h"

        void stackMenu();
        void queueMenu();
        void linkedListMenu();
        void bstMenu();
        void sortingMenu();
        void searchingMenu();
        void graphMenu();
        void hashMenu();
        void heapMenu();
        void trieMenu();
        
        
int main() {
    int choice;
    while (1) {
        printf("\n--- DSA Toolkit ---\n");
        printf("1. Stack\n2. Queue\n3. Linked List\n4. BST\n5. Sorting\n6. Searching\n7. Graph\n8. Hashing\n9. Heap\n10. Trie\n11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                 stackMenu();
                break;
            case 2:
               queueMenu();
                break;
            case 3:
                linkedListMenu();
                break;
            case 4:
                bstMenu();
                break;

            case 5:
                sortingMenu();
                break;

            case 6:
                searchingMenu();
                break;
            case 7:
                graphMenu();
                break;

            case 8:
                hashMenu();
                break;

            case 9:
                heapMenu();
                break;

            case 10:
                trieMenu();
                break;

            case 11:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}