#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedListNode
{
    int **data;
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
} Node;

Node *createNode(int x, int y)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = (int **)malloc(sizeof(int *) * 2);
    node->data[0] = (int *)malloc(sizeof(int));
    node->data[1] = (int *)malloc(sizeof(int));
    *node->data[0] = x;
    *node->data[1] = y;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

typedef struct LinkedList
{
    Node *head;
    Node *tail;
} List;

List *createList()
{
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void setHead(List *list, Node *node)
{

    list->head = node;
}

void setTail(List *list, Node *node)
{

    list->tail = node;
}

Node *getTail(List *list)
{
    return list->tail;
}

Node *getHead(List *list)
{
    return list->head;
}

Node *getNext(Node *node)
{
    return node->next;
}

Node *getPrev(Node *node)
{
    return node->prev;
}

void setNext(Node *node, Node *node2)
{
    node->next = node2;
}

void setPrev(Node *node, Node *node2)
{
    node->prev = node2;
}

void freeNode(Node *node)
{
    /* printf("freeing node\n");*/
    /* printf("%d %d\n", *node->data[0], *node->data[1]);*/
    free(node->data[1]);
    free(node->data[0]);
    free(node->data);
    free(node);
}

void freeAllNodes(Node *node)
{
    if (node->next != NULL)
    {
        if (node->next->next != NULL)
        {
            freeAllNodes(node->next);
        }
        else
        {
            freeNode(node->next);
        }
    }
    freeNode(node);
    return;
}
void freeList(List *list)
{
    if (list->head->next == NULL)
    {
        freeNode(list->head);
    }
    else if (list->tail->prev == list->head)
    {
        freeNode(list->tail);
        freeNode(list->head);
    }
    else
    {
        freeAllNodes(list->head);
    }
    free(list);
}