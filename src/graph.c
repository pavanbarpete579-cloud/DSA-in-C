#include <stdio.h>
#include "../include/graph.h"

void addEdge(int graph[V][V], int src, int dest)
{
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

void printGraph(int graph[V][V])
{
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
}
void graphMenu()
{
    int graph[V][V] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printGraph(graph);
    BFS(graph, 0);
    DFS(graph, 0);
}

void BFS(int graph[V][V], int start)
{
    int visited[V] = {0};
    int queue[V];

    int front = 0;
    int rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%d ", current);

        for (int i = 0; i < V; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}
void DFSUtil(int graph[V][V], int vertex, int visited[])
{
    visited[vertex] = 1;

    printf("%d ", vertex);

    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFSUtil(graph, i, visited);
        }
    }
}
void DFS(int graph[V][V], int start)
{
    int visited[V] = {0};

    printf("DFS Traversal: ");

    DFSUtil(graph, start, visited);

    printf("\n");
}