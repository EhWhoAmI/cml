CC=gcc
SOURCES=src/main.c
CFLAGS=-c -Wall
OBJECTS=$(SOURCES:.c=.o)
EXE=cml
all: $(SOURCES) $(EXE)
$(EXE):$(OBJECTS)
	$(CC) $(OBJECTS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
