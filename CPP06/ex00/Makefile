NAME = ScalarConverter

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

HDR = ScalarConverter.hpp

all: $(NAME)

%.o:%.cpp $(HDR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
