#include <stdio.h>
#include <limits.h>

#include "../include/bellmanford.h"

void bellmanFord(struct BFEdge edges[],
                 int vertices,
                 int edgesCount,
                 int start)
{
    int dist[100];

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[start] = 0;

    for (int i = 1; i <= vertices - 1; i++)
    {
        for (int j = 0; j < edgesCount; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX &&
                dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int j = 0; j < edgesCount; j++)
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;

        if (dist[u] != INT_MAX &&
            dist[u] + weight < dist[v])
        {
            printf("Negative weight cycle detected\n");
            return;
        }
    }

    printf("Shortest Distances:\n");

    for (int i = 0; i < vertices; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }
}
void bellmanFordMenu()
{
    struct BFEdge edges[] =
    {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int vertices = 5;

    int edgesCount =
        sizeof(edges) / sizeof(edges[0]);

    bellmanFord(edges,
                vertices,
                edgesCount,
                0);
}