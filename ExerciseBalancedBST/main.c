#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
int main() {
    TreeNode* BST = NULL;
    for(int i = 0; i < 10000; i++) {
        insertBST(BST, rand() % 10000);
    }
    printf("Is the BST balanced? %s\n", checkBalanced(BST) ? "Yes" : "No");
    return 0;
}