// n - strsSize
// L - average length of string
// O(n^2 * L)
// Θ(n^2 * L)
// Ω(n * L)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int areAnagrams(const char* str1, const char* str2, int length1, int length2) {
    if (length1 != length2) return 0;

    int count[256] = {0};
    for (int i = 0; i < length1; i++) {
        unsigned char a = (unsigned char)str1[i];
        unsigned char b = (unsigned char)str2[i];
        count[a]++;
        count[b]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return 0;
    }

    return 1;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    int* groupSizes = (int*)calloc(strsSize, sizeof(int));
    *returnSize = 0;

    int* used = (int*)calloc(strsSize, sizeof(int));

    for (int i = 0; i < strsSize; i++) {
        if (used[i]) continue;

        used[i] = 1;
        result[*returnSize] = (char**)malloc(strsSize * sizeof(char*));
        result[*returnSize][groupSizes[*returnSize]++] = strs[i];

        for (int j = i + 1; j < strsSize; j++) {
            if (!used[j] && areAnagrams(strs[i], strs[j], (int)strlen(strs[i]), (int)strlen(strs[j]))) {
                result[*returnSize][groupSizes[*returnSize]++] = strs[j];
                used[j] = 1;
            }
        }

        (*returnColumnSizes)[*returnSize] = groupSizes[*returnSize];
        (*returnSize)++;
    }

    free(used);
    free(groupSizes);
    return result;
}
int main() {
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;

    char*** groupedAnagrams = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", groupedAnagrams[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(groupedAnagrams[i]);
    }
    free(groupedAnagrams);
    free(returnColumnSizes);

    return 0;
}
