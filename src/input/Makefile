# SPDX-License-Identifier: MIT
# Makefile for Amiga Input Manager for PISTORM

CC = gcc
CFLAGS = -O2 -Wall -Wextra -std=c99 -I../.. -I../pistorm-dev -I../../platforms/amiga/registers
LDFLAGS = -lpthread -lm
TARGET = amiga_input_manager
SOURCES = input_manager.c
OBJECTS = $(SOURCES:.c=.o)

# Debug build
CFLAGS_DEBUG = -O0 -g -Wall -Wextra -std=c99 -I../.. -I../pistorm-dev -I../../platforms/amiga/registers -DDEBUG

.PHONY: all debug clean install

all: $(TARGET)

debug: CFLAGS := $(CFLAGS_DEBUG)
debug: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

# Additional targets for individual components
keyboard_test: keyboard.o
	$(CC) keyboard.o -o $@ $(LDFLAGS)

mouse_test: mouse.o
	$(CC) mouse.o -o $@ $(LDFLAGS)

lightpen_test: lightpen.o
	$(CC) lightpen.o -o $@ $(LDFLAGS)

# Dependencies
keyboard.o: keyboard.c ../pistorm-dev/pistorm_dev.h ../../platforms/amiga/registers/amiga_memory_map.h
mouse.o: mouse.c ../pistorm-dev/pistorm_dev.h ../../platforms/amiga/registers/amiga_memory_map.h
lightpen.o: lightpen.c ../pistorm-dev/pistorm_dev.h ../../platforms/amiga/registers/amiga_memory_map.h
input_manager.o: input_manager.c keyboard.c mouse.c lightpen.c amiga_input.h

# Run tests
test: $(TARGET)
	./$(TARGET) --test

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the input manager"
	@echo "  debug   - Build with debugging symbols"
	@echo "  clean   - Clean object files and executables"
	@echo "  install - Install the executable to /usr/local/bin/"
	@echo "  test    - Run test mode"
	@echo "  help    - Show this help message"