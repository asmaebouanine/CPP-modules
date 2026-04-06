NAME = easyfind

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

HDR = easyfind.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HDR)
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean