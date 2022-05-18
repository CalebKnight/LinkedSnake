#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "board.h"
#include "terminal.h"
#include "game.h"
#include "queue.h"
#include "file.h"
int main(int argc, char const *argv[])
{

    /* code */

    int rows;
    int cols;
    int fruitToWin;
    char **board;
    int **rowsAndColumns;
    if (argc == 2)
    {
        fruitToWin = atoi(argv[1]);
    }
    else
    {
        printf("Please enter the number of fruits to win\n");
        return 0;
    }
    /* If the arguments are entered incorrectly tells the user the correct syntax so they can type it in again*/

    rowsAndColumns = getRowsAndColumns("snake.txt");
    rows = *rowsAndColumns[0];
    cols = *rowsAndColumns[1];

    /*Initialise board with height of rows and width of columns*/

    board = initBoard(rows, cols);
    initRandom();
    /*This Loop calls all the functions related to generation of the snake and it's movement in a seperate file for readability in main*/
    RunInputLoop(board, rows, cols, fruitToWin, "snake.txt");
    freeRowsAndColumns(rowsAndColumns);
    return 0;
}
