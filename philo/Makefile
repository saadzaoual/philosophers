NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCS = 	src/philo.c  \
		src/parsing.c\
		src/error.c
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