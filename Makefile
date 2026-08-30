NAME		= miniRT

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= lib/libft
MLX_DIR		= lib/minilibx

INCLUDES	= -I./includes -I./lib/libft -I$(MLX_DIR)
LIBS		= -L./lib/libft -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Source files
SRC_FILES	= main.c \
				sample.c \
				window/init_window.c \
				window/close_window.c \
				parser/checker/check_extention.c \
				parser/checker/check_line.c \
				parser/checker/check_identifier.c \
				parser/checker/check_ambience.c \
				parser/checker/check_camera.c \
				parser/checker/check_rgb_val.c \
				parser/checker/check_coordinates.c \
				parser/checker/check_double_in_range.c \
				engine/vector.c \
				engine/vector_utils.c \
				engine/vector_product.c \
				parser/reader/read_file.c \
				utils/ft_atod.c \
				utils/ft_count_split_elements.c \
				utils/ft_double_equals.c \
				utils/ft_double_greater_than.c \
				utils/ft_double_less_than.c \
				utils/ft_is_double.c


SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -g3
	@echo "$(GREEN)Compiled: $<$(RESET)"

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✓ FT_miniRT compiled successfully!$(RESET)"

unit-tests:
	@$(MAKE) -C ./tests

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C ./tests
	@echo "$(RED)Object files removed$(RESET)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@rm -rf ./test/test_report.log
	@$(MAKE) fclean -C ./tests
	@echo "$(RED)Executable removed$(RESET)"

tester: CFLAGS += -DTESTER
tester: re
	@echo "$(GREEN)✓ FT_miniRT compiled for tester mode!$(RESET)"

val:
	@valgrind valgrind \
			--leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--trace-children=yes \
			--track-fds=yes		\
			--trace-children-skip='/bin/,/sbin/,/usr/bin/*' \
			./$(NAME)

norminette:
	@norminette src/* includes/*.h

re: fclean all

.PHONY: all clean fclean re tester
