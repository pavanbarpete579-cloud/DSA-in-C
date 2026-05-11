#include <stdio.h>

#include "../include/floydwarshall.h"

void printSolution(int dist[FWV][FWV])
{
    printf("Shortest Distance Matrix:\n");

    for (int i = 0; i < FWV; i++)
    {
        for (int j = 0; j < FWV; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%3d ", dist[i][j]);
            }
        }

        printf("\n");
    }
}

void floydWarshall(int graph[FWV][FWV])
{
    int dist[FWV][FWV];

    for (int i = 0; i < FWV; i++)
    {
        for (int j = 0; j < FWV; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < FWV; k++)
    {
        for (int i = 0; i < FWV; i++)
        {
            for (int j = 0; j < FWV; j++)
            {
                if (dist[i][k] + dist[k][j]
                    < dist[i][j])
                {
                    dist[i][j] =
                        dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}
void floydWarshallMenu()
{
    int graph[FWV][FWV] =
    {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);
}