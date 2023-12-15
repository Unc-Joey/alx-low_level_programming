CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SOURCES = shell.c utils.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = shell

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

