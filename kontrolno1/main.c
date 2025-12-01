#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct SkipListNode{
    int key;
    struct SkipListNode** forwardPointers;
    int nodeLevel;
}SkipListNode;
//Linked List
typedef SkipListNode* LinkedListElementType;
typedef struct LinkedListNode{
    struct LinkedListNode* next;
    LinkedListElementType value;
} LinkedListNode;
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


//Skip List
typedef struct SkipList{
    LinkedListNode** header;
    int levels;
}SkipList;
void createSkipList(SkipList* list){
    list->levels = rand() % 100 + 1;
    list->header = malloc(list->levels * sizeof(LinkedListNode*));
    if(!list->header){
        fprintf(stderr, "Memory allocation failed\n");
        exit(0);
    }
    for(int i = 0; i < list->levels; i++){
        list->header[i] = NULL;
    }
}
SkipListNode* createSkipNode(SkipList* list, int key, int minLevel){
    SkipListNode* newNode = malloc(sizeof(SkipListNode));
    if(!newNode){
        fprintf(stderr, "Memory allocation failed\n");
        exit(0);
    }
    newNode->key = key;
    int levels = rand() % list->levels + minLevel;
    if(levels <= 0) levels = 1;
    newNode->nodeLevel = levels;
    newNode->forwardPointers = malloc(levels * sizeof(struct SkipListNode*));
    if(!newNode->forwardPointers){
        fprintf(stderr, "Memory allocation failed\n");
        free(newNode);
        exit(0);
    }
    for(int i = 0; i < levels; i++){
        newNode->forwardPointers[i] = NULL;
    }
    return newNode;
}

void insert_key(SkipList* list, int key){
   SkipListNode* newNode = createSkipNode(list, key, 0);
   for(int listIndex = 0; listIndex < newNode->nodeLevel && listIndex < list->levels; listIndex++){
        pushFront(&list->header[listIndex], newNode);
   }
}
void delete_key(SkipList* list, int key){
    
}
int search_key(SkipList* list, int key){
    int curLevel = list->levels;
    for(int lvl = curLevel - 1; lvl >= 0; lvl--){
        LinkedListNode* listAtLevel = list->header[lvl];
        int sizeOfLvlList = getSize(listAtLevel);
        for(int i = 0; i < sizeOfLvlList; i++){
            int curKey = getValueAt(listAtLevel, i)->key;
            if(curKey == key){
                return 1;
            }
        }
    }
    return 0;
}
void print_keys(SkipList* list){
    if(!list) return;
    if(list->levels <= 0) return;
    LinkedListNode* lvl0 = list->header[0];
    int size = getSize(lvl0);
    for(int i = 0; i < size; i++){
        printf("%d ", getValueAt(lvl0, i)->key);
    }
    printf("\n");
}
int main(){
    SkipList* list;
    createSkipList(list);
    for(int i=0; i<50; i++){
        insert_key(list, i);
    }

    print_keys(list);
    int results[3];
    
    results[0] = search_key(list, 1);
    results[1] = search_key(list, 7);
    results[2] = search_key(list, 120);

    for(int i=0; i<3; i++){
        if(results[i]){
            printf("FOUND\n");
        }
        else{
            printf("NOT FOUND\n");
        }
    }

}
