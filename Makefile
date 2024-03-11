SRC = main.c
#CC = gcc -Wall -Werror -Wextra
CC = gcc
OBJ = $(SRC:.c=.o)
NAME = philo

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	echo "Done"
clean :
	rm -rf $(OBJ)
	echo "Cleaning has been carried out"
fclean : clean
	rm -rf $(NAME)
	echo "Cleaning++ has been carried out"
re : fclean all $(NAME)

.PHONY: all clean fclean re
