CC = g++
CPPFLAGS = -I./1fagu9085 -I./src
DEPS = $(wildcard ./1fagu9085/*.h) $(wildcard ./src/*.h)
SOURCE = $(wildcard ./1fagu9085/*.cpp) $(wildcard ./src/*.cpp)
OBJ = $(SOURCE:.cpp=.o)

BIN:= app

.PHONY: all src

all: src $(BIN)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS)



