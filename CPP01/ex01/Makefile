NAME = zombie

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Zombie.hpp

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

OBJCS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(HEADER)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJCS)
	$(CXX) $(CFLAGS) $(OBJCS) -o $(NAME)

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean