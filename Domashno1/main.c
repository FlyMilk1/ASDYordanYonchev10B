#include "LinkedList.h"
#include <stdio.h>
#include <stdbool.h>
typedef int ElementType;
ElementType binarySearch(ElementType* array, unsigned int size, ElementType element){
    int half = size/2;
    if(array[half] == element) return 1;
    else if (size <= 1){
        return 0;
    }
    else if(array[half] > element){
        return binarySearch(array, size/2, element);
    }
    else {
        return binarySearch(array+half+1, size/2, element);
    }
}

void bubbleSortValues(LinkedListNode* head){
    int i, j;
    bool swapped;
    unsigned int n = getSize(head);
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (getValueAt(head, j) > getValueAt(head, j + 1)) {
                int temp = getValueAt(head, j);
                setValueAt(head, j, getValueAt(head, j + 1));
                setValueAt(head, j + 1, temp);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void bubbleSortNodes(LinkedListNode** head){
    int i, j;
    bool swapped;
    unsigned int n = getSize(*head);
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        LinkedListNode* current = *head;
        LinkedListNode* previous = NULL;
        for (j = 0; j < n - i - 1; j++) {
            if (current == NULL || current->next == NULL) {
                break;
            }
            if (current->value > current->next->value) {
                LinkedListNode* node0 = current;
                LinkedListNode* node1 = current->next;
                if(previous){
                    previous->next = node1;
                }
                else {
                    *head = node1;
                }
                node0->next = node1->next;
                node1->next = node0;
                swapped = true;
                previous = node1;
            } else {
                previous = current;
                current = current->next;
            }
        }

        if (swapped == false)
            break;
    }
}

int main(){
    int exampleArray[] = {2, 3, 5, 6, 8, 9};
    unsigned int exampleArrSize = sizeof(exampleArray)/sizeof(exampleArray[0]);
    int wantedValues[] = {8, 7, 2};
    printf("Searching for \%d\n", wantedValues[0]);
    if(binarySearch(exampleArray, exampleArrSize, wantedValues[0])){
        printf("Found \%d\n", wantedValues[0]);
    }
    else {
        printf("Did not find \%d\n", wantedValues[0]);
    }
    printf("Searching for \%d\n", wantedValues[1]);
    if(binarySearch(exampleArray, exampleArrSize, wantedValues[1])){
        printf("Found \%d\n", wantedValues[1]);
    }
    else {
        printf("Did not find \%d\n", wantedValues[1]);
    }
    printf("Searching for \%d\n", wantedValues[2]);
    if(binarySearch(exampleArray, exampleArrSize, wantedValues[2])){
        printf("Found \%d\n", wantedValues[2]);
    }
    else {
        printf("Did not find \%d\n", wantedValues[2]);
    }

    LinkedListNode* list = NULL;
    pushBack(&list, 5);
    pushBack(&list, 3);
    pushBack(&list, 8);
    pushBack(&list, 1);
    pushBack(&list, 4);
    printf("Original list:\n");
    for(unsigned int i = 0; i < getSize(list); i++){
        printf("%d ", getValueAt(list, i));
    }
    printf("\n");
    bubbleSortValues(list);
    printf("List sorted by values:\n");
    for(unsigned int i = 0; i < getSize(list); i++){
        printf("%d ", getValueAt(list, i));
    }
    printf("\n");
    clear(&list);
    pushBack(&list, 5);
    pushBack(&list, 3);
    pushBack(&list, 8);
    pushBack(&list, 1);
    pushBack(&list, 4);
    printf("Original list:\n");
    for(unsigned int i = 0; i < getSize(list); i++){
        printf("%d ", getValueAt(list, i));
    }
    printf("\n");
    bubbleSortNodes(&list);
    printf("List sorted by nodes:\n");
    for(unsigned int i = 0; i < getSize(list); i++){
        printf("%d ", getValueAt(list, i));
    }
    printf("\n");
    clear(&list); 
    return 0;
}