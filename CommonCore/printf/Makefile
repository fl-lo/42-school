CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INCLUDE = -I.
HEADER = ft_printf.h

SRCS = ft_printf.c \
       srcs/ft_putchar.c \
       srcs/ft_putnbr_base.c \
       srcs/ft_putnbr_ptr.c \
       srcs/ft_putnbr_u.c \
       srcs/ft_putnbr.c \
       srcs/ft_putstr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
