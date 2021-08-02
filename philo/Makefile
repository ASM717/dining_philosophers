NAME		= philo
INC			= philosophers.h
SRC			= philosophers.c \
				philo_utils.c

OBJ_NAME	= $(SRC:.c=.o)

CC			= gcc -g -Wall -Wextra -Werror

RM	= rm -f

$(NAME):	$(OBJ_NAME) philosophers.h
			$(CC) -o $(NAME) $(OBJ_NAME)

# bonus:		$(NAME)./
all:		$(NAME)

clean:
			$(RM) $(OBJ_NAME)
fclean:		clean
			$(RM) ${NAME}

re:			fclean all
