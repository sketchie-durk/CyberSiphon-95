CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c11
SRC = src/core/apdu.c src/core/transport.c src/core/logger.c src/drivers/hal_virtual.c src/main.c
BIN = bin/cybersiphon

all: $(BIN)

$(BIN): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm -rf bin

.PHONY: all clean
