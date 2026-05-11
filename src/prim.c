#include <stdio.h>
#include <limits.h>

#include "../include/prim.h"

int minKey(int key[], int mstSet[])
{
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < VERTICES; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int parent[],
              int graph[VERTICES][VERTICES])
{
    printf("Edges in MST:\n");

    for (int i = 1; i < VERTICES; i++)
    {
        printf("%d - %d == %d\n",
               parent[i],
               i,
               graph[i][parent[i]]);
    }
}

void primMST(int graph[VERTICES][VERTICES])
{
    int parent[VERTICES];

    int key[VERTICES];

    int mstSet[VERTICES];

    for (int i = 0; i < VERTICES; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;

    parent[0] = -1;

    for (int count = 0;
         count < VERTICES - 1;
         count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = 1;

        for (int v = 0; v < VERTICES; v++)
        {
            if (graph[u][v] &&
                mstSet[v] == 0 &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}
void primMenu()
{
    int graph[VERTICES][VERTICES] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
}