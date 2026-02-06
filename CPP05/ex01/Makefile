NAME = Form

CXX = c++

CFALGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJS = $(SRCS:.cpp=.o)

HDRS = Bureaucrat.hpp Form.hpp

all: $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CFALGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFALGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
