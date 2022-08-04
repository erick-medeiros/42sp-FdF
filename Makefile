NAME				= fdf

SRC_PATH		= src/
OBJ_PATH		= obj/
INC_PATH		= include/
OBJ_DIRS		= obj/
LIBMLX_PATH	= lib/mlx_linux/
LIBFT_PATH	= lib/libft/
LIBFT_INC		= $(LIBFT_PATH)include/

LIBMLX			= $(LIBMLX_PATH)libmlx_Linux.a
LIBFT 			= $(LIBFT_PATH)libft.a

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -I $(INC_PATH) -I $(LIBFT_INC) -I $(LIBMLX_PATH) -g
CC					= cc
RM					= rm -fr
LIB_FLAGS		= -lft -lmlx -lm -lbsd -lXext -lX11

FILES				= main.c
FILES				+= free.c
FILES				+= exit.c
FILES				+= handle_events.c
FILES				+= instructions.c
FILES				+= init.c
FILES				+= read.c
FILES				+= camera.c
FILES				+= render.c
FILES				+= transform.c
FILES				+= transform_rotate.c
FILES				+= projection.c
FILES				+= color.c
FILES				+= bresenham.c
FILES				+= bresenham_octantes.c

SRC					= $(addprefix $(SRC_PATH), $(FILES))
OBJ					= $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

LEAKS_LOG		= leaks.log
LEAKS_EXEC	= ./fdf maps/42.fdf

C_W					= \e[00m
C_G					= \e[32m
C_R					= \e[91m

all: $(NAME)

$(OBJ_DIRS):
	@printf "$(C_G)Create dir$(C_W) $@\n"
	mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(C_G)obj: $(C_W)"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIRS) $(OBJ) $(LIBMLX) $(LIBFT)
	@printf "$(C_G)compile $(NAME) $(C_W)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -L $(LIBMLX_PATH) $(LIB_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(LIBMLX):
	@make -C $(LIBMLX_PATH)

clean:
	@printf "$(C_R)remove all objects$(C_W)\n"
	$(RM) $(OBJ) $(LEAKS_LOG)

fclean: clean
	@printf "$(C_R)remove $(NAME)$(C_W)\n"
	$(RM) $(NAME)

re: fclean all

bonus: all

rebonus: fclean bonus

norm:
	@clear
	@make norm -C $(LIBFT_PATH) --silent
	@norminette $(INC_PATH) $(SRC_PATH) | grep Error || true

leaks:
	@clear
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--log-file=$(LEAKS_LOG) \
	--track-origins=yes $(LEAKS_EXEC)

install:
	sudo apt-get install gcc make xorg libxext-dev libbsd-dev

.PHONY: clean fclean re norm leaks install
