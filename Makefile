NAME    = so_long

CC              = clang

CFLAGS  = -Wall -Wextra -Werror -g3

RM              = rm -f

PRINTF = ft_printf

FT_PRINTF = ft_printf/libftprintf.a

SRC     = ./srcs/solong.c ./srcs/map_boucle.c ./ft_printf/ft_len.c ./srcs/map_verif2.c ./srcs/event.c ./srcs/map_verif.c flood_fill.c ./srcs/event2.c main.c ./GNL/get_next_line.c ./GNL/get_next_line_utils.c

OBJ    = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${MAKE} -C ${PRINTF}
	${CC} ${OBJ} ./mlx/libmlx.a ./mlx/libmlx_Linux.a -lX11 -lXext -L -lX11 -o ${NAME} ${FT_PRINTF}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
