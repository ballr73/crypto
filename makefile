CC = g++
CFLAGS = -std=c++17 -Wall

BIN = bin
TARGET = crypto
SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')

all: clean build
build: clean
	echo $@
	mkdir $(BIN)
	$(CC) $(SOURCES) -o $(BIN)/$(TARGET) -l ssl -l crypto
clean:
	echo $@
	rm -rf $(BIN)