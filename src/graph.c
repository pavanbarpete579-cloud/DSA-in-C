#include <stdio.h>
#include <stdlib.h>
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

    struct Graph* listGraph = createGraph(5);

    addListEdge(listGraph, 0, 1);
    addListEdge(listGraph, 0, 2);
    addListEdge(listGraph, 1, 3);
    addListEdge(listGraph, 2, 4);

    printListGraph(listGraph);
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

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addListEdge(struct Graph* graph, int src, int dest)
{
    struct Node* newNode = createNode(dest);

    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);

    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printListGraph(struct Graph* graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        struct Node* temp = graph->adjLists[v];

        printf("\nVertex %d:\n", v);

        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}