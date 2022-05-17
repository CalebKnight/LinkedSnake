#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

typedef struct Queue
{
    List *queue;
    int size;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->queue = createList();
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, int x, int y)
{
    Node *node = createNode(x, y);
    if (queue->size == 0)
    {
        setHead(queue->queue, node);
    }
    else
    {
        Node *tail = getTail(queue->queue);
        setNext(tail, node);
        setPrev(node, tail);
    }
    setTail(queue->queue, node);
    queue->size++;
}

void dequeue(Queue *queue)
{
    Node *head = getHead(queue->queue);
    Node *next = getNext(head);
    if (queue->size == 0)
    {
        return;
    }
    freeNode(head);
    setHead(queue->queue, next);
    queue->size--;
}

Node *peekFirst(Queue *queue)
{
    return getHead(queue->queue);
}

Node *peekLast(Queue *queue)
{
    return getTail(queue->queue);
}

void printQueue(Queue *queue)
{
    Node *node = getHead(queue->queue);
    while (node->next != NULL)
    {
        printf("%d %d\n", *node->data[0], *node->data[1]);
        node = getNext(node);
    }
    printf("%d %d\n", *node->data[0], *node->data[1]);
}
void freeQueue(Queue *queue)
{
    freeList(queue->queue);
    free(queue);
}
