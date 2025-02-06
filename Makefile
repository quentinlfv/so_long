NAME = so_long

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra 



SRCS		= main.c \
				floodfill.c \
				check1.c \
				check2.c \
				start_game.c \
				event.c \
				moves.c	\
				init.c \
				map.c \
				utils.c \
				ft_strcpy.c \
				ft_strcmp.c \
				ft_putnbr.c \
				get_next_line.c \
				get_next_line_utils.c \

OBJS		= $(SRCS:.c=.o)

RM 			:= rm -rf

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:

	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: 
		$(MAKE) fclean
		$(MAKE) all

PHONY: all clean fclean re
