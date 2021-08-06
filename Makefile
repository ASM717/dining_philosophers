NAME		=	philo
INCLUDE		=	philo.h
SRC			=	main.c \
				ft_utils.c ft_philo_utils.c

OBJ_NAME	= $(SRC:.c=.o)
CC			= gcc -g -Wall -Wextra -Werror
RM	= rm -f
$(NAME):	$(OBJ_NAME) philo.h
			$(CC) -o $(NAME) $(OBJ_NAME)

all:		$(NAME)
clean:
			$(RM) $(OBJ_NAME)
fclean:		clean
			$(RM) ${NAME}
re:			fclean all
