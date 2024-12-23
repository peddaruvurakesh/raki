# Makefile for compiling all 5 simpcat programs

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Targets (executables)
TARGETS = simpcat1 simpcat2 simpcat3 simpcat4 simpcat5

# Rule to compile all programs
all: $(TARGETS)

# Rule for simpcat1
simpcat1: simpcat1.c
	$(CC) $(CFLAGS) -o simpcat1 simpcat1.c

# Rule for simpcat2
simpcat2: simpcat2.c
	$(CC) $(CFLAGS) -o simpcat2 simpcat2.c

# Rule for simpcat3
simpcat3: simpcat3.c
	$(CC) $(CFLAGS) -o simpcat3 simpcat3.c

# Rule for simpcat4
simpcat4: simpcat4.c
	$(CC) $(CFLAGS) -o simpcat4 simpcat4.c

# Rule for simpcat5
simpcat5: simpcat5.c
	$(CC) $(CFLAGS) -o simpcat5 simpcat5.c

# Clean up by removing the executables
clean:
	rm -f $(TARGETS)

