#include <stdio.h>

#include "../include/segmenttree.h"

void buildTree(int arr[],
               int tree[],
               int node,
               int start,
               int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;

        buildTree(arr,
                  tree,
                  2 * node,
                  start,
                  mid);

        buildTree(arr,
                  tree,
                  2 * node + 1,
                  mid + 1,
                  end);

        tree[node] =
            tree[2 * node] +
            tree[2 * node + 1];
    }
}

int queryTree(int tree[],
              int node,
              int start,
              int end,
              int left,
              int right)
{
    if (right < start || end < left)
    {
        return 0;
    }

    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;

    int p1 =
        queryTree(tree,
                  2 * node,
                  start,
                  mid,
                  left,
                  right);

    int p2 =
        queryTree(tree,
                  2 * node + 1,
                  mid + 1,
                  end,
                  left,
                  right);

    return p1 + p2;
}

void updateTree(int arr[],
                int tree[],
                int node,
                int start,
                int end,
                int index,
                int value)
{
    if (start == end)
    {
        arr[index] = value;
        tree[node] = value;
    }
    else
    {
        int mid = (start + end) / 2;

        if (index <= mid)
        {
            updateTree(arr,
                       tree,
                       2 * node,
                       start,
                       mid,
                       index,
                       value);
        }
        else
        {
            updateTree(arr,
                       tree,
                       2 * node + 1,
                       mid + 1,
                       end,
                       index,
                       value);
        }

        tree[node] =
            tree[2 * node] +
            tree[2 * node + 1];
    }
}
void segmentTreeMenu()
{
    int arr[] = {1, 3, 5, 7, 9, 11};

    int n =
        sizeof(arr) / sizeof(arr[0]);

    int tree[MAX];

    buildTree(arr,
              tree,
              1,
              0,
              n - 1);

    int sum =
        queryTree(tree,
                  1,
                  0,
                  n - 1,
                  1,
                  3);

    printf("Range Sum (1 to 3) = %d\n",
           sum);

    updateTree(arr,
               tree,
               1,
               0,
               n - 1,
               2,
               10);

    sum =
        queryTree(tree,
                  1,
                  0,
                  n - 1,
                  1,
                  3);

    printf("After Update:\n");

    printf("Range Sum (1 to 3) = %d\n",
           sum);
}