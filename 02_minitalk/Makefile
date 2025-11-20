NAMES = client server
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf

# Client Server Source files
SRC_CLIENT = ./src/client.c
SRC_SERVER = ./src/server.c

# Object files
OBJ_CLIENT =$(SRC_CLIENT:.c=.o)
OBJ_SERVER =$(SRC_SERVER:.c=.o)
OBJ_ALL = $(OBJ_CLIENT) $(OBJ_SERVER)

# Dependency files
DEP_CLIENT = $(OBJ_CLIENT:.o=.d)
DEP_SERVER = $(OBJ_SERVER:.o=.d)
DEP_ALL = $(DEP_CLIENT) $(DEP_SERVER)

# Include .d files only if they exists ignore otherwise
-include $(DEP_ALL)

# Compiler and Flags(-MMD generate dependency files to update if .h files are updated -MP prevents errors for .h)
CC = cc
INCLUDE = -I./include/ -I./libft -I./ft_printf/include
CFLAGS = -Wall -Wextra -Werror -MMD -MP $(INCLUDE)

# sets default target
.DEFAULT_GOAL := all

# build the target $(NAMES)
all: $(NAMES)

client: $(OBJ_CLIENT) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a
	    $(CC) $(OBJ_CLIENT) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a -o client
	    @echo "creating client"

server: $(OBJ_SERVER) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a
	    $(CC) $(OBJ_SERVER) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a -o server
	    @echo "creating server"

# Compile .c files to .o files and generate dependency files
src/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libft if not already built
$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)
	
# Build printf if not already built	
$(FT_PRINTF_DIR)/libftprintf.a:
		$(MAKE) -C $(FT_PRINTF_DIR)

# Remove object and dependency files
clean:
	@echo "cleaning server and client .o and .d files"
	@rm -f $(OBJ_ALL) $(DEP_ALL)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

# Remove program
fclean: clean
	@echo "removing server and client"
	@rm -f $(NAMES)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) fclean

# Delete everything and rebuilt from scratch
re: fclean all

# Phony targets (commands and not files)
.PHONY: all clean fclean re

