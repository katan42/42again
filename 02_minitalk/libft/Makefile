NAME = libft.a 

# Libft Source files
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
	  ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
	  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
	  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	  ft_putnbr_fd.c

# Bonus Linked list 
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c  

# Object files
OBJ = $(SRC:.c=.o)
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
CFLAGS = -Wall -Wextra -Werror -MMD -MP

# sets default target
.DEFAULT_GOAL := all

# build the target $(NAME) libft.a
all: $(NAME)

# Create static library(.a) from object files (using archive tool)
$(NAME): $(ALL_OBJ)
	@echo "compiling libft .c files to .o and .d files"
	@echo "creating libft.a"
	@ar rcs $(NAME) $(ALL_OBJ)

# Compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove object and dependency files
clean: 
	@echo "cleaning libft .o and .d files"
	@rm -f $(ALL_OBJ) $(ALL_DEP)

# Remove everything including library
fclean: clean
	@echo "removing libft library"
	@rm -f $(NAME)

# Delete everything and rebuilt from scratch
re: fclean all

# Phony targets (commands and not files)
.PHONY: all clean fclean re bonus
