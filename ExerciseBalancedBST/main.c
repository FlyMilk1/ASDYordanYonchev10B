#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
int main() {
    TreeNode* bst = NULL;
    for(int i = 0; i < 10000; i++) {
        insertBST(bst, rand() % 10000);
    }
    printf("Is the BST balanced? %s\n", checkBalanced(bst) ? "Yes" : "No");
    return 0;
}