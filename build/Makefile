CXX = g++
CXXFLAGS = -I../include

SRC_DIR = ../src
OBJ_DIR = ./obj
TEST_DIR = ../googletests
BIN_DIR = ./bin

NAME = $(BIN_DIR)/TaskManagement
TEST_NAME = $(BIN_DIR)/TaskManagementTest

SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/Task.cpp \
      $(SRC_DIR)/TaskManager.cpp \
      $(SRC_DIR)/User.cpp

TEST_SRC = $(TEST_DIR)/test.cpp \
           $(SRC_DIR)/Task.cpp \
           $(SRC_DIR)/TaskManager.cpp \
           $(SRC_DIR)/User.cpp

OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
TEST_OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(filter-out $(SRC_DIR)/main.cpp, $(SRC))) \
           $(OBJ_DIR)/test.o

all: $(NAME)

$(NAME): $(OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(TEST_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(TEST_NAME) -lgtest -lgtest_main -pthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/test.o: $(TEST_DIR)/test.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
