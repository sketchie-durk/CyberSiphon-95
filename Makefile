CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c11
SRC = src/core/apdu.c
BIN = bin/cybersiphon

all: $(BIN)

$(BIN): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm -rf bin

.PHONY: all clean
