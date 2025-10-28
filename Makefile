NAME = philosophers

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	./philo/utils.c \
		./philo/main.c \
		./philo/actions.c \
		./philo/parse.c \
		./philo/libft_utils.c \
		./philo/simu.c 

OBJ = $(SRC:.c=.o)


all: $(NAME)


$(NAME):  $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re