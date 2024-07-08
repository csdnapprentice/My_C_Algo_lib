#include "myStack.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * Written by HengYuan Hu 22 on April 2024
 * this function can implement the stack pop, the Time complexity is O(1)
 * this return is a pointer that point to an element.
 */
void * myStackPop(struct Stack *s){
    if(s->top > 0){
        void * x = NULL;
        x = s->item[s->top-1];
        s->item[s->top-1] = NULL;
        s->top = s->top - 1;
        return x;
    }
    return NULL;
}
/*
 * Written by HengYuan Hu 22 on April 2024
 * this function can implement the stack push, the Time complexity is O(1)
 */
void myStackPush(struct Stack *s, void * i){
    if(s->top < s->maxSize) {
        s->item[s->top] = i;
        s->top = s->top + 1;
    }else{
        printf("An error occur when want to push a element to stack! the reason is the stack is full!");
    }
}
/*
 * Written by HengYuan Hu 22 on April 2024
 * this function can implement stack clear,the Time complexity is O(1)
 */
void myStackClear(struct Stack *s){
    for(int i=0; i < s->top; i++){
        free(s->item[i]);
        s->item[i] = NULL;
    }
    s->top = 0;
}
/*
 * Written by HengYuan Hu on April 22, 2024.
 * this function is used to init a stack.
 */
void myStackInit(struct  Stack *s, int maxSize){
    s->item = malloc(sizeof(void *)*maxSize);
    for(int i=0; i<maxSize; i++){
        s->item[i] = NULL;
    }
    s->top = 0;
    s->maxSize = maxSize;
}
/*
 * Written by HengYuan Hu on April 23, 2024.
 * This function can change the maximum size of a stack, making it very simple to implement certain operations.
 * This function's time complexity depends on the size of the stack content.
 * So it's time complexity is O(n), n is the size of the stack content.
 */
int myStackChangeSize(struct Stack *s, int maxSize){
    if(maxSize < (s->top)){ //Cannot change Stack Max Size because this operation will lose data.
        return 0;
    }
    void ** temp = (void **)malloc(sizeof(void *)*maxSize);
    if(s->top != 0){
        for(int i = 0; i < s->top; i++){
            temp[i] = s->item[i];
        }
    }
    free(s->item);
    s->item = temp;
    return 1;
}
/*
 * Written by HengYuan Hu on April 24, 2024.
 * This function returns the length of the Stack as a number.
 * The time complexity is O(1).
 */
int myStackLength(struct Stack const*s){
    return s->top;
}
