#ifndef SET_H
#define SET_H
#include "BinarySearchTree.h"
#include <stdlib.h>
typedef struct Set{
    TreeNode* root;
}Set;
Set* initializeSet(){
    Set newSet;
    TreeNode* newTree;
    newSet.root = newTree;
}
void set_add(Set* set, TreeType value);
int set_contains(Set* set, TreeType value);
int is_subsetTrees(TreeNode* tree1, TreeNode* tree2);
int is_subset(Set* set1, Set* set2);
void addTreeToSet(TreeNode* node, Set* set);
Set* set_union(Set* set1, Set* set2);
void addIntersection(TreeNode* node, Set* set2, Set* intersectionSet);
Set* set_intersection(Set* set1, Set* set2);
void addDifference(TreeNode* node, Set* set2, Set* differenceSet);
Set* set_difference(Set* set1, Set* set2);
#endif