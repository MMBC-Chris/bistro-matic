##
## EPITECH PROJECT, 2018
## Bistro-Matic
## File description:
## Makefile
##

SRC	=	number.c \
		bistro.c \
		operations.c \
		pre_operations.c \
		token.c \
		check.c \
		tokenize.c \
		token_stack.c \
		number2.c \
		shunting_yard.c \
		rpn.c \
		number_stack.c \
		sub.c \
		mul.c \
<<<<<<< HEAD
		add.c

OBJ	=	$(foreach source, $(SRC), obj/$(source:.c=.o))

=======
		add.c \
		div.c
MAIN	=	main.c
TESTS	=	tests/test_number.c \
		tests/test_bistro.c \
		tests/test_operations.c \
		tests/test_pre_operations.c \
		tests/test_token.c \
		tests/test_check.c \
		tests/test_tokenize.c \
		tests/test_token_stack.c \
		tests/test_number2.c \
		tests/test_shunting_yard.c \
		tests/test_rpn.c \
		tests/test_number_stack.c \
		tests/test_sub.c \
		tests/test_mul.c \
		tests/test_add.c \
		tests/test_div.c
OBJ	=	$(SRC:.c=.o) main.o
>>>>>>> 4c03d6327a7d9c10f5b3809d2a5b06d2bc5109aa
NAME	=	calc

LIB	=	lib/my/libmy.a
<<<<<<< HEAD

CFLAGS	=	-g -Wall -Wextra -ansi -pedantic

LDFLAGS	=	-Llib/my -lmy
=======
CFLAGS	=	-Wall -Wextra -ansi -pedantic
CRFLAGS	=	--coverage -lcriterion
LDFLAGS =	-Llib/my -lmy
>>>>>>> 4c03d6327a7d9c10f5b3809d2a5b06d2bc5109aa

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $@ $(OBJ) $(LDFLAGS)

<<<<<<< HEAD
obj/%.o: src/%.c
	gcc -c $< -o $@ $(CFLAGS)
=======
$(OBJ): $(SRC)
	gcc -c $(MAIN) $(SRC) $(CFLAGS)
>>>>>>> 4c03d6327a7d9c10f5b3809d2a5b06d2bc5109aa

$(LIB):
	make -C lib/my

tests_run: $(LIB)
	gcc -o unit_tests $(SRC) $(TESTS) $(CRFLAGS) $(LDFLAGS)
	./unit_tests

clean:
	rm -f *.o
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gc*
	make -C lib/my fclean

re: fclean all
