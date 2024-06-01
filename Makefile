NAME = so_long
CC = cc
OBJS_DIR = objs
SRCS_DIR = src
INCLUDES = -Iincludes -Imlx
FLAGS = -Wall -Werror -Wextra $(INCLUDES)
LINKERS = -lmlx -framework OpenGL -framework AppKit 
MLX_DIR = mlxlib
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
MLX_OBJS = $(wildcard $(MLX_DIR)/*.o)
RM = rm -rf
MKDIR = mkdir -p

ifeq ($(shell uname -s), Linux)
	MLX_DIR = minilibx-linux
	LINKERS = -lmlx -lm -lX11 -lXext
endif
.DEFAULT_GOAL = all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

all: mlx $(NAME)

mlx:
	@make -s -C $(MLX_DIR) >/dev/null 2>&1

$(NAME): $(OBJS) | $(OBJS_DIR)
	$(CC) -s $(OBJS) $(FLAGS) -L $(MLX_DIR) $(LINKERS) -o $(NAME)

bonus: all

clean:
	$(RM) $(MLX_OBJS) $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus