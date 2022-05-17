#include <stdlib.h>
#include <stdio.h>
#include "file.h"
#include "queue.h"

int **getRowsAndColumns(char *fileName)
{

    char *string = (char *)malloc(sizeof(char) * 6);
    int **rowsAndColumns = (int **)malloc(2 * sizeof(int *));
    FILE *file = fopen(fileName, "r");
    rowsAndColumns[0] = (int *)malloc(sizeof(int));
    rowsAndColumns[1] = (int *)malloc(sizeof(int));
    string = fgets(string, 6, file);
    *rowsAndColumns[0] = intFromSubstring(string, 0);
    *rowsAndColumns[1] = intFromSubstring(string, 3);
    printf("%d %d rows/cols", *rowsAndColumns[0], *rowsAndColumns[1]);
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

char **getSnakeBodyParts(int snakeSize, char *fileName)
{
    char **snakeBody = (char **)malloc(sizeof(char *) * snakeSize);
    char *tempString = (char *)malloc(sizeof(char) * 6);
    FILE *file = fopen(fileName, "r");
    int i;
    for (i = 0; i < snakeSize; i++)
    {
        snakeBody[i] = (char *)malloc(sizeof(char));
    }
    fgets(tempString, 6, file);
    fprintf(stderr, "%sTHIS", tempString);

    i = 0;
    while (!feof(file))
    {
        char *string = (char *)malloc(sizeof(char) * 6);
        fgets(string, 6, file);
        *snakeBody[i] = string[5];
        i += 1;
        free(string);
    }
    free(tempString);
    fclose(file);
    return (snakeBody);
}

void queueCordsFromFile(Queue *queue, char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *tempString = (char *)malloc(sizeof(char) * 4);
    int x;
    int y;
    /* Skip first line*/
    fgets(tempString, 4, file);
    while (!feof(file))
    {
        char *cords = (char *)malloc(sizeof(char) * 4);
        fgets(cords, 4, file);
        x = cords[0] - '0';
        y = cords[2] - '0';

        enqueue(queue, x, y);
        free(cords);
    }
    free(tempString);
    fclose(file);
}

void freeSnakeBodyParts(char **snakeBody, int snakeSize)
{
    int i;
    for (i = 0; i < snakeSize; i++)
    {
        free(snakeBody[i]);
    }
    free(snakeBody);
}

void freeRowsAndColumns(int **rowsAndColumns)
{
    free(rowsAndColumns[0]);
    free(rowsAndColumns[1]);
    free(rowsAndColumns);
}