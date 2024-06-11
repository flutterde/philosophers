CC = cc 
CFLAGS = -Wall -Wextra -Werror  #-g -fsanitize=thread #-pthread 
HEADERS = philo_bonus.h
SRC = main_bonus.c ./utils/ft_atoi_bonus.c ./utils/ft_time_bonus.c\
./src/thread_routine_bonus.c ./src/process_fn_bonus.c\
./utils/prepare_data_bonus.c ./src/one_handler_bonus.c 


NAME = philo_bonus

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