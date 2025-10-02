#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef int LinkedListElementType;
typedef struct LinkedListNode{
    struct LinkedListNode* next;
    LinkedListElementType value;
} LinkedListNode;

struct LinkedListNode* getNode(struct LinkedListNode* head, unsigned int index);
LinkedListElementType getValueAt(struct LinkedListNode* head, unsigned int index);
void setValueAt(struct LinkedListNode* head, unsigned int index, LinkedListElementType value);
void pushFront(struct LinkedListNode** head, LinkedListElementType value);
void pushBack(struct LinkedListNode** head, LinkedListElementType value);
void popFront(struct LinkedListNode** head);
void popBack(struct LinkedListNode** head);
unsigned int getSize(struct LinkedListNode* head);
void clear(struct LinkedListNode** head);
#endif