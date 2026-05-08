#ifndef GRAPH_H
#define GRAPH_H

#define V 4

void addEdge(int graph[V][V], int src, int dest);
void printGraph(int graph[V][V]);
void BFS(int graph[V][V], int start);


#endif