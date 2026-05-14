#include <stdio.h>

#include "../include/priorityqueue.h"

int pqHeap[PQMAX];

int pqSize = 0;

void pqSwap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertPQ(int value)
{
    pqSize++;

    pqHeap[pqSize] = value;

    int current = pqSize;

    while (current > 1 &&
           pqHeap[current] >
           pqHeap[current / 2])
    {
        pqSwap(&pqHeap[current],
               &pqHeap[current / 2]);

        current /= 2;
    }
}

int deletePQ()
{
    if (pqSize == 0)
    {
        return -1;
    }

    int max = pqHeap[1];

    pqHeap[1] = pqHeap[pqSize];

    pqSize--;

    int current = 1;

    while (2 * current <= pqSize)
    {
        int child = 2 * current;

        if (child + 1 <= pqSize &&
            pqHeap[child + 1] >
            pqHeap[child])
        {
            child++;
        }

        if (pqHeap[current] <
            pqHeap[child])
        {
            pqSwap(&pqHeap[current],
                   &pqHeap[child]);

            current = child;
        }
        else
        {
            break;
        }
    }

    return max;
}

void displayPQ()
{
    for (int i = 1; i <= pqSize; i++)
    {
        printf("%d ", pqHeap[i]);
    }

    printf("\n");
}
void priorityQueueMenu()
{
    insertPQ(10);
    insertPQ(40);
    insertPQ(20);
    insertPQ(50);

    printf("Priority Queue:\n");

    displayPQ();

    printf("Deleted: %d\n",
           deletePQ());

    printf("After Deletion:\n");

    displayPQ();
}