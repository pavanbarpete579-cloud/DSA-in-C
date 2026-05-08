#ifndef HASH_H
#define HASH_H

#define SIZE 10

struct HashNode
{
    int data;
    struct HashNode* next;
};

void insertHash(int key);
void searchHash(int key);
void displayHash();

#endif