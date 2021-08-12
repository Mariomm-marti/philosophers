NAME		= philo

LIST		=	forks.c \
				main.c \
				parser.c \
				philos.c \
				routine.c \
				routine_take_forks.c \
				timestamps.c \
				utils.c
SRCS		= $(addprefix srcs/,$(LIST))
OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra -I includes/

%.o:		%.c
			@clang $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@clang $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
