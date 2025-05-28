NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCS	=	sources/main.c \
			sources/parsing.c \
			sources/grim_reaper.c \
			sources/time.c \
			sources/philosopher.c \
			sources/init.c \
			sources/output.c \
			sources/exit.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
