# PHILOSOPHERS SOURCE FILES
PHILO_SRC = philo.c initdata.c initphilos.c initforks.c parsing.c math.c ft_usleep.c utils.c monitor.c clean.c routine.c launche.c routine_utiles.c
PHILO_OBJ = $(PHILO_SRC:.c=.o)

# COMPILER & FLAGS
CC = cc -pthread
FLAGS = -Wall -Wextra -Werror

# OUTPUT EXECUTABLE
NAME = philo

# RULES
all: $(NAME)

$(NAME): $(PHILO_OBJ) $(LIBFT_OBJ)
	@$(CC) $(PHILO_OBJ) -o $(NAME)


# COMPILE OBJECTS
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(PHILO_OBJ) $(LIBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re