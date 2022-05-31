SRCS = ft_itoa_base.c \
				ft_strlen.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \

NAME = libft.a

CC = cc

LIB = ar -rcs

CFLAGS = -Wall -Werror -Wextra

HEADER = libft.h

OBJS = 		${SRCS:.c=.o}

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS} ${HEADER}
				${LIB} ${NAME} ${OBJS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re