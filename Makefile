NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	./philosophers/utils.c \
		./philosophers/main.c \
		./philosophers/actions.c \
		./philosophers/parse.c \
		./philosophers/libft_utils.c \
		./philosophers/simu.c 

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