#include <stdio.h>
#include "../include/heap.h"

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(int value)
{
    heap[size] = value;

    int current = size;

    while (current > 0)
    {
        int parent = (current - 1) / 2;

        if (heap[parent] < heap[current])
        {
            swap(&heap[parent], &heap[current]);
        }

        current = parent;
    }

    size++;
}

void heapify(int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
    {
        largest = left;
    }

    if (right < size && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);

        heapify(largest);
    }
}

void deleteRoot()
{
    if (size <= 0)
    {
        return;
    }

    heap[0] = heap[size - 1];

    size--;

    heapify(0);
}

void printHeap()
{
    printf("Heap Elements: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
}
void heapMenu()
{
    insertHeap(50);
    insertHeap(30);
    insertHeap(40);
    insertHeap(10);
    insertHeap(5);

    printHeap();

    deleteRoot();

    printf("After deleting root:\n");

    printHeap();
}