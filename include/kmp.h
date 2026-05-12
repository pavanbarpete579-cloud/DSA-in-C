#ifndef KMP_H
#define KMP_H

void computeLPS(char pattern[],
                int lps[],
                int m);

void KMPSearch(char text[],
               char pattern[]);

#endif