TARGET = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

C_FILES = push_swap.c swap.c push.c rotate.c rev_rotate.c parse.c error.c \
	ft_split.c ft_atol.c strings.c\
	calc_utils.c calc_stack_a.c calc_stack_b.c sort.c

O_DIR = objs

O_FILES = $(patsubst %.c, $(O_DIR)/%.o, $(C_FILES))

HEADER = header_ps.h

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(O_FILES)
	@$(CC) $(CFLAGS) -o $(TARGET) $(O_FILES)
	@echo "Compiled Program"

$(O_DIR)/%.o: %.c $(HEADER) | $(O_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

norm:
	@norminette -R CheckForbiddenSourceHeader

clean:
	@rm -rf $(O_FILES)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf $(TARGET)
	@echo "Removed push_swap"

re: fclean all
