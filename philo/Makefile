NAME		=	philo

INCLUDE		=	philo.h

SRC			=	main.c \
				ft_philo_life.c ft_stewart.c\
				ft_utils.c ft_philo_utils.c

OBJ_NAME	= $(SRC:.c=.o)

GCCFLAGS	= gcc -g -Wall -Wextra -Werror

.c.o:
			$(GCCFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ_NAME) $(INCLUDE)
			$(GCCFLAGS) -o $(NAME) $(OBJ_NAME)

all:		$(NAME)

clean:
			rm -f $(OBJ_NAME)

fclean:		clean
			rm -f ${NAME}

re:			fclean all
