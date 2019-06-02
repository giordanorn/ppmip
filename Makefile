# ENVIRONMENT

PROGRAM_NAME   = ppmip

SOURCES_DIR    = ./src
HEADERS_DIR    = ./include
OBJECTS_DIR    = ./obj
RESOURCES_DIR  = ./res

OBJECTS        = $(OBJECTS_DIR)/utils.o $(OBJECTS_DIR)/file.o $(OBJECTS_DIR)/filters.o

# MACROS
CC             = gcc
CFLAGS 	       = -Wall -I. -I$(HEADERS_DIR)

# PHONY CALLS
.PHONY: all clean

# TASKS
all: $(OBJECTS) $(PROGRAM_NAME)
	
$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(HEADERS_DIR)/%.h
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 
	
$(PROGRAM_NAME): $(SOURCES_DIR)/main.c $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -f $(PROGRAM_NAME)
	rm -rf $(OBJECTS_DIR)
