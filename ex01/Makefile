NAME	= libft.a

SRCS	= \
	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_strcmp.c \
	srcs/ft_strlen.c \
	srcs/ft_swap.c

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

.c.o:
	gcc -Wall -Wextra -Werror -I includes -c $< -o ${<:.c=.o} 

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm ${OBJS}

fclean:	clean
	rm ${NAME}

re:	fclean all
