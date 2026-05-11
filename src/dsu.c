#include <stdio.h>
#include "../include/dsu.h"

int parent[MAX];

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

int findParent(int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] =
        findParent(parent[node]);
}

void unionSets(int a, int b)
{
    int parentA = findParent(a);

    int parentB = findParent(b);

    if (parentA != parentB)
    {
        parent[parentB] = parentA;
    }
}
void dsuMenu()
{
    makeSet(5);

    unionSets(0, 1);
    unionSets(1, 2);

    if (findParent(0) == findParent(2))
    {
        printf("0 and 2 are connected\n");
    }
    else
    {
        printf("0 and 2 are not connected\n");
    }

    if (findParent(3) == findParent(4))
    {
        printf("3 and 4 are connected\n");
    }
    else
    {
        printf("3 and 4 are not connected\n");
    }
}