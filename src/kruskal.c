#include <stdio.h>
#include "../include/kruskal.h"
#include "../include/dsu.h"

void sortEdges(struct Edge edges[], int edgesCount)
{
    for (int i = 0; i < edgesCount - 1; i++)
    {
        for (int j = 0; j < edgesCount - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(struct Edge edges[], int vertices, int edgesCount)
{
    makeSet(vertices);

    sortEdges(edges, edgesCount);

    printf("Edges in MST:\n");

    for (int i = 0; i < edgesCount; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (findParent(u) != findParent(v))
        {
            printf("%d -- %d == %d\n",
                   u,
                   v,
                   edges[i].weight);

            unionSets(u, v);
        }
    }
}
void kruskalMenu()
{
    struct Edge edges[] =
    {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int vertices = 4;

    int edgesCount =
        sizeof(edges) / sizeof(edges[0]);

    kruskal(edges, vertices, edgesCount);
}