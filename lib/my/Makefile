##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC	=	my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c				\
		my_strlen.c				\
		my_getnbr.c				\
		my_strcpy.c				\
		my_strncpy.c				\
		my_strcmp.c				\
		my_strncmp.c				\
		my_strcat.c				\
		my_strncat.c				\
		my_str_to_word_array.c			\
		my_strdup.c				\
		my_nbrlen.c				\
		my_get_next_nbr.c			\
		my_str_to_arr.c				\
		my_int_to_str.c				\
		my_str_to_line.c			\
		load_file_in_mem.c			\
		free_char_arr.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c -Wall -Wextra $(SRC)
	ar rc $(NAME) *.o
	cp $(NAME) ../
	cp my.h ../../include

clean:
	rm -f *.o
	rm -f ../$(NAME)
	rm -f ../../include/my.h
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
