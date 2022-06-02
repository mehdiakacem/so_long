NAME = so_long

FLAGS = -Wall -Werror -Wextra

SRC = so_long.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)

%.o : %.c
	gcc $(FLAGS) -c $<

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all