#include "queue.h"
#ifndef SNAKE_H
#define SNAKE_H
Queue *createSnake(char **board, char *fileName);
char getHeadDirection(int direction);
int moveSnake(Queue *snake, char **board, int direction, int rows, int cols);
void placeBodyBehindHead(char **board, int x, int y, int direction);
int checkLoss(int newX, int newY, char **board, int rows, int cols, Queue *snake, int direction);
void getNewCords(int direction, int *x, int *y);
int fruitCollected(char **board, int headX, int headY);
void growSnake(Queue *snake, char **board, int direction);
int checkMoveIsLegal(int i, char **board, int headX, int headY, Queue *snake);
#endif
#ifdef UNBEATABLE
#define UNBEATABLE 1
#else
#define UNBEATABLE 0
#endif