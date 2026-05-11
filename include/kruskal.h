#ifndef KRUSKAL_H
#define KRUSKAL_H

struct Edge
{
    int src;
    int dest;
    int weight;
};

void kruskal(struct Edge edges[], int vertices, int edgesCount);

#endif