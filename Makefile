# Makefile
CC = clang

INCLUDE_DIR = include
ifeq ($(DEBUG), 1)
    CFLAGS = -Wall -std=c99 -I$(INCLUDE_DIR) -Wextra -g -O0
else
    CFLAGS = -Wall -std=c99 -I$(INCLUDE_DIR) -Wextra -O2
endif

TARGET = calc

SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

TEST_DIR = tests
TEST_TARGET = test
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(filter-out $(OBJ_DIR)/main.o, $(OBJS))

all: $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/$(TEST_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -MD

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(BUILD_DIR)/$@

run:
	$(BUILD_DIR)/$(TARGET)

test: $(OBJS)
	mkdir -p $(BUILD_DIR)/$(TEST_DIR)
	$(CC) -o $(BUILD_DIR)/$(TEST_DIR)/$(TEST_TARGET) -I$(INCLUDE_DIR)  $(TEST_OBJS) $(TEST_DIR)/test.c
	$(BUILD_DIR)/$(TEST_DIR)/test | tests/greenest

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
