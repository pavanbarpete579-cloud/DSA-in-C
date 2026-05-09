#include <stdio.h>
#include "../include/dp.h"

int memo[100];

int fibonacciMemoHelper(int n)
{
    if (n <= 1)
    {
        return n;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] =
        fibonacciMemoHelper(n - 1) +
        fibonacciMemoHelper(n - 2);

    return memo[n];
}

int fibonacciMemo(int n)
{
    for (int i = 0; i < 100; i++)
    {
        memo[i] = -1;
    }

    return fibonacciMemoHelper(n);
}
void dpMenu()
{
    int n = 10;

    int result = fibonacciMemo(n);

    printf("Fibonacci(%d) = %d\n", n, result);
}