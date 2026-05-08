#ifndef GRAPH_H
#define GRAPH_H

#define V 5

void addEdge(int graph[V][V], int src, int dest);
void printGraph(int graph[V][V]);
void BFS(int graph[V][V], int start);
void DFS(int graph[V][V], int start);
void dijkstra(int graph[V][V], int start);

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v);
struct Graph* createGraph(int vertices);
void addListEdge(struct Graph* graph, int src, int dest);
void printListGraph(struct Graph* graph);


#endif
