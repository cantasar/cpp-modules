NAME = FragTrap
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re