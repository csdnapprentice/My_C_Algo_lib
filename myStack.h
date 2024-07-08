#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H
struct Stack{
    void ** item;
    int top;
    int maxSize;
};
void * myStackPop(struct Stack *s);
void myStackPush(struct Stack *s, void * i);
void myStackClear(struct Stack *s);
void myStackInit(struct  Stack *s, int maxSize);
int myStackChangeSize(struct Stack *s, int maxSize);
int myStackLength(struct Stack const*s);
#endif //STACK_MYSTACK_H