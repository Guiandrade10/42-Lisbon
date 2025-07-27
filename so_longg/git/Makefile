# Executable name
NAME        = so_long

# Compilers and flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

# Directories
SRC_DIR     = src
INCLUDE_DIR = include
LIBFT_DIR   = Libft
MLX_DIR     = mlx

# Paths
INCLUDES    = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR)

# Sources and objects
SRC         = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ         = $(SRC:.c=.o)

# Libraries
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_FLAGS   = -Lmlx -lmlx_Linux -lXext -lX11

# Default target
all: $(NAME)

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Link the executable
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT) -no-pie

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean objects
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

# Full clean including binary
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rebuild all
re: fclean all

# Phony targets
.PHONY: all clean fclean re
