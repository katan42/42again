NAME = libftprintf.a
LIBFT_DIR = ./libft

# Libft Source files
SRC = ./src/ft_printchar.c ./src/ft_printstr.c ./src/ft_print_ptr.c ./src/ft_print_nbr.c \
	./src/ft_print_unsigned_nbr.c ./src/ft_print_hex.c ./src/ft_printf.c

# Object files
OBJ = $(SRC:.c=.o)

# Dependency files
DEP = $(OBJ:.o=.d)

# Include .d files only if they exists ignore otherwise
-include $(DEP)

# Compiler and Flags(-MMD generate dependency files to update if .h files are updated -MP prevents errors for .h)
CC = cc
INCLUDE = -I./include/ -I$(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror -MMD -MP $(INCLUDE)

# sets default target
.DEFAULT_GOAL := all

# build the target $(NAME) libft.a
all: $(NAME)

# Create static library(.a) from object files (using archive tool)
$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a
	@echo "compiling ft_printf .c files to .o and .d files"
	@echo "creating libftprintf.a"
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

# Compile .c files to .o files and generate dependency files
src/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libft if not already built
$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

# Remove object and dependency files
clean:
	@echo "cleaning ft_printf .o and .d files"
	@rm -f $(OBJ) $(DEP)
	@$(MAKE) -C ./libft/ clean

# Remove everything including library
fclean: clean
	@echo "removing libftprintf and libft library"
	@rm -f $(NAME)
	@$(MAKE) -C ./libft/ fclean

# Delete everything and rebuilt from scratch
re: fclean all

# Phony targets (commands and not files)
.PHONY: all clean fclean re

