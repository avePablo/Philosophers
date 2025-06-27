NAME = libprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c 	\
		ft_putchar_pf.c	\
		ft_putnbr_pf.c	\
		ft_putstr_pf.c 	\
		ft_putunbr_pf.c	\
		ft_puthex_pf.c

 OBJ = $(SRC:.c=.o)


 all: $(NAME)

 $(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re