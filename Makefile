SRC_DIR = ./src
INCLUDES = ./include
BIN_DIR = ./bin
TEST_DIR = ./tests
TEST_BIN_DIR = ./bin/tests

CFLAGS = -Wall -Werror -I$(INCLUDES)
CC = gcc

SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

OBJ = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%.o, $(TEST_SRC))

TARGET = $(BIN_DIR)/temp_converter
TEST_TARGET = $(TEST_BIN_DIR)/temp_converter_tests

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)
	mkdir -p $(TEST_BIN_DIR)

tests: $(TEST_OBJ) $(OBJ)
	$(CC) $(TEST_OBJ) $(OBJ) -o $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_BIN_DIR)/%.o: $(TEST_DIR)/%.c | $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)
	rm -f $(TEST_BIN_DIR)/*.o $(TEST_TARGET)

run:
	$(TARGET)

