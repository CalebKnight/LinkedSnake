#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

typedef struct Queue
{
    List *queue;
    int size;
} Queue;
/*Creates an empty queue with no data to be intiialised later*/
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->queue = createList();
    queue->size = 0;
    return queue;
}
/*Add item to the back of the linked list that represents the queue*/
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
/*Remove item from front of the linked list that represents the queue*/
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

/*This function is not utilised in the actual snake game however is useful for testing and thus I have left it in*/
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

/*Frees all memory from the queue, not to be confused with the freeing of the linked list inside of the queue*/
void freeQueue(Queue *queue)
{
    freeList(queue->queue);
    free(queue);
}
