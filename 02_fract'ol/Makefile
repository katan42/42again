NAME = fractol
BONUS_NAME = fractol_bonus
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
MLX_DIR = ./minilibx-linux

LIBS = -L/usr/X11/lib -L$(LIBFT_DIR) -L$(FT_PRINTF_DIR) -L$(MLX_DIR) -lft -lftprintf -lmlx -lXext -lX11 -lm

# Source files
SRC = src/utils_ft_atof.c src/events.c src/main.c src/complex_math.c \
		src/too_complex_fractals.c src/initialise_and_exit.c
		
# Bonus Source files
BONUS_SRC = src_bonus/utils_ft_atof_bonus.c src_bonus/events_bonus.c src_bonus/main_bonus.c \
		src_bonus/complex_math_bonus.c src_bonus/too_complex_fractals_bonus.c \
		src_bonus/initialise_and_exit_bonus.c src_bonus/fractals_newton_bonus.c

# Object files
OBJ =$(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
ALL_OBJ = $(OBJ) $(BONUS_OBJ)

# Dependency files
DEP = $(OBJ:.o=.d)
BONUS_DEP = $(BONUS_OBJ:.o=.d)
ALL_DEP = $(DEP) $(BONUS_DEP)

# Include .d files only if they exists ignore otherwise
-include $(ALL_DEP)

# Compiler and Flags(-MMD generate dependency files to update if .h files are updated -MP prevents errors for .h)
CC = cc
INCLUDE = -I./include/ -I./libft -I./ft_printf/include
CFLAGS = -Wall -Wextra -Werror -MMD -MP $(INCLUDE)

# sets default target
.DEFAULT_GOAL := all

# build the target $(NAMES)
all: $(NAME)

$(NAME):$(OBJ) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(MLX_DIR)/libmlx.a
	    $(CC) $(OBJ) $(LIBS) -o $(NAME)
	    @echo "creating fract'ol"

# Compile .c files to .o files and generate dependency files
src/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

src_bonus/%.o: src_bonus/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Build with bonus files
bonus: $(BONUS_NAME)

$(BONUS_NAME):$(BONUS_OBJ) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(MLX_DIR)/libmlx.a
	    $(CC) $(BONUS_OBJ) $(LIBS) -o $(BONUS_NAME)
	    @echo "creating fract'ol bonus"

# Build libft if not already built
$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

# Build ft_printf if not already built
$(FT_PRINTF_DIR)/libftprintf.a:
		$(MAKE) -C $(FT_PRINTF_DIR)

# Build mlxlib if not already built
$(MLX_DIR)/libmlx.a:
		$(MAKE) -C $(MLX_DIR)

# Remove object and dependency files
clean:
	@echo "cleaning fract'ol and bonus .o and .d files"
	@rm -f $(ALL_OBJ) $(ALL_DEP)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

# Remove program
fclean: clean
	@echo "removing fract'ol and bonus"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	
# Delete everything and rebuilt from scratch
re: fclean all

# Phony targets (commands and not files)
.PHONY: all clean fclean re bonus

