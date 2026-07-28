# compiler to use
CXX = g++
# enable common and additional warnings
# compile using c++17 standard
CXXFLAGS = -Wall -Wextra -std=c++17

# SRC = src/main.cpp src/bubble_sort.cpp src/print_info.cpp # dependencies
SRC = $(wildcard src/*.cpp)
BUILD_DIR = build
TARGET = $(BUILD_DIR)/main # output file

# default target to build on `make` command
all: $(TARGET)
# to build $TARGET, use $SRC
# if there're changes
$(TARGET): $(SRC)
    # @: don't print command before execute
	@mkdir -p $(BUILD_DIR)
    # $@: target being created
    # $<: first dependency only
    # $^: all dependencies
	$(CXX) $(CXXFLAGS) -o $@ $^
    # expands to:
    # g++ -Wall -Wextra -std=c++17 -o build/main src/main.cpp

# runs on `make clean` command
clean:
	@rm -rf $(BUILD_DIR)

# phony == fake
# run make command even if there is files named `all` or `clean`
.PHONY: all clean
