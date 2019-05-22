# FOLDERS
SOURCES_DIR 	= ./src
HEADERS_DIR 	= ./include
OBJECTS_DIR 	= ./obj
RESOURCES_DIR 	= ./res

# MACROS
C_COMPILER 	= gcc
COMPILER_FLAGS 	= -I. -I$(HEADERS_DIR)

# PHONY CALLS
.PHONY: all build main

# TASKS
all: build main
	
build: $(OBJECTS_DIR)/utils.o

$(OBJECTS_DIR)/utils.o: $(SOURCES_DIR)/utils.c $(HEADERS_DIR)/utils.h
	mkdir -p $(OBJECTS_DIR)
	$(C_COMPILER) $(COMPILER_FLAGS) -c $< -o $@ 
	

main: $(SOURCES_DIR)/main.c $(OBJECTS_DIR)/utils.o
	$(C_COMPILER) $(COMPILER_FLAGS) $^ -o $@ -lm
