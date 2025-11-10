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
    if(!checkBalanced(treeNode)) {
        balanceBST(treeNode);
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
void storeInOrder(TreeNode* treeNode, LinkedListNode** list){
    if(treeNode == NULL) return;
    storeInOrder(treeNode->left, list);
    pushBack(list, treeNode->data);
    storeInOrder(treeNode->right, list);
}
TreeNode* buildBalancedBST(TreeType* arr, int size){
    if(size <= 0) return NULL;
    int mid = size / 2;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = arr[mid];
    node->left = buildBalancedBST(arr, mid);
    node->right = buildBalancedBST(arr + mid + 1, size - mid - 1);
    return node;
}
TreeNode* balanceBST(TreeNode* bstpointer){
    LinkedListNode* list = NULL;
    storeInOrder(bstpointer, &list);
    bubbleSort(&list);
    int size = getSize(list);
    TreeType* arr = (TreeType*)malloc(size * sizeof(TreeType));
    for(int i = 0; i < size; i++){
        arr[i] = getValueAt(list, i);
    }
    clear(&list);
    free(bstpointer);
    bstpointer = buildBalancedBST(arr, size);
    free(arr);
    return bstpointer;
}
int checkBalanced(TreeNode* treeNode){
    if(treeNode == NULL) return 1;
    int leftHeight = 0, rightHeight = 0;
    TreeNode* leftSubtree = treeNode->left;
    TreeNode* rightSubtree = treeNode->right;
    while(leftSubtree != NULL){
        leftHeight++;
        leftSubtree = leftSubtree->left;
    }
    while(rightSubtree != NULL){
        rightHeight++;
        rightSubtree = rightSubtree->right;
    }
    int heightDiff = leftHeight - rightHeight;
    if(heightDiff < -1 || heightDiff > 1) return 0;
    return checkBalanced(treeNode->left) && checkBalanced(treeNode->right);
}