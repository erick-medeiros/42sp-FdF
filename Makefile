NAME				= fdf
LIBMLX			= libmlx_Linux.a
LIBFT 			= libft.a

CFLAGS			= -Wall -Wextra -Werror
CC					= cc
RM					= rm -fr
MLX_FLAGS		= -lm -lmlx -lXext -lX11

SRC_PATH		= ./src/
OBJ_PATH		= ./obj/
LIBMLX_PATH	= ./libmlx_linux/
LIBFT_PATH	= ./libft/

FILES				= main.c

SRC					= $(addprefix $(SRC_PATH), $(FILES))
OBJ					= $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBMLX_PATH) $(MLX_FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: clean fclean re