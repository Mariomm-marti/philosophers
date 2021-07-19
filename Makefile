NAME		= philo

LIST		= main.c
SRCS		= $(addprefix srcs/,$(LIST))
OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

%.o:		%.c
			@clang -Wall -Werror -Wextra -c $< -o $@

$(NAME):	$(OBJS)
			@clang $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
