CXX = g++
CFLAGS = -I./include

NAME = TaskManagement
SRC = ./src/main.cpp\
	  ./src/Task.cpp\
	  ./src/TaskManager.cpp\
	  ./src/User.cpp

OBJ = $(SRC:.cpp=.o)
HEAD = ./include/Task.hpp\
		./include/TaskManager.hpp\
		./include/User.hpp\
		./include/Date.hpp

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o : %.cpp $(HEAD)
	$(CXX) $(CFLAGS) -c $< -o $@



clean:
	rm -f $(OBJ) $(NAME)
