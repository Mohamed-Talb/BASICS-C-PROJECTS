#ESOURCES
SRCS = 	pushswap.c lstutils.c parsing.c pushoperation.c libutils.c \
		swapoperation.c rotateoperation.c rrotateoperation.c ft_atoi.c ft_split.c \
		sortthree.c  utils.c sorttwo.c top.c targets.c cost.c bigsort.c ft_substr.c \

SRCBONUS = checker_bonus.c getnextline.c  pushoperation.c utils.c lstutils.c ft_split.c \
		   libutils.c swapoperation.c rotateoperation.c rrotateoperation.c parsing.c ft_atoi.c ft_substr.c\

#VARIABLES
CC = cc
NAME = push_swap
BONUSNAME = checker_linux
OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCBONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

# COLORS
RESET = \033[0m
RED = \033[1;31m
BLUE = \033[1;34m
CYAN = \033[1;36m
BLACK = \033[1;30m
WHITE = \033[1;37m
GREEN = \033[1;32m
PURPLE = \033[1;35m
RED = \033[1;31m
# Special characters
GEAR = ⚙️
CHECK = ✓
SPARK = ✨
ROCKET = 🚀

all: logo $(NAME)

bonus: $(BONUSNAME)

logo:
	@clear
	@echo "\n\n"
	@echo "$(CYAN)Loading ORION SORT Engine...$(RESET)"
	@sleep 0.5
	@echo "$(CYAN)"
	@echo "   ██████╗  ██████╗  ██╗ ██████╗  ███╗   ██╗ "
	@sleep 0.1
	@echo "  ██╔═══██╗ ██╔══██╗ ██║ ██╔══██╗ ████╗  ██║"
	@sleep 0.1
	@echo "  ██║   ██║ ██████╔╝ ██║ ██║  ██║ ██╔██╗ ██║"
	@sleep 0.1
	@echo "  ██║   ██║ ██╔══██╗ ██║ ██║  ██║ ██║╚██╗██║"
	@sleep 0.1
	@echo "  ╚██████╔╝ ██║  ██║ ██║ ██████╔╝ ██║ ╚████║"
	@sleep 0.1
	@echo "   ╚═════╝  ╚═╝  ╚═╝ ╚═╝ ╚═════╝  ╚═╝  ╚═══╝"
	@sleep 0.2
	@echo "$(CYAN)BY: mtaleb$(RESET)"
	@echo "\n$(BLACK)NITIALIZE ORION PUSH SWP COMPONENTS $(SPARK)$(RESET)"
	@sleep 0.5

$(NAME): $(OBJS)
	@echo "\n$(PURPLE)$(GEAR)ASSEMBLING COMPONENTS...$(RESET)"
	@echo "$(BLACK)"
	$(CC) $(OBJS) -o $(NAME)
	@echo "$(RESET)"
	@echo "$(GREEN)$(CHECK)BINARY COMPILATION COMPLETS$(RESET)"
	@echo "\n$(GREEN)$(ROCKET) PUSH SWAP SORT IS READY FOR LAUNCH $(ROCKET)$(RESET)\n"

$(BONUSNAME): $(OBJSBONUS)
	@echo "\n$(PURPLE)$(GEAR)ASSEMBLING COMPONENTS...$(RESET)"
	@echo "$(BLACK)"
	$(CC) $(OBJSBONUS) -o $(BONUSNAME)
	@echo "$(RESET)"
	@echo "$(GREEN)$(CHECK)BINARY COMPILATION COMPLETS$(RESET)"
	
%.o: %.c
	@echo "$(PURPLE)$(GEAR) COMPILING OBJECTS FILES $<...$(RESET)"
	@$(CC) -c $< -o $@
	@echo "$(GREEN)$(CHECK) COMPILED $< SUCCESSFULLY$(RESET)"

clean:
	@rm -rf $(OBJS) $(OBJSBONUS)

fclean: clean
	@rm -rf $(NAME) $(BONUSNAME)
	
re: fclean all

.PHONY: all clean fclean re bonus logo 