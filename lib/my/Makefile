##
## EPITECH PROJECT, 2018
## Rush2
## File description:
## make lib
##

SRC	=	*.c
OBJ	=	*.o
NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/my.h

$(OBJ): $(SRC)
	gcc -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
