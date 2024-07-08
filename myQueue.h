#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <stddef.h>

struct Queue{
    void ** item;
    int front;
    int rear;
    int maxSize;
};
void *myDeQueue(struct Queue *q);
int myEnQueue(struct Queue *q, void *i, size_t elementSize, int copy);
void myQueueClear(struct Queue *q, int copy);
int myQueueInit(struct Queue *q, int maxSize);
int myQueueChangeSize(struct Queue *q, int maxSize);
int myQueueLength(struct Queue const *q);
int myQueueEmpty(struct Queue const* q);
int myQueueFull(struct Queue const* q);
#endif //MYQUEUE_H
