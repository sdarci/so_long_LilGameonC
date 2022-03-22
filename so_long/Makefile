SRCS		= main.c utils.c ft_printf_utils.c hooks.c ft_printf_utils2.c \
			ft_printf.c ft_split.c get_next_line.c get_next_line_utils.c \
			pars_map.c play.c ft_itoa.c hooksutils.c

OBJS		= ${SRCS:.c=.o}

HEAD		= so_long.h

NAME		= so_long

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o:	%.c ${HEAD}
		${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -Imlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
