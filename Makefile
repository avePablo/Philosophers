NAME = philosophers

CC = gcc

CFLAGS = -Wall -Werror -Wextra


LIBDIR1 = ./Libft
LIBDIR2 = ./ft_printf
LIB = $(LIBDIR2)/libprintf.a $(LIBDIR1)/libft.a  


SRC =	./philo/utils.c \
		./philo/main.c

OBJ = $(SRC:.c=.o)


all: $(NAME)


$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)


$(LIB):
	make -C $(LIBDIR1) all 	
	make -C $(LIBDIR2) all 

clean:
	rm -f $(OBJ)
	make -C $(LIBDIR1) clean
	make -C $(LIBDIR2) clean


fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR1) fclean
	make -C $(LIBDIR2) fclean

re: fclean all

.PHONY: all clean fclean re