#include "myQueue.h"
#include <stdlib.h>
#include <string.h>
/*
 *Written by HengYuan Hu on May 6, 2024.
 */
void *myDeQueue(struct Queue *q) {
    if(myQueueEmpty(q)) {
        return NULL;
    }
    void * item = q->item[q->front];
    q->front = (q->front + 1) % q->maxSize;
    return item;
}
/*
 *Written by HengYuan Hu on May 6, 2024.
 */
int myEnQueue(struct Queue *q, void *i, size_t elementSize, int copy) {
    if(myQueueFull(q)) {
        return 0;
    }
    if(copy) {
        void * item = malloc(elementSize);
        memcpy(item, i, elementSize);
        q->item[q->rear] = item;
    }else {
        q->item[q->rear] = i;
    }
    q->rear = (q->rear + 1) % q->maxSize;
    return 1;
}
/*
 *Written by HengYuan Hu on May 6, 2024.
 */
void myQueueClear(struct Queue *q, int copy) {
    if(copy) {
        for(int i=q->rear; i%q->maxSize<q->rear; i++) {
            free(q->item[i]);
            q->item[i] = NULL;
        }
    }else {
        for(int i=q->rear; i%q->maxSize<q->rear; i++) {
            q->item[i] = NULL;
        }
    }
    q->front = 0;
    q->rear = 0;
}
/*
 *Written by HengYuan Hu on May 6, 2024.
 */
int myQueueInit(struct Queue *q, int maxSize) {
    if(maxSize < 0) {
        return 0;
    }
    q->item = (void **)malloc(sizeof(void *)*maxSize);
    if(q->item == NULL) {
        return 0;
    }
    q->front = 0;
    q->rear = 0;
    q->maxSize = maxSize;
    for(int i=0; i<maxSize; i++) {
        q->item[i] = NULL;
    }
    return 1;
}
/*
 *Written by HengYuan Hu on May 6, 2024.
 */
int myQueueChangeSize(struct Queue *q, int maxSize) {
    int length = myQueueLength(q);
    if(length >= maxSize) {
        return 0;
    }
    void ** queue = (void **)malloc(sizeof(void *)*maxSize);
    if(queue == NULL) {
        return 0;
    }
    for(int i=q->rear, j=0; i%q->maxSize<q->rear; i++, j++) {
        queue[j] = q->item[i%q->maxSize];
        free(q->item[i%q->maxSize]);
    }
    q->front = 0;
    q->rear = length;
    q->maxSize = maxSize;
    free(q->item);
    q->item = queue;
    return 1;
}
/*
 *Written by HengYuan Hu on May 6, 2024.
 */
int myQueueLength(struct Queue const *q) {
    return (q->rear - q->front + q->maxSize)%q->maxSize;
}
/*
 *Written by HengYuan Hu on May 6, 2024.
 */
int myQueueEmpty(struct Queue const* q) {
    if(q->rear == q->front) {
        return 1;
    }
    return 0;
}
/*
 *Written by HengYuan Hu on May 6, 2024.
 */
int myQueueFull(struct Queue const* q) {
    if((q->rear+1)%q->maxSize == q->front) {
        return 1;
    }
    return 0;
}