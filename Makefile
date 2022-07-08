NAME				= fdf

SRC_PATH		= ./src/
OBJ_PATH		= ./obj/
INC_PATH		= ./include/
LIBMLX_PATH	= ./libmlx_linux/
LIBFT_PATH	= ./libft/
LIBFT_INC		= $(LIBFT_PATH)include/

LIBMLX			= $(LIBMLX_PATH)libmlx_Linux.a
LIBFT 			= $(LIBFT_PATH)libft.a

CFLAGS			= -I $(INC_PATH) -I $(LIBFT_INC)#-Wall -Wextra -Werror
CC					= cc
RM					= rm -fr
LIB_FLAGS		= -lft -lmlx -lm -lbsd -lXext -lX11

FILES				= main.c

SRC					= $(addprefix $(SRC_PATH), $(FILES))
OBJ					= $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -L $(LIBMLX_PATH) $(LIB_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

norm:
	@norminette $(INC_PATH) $(SRC_PATH) | grep Error || true

.PHONY: clean fclean re norm