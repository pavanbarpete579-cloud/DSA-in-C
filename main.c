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
#include "dp.h"
#include "backtracking.h"
#include "greedy.h"
#include "dsu.h"
#include "kruskal.h"
#include "prim.h"
#include "bellmanford.h"
#include "floydwarshall.h"
#include "segmenttree.h"
#include "fenwick.h"

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
        void dpMenu();
        void backtrackingMenu();
        void greedyMenu();
        void dsuMenu();
        void kruskalMenu();
        void primMenu();
        void bellmanFordMenu();
        void floydWarshallMenu();
        void segmentTreeMenu();
        void fenwickMenu();
        
        
        
int main() {
    int choice;
    while (1) {
        printf("\n--- DSA Toolkit ---\n");
        printf("1. Stack\n2. Queue\n3. Linked List\n4. BST\n5. Sorting\n6. Searching\n7. Graph\n8. Hashing\n9. Heap\n10. Trie\n11. Dp\n12. Backtracking\n13. Greedy Algorithms\n14. Disjoint Set Union\n15. Kruskal Algorithm\n16. Prim Algorithm\n17. Bellman-Ford\n18. Floyd-Warshall\n19. Segment Tree\n20. Fenwick Tree\n21. Exit\n");

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
                dpMenu();
            break;

            case 12:
                backtrackingMenu();
                break;

            case 13:
                greedyMenu();
                break;

            case 14:
                dsuMenu();
                break;

            case 15:
                kruskalMenu();
                break;

            case 16:
                primMenu();
                break;

            case 17:
                bellmanFordMenu();
                break;

            case 18:
                floydWarshallMenu();
                break;

            case 19:
                segmentTreeMenu();
                break;

            case 20:
                fenwickMenu();
                break;

            case 21:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}