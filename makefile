CC = gcc
CFLAGS = -Wall

all: task1

task1: src/task1.c
	$(CC) $(CFLAGS) src/task1.c -o task1