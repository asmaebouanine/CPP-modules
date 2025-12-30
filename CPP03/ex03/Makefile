NAME = DiamondTrap

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HDRS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean