#include <stdio.h>
#include <string.h>

#include "../include/rabinkarp.h"

#define PRIME 101

void rabinKarpSearch(char text[],
                     char pattern[])
{
    int n = strlen(text);

    int m = strlen(pattern);

    int patternHash = 0;
    int textHash = 0;

    int h = 1;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * 256) % PRIME;
    }

    for (int i = 0; i < m; i++)
    {
        patternHash =
            (256 * patternHash +
             pattern[i]) % PRIME;

        textHash =
            (256 * textHash +
             text[i]) % PRIME;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == textHash)
        {
            int match = 1;

            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = 0;
                    break;
                }
            }

            if (match)
            {
                printf("Pattern found at index %d\n",
                       i);
            }
        }

        if (i < n - m)
        {
            textHash =
                (256 * (textHash -
                text[i] * h) +
                text[i + m]) % PRIME;

            if (textHash < 0)
            {
                textHash += PRIME;
            }
        }
    }
}
void rabinKarpMenu()
{
    char text[] =
        "AABAACAADAABAABA";

    char pattern[] =
        "AABA";

    rabinKarpSearch(text, pattern);
}