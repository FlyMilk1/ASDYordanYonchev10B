#include <stdio.h>
void bubbleSort(int* arr, int n) {
    int i, j;
    int temp;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        if (swapped == 0)
            break;
    }
}
int findContentChildren(int* g, int gSize, int* s, int sSize){
    bubbleSort(g, gSize);
    bubbleSort(s, sSize);
    int childIndex = 0;
    int cookieIndex = 0;
    while(childIndex < gSize && cookieIndex < sSize){
        if(s[cookieIndex] >= g[childIndex]){
            childIndex++;
        }
        cookieIndex++;
    }
    return childIndex;
}
int main() {
    int g[] = {1, 2, 3};
    int s[] = {1, 1};
    int gSize = sizeof(g) / sizeof(g[0]);
    int sSize = sizeof(s) / sizeof(s[0]);
    int result = findContentChildren(g, gSize, s, sSize);
    printf("Number of content children: %d\n", result);
    return 0;
}