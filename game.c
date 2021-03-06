#include <stdlib.h>
#include <stdio.h>
#include "random.h"
#include "board.h"
#include "snake.h"
#include "terminal.h"
#include "queue.h"
/*Takes in the direction int variable defined in main and outputs an integer based on the keyboard input for use in later functions to determine the direction of the snake.*/
void getInput(int *direction)
{
    char input;
    scanf("%c", &input);
    switch (input)
    {
    case 'w':
        *direction = 1;
        break;
    case 'd':
        *direction = 2;
        break;
    case 's':
        *direction = 3;
        break;
    case 'a':
        *direction = 4;
        break;
    default:
        *direction = 0;
        break;
    }
}
/*Because of how the board clearing works the user needs to be verified as having read the message before continuing the loop*/
/*This function is utilised to stop the program until this verification occurs*/
void awaitingInput()
{
    char input = ' ';
    while (input == ' ')
    {
        printf("Press any key to continue \n");
        scanf("%c", &input);
    }
}

/*A function that calls most functions defined in Snake.C to allow the snake to move*/
void RunInputLoop(char **board, int rows, int cols, int fruitToWin, char *fileName)
{
    int status = 1;
    int direction;
    int i = 0;
    Queue *snake = createSnake(board, fileName);
    printf("Welcome to the snake game\n");
    printBoard(board, rows, cols);
    placeFood(board, rows, cols);
    status = 1;
    while (status != 0 && i != fruitToWin)
    {
        system("clear");
        fflush(stdin);
        printBoard(board, rows, cols);
        printf("Food eaten %d/%d\n", i, fruitToWin);
        disableBuffer();
        getInput(&direction);
        if (direction == 0)
        {
            /*Awaits verification from user before continuing to ensure they have read the error message*/
            printf("Invalid input please use WASD\n");
            awaitingInput();
        }
        else
        {
            status = moveSnake(snake, board, direction, rows, cols);
        }
        if (status == 2)
        {
            growSnake(snake, board, direction);
            placeFood(board, rows, cols);
            i++;
        }
        enableBuffer();
    }
    if (status == 0)
    {
        printf("You lost\n");
    }
    else if (status == 2)
    {
        printf("You won\n");
    }
    i++;

    freeQueue(snake);
    freeBoard(board, rows);
}