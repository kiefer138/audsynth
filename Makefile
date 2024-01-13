CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
CFLAGS_TEST = -Wall -Wextra -Iinclude -g  # Add -g here
LIBS = -lportaudio
SRC = $(wildcard src/*.c)
OBJ = $(filter-out src/main.o, $(SRC:.c=.o))
BIN = audsynth
TEST_SRC = $(wildcard test/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_BIN = $(TEST_SRC:.c=)

.PHONY: build clean test

build: $(BIN)

$(BIN): $(OBJ) src/main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(TEST_BIN)

test/%: test/%.o $(OBJ)
	$(CC) $(CFLAGS_TEST) -o $@ $^ $(LIBS)  # Use CFLAGS_TEST here
	./$@

clean:
	rm -f $(OBJ) $(BIN) $(TEST_OBJ) $(TEST_BIN) src/main.o
