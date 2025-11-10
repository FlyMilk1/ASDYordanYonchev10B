#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "LinkedList.h"
typedef int TreeType;
typedef struct TreeNode {
    TreeType data;
    TreeNode* left;
    TreeNode* right;
}TreeNode;
typedef struct BST{
    TreeNode* root;
}BST;
void insertBST(TreeNode* treeNode, TreeType value);
int searchBST(TreeNode* treeNode, TreeType value);
void storeInOrder(TreeNode* treeNode, LinkedListNode** list);
TreeNode* buildBalancedBST(TreeType* arr, int size);
TreeNode* balanceBST(BST* bstpointer);
int checkBalanced(TreeNode* treeNode);
#endif