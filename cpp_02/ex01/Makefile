SRCS	= Fixed.cpp main.cpp
OBJS	= $(SRCS:.cpp=.o)
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCDIR	= src
NAME	= fixed

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re