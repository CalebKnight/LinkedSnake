CC = gcc
snake: main.o random.o game.o snake.o terminal.o board.o linkedList.o queue.o file.o
	$(CC) -o snake main.o random.o game.o snake.o terminal.o board.o linkedList.o queue.o file.o
	
main.o: main.c main.h
	$(CC) -c -Wall -ansi -pedantic -Werror main.c -o main.o

random.o: random.c random.h
	$(CC) -c -Wall -ansi -pedantic -Werror random.c -o random.o

game.o: game.c game.h random.c random.h board.c board.h snake.c snake.h terminal.c terminal.h queue.c queue.h 
	$(CC) -c -Wall -ansi -pedantic -Werror game.c -o game.o

snake.o: snake.c snake.h game.c game.h queue.c queue.h linkedList.c linkedList.h file.c file.h
	$(CC) -c -Wall -ansi -pedantic -Werror snake.c -o snake.o

terminal.o: terminal.c terminal.h
	$(CC) -c -Wall -ansi -pedantic -Werror terminal.c -o terminal.o

board.o: board.c board.h random.c random.h
	$(CC) -c -Wall -ansi -pedantic -Werror board.c -o board.o

linkedList.o: linkedList.c linkedList.h
	$(CC) -c -Wall -ansi -pedantic -Werror linkedList.c -o linkedList.o

queue.o: queue.c queue.h linkedList.c linkedList.h
	$(CC) -c -Wall -ansi -pedantic -Werror queue.c -o queue.o

file.o: file.c file.h queue.c queue.h
	$(CC) -c -Wall -ansi -pedantic -Werror file.c -o file.o

