#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedListNode
{
    /* While there was eventually an email that clarified that these nodes are meant to have void pointers it was released too late for me to change my code and hence this remains non generic */
    int **data;
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
} Node;

/*Creates a node with empty data to be initialised with values later*/
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
/*Creates a list with empty pointers to be initialised later*/
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
/*Frees all data from a node*/
void freeNode(Node *node)
{
    free(node->data[1]);
    free(node->data[0]);
    free(node->data);
    free(node);
}
/*Loop through the list and free each node one by one from memory*/
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
}
/*Free both or one of the two head and tail pointers in the list and the list itself from memory*/
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