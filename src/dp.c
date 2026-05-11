#include <stdio.h>
#include "../include/dp.h"
#include <string.h>
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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n)
{
    int dp[100][100];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                dp[i][w] =
                    max(
                        values[i - 1] +
                        dp[i - 1][w - weights[i - 1]],

                        dp[i - 1][w]
                    );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}
int maxValue(int a, int b)
{
    return (a > b) ? a : b;
}

int longestCommonSubsequence(char str1[], char str2[])
{
    int m = strlen(str1);
    int n = strlen(str2);

    int dp[100][100];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] =
                    maxValue(dp[i - 1][j],
                             dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int coinChangeWays(int coins[], int n, int amount)
{
    int dp[100];

    for (int i = 0; i <= amount; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}
int longestIncreasingSubsequence(int arr[], int n)
{
    int dp[100];

    int maxLength = 1;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] &&
                dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }

        if (dp[i] > maxLength)
        {
            maxLength = dp[i];
        }
    }

    return maxLength;
}
void dpMenu()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};

    int n =
        sizeof(arr) / sizeof(arr[0]);

    int length =
        longestIncreasingSubsequence(arr, n);

    printf("LIS Length = %d\n", length);
}