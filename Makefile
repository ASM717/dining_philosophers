NAME		= phylo

SRC			= library.c

SRCS		= $(addprefix srcs/, $(SRC))

OBJS		= $(SRCS:.c=.o)

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -g

all:$(NAME)

$(NAME):
	@$(CC) ${FLAGS} ${SRCS} -o ${NAME}
	@echo "\n\033[0;33mCompile Philosophers Done!"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\n\033[0;33mClean .o Files Done!"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;33mClean All Files Done!"

re: fclean all

norm :
	norminette *.h ./srcs/*.c

.PHONY: all clean fclean re norm