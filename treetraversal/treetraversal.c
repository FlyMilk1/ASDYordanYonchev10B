#include <stdio.h>
#include <stdlib.h>

#define MIN_VAL -1000000
#define MAX_VAL  1000000

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* buildBSTFromPreorder(int arr[], int *index, int n, int min, int max) {
    if (*index >= n)
        return NULL;

    int val = arr[*index];

    if (val < min || val > max)
        return NULL;

    Node* root = newNode(val);
    (*index)++;

    root->left = buildBSTFromPreorder(arr, index, n, min, val - 1);
    root->right = buildBSTFromPreorder(arr, index, n, val + 1, max);

    return root;
}

Node* buildBSTFromPostorder(int arr[], int *index, int min, int max) {
    if (*index < 0)
        return NULL;

    int val = arr[*index];

    if (val < min || val > max)
        return NULL;

    Node* root = newNode(val);
    (*index)--;

    root->right = buildBSTFromPostorder(arr, index, val + 1, max);
    root->left = buildBSTFromPostorder(arr, index, min, val - 1);

    return root;
}

Node* buildBSTFromInorder(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node* root = newNode(arr[mid]);
    root->left = buildBSTFromInorder(arr, start, mid - 1);
    root->right = buildBSTFromInorder(arr, mid + 1, end);

    return root;
}

void printInorder(Node* root) {
    if (!root)
        return;

    printInorder(root->left);
    printf("%d ", root->key);
    printInorder(root->right);
}

void freeTree(Node* root) {
    if (!root)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int postorder[] = {1, 7, 5, 50, 40, 10};
    int inorder[] = {1, 5, 7, 10, 40, 50};

    int n = sizeof(preorder) / sizeof(preorder[0]);

    int preIndex = 0;
    Node* preRoot = buildBSTFromPreorder(preorder, &preIndex, n, MIN_VAL, MAX_VAL);

    int postIndex = n - 1;
    Node* postRoot = buildBSTFromPostorder(postorder, &postIndex, MIN_VAL, MAX_VAL);

    Node* inRoot = buildBSTFromInorder(inorder, 0, n - 1);

    printInorder(preRoot);
    printf("\n");

    printInorder(postRoot);
    printf("\n");

    printInorder(inRoot);
    printf("\n");

    freeTree(preRoot);
    freeTree(postRoot);
    freeTree(inRoot);

    return 0;
}
