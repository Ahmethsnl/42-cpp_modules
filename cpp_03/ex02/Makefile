SRCS	= ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp
OBJS	= $(SRCS:.cpp=.o)

CPP		= c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
NAME	= FragTrap

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re