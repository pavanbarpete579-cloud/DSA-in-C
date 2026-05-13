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
    struct TrieNode* root =
        createTrieNode();

    insertWord(root, "cat");
    insertWord(root, "car");
    insertWord(root, "cart");
    insertWord(root, "dog");

    printf("Suggestions:\n");

    autocomplete(root, "ca");
}
void printSuggestions(struct TrieNode* root,
                      char word[],
                      int level)
{
    if (root->isEndOfWord)
    {
        word[level] = '\0';

        printf("%s\n", word);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            word[level] = i + 'a';

            printSuggestions(root->children[i],
                             word,
                             level + 1);
        }
    }
}
void autocomplete(struct TrieNode* root,
                  char prefix[])
{
    struct TrieNode* current = root;

    for (int i = 0; prefix[i] != '\0'; i++)
    {
        int index = prefix[i] - 'a';

        if (current->children[index] == NULL)
        {
            printf("No suggestions found\n");

            return;
        }

        current = current->children[index];
    }

    char word[100];

    strcpy(word, prefix);

    printSuggestions(current,
                     word,
                     strlen(prefix));
}