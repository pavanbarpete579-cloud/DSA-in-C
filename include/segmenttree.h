#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#define MAX 100

void buildTree(int arr[],
               int tree[],
               int node,
               int start,
               int end);

int queryTree(int tree[],
              int node,
              int start,
              int end,
              int left,
              int right);

void updateTree(int arr[],
                int tree[],
                int node,
                int start,
                int end,
                int index,
                int value);

#endif