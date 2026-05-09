#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/trie.h"

struct TrieNode* createTrieNode()
{
    struct TrieNode* node =
        (struct TrieNode*)malloc(sizeof(struct TrieNode));

    node->isEndOfWord = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

void insertWord(struct TrieNode* root, char* word)
{
    struct TrieNode* current = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
        {
            current->children[index] = createTrieNode();
        }

        current = current->children[index];
    }

    current->isEndOfWord = 1;
}

int searchWord(struct TrieNode* root, char* word)
{
    struct TrieNode* current = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
        {
            return 0;
        }

        current = current->children[index];
    }

    return current->isEndOfWord;
}
void trieMenu()
{
    struct TrieNode* root = createTrieNode();

    insertWord(root, "cat");
    insertWord(root, "car");
    insertWord(root, "dog");

    if (searchWord(root, "cat"))
    {
        printf("cat found\n");
    }
    else
    {
        printf("cat not found\n");
    }

    if (searchWord(root, "bat"))
    {
        printf("bat found\n");
    }
    else
    {
        printf("bat not found\n");
    }
}