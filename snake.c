#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include "game.h"
#include "queue.h"
#include "linkedList.h"
#include "file.h"

/*Creates a snake as #-> with the amount of - defined by the size of the snake given by snakeSize*/
Queue *createSnake(char **board, char *fileName)
{
    Queue *snake = createQueue();
    char **snakeBody = getSnakeBodyParts(snake->size, fileName);
    int i;
    Node *position = snake->queue->head;
    queueCordsFromFile(snake, fileName);

    for (i = 0; i < snake->size; i++)
    {
        int x = *position->data[0];
        int y = *position->data[1];
        board[y][x] = *snakeBody[i];
        position = position->next;
    }
    freeSnakeBodyParts(snakeBody, snake->size);
    return snake;
}

int moveSnake(Queue *snake, char **board, int direction, int rows, int cols)
{
    int status;
    /*The tail is actually the head of the linked list as it needs to be removed first*/
    /*The head is the tail of the linked list as it needs to be removed last*/
    Node *tail = getHead(snake->queue);
    Node *head = getTail(snake->queue);
    int headX = *head->data[0];
    int headY = *head->data[1];
    int tailX = *tail->data[0];
    int tailY = *tail->data[1];
    int newTailX = *getNext(tail)->data[0];
    int newTailY = *getNext(tail)->data[1];
    status = checkLoss(headX, headY, board, rows, cols, snake, direction);
    if (status != 0)
    {
        placeBodyBehindHead(board, headX, headY, direction);
        switch (direction)
        {
        case 1:
            headY--;
            break;
        case 2:
            headX++;
            break;
        case 3:
            headY++;
            break;
        case 4:
            headX--;
            break;
        }

        board[tailY][tailX] = ' ';
        board[newTailY][newTailX] = '#';
        if (fruitCollected(board, headX, headY) == 1)
        {
            status = 2;
        }
        enqueue(snake, headX, headY);
        board[headY][headX] = getHeadDirection(direction);
        dequeue(snake);
    }
    return status;
}

void growSnake(Queue *snake, char **board, int direction)
{
    int i = 0;
    int headX = *getTail(snake->queue)->data[0];
    int headY = *getTail(snake->queue)->data[1];
    int status = 0;
    status = checkMoveIsLegal(direction, board, headX, headY, snake);
    while (status == 0)
    {
        status = checkMoveIsLegal(i, board, headX, headY, snake);
        i += 1;
    }
}

int checkMoveIsLegal(int i, char **board, int headX, int headY, Queue *snake)
{
    int status = 0;
    switch (i)
    {
    case 1:
        if (board[headY - 1][headX] == ' ')
        {
            enqueue(snake, headX, headY - 1);
            board[headY - 1][headX] = getHeadDirection(i);
            board[headY][headX] = '|';
            status = 1;
        }
        break;
    case 2:
        if (board[headY][headX + 1] == ' ')
        {
            enqueue(snake, headX + 1, headY);
            board[headY][headX + 1] = getHeadDirection(i);
            board[headY][headX] = '-';
            status = 1;
        }
        break;
    case 3:
        if (board[headY + 1][headX] == ' ')
        {
            enqueue(snake, headX, headY + 1);
            board[headY + 1][headX] = getHeadDirection(i);
            board[headY][headX] = '|';
            status = 1;
        }
        break;
    case 4:
        if (board[headY][headX - 1] == ' ')
        {
            enqueue(snake, headX - 1, headY);
            board[headY][headX - 1] = getHeadDirection(i);
            board[headY][headX] = '-';
            status = 1;
        }
        break;
    default:
        break;
    }
    return status;
}

void placeBodyBehindHead(char **board, int x, int y, int direction)
{
    switch (direction)
    {
    case 1:
        board[y][x] = '|';
        break;
    case 2:
        board[y][x] = '-';
        break;
    case 3:
        board[y][x] = '|';
        break;
    case 4:
        board[y][x] = '-';
        break;
    default:
        break;
    }
}

int checkLoss(int x, int y, char **board, int rows, int cols, Queue *snake, int direction)
{
    int newX = x;
    int newY = y;
    int status = 1;
    switch (direction)
    {
    case 1:
        newY--;
        break;
    case 2:
        newX++;
        break;
    case 3:
        newY++;
        break;
    case 4:
        newX--;
        break;
    }
    if ((newX < 1 || newX >= cols - 1 || newY < 1 || newY >= rows - 1 || board[newY][newX] != ' ') && board[newY][newX] != '&')
    {

        Node *head = getTail(snake->queue);
        Node *next = getPrev(head);
        int previousPositionX = *next->data[0];
        int previousPositionY = *next->data[1];
        /*If the new co-ordinate is the border or is backwards don't move the snake and fire a warning message*/
        if (previousPositionX == newX && previousPositionY == newY)
        {
            printf("You can't move backwards!\n");
            awaitingInput();
        }
        if (newX < 1 || newX >= cols - 1 || newY < 1 || newY >= rows - 1)
        {
            printf("Cannot escape the map\n");
            awaitingInput();
        }
        /*If it's not unbeatable then end the game*/
        if (UNBEATABLE != 1)
        {
            printf("Game over!\n");
            status = 0;
        }
    }
    else if (board[newY][newX] == '&')
    {
        status = 2;
    }
    return status;
}

int fruitCollected(char **board, int headX, int headY)
{
    int status = 0;
    if (board[headY][headX] == '&')
    {
        status = 1;
    }
    return status;
}
/*Return a character for the head based on what direction the snake is moving ^ or < or > or v*/
char getHeadDirection(int direction)
{
    char head = ' ';
    switch (direction)
    {
    case 1:
        head = '^';
        break;
    case 2:
        head = '>';
        break;
    case 3:
        head = 'v';
        break;
    case 4:
        head = '<';
        break;
    default:
        head = ' ';
        break;
    }
    return head;
}
