CC = gcc
CFLAGS = -Wall -Wextra
SRC = main.c
EXEC = helper

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXEC)

