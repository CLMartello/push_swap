# Configuration --------------------------------------------------- #

NAME = push_swap

BONUS = checker

HEADER = header_ps.h

# Files ----------------------------------------------------------- #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

# Flags ----------------------------------------------------------- #

C_FILES = push_swap.c swap.c push.c rotate.c rev_rotate.c parse.c error.c \
	ft_split.c ft_atol.c strings.c\
	calc_utils.c calc_stack_a.c calc_stack_b.c sort.c\

BON_C_FILES = swap.c push.c rotate.c rev_rotate.c parse.c error.c \
        ft_split.c ft_atol.c strings.c\
        calc_utils.c calc_stack_a.c calc_stack_b.c sort.c\
	checker.c get_next_line.c

O_DIR = objs

BON_O_DIR = bonus_objs

# Pattern Rule ---------------------------------------------------- #

O_FILES = $(patsubst %.c, $(O_DIR)/%.o, $(C_FILES))

BON_O_FILES = $(patsubst %.c, $(BON_O_DIR)/%.o, $(BON_C_FILES))

$(NAME): $(O_FILES)
	@$(CC) $(CFLAGS) $(O_FILES) -o $(NAME)
	@echo "Compiled Program"

$(O_DIR)/%.o: %.c $(HEADER) | $(O_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

.bonus: $(BON_O_FILES) 
	@$(CC) $(CFLAGS) $(BON_O_FILES) -o $(BONUS)
	@echo "Compiled Bonus"

$(BON_O_DIR)/%.o: %.c $(HEADER) | $(BON_O_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Directory Rule -------------------------------------------------- #

$(O_DIR):
	@mkdir -p $@

$(BON_O_DIR):
	@mkdir -p $@

# Phonies --------------------------------------------------------- #

.PHONY: all clean fclean re

all: $(NAME)

bonus: .bonus

norm:
	@norminette -R CheckForbiddenSourceHeader

clean:
	@rm -rf $(O_FILES) $(BON_O_FILES) $(O_DIR) $(BON_O_DIR)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf $(NAME) $(BONUS)
	@rm -rf .bonus
	@echo "Removed push_swap"

re: fclean all
