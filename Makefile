NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra


LIBDIR1 = ./Libft
LIBDIR2 = ./ft_printf
LIB = $(LIBDIR2)/libprintf.a $(LIBDIR1)/libft.a  


SRC =	./mandatory/src/utils.c \
		./mandatory/src/main.c \
		./mandatory/src/stack.c \
		./mandatory/src/moves_1.c \
		./mandatory/src/moves_2.c \
		./mandatory/src/ksort.c \
		./mandatory/src/sp_cases.c \
		./mandatory/src/index.c \
		./mandatory/src/prints.c

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