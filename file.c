#include <stdlib.h>
#include <stdio.h>
#include "file.h"
#include "queue.h"
/*Get rows of columns from the first line of snake.txt and return them as a int array*/
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
/*Converts a substring of double digits into a single integer*/
/*Is not applicable to 3 digit strings as it is hard coded to double digits*/
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
/*Create a string with each char index being a snake body part from the input file snake.txt*/
void getSnakeBodyParts(char *snakeBody, int snakeSize, char *fileName)
{
    FILE *file = fopen(fileName, "r");
    /*In this instance the string is 7 characters long to include the "\n" line character*/
    char *tempString = (char *)malloc(sizeof(char) * 7);
    int i;
    /*Skip row/cols line*/
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
    /*In this instance the string is 6 characters long as the "\n" character will get popped off by the while loop condition*/
    char *tempString = (char *)malloc(sizeof(char) * 6);
    int x;
    int y;
    int c;
    /*Skip rows/cols line*/
    fgets(tempString, 6, file);
    while ((c = fgetc(file)) != EOF)
    {
        fgets(tempString, 6, file);
        /*X and Y are assumed to always be single digits to convert to ints*/
        x = tempString[2] - '0' + 1;
        y = tempString[0] - '0' + 1;
        enqueue(queue, x, y);
    }
    free(tempString);
    fclose(file);
}
/*Free the snakeBody string from memory*/
void freeSnakeBodyParts(char *snakeBody, int snakeSize)
{
    free(snakeBody);
}
/*Free rows and columns from memory*/
void freeRowsAndColumns(int **rowsAndColumns)
{
    free(rowsAndColumns[0]);
    free(rowsAndColumns[1]);
    free(rowsAndColumns);
}