#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// CREATE NODE
struct Node* create(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// INSERT
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return create(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// SEARCH
int searchBST(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;

    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// INORDER (sorted output)
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// FIND MIN (used in delete)
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// DELETE (hard part)
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // 1 child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // 2 children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// MENU
void bstMenu() {
    struct Node* root = NULL;
    int ch, val;

    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1.Insert\n2.Search\n3.Inorder\n4.Delete\n5.Back\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                scanf("%d", &val);
                if (searchBST(root, val))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;

            case 3:
                inorder(root);
                printf("\n");
                break;

            case 4:
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;

            case 5:
                return;

            default:
                printf("Invalid\n");
        }
    }
}


