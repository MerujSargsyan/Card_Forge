CC=gcc++
CFLAGS=-Wall -Wextra -std=c++11

default: CardForge.o

CardForge.o: CardForge.h
	$(CC) $(CFLAGS) -c $< -I$(RAYLIBDIR) -L$(RAYLIBDIR) 
