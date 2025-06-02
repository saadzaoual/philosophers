NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS	=	src/philo.c\
			src/parsing.c\
			src/init.c\
			src/time.c

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