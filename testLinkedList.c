#include "myLinkedList.h"
#include <stdio.h>
int main() {
    struct myLinkedList *l = NULL;
    myInitLinkedList(&l);
    for(int n=0; n<10; n++) {
        myLinkedListInsertTailNodes(&l,(void *)&n, sizeof(n));
    }
    int returnSize = 0;
    myLinkedListDeleteNodes(&l, 6);
    int * array = myLinkedListTraversal(&l, sizeof(int), &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("the value of the node %d is %d\n", i+1, array[i]);
    }
    printf("the value of the first node is %d\n", *(int *)l->head->next->val);
    printf("this linked list's length is %d\n", l->length);
    return 0;
}