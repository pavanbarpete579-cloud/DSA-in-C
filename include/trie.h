#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* createTrieNode();

void insertWord(struct TrieNode* root, char* word);

int searchWord(struct TrieNode* root, char* word);

#endif