CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

SRC_DIR = src
INC_DIR = include
TEST_DIR = test
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/SocialNetworkSimulator
TEST_TARGET = $(BIN_DIR)/TestRunner

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_FILES))

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJ_FILES)
    @mkdir -p $(BIN_DIR)
    $(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(OBJ_FILES) $(TEST_OBJ_FILES)
    @mkdir -p $(BIN_DIR)
    $(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
    @mkdir -p $(OBJ_DIR)
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
    @mkdir -p $(OBJ_DIR)
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR)

test: $(TEST_TARGET)
    ./$(TEST_TARGET)

.PHONY: all clean test