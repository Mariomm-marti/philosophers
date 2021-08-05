NAME		= philo

LIST		= parser.c \
			  utils.c \
			  init_philos.c \
			  worker_philos.c \
			  timestamps.c \
			  main.c
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
