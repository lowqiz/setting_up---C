##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile ls
##

SRC 	=		src/setting_up.c		\
				src/setting_up_handle_error.c		\

OBJ 	= 		$(SRC:.c=.o)

NAME	= 		setting_up

CFLAGS    =    -Wextra -Wall -pedantic -Wshadow -I./ -Wundef -Wpointer-arith -Wfloat-equal -Winit-self -Waggregate-return -Wwrite-strings -Wcast-align -Wmissing-field-initializers

all: 
	make -C lib/my/ all
	epiclang -o setting_up src/setting_up.c src/setting_up_handle_error.c -lmy -L./lib/my/

$(NAME): 		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm setting_up

fclean: clean
		make -C lib/my/ fclean

re: 	fclean all
