NAME = ClapTrap

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: .%cpp ClapTrap.hpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean