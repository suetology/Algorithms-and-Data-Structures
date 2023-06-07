CC:= g++
SRC:= test.cpp
DEPS = $(wildcard *.h)
BIN:= test.exe
RM:= del

all: $(BIN)

$(BIN): $(SRC) $(DEPS)
	$(CC) -o $@ $(SRC) -I.

clean:
	$(RM) $(BIN)