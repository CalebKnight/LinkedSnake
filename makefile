CC = gcc
snake: main.c random.c game.c snake.c terminal.c board.c linkedList.c queue.c file.c main.h random.h game.h snake.h terminal.h board.h linkedList.h queue.h file.h
	$(CC) -Wall -ansi -pedantic -Werror main.c random.c game.c snake.c terminal.c board.c linkedList.c queue.c file.c -o snake 
UNBEATABLE: main.c random.c game.c snake.c terminal.c board.c linkedList.c main.h random.h game.h snake.h terminal.h board.h linkedList.h
	$(CC) -Wall -ansi -pedantic -Werror main.c random.c game.c snake.c terminal.c board.c linkedList.c -D UNBEATABLE -o snake 

