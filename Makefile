##
# origami/huff
#
# @version 0.1

CC=gcc
CFLAGS=-g -Wall
TARGET=origami

SRCS=$(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
# end
