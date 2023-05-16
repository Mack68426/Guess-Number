CC = gcc
BIN_PATH = bin
SRC_PATH = src

EXEC = $(BIN_PATH)/main.exe
SOURCES = $(wildcard $(SRC_PATH)/*.c)

all: 
	$(CC) -g $(SOURCES) -o $(EXEC)

run: $(EXEC)
	./$<