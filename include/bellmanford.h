#ifndef BELLMANFORD_H
#define BELLMANFORD_H

struct BFEdge
{
    int src;
    int dest;
    int weight;
};

void bellmanFord(struct BFEdge edges[],
                 int vertices,
                 int edgesCount,
                 int start);

#endif