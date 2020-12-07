CC = gcc
CFLAGS = -Wall

all: task1 task2

task1: src/task1.c
	$(CC) $(CFLAGS) src/task1.c -o bin/task1

task2: src/task2.c
	$(CC) $(CFLAGS) src/task2.c -o bin/task2