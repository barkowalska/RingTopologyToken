ROOT_DIR = ..
INC_DIR = $(ROOT_DIR)/inc
SRC_DIR = $(ROOT_DIR)/src
OBJ_DIR = $(ROOT_DIR)/obj
BIN_DIR = $(ROOT_DIR)/bin

COMP = g++
LOADER = g++


main.o: $(SRC_DIR)/main.cpp
	$(COMP) -c -I $(INC_DIR) main.cpp -o $(OBJ_DIR)/main.o

program: main.o 
	$(LOADER) $(OBJ_DIR)/main.o  -o $(BIN_DIR)/program