# Set the default compiler to gcc
CC = clang++

# Set the flags
CFLAGS = -std=c++17

#The Directories
SRC_DIR = ./src
BUILD_DIR = ./build
INC_DIR = ./inc

#Include dir
INC = -I$(INC_DIR)

# -Wall -Wextra -Werror
# Files to run
#SRC = *.cpp
#OBJ = *.o
TARGET = my_out

#Search for .cpp files in the source directory
SRCS = $(shell find $(SRC_DIR) -type f -name "*.cpp")
#Replace the dir name and file extensions for object files
OBJS = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRCS:.cpp=.o))

# Default make
all : $(TARGET)

#Link
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

#Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp #$(INC_DIR)/%.h
	@mkdir -p $(dir $@)
	$(CC) $(INC) -c $< -o $@

#Clean only Objects
clean:
	rm -r $(BUILD_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all	