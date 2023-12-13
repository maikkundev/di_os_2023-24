CC = gcc
CFLAGS = -Wall -Wextra -Wno-newline-eof -pedantic

SRC_DIR = erg3
OUT_DIR = out

all: $(OUT_DIR)/sort

$(OUT_DIR)/sort: $(SRC_DIR)/main.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)
	rm -rf input output
	rmdir $(OUT_DIR) 2>/dev/null || true
