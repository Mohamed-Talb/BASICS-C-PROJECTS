
#LIBFT SOURCES FILES
LIBFT_SRC = LIBFT/ft_putchar_fd.c LIBFT/ft_putstr_fd.c LIBFT/ft_putnbr_fd.c \
			LIBFT/ft_strchr.c LIBFT/ft_strdup.c LIBFT/ft_itoa.c LIBFT/ft_strrchr.c \
            LIBFT/ft_strtrim.c LIBFT/ft_substr.c LIBFT/ft_split.c LIBFT/ft_strlcat.c \
			LIBFT/ft_strncmp.c LIBFT/ft_atoi.c LIBFT/ft_striteri.c LIBFT/ft_calloc.c \
			LIBFT/ft_strlcpy.c LIBFT/ft_strlen.c LIBFT/ft_memcmp.c LIBFT/ft_memmove.c \
            LIBFT/ft_bzero.c LIBFT/ft_strnstr.c LIBFT/ft_strmapi.c LIBFT/ft_strjoin.c \
			LIBFT/ft_isprint.c LIBFT/ft_tolower.c LIBFT/ft_toupper.c LIBFT/ft_append.c \
			LIBFT/ft_isalnum.c LIBFT/ft_isalpha.c LIBFT/ft_isascii.c LIBFT/ft_isdigit.c \
			LIBFT/ft_memcpy.c LIBFT/ft_memchr.c LIBFT/ft_memset.c LIBFT/ft_putendl_fd.c \

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

#PRINTF SRC FILES
RESOURCE = 	 checks.c precision.c flags.c printunsigned.c \
             printmemory.c printchar.c ft_printf.c inits.c \
             printhexa.c printint.c printstring.c utils.c \
             width.c

OBJECTS = $(RESOURCE:.c=.o)

# COMPILING:
AR = ar rcs
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_OBJ)
	 $(AR) $(NAME) $(OBJECTS) $(LIBFT_OBJ)

bonus: all


# COMPILE OBJECTS
LIBFT/%.o: LIBFT/%.c
	cc -c $< -o $@

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re