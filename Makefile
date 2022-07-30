NAME				= fdf

SRC_PATH		= src/
OBJ_PATH		= obj/
INC_PATH		= include/
OBJ_DIRS		= obj/
LIBMLX_PATH	= libmlx_linux/
LIBFT_PATH	= libft/
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
FILES				+= render.c
FILES				+= render_map.c
FILES				+= transform_scale.c
FILES				+= transform_rotate.c
FILES				+= transform_translate.c
FILES				+= projection.c
FILES				+= bresenham.c
FILES				+= bresenham_octantes.c

SRC					= $(addprefix $(SRC_PATH), $(FILES))
OBJ					= $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

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

$(NAME): $(OBJ_DIRS) $(OBJ) $(LIBFT)
	@printf "$(C_G)compile $(NAME) $(C_W)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -L $(LIBMLX_PATH) $(LIB_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@printf "$(C_R)remove all objects$(C_W)\n"
	$(RM) $(OBJ)

fclean: clean
	@printf "$(C_R)remove $(NAME)$(C_W)\n"
	$(RM) $(NAME)

re: fclean all

norm:
	@clear
	@norminette $(INC_PATH) $(SRC_PATH) | grep Error || true

valg:
	@clear
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--log-file=leaks.log \
	--track-origins=yes ./fdf

.PHONY: clean fclean re norm valg
