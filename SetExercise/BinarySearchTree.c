#include "BinarySearchTree.h"
#include <stdlib.h>
void insertBST(TreeNode* treeNode, TreeType value){
    if(treeNode == NULL){
        treeNode = (TreeNode*)malloc(sizeof(TreeNode));
        treeNode->data = value;
    }
    else if (value > treeNode->data){
        insertBST(treeNode->right, value);  
    }
    else if (value < treeNode->data){
        insertBST(treeNode->left, value);
    }
    else{
        return;
    }
}
int searchBST(TreeNode* treeNode, TreeType value){
    if(treeNode->data == value) return 1;
    else if(value > treeNode->data){
        return searchBST(treeNode->right, value);
    }
    else if(value < treeNode->data){
        return searchBST(treeNode->left, value);
    }
    return 0;
}