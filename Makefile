SRCS = ./srcs/ft_printf.c \
 				./srcs/hex_conversion.c \
				./srcs/int_conversion.c \
				./srcs/ptr_conversion.c \
				./srcs/str_conversion.c \
 				./srcs/unsigint_conversion.c \

NAME = libftprintf.a

CC = cc

LIB = ar -rcs

CFLAGS = -Wall -Werror -Wextra

HEADER = ./incs/ft_printf.h

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS =	${SRCS:.c=.o}	

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I./incs -I./libft -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} $(LIBFT) $(HEADER)
				${LIB} ${NAME} ${OBJS}

$(LIBFT):
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

clean:
			make clean -C $(LIBFT_DIR)
			rm -f ${OBJS}

fclean:		clean
				make fclean -C $(LIBFT_DIR)
				rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re