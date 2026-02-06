NAME = Bureaucrat

CXX = c++

CFALGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)

HDR = Bureaucrat.hpp

all: $(NAME)

%.o: %.cpp $(HDR)
	$(CXX) $(CFALGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFALGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean