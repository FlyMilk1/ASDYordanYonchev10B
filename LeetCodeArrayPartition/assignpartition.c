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
int getSumOfMinPairs(int* arr, int n) {
    bubbleSort(arr, n);
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    int arr[] = {1, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = getSumOfMinPairs(arr, n);
    printf("Sum of min pairs: %d\n", result);
    return 0;
}