#include "linkedList.h"
#ifndef QUEUE_H
#define QUEUE_H
typedef struct Queue
{
    List *queue;
    int size;
} Queue;
Queue *createQueue();
void enqueue(Queue *queue, int x, int y);
void dequeue(Queue *queue);
void printQueue(Queue *queue);
void freeQueue(Queue *queue);
Node *peekFirst(Queue *queue);
Node *peekLast(Queue *queue);
#endif