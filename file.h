#include "queue.h"
#ifndef FILE_H
#define FILE_H
int intFromSubstring(char *string, int start);
int **getRowsAndColumns(char *fileName);
char **getBodyParts(char *fileName);
void freeRowsAndColumns(int **rowsAndColumns);
char **getSnakeBodyParts(int snakeSize, char *fileName);
void freeSnakeBodyParts(char **snakeBody, int snakeSize);
void queueCordsFromFile(Queue *queue, char *fileName);
#endif