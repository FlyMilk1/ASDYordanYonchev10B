#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
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
#endif