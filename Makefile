##
## EPITECH PROJECT, 2022
## make
## File description:
## make
##

SRC		=	main.c				\

SRC_TEST = src/my_put.c					\

OBJ		=	$(SRC:.c=.o)

NAME	= 	test

CPPFLAGS = -I ./include

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ)

tests_run:
		gcc -o test $(SRC_TEST) ./tests/test_minishel.c \
		--coverage -lcriterion
		./test

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
