# compile main.c into a dll
# link main.h with main.c
# Link with the shared library dosato_lib.dll in the dosato_source directory

# Compiler
# Compiler flags
CFLAGS = -Wall -Werror

# Include directories
INCLUDES = -I./dosato_source

# Linker flags
LDFLAGS = -L./dosato_source -ldosato_lib

# Source files
SRCS = main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target
TARGET = mydll.dll

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -shared -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
CC = gcc
