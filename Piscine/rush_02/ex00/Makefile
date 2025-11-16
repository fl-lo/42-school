NAME=rush-02
CC=cc
CFLAGS=-Wall -Wextra -Werror
SOURCES=main.c dictionary.c ft_string.c clean_str.c ft_split_str.c dict_check.c free_array.c ft_write_numbers.c split_nbr.c ft_write_numbers.c ft_writes.c zero.c


all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(NAME)

fclean: clean

re: fclean
	all
