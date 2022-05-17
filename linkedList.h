#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct LinkedListNode
{
    int **data;
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
} Node;
typedef struct LinkedList
{
    Node *head;
    Node *tail;
} List;
Node *createNode(int x, int y);
List *createList();
void setHead(List *list, Node *node);
void setNext(Node *node, Node *next);
void setPrev(Node *node, Node *prev);
void setTail(List *list, Node *node);
Node *getNext(Node *node);
void freeNode(Node *node);
void freeAllNodes(Node *node);
void freeList(List *list);
Node *getTail(List *list);
Node *getHead(List *list);
Node *getPrev(Node *node);
Node *getNext(Node *node);
#endif