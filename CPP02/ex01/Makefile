NAME = fixed

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp

OBJCS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp Fixed.hpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJCS)
	$(CXX) $(CFLAGS) $(OBJCS) -o $(NAME)

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean