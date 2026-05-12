#ifndef FENWICK_H
#define FENWICK_H

#define FMAX 100

void updateBIT(int bit[],
               int n,
               int index,
               int value);

int queryBIT(int bit[],
             int index);

void buildBIT(int arr[],
              int bit[],
              int n);

#endif