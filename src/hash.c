#include <stdio.h>
#include <stdlib.h>
#include "../include/hash.h"

struct HashNode* hashTable[SIZE] = {NULL};

int hashFunction(int key)
{
    return key % SIZE;
}

void insertHash(int key)
{
    int index = hashFunction(key);

    struct HashNode* newNode =
        (struct HashNode*)malloc(sizeof(struct HashNode));

    newNode->data = key;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}

void searchHash(int key)
{
    int index = hashFunction(key);

    struct HashNode* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Key %d found\n", key);
            return;
        }

        temp = temp->next;
    }

    printf("Key %d not found\n", key);
}

void displayHash()
{
    for (int i = 0; i < SIZE; i++)
    {
        struct HashNode* temp = hashTable[i];

        printf("%d: ", i);

        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}
void hashMenu()
{
    insertHash(15);
    insertHash(25);
    insertHash(35);
    insertHash(20);

    displayHash();

    searchHash(25);
    searchHash(99);
}