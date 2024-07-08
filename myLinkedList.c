#include "myLinkedList.h"

#include <stdlib.h>
#include <string.h>
/*
 * Written by HengYuan Hu on May 15, 2024.
 * This function can initialize a linked list.
 * The parameter must be a null pointer.
 */
int myInitLinkedList(struct myLinkedList ** list) {
    *list = (struct myLinkedList *)malloc(sizeof(struct myLinkedList));
    if(*list == NULL) {
        return 0;
    }
    (*list)->head = (struct myLinkedListNode *)malloc(sizeof(struct myLinkedListNode));
    if((*list)->head == NULL) {
        free(list);
        list = NULL;
        return 0;
    }
    (*list)->head->val = NULL;
    (*list)->head->next = NULL;
    (*list)->length = 0;
    return 1;
}
/*
 * Written by HengYuan Hu on May 15, 2024.
 * This function can initialize a linked list.
 * The parameter must be a pointer.
 */
int myDestroyLinkedList(struct myLinkedList** list) {
    if(*list == NULL) {
        return 0;
    }
    struct myLinkedListNode * p = (*list)->head;
    while((*list)->head != NULL) {
        (*list)->head = (*list)->head->next;
        free(p);
        p = (*list)->head;
    }
    p = NULL;
    free(*list);
    (*list) = NULL;
    return 1;
}
/*
 * Written by HengYuan Hu on May 15, 2024.
 * This function is insert a node to a
 */
int myLinkedListInsertTailNodes(struct myLinkedList **list, const void *item, size_t elementSize){
    struct myLinkedListNode* p = (*list)->head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = (struct myLinkedListNode *)malloc(sizeof(struct myLinkedListNode));
    if(p->next == NULL) {
        free(p->next);
        p->next = NULL;
        return 0;
    }
    p->next->val = malloc(elementSize);
    if(p->next->val == NULL) {
        return 0;
    }
    memcpy(p->next->val, item, elementSize);
    p->next->next = NULL;
    (*list)->length = (*list)->length + 1;
    return 1;
}
/*
 * Written by HengYuan Hu on May 17, 2024.
 * this function can return an array that the element's val is the linked list's node value.
 * the time complexity is O(n).
 */
void * myLinkedListTraversal(struct myLinkedList ** list, size_t elementSize, int *returnSize) {
    void * array = malloc(elementSize * (*list)->length);
    if(array == NULL) {
        if(returnSize != NULL) {
            *returnSize = 0;
        }
        return 0;
    }
    struct myLinkedListNode * p = (*list)->head->next;
    int count = 0;
    while(p!=NULL) {
        memcpy(array + elementSize * count, p->val, elementSize);
        p = p->next;
        count++;
    }
    if(returnSize != NULL) {
        *returnSize = count;
    }
    return array;
}
/*
 * Written by HengYuan Hu on May 17, 2024.
 * The function deletes a node in the linked list based on the position provided by the parameter 'number'.
 */
int myLinkedListDeleteNodes(struct myLinkedList ** list, int number){
    int count = 0;
    struct myLinkedListNode * p = (*list)->head->next;
    struct myLinkedListNode *q = (*list)->head;
    while(p!=NULL) {
        if(count == number) {
            q->next = p->next;
            free(p);
            p = NULL;
            (*list)->length -= 1;
            return 1;
        }else {
            p = p->next;
            q = q->next;
            count++;
        }
    }
    return 0;

}
