#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef int QuickSortType;
int swapsQuickSort = 0;
int swapsBubbleSort = 0;
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partitionArray(int arr[], int low, int high) {
    
    int pivot = arr[high];
    
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            swapsQuickSort++;
        }
    }
    
    swap(&arr[i + 1], &arr[high]);  
    swapsQuickSort++;
    return i + 1;
}

void quickSortArray(QuickSortType* array, int low, int high){
    if(low < high){
        int partitionIndex = partitionArray(array, low, high);
        quickSortArray(array, low, partitionIndex - 1);
        quickSortArray(array, partitionIndex + 1, high);
    }
}

void quickSortListValues(LinkedListNode** head){
    if(*head == NULL || (*head)->next == NULL) return;

    LinkedListNode* pivot = *head;
    LinkedListNode* current = (*head)->next;
    LinkedListNode* left = NULL;
    LinkedListNode* right = NULL;

    while(current != NULL){
        if(current->value < pivot->value){
            pushBack(&left, current->value);
        }
        else {
            pushBack(&right, current->value);
        }
        current = current->next;
    }

    quickSortListValues(&left);
    quickSortListValues(&right);

    if(left != NULL){
        *head = left;
        LinkedListNode* tail = left;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = pivot;
    }
    else {
        *head = pivot;
    }
    pivot->next = right;
}
void quickSortListNodes(LinkedListNode** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    LinkedListNode* pivot = *head;
    LinkedListNode* current = pivot->next;
    pivot->next = NULL;
    LinkedListNode* left = NULL;
    LinkedListNode* right = NULL;

    while (current != NULL) {
        LinkedListNode* next = current->next;
        if (current->value < pivot->value){
            current->next= left;
            left = current;
        }
        else{
            current->next = right;
            right = current;
        }
        current = next;
    }

    quickSortListNodes(&left);
    quickSortListNodes(&right);

    if (left != NULL){
        *head = left;
        LinkedListNode* tail = left;
        while (tail->next != NULL){
            tail = tail->next;
        }
        tail->next = pivot;
    }
    else{
        *head = pivot;
    }
    pivot->next = right;

    
}
void bubbleSortArray(QuickSortType* array, unsigned int size){
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapsBubbleSort++;
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main(){
    printf("Using quicksort (high pivot):\n");
//Quicksort array
    QuickSortType arr1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Unsorted array (Random):\n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    quickSortArray(arr1, 0, n1 - 1);
    printf("Sorted array (from random):\n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nNumber of swaps: %d\n\n", swapsQuickSort);

    swapsQuickSort = 0;
    QuickSortType arr2[] = {1, 5, 7, 8, 9, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Already sorted array:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    quickSortArray(arr2, 0, n2 - 1);
    printf("Sorted array (from sorted input):\n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\nNumber of swaps: %d\n\n", swapsQuickSort);

    swapsQuickSort = 0;
    QuickSortType arr3[] = {10, 9, 8, 7, 5, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Reverse sorted array:\n");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    quickSortArray(arr3, 0, n3 - 1);
    printf("Sorted array (from reverse sorted input):\n");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\nNumber of swaps: %d\n\n", swapsQuickSort);

//Bubble sort
    printf("Using bubble sort (random array):\n");
    QuickSortType arr4[] = {10, 7, 8, 9, 1, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    bubbleSortArray(arr4, n4);
    printf("Sorted array:\n");
    for (int i = 0; i < n4; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\nNumber of swaps: %d\n\n", swapsBubbleSort);

    swapsBubbleSort = 0;
    printf("Using bubble sort (already sorted array):\n");
    QuickSortType arr5[] = {1, 5, 7, 8, 9, 10};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    bubbleSortArray(arr5, n5);
    printf("Sorted array (from sorted input):\n");
    for (int i = 0; i < n5; i++) {
        printf("%d ", arr5[i]);
    }
    printf("\nNumber of swaps: %d\n\n", swapsBubbleSort);

    swapsBubbleSort = 0;
    printf("Using bubble sort (reverse sorted array):\n");
    QuickSortType arr6[] = {10, 9, 8, 7, 5, 1};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    bubbleSortArray(arr6, n6);
    printf("Sorted array (from reverse sorted input):\n");
    for (int i = 0; i < n6; i++) {
        printf("%d ", arr6[i]);
    }
    printf("\nNumber of swaps: %d\n\n", swapsBubbleSort);
//Quicksort linked list
    LinkedListNode* list = NULL;
    pushBack(&list, 10);
    pushBack(&list, 7);
    pushBack(&list, 8);
    pushBack(&list, 9);
    pushBack(&list, 1);
    pushBack(&list, 5);
    printf("Unsorted linked list: \n");
    LinkedListNode* current = list;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
    quickSortListValues(&list);
    printf("Sorted linked list (Values): \n");
    current = list;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n\n");
    clear(&list);

    LinkedListNode* list2 = NULL;
    pushBack(&list2, 10);
    pushBack(&list2, 7);
    pushBack(&list2, 8);
    pushBack(&list2, 9);
    pushBack(&list2, 1);
    pushBack(&list2, 5);
    printf("Unsorted linked list: \n");
    current = list2;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
    quickSortListNodes(&list2);
    printf("Sorted linked list (Nodes): \n");
    current = list2;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
    clear(&list2);

    return 0;
}