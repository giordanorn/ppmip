PROGRAM_NAME   = ppmip

SOURCES_DIR    = ./src
HEADERS_DIR    = ./include
OBJECTS_DIR    = ./obj
RESOURCES_DIR  = ./res

CC             = gcc
CFLAGS 	       = -Wall -I$(HEADERS_DIR)
OBJECTS        = $(OBJECTS_DIR)/utils.o $(OBJECTS_DIR)/file.o $(OBJECTS_DIR)/filters.o $(OBJECTS_DIR)/transform.o
TEST_FILENAME  = $(RESOURCES_DIR)/test

.PHONY: all build clean test cleantest cleanall dirs

all: build

build: dirs $(PROGRAM_NAME)
	
$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(HEADERS_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@ 
	
$(PROGRAM_NAME): $(SOURCES_DIR)/$(PROGRAM_NAME).c $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -f $(PROGRAM_NAME)
	rm -rf $(OBJECTS_DIR)

test: $(PROGRAM_NAME)
	./$(PROGRAM_NAME) greyscale $(TEST_FILENAME).ppm $(TEST_FILENAME)-greyscale.ppm
	./$(PROGRAM_NAME) threshold $(TEST_FILENAME).ppm $(TEST_FILENAME)-threshold.ppm

dirs:
	mkdir -p $(OBJECTS_DIR)


cleantest:
	rm -f $(TEST_FILENAME)-greyscale.ppm
	rm -f $(TEST_FILENAME)-threshold.ppm
	
cleanall: clean cleantest
	@echo "Cleaning all files done."

