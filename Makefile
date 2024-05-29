NAME	=	minishell

SRCS	=	main.c  \
		utils1.c

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

RLFLAG	=	-lreadline

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(RLFLAG)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
