CC := gcc
CFLAGS := -Iinclude 
TARGET := tempest

SRC := src/main.c
OBJ := $(SRC:.c=.o)

FORMAT_FILES := $(shell find . -type d -name '$(BUILD)' -prune -false -o -type f \( -name '*.c' -o -name '*.h' \))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

format:
	@echo "Formatting the Tempest source code..."
	@clang-format -i $(FORMAT_FILES)

clean:
	rm -rf src/*.o $(TARGET)

.PHONY: all format clean run
