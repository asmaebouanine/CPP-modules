NAME = weapon

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJCS = $(SRCS:.cpp=.o)

HEADER = Weapon.hpp HumanA.hpp HumanB.hpp

all: $(NAME)

%.o: %.cpp $(HEADER)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJCS)
	$(CXX) $(CFLAGS) $(OBJCS) -o $(NAME)

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME)

re: fclean re

.PHONY: clean