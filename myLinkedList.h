#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <stddef.h>
struct myLinkedListNode {
    void *val;
    struct myLinkedListNode * next;
};
struct myLinkedList {
    struct myLinkedListNode *head;
    int length;
};
int myInitLinkedList(struct myLinkedList ** list);
int myDestroyLinkedList(struct myLinkedList ** list);
int myLinkedListInsertTailNodes(struct myLinkedList **list, const void *item, size_t elementSize);
void * myLinkedListTraversal(struct myLinkedList ** list, size_t elementSize, int * returnSize);
int myLinkedListDeleteNodes(struct myLinkedList ** list, int number);
#endif //MYLINKEDLIST_H
