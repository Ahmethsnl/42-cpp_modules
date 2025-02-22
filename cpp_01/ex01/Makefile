SRCS	= main.cpp Zombie.cpp zombieHorde.cpp

OBJ		= $(SRCS:.cpp=.o)

NAME	= zombie

CPP		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re