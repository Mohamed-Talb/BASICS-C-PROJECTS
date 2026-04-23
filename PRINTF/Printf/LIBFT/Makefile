NAME = libft.a
RESOURCE = 	ft_strlcpy.c ft_strlen.c ft_memcmp.c ft_memmove.c ft_memcpy.c ft_memchr.c ft_memset.c ft_putendl_fd.c \
			ft_strncmp.c ft_atoi.c ft_striteri.c ft_calloc.c ft_bzero.c ft_strnstr.c ft_strmapi.c ft_strjoin.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_strchr.c ft_strdup.c  ft_itoa.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_split.c ft_strlcat.c \
			ft_isprint.c ft_tolower.c ft_toupper.c \
			

BONUS_RESOURCE = ft_lstmap_bonus .c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
				 ft_lstiter_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c \

OBJECTS = $(RESOURCE:.c=.o)

BONUS_OBJECTS = $(BONUS_RESOURCE:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(NAME): all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

PHONY: all clean fclean re

%.o: %.c
	cc $(FLAGS) -c $< -o $@