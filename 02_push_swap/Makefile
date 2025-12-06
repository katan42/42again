NAME = push_swap
LIBFT_DIR = ./libft

# Source files
SRC = ./src/initialise.c ./src/input_validation.c ./src/main.c ./src/normalise_values.c \
./src/sort_five.c ./src/sort_radix.c ./src/sort_three.c ./src/sort_utils_menu_checks.c \
./src/stack_operations_push.c ./src/stack_operations_reverse.c ./src/stack_operations_rotate.c \
./src/stack_operations_swap.c ./src/stack_utils_error_free.c

# Object files
OBJ =$(SRC:.c=.o)

# Dependency files
DEP = $(OBJ:.o=.d)

# Include .d files only if they exists ignore otherwise
-include $(DEP)

# Compiler and Flags(-MMD generate dependency files to update if .h files are updated -MP prevents errors for .h)
CC = cc
INCLUDE = -I./include/ -I./libft
CFLAGS = -Wall -Wextra -Werror -MMD -MP $(INCLUDE)

# sets default target
.DEFAULT_GOAL := all

# build the target $(NAMES)
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a
	    $(CC) $(OBJ) $(LIBFT_DIR)/libft.a -o $(NAME)
	    @echo "creating push_swap"

# Compile .c files to .o files and generate dependency files
src/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libft if not already built
$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

# Remove object and dependency files
clean:
	@echo "cleaning push_swap .o and .d files"
	@rm -f $(OBJ) $(DEP)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Remove program
fclean: clean
	@echo "removing push_swap"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	
# Delete everything and rebuilt from scratch
re: fclean all

# Phony targets (commands and not files)
.PHONY: all clean fclean re

