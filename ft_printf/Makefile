#Gude-and

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = ft_printchar.c ft_printf.c ft_printhex.c ft_printnbr.c ft_printptr.c\
ft_printptr.c ft_printstr.c ft_printunint.c

OBJ = $(SRC_FILES:.c=.o)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

 $(NAME) : $(OBJ)
	@ar rsc $(NAME) $(OBJ)

clean:
	@rm -f  $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all