#include <stdio.h>

#include "../include/fenwick.h"

void updateBIT(int bit[],
               int n,
               int index,
               int value)
{
    index++;

    while (index <= n)
    {
        bit[index] += value;

        index += index & (-index);
    }
}

int queryBIT(int bit[],
             int index)
{
    int sum = 0;

    index++;

    while (index > 0)
    {
        sum += bit[index];

        index -= index & (-index);
    }

    return sum;
}

void buildBIT(int arr[],
              int bit[],
              int n)
{
    for (int i = 0; i <= n; i++)
    {
        bit[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        updateBIT(bit,
                  n,
                  i,
                  arr[i]);
    }
}
void fenwickMenu()
{
    int arr[] = {1, 2, 3, 4, 5};

    int n =
        sizeof(arr) / sizeof(arr[0]);

    int bit[FMAX];

    buildBIT(arr, bit, n);

    int sum =
        queryBIT(bit, 3);

    printf("Prefix Sum (0 to 3) = %d\n",
           sum);

    updateBIT(bit, n, 2, 5);

    sum =
        queryBIT(bit, 3);

    printf("After Update:\n");

    printf("Prefix Sum (0 to 3) = %d\n",
           sum);
}