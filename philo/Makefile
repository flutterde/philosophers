CC = cc 
CFLAGS = -Wall -Wextra -Werror # -g -fsanitize=thread -pthread 
HEADERS = philo.h
SRC = ft_main.c ./utils/ft_atoi.c ./src/ft_time.c ./utils/getters_setters.c  ./utils/prepare.c  ./src/one_handler.c \
./utils/print_status.c ./utils/clean_up.c ./src/thread_routine.c\

NAME = philo

OBJS = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)


re : fclean all


.PHONY: all clean fclean re  
