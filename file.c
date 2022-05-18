#include <stdlib.h>
#include <stdio.h>
#include "file.h"
#include "queue.h"

int **getRowsAndColumns(char *fileName)
{

    char *string = (char *)malloc(sizeof(char) * 7);
    int **rowsAndColumns = (int **)malloc(sizeof(int *) * 2);
    FILE *file = fopen(fileName, "r");
    rowsAndColumns[0] = (int *)malloc(sizeof(int));
    rowsAndColumns[1] = (int *)malloc(sizeof(int));
    string = fgets(string, 7, file);
    *rowsAndColumns[0] = intFromSubstring(string, 0);
    *rowsAndColumns[1] = intFromSubstring(string, 3);
    fclose(file);
    free(string);

    return (rowsAndColumns);
}

int intFromSubstring(char *string, int start)
{
    int number;
    char *subString = (char *)malloc(sizeof(char) * 3);
    subString[0] = string[start];
    subString[1] = string[start + 1];
    /* Need to add a terminator to the string to prevent atoi from having a read error */
    subString[2] = '\0';
    number = atoi(subString);
    free(subString);
    return number;
}

void getSnakeBodyParts(char *snakeBody, int snakeSize, char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *tempString = (char *)malloc(sizeof(char) * 7);
    int i;
    fgets(tempString, 7, file);
    for (i = 0; i < snakeSize; i++)
    {
        fgets(tempString, 7, file);
        snakeBody[i] = tempString[4];
    }
    free(tempString);
    fclose(file);
}

void queueCordsFromFile(Queue *queue, char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *tempString = (char *)malloc(sizeof(char) * 6);
    int x;
    int y;
    int c;
    /* Skip first line*/
    fgets(tempString, 6, file);
    while ((c = fgetc(file)) != EOF)
    {
        fgets(tempString, 6, file);
        x = tempString[2] - '0' + 1;
        y = tempString[0] - '0' + 1;
        enqueue(queue, x, y);
    }
    free(tempString);
    fclose(file);
}

void freeSnakeBodyParts(char *snakeBody, int snakeSize)
{
    free(snakeBody);
}

void freeRowsAndColumns(int **rowsAndColumns)
{
    free(rowsAndColumns[0]);
    free(rowsAndColumns[1]);
    free(rowsAndColumns);
}