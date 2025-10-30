#include <stdio.h>
enum Color { RED = 0, WHITE = 1, BLUE = 2 };
void sortColors(int* arr, int n) {
    int redCount = 0, whiteCount = 0, blueCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == RED) {
            redCount++;
        } else if (arr[i] == WHITE) {
            whiteCount++;
        } else if (arr[i] == BLUE) {
            blueCount++;
        }
    }
    int index = 0;
    for (int i = 0; i < redCount; i++) {
        arr[index++] = RED;
    }
    for (int i = 0; i < whiteCount; i++) {
        arr[index++] = WHITE;
    }
    for (int i = 0; i < blueCount; i++) {
        arr[index++] = BLUE;
    }
}
int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortColors(arr, n);
    printf("Sorted colors: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}