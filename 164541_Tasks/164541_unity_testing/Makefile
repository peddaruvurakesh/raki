# Compiler and flags
CC = gcc
CFLAGS = -I Unity/src -Wall -Wextra -g

# Source files
SRC = person.c testcalc.c Unity/src/unity.c

# Output binary for the test
TARGET = person

# Default rule to compile and run tests
all: $(TARGET) run

# Rule to link and create the test binary
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Run the unit tests
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)
	rm -f *.o

