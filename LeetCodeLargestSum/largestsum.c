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

int getLargestSum(int* arr, int arrSize, int k) {
    bubbleSort(arr, arrSize);
    int sum = 0;
    for(int index=arrSize-1; index >= arrSize-k; index--){
        sum +=  arr[index];
    }
    return sum;
}
int main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = getLargestSum(arr, n, k);
    printf("Sum of the largest %d elements is: %d\n", k, result);
    return 0;
}
