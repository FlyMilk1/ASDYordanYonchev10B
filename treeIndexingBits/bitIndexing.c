#include <stdlib.h>
#include <stdio.h>

typedef int TreeType;

typedef struct TreeNode {
    TreeType data;
    struct TreeNode* left;
    struct TreeNode* right;
    unsigned char index;
} TreeNode;

typedef struct BST {
    TreeNode* root;
} BST;

void insertBST(TreeNode** treeNode, TreeType value) {
    if (*treeNode == NULL) {
        *treeNode = (TreeNode*)malloc(sizeof(TreeNode));
        (*treeNode)->data = value;
        (*treeNode)->left = NULL;
        (*treeNode)->right = NULL;
        return;
    }

    if (value > (*treeNode)->data) {
        insertBST(&(*treeNode)->right, value);
    } else if (value < (*treeNode)->data) {
        insertBST(&(*treeNode)->left, value);
    }
}

int searchBST(TreeNode* treeNode, TreeType value) {
    if (treeNode == NULL) return 0;
    if (treeNode->data == value) return 1;
    if (value > treeNode->data) return searchBST(treeNode->right, value);
    return searchBST(treeNode->left, value);
}

void assignBitIndexing(TreeNode* node, unsigned char index) {
    if (node == NULL) return;

    node->index = index;

    assignBitIndexing(node->left, index << 1);
    assignBitIndexing(node->right, (index << 1) + 1);
}

int main() {
    BST* bst = (BST*)malloc(sizeof(BST));
    bst->root = NULL;

    insertBST(&bst->root, 10);
    insertBST(&bst->root, 5);
    insertBST(&bst->root, 15);
    insertBST(&bst->root, 3);
    insertBST(&bst->root, 7);
    insertBST(&bst->root, 12);
    insertBST(&bst->root, 18);

    assignBitIndexing(bst->root, 1);

    printf("Node 10 index: %u\n", bst->root->index);
    printf("Node 5 index: %u\n", bst->root->left->index);
    printf("Node 15 index: %u\n", bst->root->right->index);
    printf("Node 3 index: %u\n", bst->root->left->left->index);
    printf("Node 7 index: %u\n", bst->root->left->right->index);
    printf("Node 12 index: %u\n", bst->root->right->left->index);
    printf("Node 18 index: %u\n", bst->root->right->right->index);

    return 0;
}
