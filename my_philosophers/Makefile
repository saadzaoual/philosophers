NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCS = sources/philosophers.c sources/parsing.c sources/error.c sources/initialazation.c
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
