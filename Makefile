CC := gcc
CFLAGS := -std=c99 -Wall -Wextra
CFLAGS += -ggdb -Og
LIBS :=


SRC_DIR := ./src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:.c=.o)
BIN := a.out


$(BIN): $(OBJ_FILES)
	$(CC) -o $(BIN) $(OBJ_FILES)


%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(BIN) $(SRC_DIR)/*.o
