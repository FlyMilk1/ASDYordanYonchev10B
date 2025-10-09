#include "Set.h"
void set_add(Set* set, TreeType value){
    insertBST(set->root, value);
}
int set_contains(Set* set, TreeType value){
    return searchBST(set->root, value);
}
int is_subsetTree(TreeNode* tree1, TreeNode* tree2){
    if (tree1 == NULL) return 1;
    if (searchBST(tree2, tree1->data) == 0) return 0;
    if (!is_subsetTree(tree1->left, tree2)) return 0;
    if (!is_subsetTree(tree1->right, tree2)) return 0;
    return 1;
}
int is_subset(Set* set1, Set* set2){
    return is_subsetTree(set1->root, set2->root);
}
void addTreeToSet(TreeNode* node, Set* set) {
    if (node == NULL) return;
    set_add(set, node->data);
    addTreeToSet(node->left, set);
    addTreeToSet(node->right, set);
}

Set* set_union(Set* set1, Set* set2){
    Set* unionSet = (Set*)malloc(sizeof(Set));
    addTreeToSet(set1->root, unionSet);
    addTreeToSet(set2->root, unionSet);
    return unionSet;
}
void addIntersection(TreeNode* node, Set* set2, Set* intersectionSet) {
    if (node == NULL) return;
    if (set_contains(set2, node->data)) {
        set_add(intersectionSet, node->data);
    }
    addIntersection(node->left, set2, intersectionSet);
    addIntersection(node->right, set2, intersectionSet);
}

Set* set_intersection(Set* set1, Set* set2){
    Set* intersectionSet = (Set*)malloc(sizeof(Set));
    intersectionSet->root = NULL;
    addIntersection(set1->root, set2, intersectionSet);
    return intersectionSet;
}
void addDifference(TreeNode* node, Set* set2, Set* differenceSet){
    if (node == NULL) return;
    if(!set_contains(set2, node->data)){
        set_add(differenceSet, node->data);
    }
    addDifference(node->left, set2, differenceSet);
    addDifference(node->right, set2, differenceSet);
}
Set* set_difference(Set* set1, Set* set2){
    Set* differenceSet = (Set*)malloc(sizeof(Set));
    differenceSet->root = NULL;
    addDifference(set1->root, set2, differenceSet);
    return differenceSet;
}