CC     = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRCS = main.c src/mapa.c src/pacman.c src/ui.c
OUT  = pacman

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(OUT)

clean:
	rm -f $(OUT)