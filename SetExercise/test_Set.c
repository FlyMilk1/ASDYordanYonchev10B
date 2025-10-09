#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

Set* create_set_with_values(TreeType* values, int n) {
    Set* set = (Set*)malloc(sizeof(Set));
    set->root = NULL;
    for (int i = 0; i < n; ++i) {
        set_add(set, values[i]);
    }
    return set;
}

void test_set_add_and_contains() {
    TreeType vals[] = {5, 3, 7, 1, 4};
    Set* set = create_set_with_values(vals, 5);

    for (int i = 0; i < 5; ++i) {
        if (!set_contains(set, vals[i])) {
            printf("FAIL: set_contains missing %d\n", vals[i]);
            return;
        }
    }
    if (set_contains(set, 10)) {
        printf("FAIL: set_contains found non-existent 10\n");
        return;
    }
    printf("PASS: test_set_add_and_contains\n");
}

void test_is_subset() {
    TreeType vals1[] = {1, 2, 3};
    TreeType vals2[] = {1, 2, 3, 4, 5};
    Set* set1 = create_set_with_values(vals1, 3);
    Set* set2 = create_set_with_values(vals2, 5);

    if (!is_subset(set1, set2)) {
        printf("FAIL: set1 should be subset of set2\n");
        return;
    }
    if (is_subset(set2, set1)) {
        printf("FAIL: set2 should not be subset of set1\n");
        return;
    }
    printf("PASS: test_is_subset\n");
}

void test_set_union() {
    TreeType vals1[] = {1, 2, 3};
    TreeType vals2[] = {3, 4, 5};
    Set* set1 = create_set_with_values(vals1, 3);
    Set* set2 = create_set_with_values(vals2, 3);

    Set* u = set_union(set1, set2);
    for (int i = 1; i <= 5; ++i) {
        if (!set_contains(u, i)) {
            printf("FAIL: set_union missing %d\n", i);
            return;
        }
    }
    printf("PASS: test_set_union\n");
}

void test_set_intersection() {
    TreeType vals1[] = {1, 2, 3};
    TreeType vals2[] = {2, 3, 4};
    Set* set1 = create_set_with_values(vals1, 3);
    Set* set2 = create_set_with_values(vals2, 3);

    Set* inter = set_intersection(set1, set2);
    if (!set_contains(inter, 2) || !set_contains(inter, 3)) {
        printf("FAIL: set_intersection missing 2 or 3\n");
        return;
    }
    if (set_contains(inter, 1) || set_contains(inter, 4)) {
        printf("FAIL: set_intersection contains 1 or 4\n");
        return;
    }
    printf("PASS: test_set_intersection\n");
}

void test_set_difference() {
    TreeType vals1[] = {1, 2, 3};
    TreeType vals2[] = {2, 4};
    Set* set1 = create_set_with_values(vals1, 3);
    Set* set2 = create_set_with_values(vals2, 2);

    Set* diff = set_difference(set1, set2);
    if (!set_contains(diff, 1) || !set_contains(diff, 3)) {
        printf("FAIL: set_difference missing 1 or 3\n");
        return;
    }
    if (set_contains(diff, 2) || set_contains(diff, 4)) {
        printf("FAIL: set_difference contains 2 or 4\n");
        return;
    }
    printf("PASS: test_set_difference\n");
}

int main() {
    test_set_add_and_contains();
    test_is_subset();
    test_set_union();
    test_set_intersection();
    test_set_difference();
    return 0;
}