##
# origami/huff
#
# @version 0.1

CC=clang
CFLAGS=-g -Wall
TARGET=origami

BUILD_DIR=build
OUTPUT=$(BUILD_DIR)/$(TARGET)
SRCS=$(wildcard *.c)

all: $(OUTPUT)

$(OUTPUT): $(SRCS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRCS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
# end
