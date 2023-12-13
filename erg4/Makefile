CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = main.c
EXEC = process

all: $(EXEC)

$(EXEC): $(SRC_DIR)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXEC)
