CC:= g++
SRC:= main.cpp
DEPS = $(wildcard *.h)
BIN:= main.exe
RM:= del

all: $(BIN)

$(BIN): $(SRC) $(DEPS)
	$(CC) -o $@ $(SRC) -I.

clean:
	$(RM) $(BIN)