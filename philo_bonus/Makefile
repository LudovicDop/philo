SRC = main.c
CC = cc
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
NAME = philo_bonus

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	echo "Done!"
clean : 
	rm -rf $(OBJ)
	echo "Cleaning has been carried out"
fclean : clean
	rm -rf $(NAME)
	echo "Cleaning++ has been carried out"
re : fclean all $(NAME)
.PHONY: all clean fclean re 