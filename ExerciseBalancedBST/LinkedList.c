#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

LinkedListNode* getNode(LinkedListNode* head, unsigned int index){
    LinkedListNode* current = head;
    unsigned int count = 0;
    while(current != NULL){
        if(count == index){
            return current;
        }
        count++;
        current = current->next;
    }
    fprintf(stderr, "Index out of bounds\n");
    exit(0);
}

LinkedListElementType getValueAt(LinkedListNode* head, unsigned int index){
    LinkedListNode* current = head;
    unsigned int count = 0;
    while(current != NULL){
        if(count == index){
            return current->value;
        }
        count++;
        current = current->next;
    }
    fprintf(stderr, "Index out of bounds\n");
    exit(0);
}

void setValueAt(LinkedListNode* head, unsigned int index, LinkedListElementType value){
    LinkedListNode* current = head;
    unsigned int count = 0;
    while(current != NULL){
        if(count == index){
            current->value = value;
            return;
        }
        count++;
        current = current->next;
    }
    fprintf(stderr, "Index out of bounds\n");
    exit(0);
}
void pushFront(LinkedListNode** head, LinkedListElementType value){
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if(!newNode){
        fprintf(stderr, "Memory allocation failed\n");
        exit(0);
    }
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}
void pushBack(LinkedListNode** head, LinkedListElementType value){
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if(!newNode){
        fprintf(stderr, "Memory allocation failed\n");
        exit(0);
    }
    newNode->value = value;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    LinkedListNode* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}
void popFront(LinkedListNode** head){
    if(*head == NULL){
        return;
    }
    LinkedListNode* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void popBack(LinkedListNode** head){
    if(*head == NULL){
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    LinkedListNode* current = *head;
    while(current->next->next != NULL){
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}
unsigned int getSize(LinkedListNode* head){
    unsigned int count = 0;
    LinkedListNode* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}
void clear(LinkedListNode** head){
    LinkedListNode* current = *head;
    LinkedListNode* next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
void bubbleSort(LinkedListNode** head){
    if(*head == NULL) return;
    int swapped;
    LinkedListNode* ptr1;
    LinkedListNode* lptr = NULL;
    do{
        swapped = 0;
        ptr1 = *head;
        while(ptr1->next != lptr){
            if(ptr1->value > ptr1->next->value){
                LinkedListElementType temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }while(swapped);
}