#include <stdio.h>

int areAnagrams(const char* str1, const char* str2, int length1, int length2) {
    int count[256] = {0};
    int i;

    for (i = 0; str1[i] && str2[i]; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    if (length1 != length2) {
        return 0;
    }

    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}
int main() {
    const char* str1 = "anagram";
    const char* str2 = "nagaram";
    int length1 = 6;
    int length2 = 6;

    if (areAnagrams(str1, str2, length1, length2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
