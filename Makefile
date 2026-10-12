CC := gcc
CFLAGS := -Iinclude 

SRC := src/main.c arch/x86_64/timer/timer.c

FORMAT_FILES := $(shell find . -type d -name '$(BUILD)' -prune -false -o -type f \( -name '*.c' -o -name '*.h' \))

format:
	@echo "Formatting the Tempest source code..."
	@clang-format -i $(FORMAT_FILES)

clean:
	rm -rf tempest

.PHONY: format clean
